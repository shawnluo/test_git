
import matplotlib.pyplot as plt 
import numpy as np 
import random
import sys
import os
import signal
import re

time_length = 1600
time_sample = 100
# time_interval = float(time_length / time_sample)
error_coeff = 3
t = np.linspace(0, time_length, time_sample)
Slope = 1
Intercept = 0
standard_in = 0

# The system model
system_model = lambda i : Slope * i + Intercept
standard_out = system_model(standard_in) # 100

'''
Kp = 0.8 # average
Ki = -0.7 # intergre
Kd = -0.01 # diff
'''

Kp = 0.8 # average
Ki = -0.7 # intergre
Kd = 0.01 # diff

error_bef = []
real_out_ajust = []

# 模拟胶带初始运动方向，此刻胶带与中心点的距离:   75cm --> 80cm
real_out_ajust.append(350)
real_out_ajust.append(370)

error_bef.append(real_out_ajust[0] - standard_out)
Out_plt = np.linspace(standard_out, standard_out, time_sample)

def handler(signum, frame):
    print('This gets printed after the window closes, signal is:', signum)

def handle_close(evt):
    print('Handling close as user clicked on window')
    if evt == "ctrl+c":
        plt.close() # close the figure
        exit() # exit the program cleanly

# 标准直接计算公式1：Pout = Kp * e(t) + Ki * Sum[e(t)] + Kd * [e(t) - e(t - 1)]
def PID_Controller_Direct_Mem(standard_out, t):
        global time_sample, Kp, Ki, Kd, error_bef, real_out_ajust
        if t > time_sample:
                print("Time Out! Quit!")
                return -1
        # print("real_out_ajust[", t, "] =", real_out_ajust[t])
        
        error_now = real_out_ajust[t] - standard_out
        error_bef.append(error_now) # 记录了所有的误差
        
        integrate_res = np.sum(error_bef)
        Diffirent_res = error_now - error_bef[t - 1]
        
        # format 1
        # print("p: %5.5f" %error_now, "i: %5.5f" %integrate_res, "d: %5.5f" %Diffirent_res)
        
        # format 2
        # format_string = "%-9s %-{}s %6.3f%% (%{}i/%{}i) total events: %{}i".format(
        #          max_len_key, max_len_pos, max_len_total, max_len_events)
        # Version:  1.0.0.0  2.688% (10/372) total events: 150
        # Version:  1.4.1.15 0.000% ( 0/181) total events:  73

        # format 3
        format_string = "[p] %8.3f%%   [i] %8.3f%%    [d] %8.3f%%".format(
                 error_now, integrate_res, Diffirent_res)
        print(format_string % (error_now, integrate_res, Diffirent_res))
        
        # print(1, re.sub(r'\.?0+$',lambda match: ' '*(match.end()-match.start()),'{:>7.3f}'.format(error_now)),'|')
        
        # 比例 Kp * error_now：         将胶带回调到中心点的力度（误差比较大的时候，这一项也会比较大；当误差比较小的时候，会比较小）  单独使能，胶带会做往返运动！
        # 积分 Ki * integrate_res:      对过去做累计   -->   过去所有误差相加  =  最后胶带停下来的位置
        # 微分 Kd * Diffirent_res：     对未来做预测   -->   上次距离中点的距离 - 此次距离中点的距离，由于for循环中，每次都进行计算 = 速度  单独使能，会对速度做出反应 - 速度越快，这一项的份量越大
        return Kp * error_now + Ki * integrate_res + Kd * Diffirent_res


def main():
        print("The Standard Output: %d" % standard_out)
        # signal.signal(signal.SIGINT, handler)
        signal.signal(signal.SIGINT, signal.SIG_DFL)
        
        for t_slice in range(1, time_sample - 1):
                Pout = PID_Controller_Direct_Mem(standard_out, t_slice)
                real_out_ajust.append(system_model(Pout))

        # fig, ax = plt.subplots()
        plt.figure('PID_Controller_Direct_Mem')
        plt.xlim(0, time_length)
        plt.ylim(-600, 600)

        plt.plot(t, real_out_ajust, color = "red")
        plt.plot(t, Out_plt)

        # plt.subplots().canvas.mpl_connect('key_press_event', handle_close)
        
        plt.show()
        

if __name__ == "__main__":
        main()

