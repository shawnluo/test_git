import re
import matplotlib.pyplot as plt
import numpy as np
import sys
import os

arguments = sys.argv

# Step 1: Read the log file and filter lines containing "XR_CamDev", "AF", "diff", and "now"
file_path = arguments[1]

with open(file_path, 'r') as file:
    lines = file.readlines()

filtered_lines = [line for line in lines if 'XR_CamDev' in line and 'AF' in line and 'diff' in line]

# Step 2: Save filtered lines to a.csv
a_csv_path = './a.csv'
with open(a_csv_path, 'w') as a_file:
    a_file.writelines(filtered_lines)

# Step 3: Split the lines based on XR_CamDev numbers (0 to 5) and extract FPS data from "now" timestamp
camdev_pattern = re.compile(r'XR_CamDev (\d)')
diff_pattern = re.compile(r'diff\((\d+)\)')
now_pattern = re.compile(r'now\((\d+)\)')
ts_pattern = re.compile(r'ts\((\d+)\)')  # 提取 timestamp

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
now_timestamps = {0: [], 1: [], 2: [], 3: [], 4: [], 5: []}
camdev_logs = {0: [], 1: [], 2: [], 3: [], 4: [], 5: []}  # 中间结果日志

for line in filtered_lines:
    match_camdev = camdev_pattern.search(line)
    match_diff = diff_pattern.search(line)
    match_now = now_pattern.search(line)
    match_ts = ts_pattern.search(line)  # 匹配 timestamp

    if match_camdev and match_diff and match_now and match_ts:  # 增加对 timestamp 的匹配
        camdev_number = int(match_camdev.group(1))
        diff_value_ns = int(match_diff.group(1))  # diff value in nanoseconds
        now_value_ns = int(match_now.group(1))  # now value in nanoseconds
        ts_value_ns = int(match_ts.group(1))    # timestamp value in nanoseconds

        # Process camdevs 0 to 5
        if camdev_number in camdev_data:
            # Save the converted values in milliseconds
            camdev_data[camdev_number].append(diff_value_ns / 1e6)  # 转换为毫秒

            # Store the now timestamps for plotting
            now_timestamps[camdev_number].append(now_value_ns)  # 存储 now timestamp
            
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
    if now_timestamps[camdev_number]:
        start_time_ns = now_timestamps[camdev_number][0]  # the first now timestamp for this CamDev
        time_in_seconds = [(t - start_time_ns) / 1e9 for t in now_timestamps[camdev_number]]  # convert to seconds

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
        fps_data[camdev_number].append(fps_count)

# Plotting three plots (Box plot + FPS plot + Timestamp plot)
fig, axs = plt.subplots(3, 1, figsize=(16, 12))

# Plot 1: Box Plot for diff values
data_to_plot_ms = [camdev_data[i] for i in range(6)]
axs[0].boxplot(data_to_plot_ms, vert=False, patch_artist=True, tick_labels=[camdev_map[i] for i in range(6)])
axs[0].set_title('Box Plot with diff Data (in milliseconds) for Cameras')
axs[0].set_xlabel('Diff Values (in milliseconds)')
axs[0].set_ylabel('Camera')

# Plot 2: FPS Plot for Cameras
for camdev_number in range(0, 6):  # Loop through the camdev numbers 0 to 5
    axs[1].plot(np.arange(len(fps_data[camdev_number])), fps_data[camdev_number], label=camdev_map[camdev_number])

axs[1].set_title('FPS (Frames per Second) for Cameras')
axs[1].set_xlabel('Time (seconds)')
axs[1].set_ylabel('FPS')
axs[1].legend()

# Plot 3: Timestamp Plot for Cameras (使用散点图，展示 now timestamp)
fig_ts, axs_ts = plt.subplots(6, 1, figsize=(16, 12), sharex=True)

for camdev_number in range(0, 6):
    if now_timestamps[camdev_number]:
        # 计算与第一个 now timestamp 的差值
        first_now_timestamp = now_timestamps[camdev_number][0]
        relative_time = [(now - first_now_timestamp) for now in now_timestamps[camdev_number]]  # 保持纳秒单位
        
        # 确保相对时间和y值匹配
        if len(relative_time) > 0:
            axs_ts[camdev_number].scatter(np.array(relative_time) / 1e6, [camdev_number] * len(relative_time), label=camdev_map[camdev_number])  # 转换为毫秒
        axs_ts[camdev_number].set_title(f'Now Timestamps for {camdev_map[camdev_number]}')
        axs_ts[camdev_number].set_ylabel('Camera')
        axs_ts[camdev_number].set_yticks([camdev_number])  # 设置y轴刻度只显示摄像头编号
        axs_ts[camdev_number].legend()

# 设置x轴范围和刻度
max_time = max(max(now) for now in (ts for ts in now_timestamps.values() if ts))  # 找到最大的 now timestamp
axs_ts[-1].set_xlabel('Time (milliseconds)')  # X-axis label for the last subplot
axs_ts[-1].set_xlim(0, max_time)  # 设置x轴范围（保持纳秒单位）
tick_frequency = max_time / 10  # 控制刻度数量
axs_ts[-1].set_xticks(np.arange(0, max_time, tick_frequency))  # 设置刻度

# Save the combined plot
combined_plot_path = './combined_plot.png'
plt.tight_layout()  # Improve layout
plt.savefig(combined_plot_path)

# Show the plot on the screen
plt.show()

print(f"Combined plot saved to {combined_plot_path}")
print(f"Filtered data saved to respective CSV files.")
