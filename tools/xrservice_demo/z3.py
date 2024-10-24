import re
import matplotlib.pyplot as plt
import numpy as np
import sys
import os
from datetime import datetime

arguments = sys.argv

# Step 1: Read the log file and filter lines containing "XR_CamDev", "AF", "diff", and "now"
file_path = arguments[1]

with open(file_path, 'r') as file:
    lines = file.readlines()

filtered_lines = [
    line for line in lines if 'XR_CamDev' in line and 'AF' in line and 'diff' in line]

# Step 2: Save filtered lines to a.csv
a_csv_path = './a.csv'
with open(a_csv_path, 'w') as a_file:
    a_file.writelines(filtered_lines)

# Step 3: Split the lines based on XR_CamDev numbers (0 to 5) and extract relevant data
camdev_pattern = re.compile(r'XR_CamDev (\d)')  # \d  match number, r  raw string
diff_pattern = re.compile(r'diff\((\d+)\)')     # \d+  match 1 or multiple numbers    \d{2} match 2 continue numbers
now_pattern = re.compile(r'now\((\d+)\)')
ts_pattern = re.compile(r'ts\((\d+)\)')  # 提取 timestamp
time_pattern = re.compile(r'(\d{2}-\d{2} \d{2}:\d{2}:\d{2}\.\d{3})')  # 提取系统时间

# Mapping XR_CamDev numbers to camera names
camdev_map = {
    0: "fish-eye-mid",
    1: "fish-eye-leftdown",
    2: "fish-eye-rightdown",
    3: "tof",
    4: "rgb-left",
    5: "rgb-right"
}

camdev_data = {0: [], 1: [], 2: [], 3: [], 4: [], 5: []}
fps_data = {0: [], 1: [], 2: [], 3: [], 4: [], 5: []}
system_times = {0: [], 1: [], 2: [], 3: [], 4: [], 5: []}  # 用于存储系统时间
camdev_logs = {0: [], 1: [], 2: [], 3: [], 4: [], 5: []}  # 中间结果日志

ts_times = {0: [], 1: [], 2: [], 3: [], 4: [], 5: []}  # 用于存储 ts_value_ns

for line in filtered_lines:
    match_camdev = camdev_pattern.search(line)
    match_diff = diff_pattern.search(line)
    match_now = now_pattern.search(line)
    match_ts = ts_pattern.search(line)  # 匹配 timestamp
    match_time = time_pattern.search(line)  # 匹配系统时间

    if match_camdev and match_diff and match_now and match_ts and match_time:  # 确保所有数据都被匹配
        camdev_number = int(match_camdev.group(1))
        diff_value_ns = int(match_diff.group(1))  # diff value in nanoseconds
        now_value_ns = int(match_now.group(1))  # now value in nanoseconds
        # timestamp value in nanoseconds
        ts_value_ns = int(match_ts.group(1))
        system_time_str = match_time.group(1)   # 系统时间字符串

        # 解析系统时间为 datetime 对象
        system_time = datetime.strptime(system_time_str, "%m-%d %H:%M:%S.%f")

        # Process camdevs 0 to 5
        if camdev_number in camdev_data:
            # Save the converted values in milliseconds
            camdev_data[camdev_number].append(diff_value_ns / 1e6)  # 转换为毫秒

            # Store the system time for plotting
            system_times[camdev_number].append(
                system_time.timestamp())  # 存储系统时间的时间戳（秒）

            # 保存中间结果日志
            camdev_logs[camdev_number].append(line)  # 保存当前行

# Step 4: Save intermediate results to CSV files
for camdev_number in range(0, 6):
    if camdev_logs[camdev_number]:
        log_file_path = f'./camdev_{camdev_map[camdev_number]}.csv'
        with open(log_file_path, 'w') as log_file:
            log_file.writelines(camdev_logs[camdev_number])

# Step 5: Calculate FPS based on timestamps (1 second interval)
for camdev_number in range(0, 6):
    if system_times[camdev_number]:
        # the first system time for this CamDev
        start_time = system_times[camdev_number][0]
        time_in_seconds = [(t - start_time)
                           # convert to seconds
                           for t in system_times[camdev_number]]

        # Count how many timestamps fall within each 1-second interval
        current_second = 0
        fps_count = 0
        for t in time_in_seconds:
            if t < current_second + 1:
                fps_count += 1
            else:
                fps_data[camdev_number].append(fps_count)
                current_second += 1
                fps_count = 1  # count this frame for the new second

        # Append the last FPS count
        fps_data[camdev_number].append(fps_count) # 每一秒一个数据

# Plotting three plots (Box plot + FPS plot + Timestamp plot)
fig, axs = plt.subplots(3, 1, figsize=(16, 12))

# Plot 1: Box Plot for diff values
data_to_plot_ms = [camdev_data[i] for i in range(6)]
axs[0].boxplot(data_to_plot_ms, vert=False, patch_artist=True,
               tick_labels=[camdev_map[i] for i in range(6)])
