
import sys
import pprint
from functools import reduce
import os
import random

""" 
模拟车辆遇到十字路口的行为，：
    u: 5%
    left: 15%
    right: 20%
    straight: 60%
    最后显示统计: {'straight': 60, 'right': 20, 'left': 15, 'u': 5}
    
    要求将这些行为分散开
"""

SLANG = {'left': 'Hang a Louie.',
         'right': 'Hang a Ralph.',
         'straight': 'Hang a Sam.',
         'u': 'Bang a you-ee.'}

def drive_sim(num_intersections: int):
    action_count = dict()
    for i in range(num_intersections):
        direction = random.random()   # 这个函数会输出[0, 1]之间的均匀随机分布。
        if direction <= 0.05:
            action = 'u'
        elif 0.05 < direction <= 0.2:
            action = 'left'
        elif 0.2 < direction <= 0.4:
            action = 'right'
        else:
            action = 'straight'
        action_count[action] = action_count.get(action, 0) + 1
        # action_count[action] = action_count[action] + 1   # 同样
        
        print(i+1, SLANG[action])
    print(action_count)

drive_sim(100)


# c++
void drive_sim(int num) {
    unordered_map<string, int> umap;
    umap["left"] = 0;
    umap["right"] = 0;
    umap["u"] = 0;
    unordered_map<string, string> umap2;
    umap2["left"] = "one";
    umap2["right"] = "two";
    umap2["u"] = "three";

    int random;
    srand((unsigned) time(NULL));
    string action;
    for(int i = 0; i < num; i++) {
        random = rand() % 10;
        if(random <= 3) {
            action = "left";
        } else if(random <= 6) {
            action = "right";
        } else {
            action = "u";
        }
        umap[action]++;
        cout << i + 1 << " , " << umap2[action] << endl;
    }

    for(auto it = umap.begin(); it != umap.end(); it++) {
        cout << it->first << " : " << it->second << " ";
    }
    cout << endl;
}