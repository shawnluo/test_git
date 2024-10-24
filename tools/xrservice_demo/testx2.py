import re
import matplotlib.pyplot as plt
import numpy as np
import sys

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
ts_pattern = re.compile(r'ts\((\d+)\)')  # 新增：提取 timestamp

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
timestamps = {0: [], 1: [], 2: [], 3: [], 4: [], 5: []}

a0_lines, a1_lines, a2_lines, a3_lines, a4_lines, a5_lines = [], [], [], [], [], []

for line in filtered_lines:
    match_camdev = camdev_pattern.search(line)
    match_diff = diff_pattern.search(line)
    match_now = now_pattern.search(line)
    match_ts = ts_pattern.search(line)  # 新增：匹配 timestamp

    if match_camdev and match_diff and match_now and match_ts:  # 修改：增加对 timestamp 的匹配
        camdev_number = int(match_camdev.group(1))
        diff_value_ns = int(match_diff.group(1))  # diff value in nanoseconds
        diff_value_ms = diff_value_ns / 1e6  # convert to milliseconds
        now_value_ns = int(match_now.group(1))  # now value in nanoseconds
        ts_value_ns = int(match_ts.group(1))    # timestamp value in nanoseconds

        # Process camdevs 0 to 5
        if camdev_number in camdev_data:
            if camdev_number == 0:
                a0_lines.append(line)
            elif camdev_number == 1:
                a1_lines.append(line)
            elif camdev_number == 2:
                a2_lines.append(line)
            elif camdev_number == 3:
                a3_lines.append(line)
            elif camdev_number == 4:
                a4_lines.append(line)
            elif camdev_number == 5:
                a5_lines.append(line)

            # Save the converted values in milliseconds
            camdev_data[camdev_number].append(diff_value_ms)

            # Store the timestamps for calculating FPS and plotting
            timestamps[camdev_number].append(now_value_ns)
            timestamps[camdev_number].append(ts_value_ns)  # 新增：存储 timestamp

# Step 4: Calculate FPS based on timestamps (1 second interval)
for camdev_number in range(0, 6):
    if timestamps[camdev_number]:
        start_time_ns = timestamps[camdev_number][0]  # the first timestamp for this CamDev
        time_in_milliseconds = [(t - start_time_ns) / 1e6 for t in timestamps[camdev_number]]  # convert to milliseconds

        # Count how many timestamps fall within each 1-second interval
        current_second = 0
        fps_count = 0
        for t in time_in_milliseconds:
            if t < current_second + 1000:  # 1000 milliseconds in a second
                fps_count += 1
            else:
                fps_data[camdev_number].append(fps_count)
                current_second += 1000  # move to the next second
                fps_count = 1  # count this frame for the new second
        
        # Append the last FPS count
        fps_data[camdev_number].append(fps_count)

# Update file paths to reflect the new camera names
file_map = {
    0: './fish-eye-mid.csv',
    1: './fish-eye-leftdown.csv',
    2: './fish-eye-rightdown.csv',
    3: './tof.csv',
    4: './rgb-left.csv',
    5: './rgb-right.csv',
}

# Step 5: Save each camera's filtered lines to respective files
with open(file_map[0], 'w') as file_mid:
    file_mid.writelines(a0_lines)
with open(file_map[1], 'w') as file_leftdown:
    file_leftdown.writelines(a1_lines)
with open(file_map[2], 'w') as file_rightdown:
    file_rightdown.writelines(a2_lines)
with open(file_map[3], 'w') as file_rgb_left:
    file_rgb_left.writelines(a3_lines)
with open(file_map[4], 'w') as file_rgb_right:
    file_rgb_right.writelines(a4_lines)
with open(file_map[5], 'w') as file_unknown:
    file_unknown.writelines(a5_lines)

# Plotting three plots (Box plot + FPS plot + Timestamp plot)
fig, axs = plt.subplots(3, 1, figsize=(16, 9))

# Plot 1: Box Plot for diff values
data_to_plot_ms = [camdev_data[0], camdev_data[1], camdev_data[2], camdev_data[3], camdev_data[4], camdev_data[5]]
axs[0].boxplot(data_to_plot_ms, vert=False, patch_artist=True, tick_labels=[camdev_map[i] for i in range(0, 6)])
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

# Plot 3: Timestamp Plot for Cameras (使用散点图，展示时间差）
fig_ts, axs_ts = plt.subplots(6, 1, figsize=(16, 12), sharex=True)

for camdev_number in range(0, 6):
    if timestamps[camdev_number]:
        # 计算时间差
        relative_time = [0]  # 第一个时间戳
        previous_timestamp = timestamps[camdev_number][0]
        
        for ts in timestamps[camdev_number][1:]:
            time_diff = (ts - previous_timestamp) / 1e6  # 转换为毫秒
            relative_time.append(relative_time[-1] + time_diff)
            previous_timestamp = ts

        # 绘制时间戳
        axs_ts[camdev_number].scatter(relative_time, [camdev_number] * len(relative_time), label=camdev_map[camdev_number])
        axs_ts[camdev_number].set_title(f'Timestamps for {camdev_map[camdev_number]}')
        axs_ts[camdev_number].set_ylabel('Camera')
        axs_ts[camdev_number].legend()

axs_ts[-1].set_xlabel('Time (milliseconds)')  # X-axis label for the last subplot

# Save the combined plot
combined_plot_path = './combined_plot.png'
plt.tight_layout()  # Improve layout
plt.savefig(combined_plot_path)

# Show the plot on the screen
plt.show()

print(f"Combined plot saved to {combined_plot_path}")
print(f"Filtered data saved to respective CSV files: {list(file_map.values())}")