axs[0].set_title('Box Plot with diff Data (in milliseconds) for Cameras')
axs[0].set_xlabel('Diff Values (in milliseconds)')
axs[0].set_ylabel('Camera')

# Plot 2: FPS Plot for Cameras
for camdev_number in range(0, 6):  # Loop through the camdev numbers 0 to 5
    axs[1].plot(np.arange(len(fps_data[camdev_number])),
                fps_data[camdev_number], label=camdev_map[camdev_number])

axs[1].set_title('FPS (Frames per Second) for Cameras')
axs[1].set_xlabel('Time (seconds)')
axs[1].set_ylabel('FPS')
axs[1].legend()

# Plot 3: Timestamp Plot for Cameras (使用散点图，展示系统时间)
fig_ts, axs_ts = plt.subplots(6, 1, figsize=(16, 12), sharex=True)

# for camdev_number in range(0, 6):
#     if system_times[camdev_number]:
#         # 计算与第一个系统时间的差值
#         first_system_time = system_times[camdev_number][0]
#         relative_time = [(ts - first_system_time)
#                          for ts in system_times[camdev_number]]  # 保持秒单位

#         # 确保相对时间和y值匹配
#         # print(f"Camera {camdev_map[camdev_number]}: Relative times (seconds): {
#         #       relative_time}")  # 调试信息
#         if len(relative_time) > 0:
#             axs_ts[camdev_number].scatter(relative_time, [
#                                           # 保持秒单位
#                                           camdev_number] * len(relative_time), label=camdev_map[camdev_number])
#         axs_ts[camdev_number].set_title(
#             f'System Times for {camdev_map[camdev_number]}')
#         axs_ts[camdev_number].set_ylabel('Camera')
#         axs_ts[camdev_number].set_yticks([camdev_number])  # 设置y轴刻度只显示摄像头编号
#         axs_ts[camdev_number].legend()

# # 设置x轴范围和刻度
# max_time = max(max(ts) for ts in system_times.values() if ts)  # 找到最大的系统时间
# print(f"Max time (seconds): {max_time}")  # 调试信息
# axs_ts[-1].set_xlabel('Time (seconds)')  # X-axis label for the last subplot
# axs_ts[-1].set_xlim(0, max_time)  # 设置x轴范围
# tick_frequency = max_time / 10  # 控制刻度数量
# axs_ts[-1].set_xticks(np.arange(0, max_time, tick_frequency))  # 设置刻度

# # Save the combined plot
# combined_plot_path = './combined_plot.png'
# plt.tight_layout()  # Improve layout
# plt.savefig(combined_plot_path)

# # Show the plot on the screen
# plt.show()

# 绘制时间戳（以纳秒为单位）的分布，只显示横轴
for camdev_number in range(0, 6):  # 遍历每个摄像头
    if ts_times[camdev_number]:  # 确保有 ts 数据
        first_ts_ns = ts_times[camdev_number][0]  # 获取第一个 ts 时间戳（纳秒）
        # 计算相对于第一个时间点的时间差，单位为纳秒
        relative_time_ns = [(ts - first_ts_ns) for ts in ts_times[camdev_number]]

        if len(relative_time_ns) > 0:
            # 绘制散点图，x轴为相对时间（纳秒），y轴为空，所有点绘制在同一水平线上
            axs_ts[camdev_number].scatter(relative_time_ns, 
                                          [0] * len(relative_time_ns),  # 将所有点绘制在y=0的水平线上
                                          label=camdev_map[camdev_number])
        axs_ts[camdev_number].set_title(f'Timestamp Distribution for {camdev_map[camdev_number]} (ns)')
        axs_ts[camdev_number].set_yticks([])  # 移除Y轴的刻度
        axs_ts[camdev_number].legend()

# 设置x轴的刻度和范围
valid_ts_times = [ts for ts in ts_times.values() if ts]  # 过滤掉空的时间戳列表

# 计算最大时间戳（纳秒）
if valid_ts_times:
    max_time_ns = max(max(ts) for ts in valid_ts_times)  # 找到最大 ts 时间戳（纳秒）
else:
    max_time_ns = 0  # 如果没有有效的时间戳数据，最大时间设置为 0

axs_ts[-1].set_xlabel('Time (nanoseconds)')  # x轴标签
axs_ts[-1].set_xlim(0, max_time_ns)  # 设置x轴范围
if max_time_ns > 0:
    tick_frequency_ns = max_time_ns / 10  # 设置刻度频率
    axs_ts[-1].set_xticks(np.arange(0, max_time_ns, tick_frequency_ns))  # 设置x轴刻度

plt.tight_layout()  # 调整布局，防止重叠
plt.show()



# print(f"Combined plot saved to {combined_plot_path}")
# print(f"Filtered data saved to respective CSV files.")
