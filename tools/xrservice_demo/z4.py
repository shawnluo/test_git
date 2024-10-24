
import re
import matplotlib.pyplot as plt
import numpy as np
import sys
import os
import csv
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
camdev_pattern = re.compile(r'XR_CamDev (\d)')
diff_pattern = re.compile(r'diff\((\d+)\)')
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
ts_times = {0: [], 1: [], 2: [], 3: [], 4: [], 5: []}  # 用于存储 ts 值

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
        ts_value_ns = int(match_ts.group(1))  # timestamp value in nanoseconds
        system_time_str = match_time.group(1)   # 系统时间字符串

        # 解析系统时间为 datetime 对象
        system_time = datetime.strptime(system_time_str, "%m-%d %H:%M:%S.%f")

        # Process camdevs 0 to 5
        if camdev_number in camdev_data:
            # Save the converted values in milliseconds
            camdev_data[camdev_number].append(diff_value_ns / 1e6)  # 转换为毫秒
            ts_times[camdev_number].append(ts_value_ns)  # 保存 ts（纳秒）

            # Store the system time for plotting
            system_times[camdev_number].append(
                system_time.timestamp())  # 存储系统时间的时间戳（秒）

# Step 4: Save ts data for fish-eye-mid (camdev_number = 0)
camdev_number = 0  # fish-eye-mid

if ts_times[camdev_number]:
    csv_file_path = 'TS-fish-eye-mid.csv'

    # 将 ts 数据写入 CSV 文件，单位为纳秒
    with open(csv_file_path, 'w', newline='') as csvfile:
        csvwriter = csv.writer(csvfile)
        csvwriter.writerow(['Timestamp (ns)'])  # 写入表头
        for ts in ts_times[camdev_number]:
            csvwriter.writerow([ts])

    print(f"fish-eye-mid 的时间戳已保存到 {csv_file_path}，单位为纳秒。")

    # 计算第一个和最后一个时间戳的差值，转换为毫秒
    first_ts_ns = ts_times[camdev_number][0]  # 第一个时间戳
    last_ts_ns = ts_times[camdev_number][-1]  # 最后一个时间戳

    # 时间差，以毫秒为单位
    total_time_ms = (last_ts_ns - first_ts_ns) / 1e6
    print(f"时间戳范围为 {total_time_ms} 毫秒。")

    # 计算每个时间戳相对于第一个时间戳的时间差，并转换为毫秒
    relative_time_ms = [(ts - first_ts_ns) / 1e6 for ts in ts_times[camdev_number]]

    # 绘制相对时间的分布图（X 轴为时间差，单位：毫秒）
    plt.figure(figsize=(10, 2))  # 创建一个较宽的图以展示时间分布
    plt.scatter(relative_time_ms, [0] * len(relative_time_ms), marker='o', color='blue')
    plt.title('Timestamp Distribution for fish-eye-mid (ms)')
    plt.xlabel('Time (milliseconds)')
    plt.yticks([])  # 移除 Y 轴刻度
    plt.xlim(0, total_time_ms)  # 设置 X 轴范围
    plt.tight_layout()
    plt.show()

else:
    print("没有找到 fish-eye-mid 的 ts 数据。")
