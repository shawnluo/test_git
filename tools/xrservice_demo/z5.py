import re
import matplotlib.pyplot as plt
import csv
import sys
from datetime import datetime

arguments = sys.argv

# 提取摄像头名称和对应的编号
camdev_map = {
    0: "fish-eye-mid",
    1: "fish-eye-leftdown",
    2: "fish-eye-rightdown",
    3: "tof",
    4: "rgb-left",
    5: "rgb-right"
}

# 初始化存储时间戳数据
ts_times = {0: [], 1: [], 2: [], 3: [], 4: [], 5: []}  # 存储各摄像头的 ts 值
system_times = {0: [], 1: [], 2: [], 3: [], 4: [], 5: []}  # 存储系统时间

# 假设日志文件已经从命令行参数获取，或通过其他方式传递
# file_path = 'your_log_file_path_here'  # 这里替换为实际的日志文件路径
file_path = arguments[1]

# 正则表达式用于提取时间戳 (ts) 和摄像头编号 (camdev_number)
camdev_pattern = re.compile(r'XR_CamDev (\d)')
ts_pattern = re.compile(r'ts\((\d+)\)')  # 提取 timestamp

# 读取日志文件并提取数据
with open(file_path, 'r') as file:
    lines = file.readlines()

for line in lines:
    match_camdev = camdev_pattern.search(line)
    match_ts = ts_pattern.search(line)  # 匹配时间戳

    if match_camdev and match_ts:
        camdev_number = int(match_camdev.group(1))  # 获取摄像头编号
        ts_value_ns = int(match_ts.group(1))  # 获取时间戳（以纳秒为单位）
        
        # 存储时间戳数据
        if camdev_number in ts_times:
            ts_times[camdev_number].append(ts_value_ns)

# Step 1: 设置颜色和y轴位置
colors = ['blue', 'green', 'red', 'purple', 'orange', 'cyan']  # 为每个摄像头定义颜色
y_offsets = [0, 1, 2, 3, 4, 5]  # 将摄像头数据绘制在不同的水平线上

# Step 2: 遍历所有摄像头并绘制每个摄像头的时间戳分布
plt.figure(figsize=(10, 6))  # 创建一个较高的图表，方便展示6个摄像头的数据

max_total_time_ms = 0  # 用来确定 X 轴的范围

for camdev_number in range(0, 6):
    if ts_times[camdev_number]:  # 确保有 ts 数据
        first_ts_ns = ts_times[camdev_number][0]  # 获取第一个时间戳
        last_ts_ns = ts_times[camdev_number][-1]  # 获取最后一个时间戳

        # 时间差，以毫秒为单位
        total_time_ms = (last_ts_ns - first_ts_ns) / 1e6
        max_total_time_ms = max(max_total_time_ms, total_time_ms)  # 更新最大时间差

        # 计算每个时间戳相对于第一个时间戳的时间差，并转换为毫秒
        relative_time_ms = [(ts - first_ts_ns) / 1e6 for ts in ts_times[camdev_number]]

        # 检查是否有正确的时间差数据
        print(f"Camera {camdev_number} relative times (ms): {relative_time_ms}")

        # 绘制每个摄像头的时间戳分布，y_offsets 确保每个摄像头绘制在不同的水平线上
        plt.scatter(relative_time_ms, [y_offsets[camdev_number]] * len(relative_time_ms),
                    marker='o', color=colors[camdev_number], label=camdev_map[camdev_number])

# Step 3: 设置图表的其他属性
plt.title('Timestamp Distribution for All Cameras (ms)')
plt.xlabel('Time (milliseconds)')
plt.yticks(y_offsets, [camdev_map[i] for i in range(6)])  # 设置 Y 轴标签为摄像头名称

# 确保 X 轴能够显示所有数据点
plt.xlim(0, max_total_time_ms * 1.1)  # 增加 10% 的缓冲区
plt.legend(loc='upper right')  # 在右上角显示图例，区分颜色
plt.tight_layout()
plt.show()

# 保存fish-eye-mid的ts值到CSV文件
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

    # 计算第一个和最后一个时间戳的差值，并转换为毫秒
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
