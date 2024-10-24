import re
import matplotlib.pyplot as plt
import numpy as np
import csv
from datetime import datetime

# ts_times 中存储每个摄像头的时间戳（模拟数据，单位：纳秒）
ts_times = {0: [], 1: [], 2: [], 3: [], 4: [], 5: []}  # 用于存储各摄像头的 ts 值

# 模拟时间戳数据，最后一个摄像头有变化
ts_times[0] = [162784923123456789, 162784923223456789, 162784923323456789]  # fish-eye-mid
ts_times[1] = [162784923123456789, 162784923223456789, 162784923323456789]  # fish-eye-leftdown
ts_times[2] = [162784923123456789, 162784923223456789, 162784923323456789]  # fish-eye-rightdown
ts_times[3] = [162784923123456789, 162784923223456789, 162784923323456789]  # tof
ts_times[4] = [162784923123456789, 162784923223456789, 162784923323456789]  # rgb-left
ts_times[5] = [162784923123456789, 162784923223456789, 162784923423456789]  # rgb-right (变化)

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
                    marker='o', color=colors[camdev_number], label=f"Camera {camdev_number}")

# Step 3: 设置图表的其他属性
plt.title('Timestamp Distribution for All Cameras (ms)')
plt.xlabel('Time (milliseconds)')
plt.yticks(y_offsets, [f"Camera {i}" for i in range(6)])  # 设置 Y 轴标签为摄像头编号

# 确保 X 轴能够显示所有数据点
plt.xlim(0, max_total_time_ms * 1.1)  # 增加 10% 的缓冲区
plt.legend(loc='upper right')  # 在右上角显示图例，区分颜色
plt.tight_layout()
plt.show()
