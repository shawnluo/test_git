#include "common.h"
#include "test.h"

/*
project:BFS
author:zhy
IDE:VSCode
Comlile:windows gcc -v 4.8.1
*/

#include <stdio.h>
#include <stdlib.h>

#define _MAX_X 5 // 迷宫的大小
#define _MAX_Y 4

int arr[_MAX_X][_MAX_Y] = {0};                           // 迷宫二维数组
int endx = 3, endy = 2;                                  // 目的地
int startx = 0, starty = 0;                              // 起点
int stop[][2] = {{0, 2}, {2, 2}, {3, 1}, {4, 3}};        // 障碍物
int next_step[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 上下左右四个方向(坐标变化)

struct point
{ // 迷宫的每一个点
    int x;
    int y;
    int step; // 当前的步数：每一次扩展都加1
    int pre;  // 上一个点，该属性用于的得到走迷宫的路径
};
int head, tail; // 队列的队头和队尾

// 使用数组来模拟队列，该队列存储广度搜素时经过的每一个点
struct point queue[_MAX_X * _MAX_Y] = {0};

/*绘制迷宫到终端*/
int draw()
{
    int i, j;

    // 打印迷宫图
    putchar('\n');
    for (i = 0; i < _MAX_X; ++i)
    {
        for (j = 0; j < _MAX_Y; ++j)
        {
            switch (arr[i][j])
            {
            case 0:
                printf("_"); // 可以走的地方
                break;
            case -1:
                printf("X"); // 障碍物
                break;
            case -2:
                printf("O"); // 终点
                break;
            case -3:
                printf("S"); // 起点
                break;
            default:
                printf("%d", arr[i][j]);
                break;
            }
            printf("|");
        }
        printf("\n");
    }
    putchar('\n');
}

// BFS
void bfs()
{
    int i = 0;
    int nextx = 0, nexty = 0; // 下一个点的坐标

    // 标记是否找到目标(除了标记找到目标以外，它还用于跳出while和for两重嵌套的循环)
    int flag = 0;

    // 队列的头尾
    head = 0;
    tail = 0;

    // 将起点入队
    queue[tail].x = startx;
    queue[tail].y = starty;
    queue[tail].pre = 0;
    queue[tail].step = 1;
    ++tail; // 移到下一个空白位置

    while (head < tail) // 队列中还存在点没有完成广度搜索
    {
        for (i = 0; i < sizeof(arr) / sizeof(int) / 2; ++i)
        {
            nextx = queue[head].x + next_step[i][0];
            nexty = queue[head].y + next_step[i][1];

            // 判断这些点是不是在迷宫内
            if (nextx < 0 || nexty < 0 || nextx >= _MAX_X || nexty >= _MAX_Y)
            {
                continue;
            }

            // 判断这些点是否可以走(不是障碍且没有走过)
            if (arr[nextx][nexty] == 0)
            {
                /*将这个点标记为已经走过了，然后令这个点入队;准备在当前所有方向尝试完成后(即for循环结束)进行扩展(去下一层次的点,进入下一次while)*/
                arr[nextx][nexty] = queue[head].step; // 标记
                queue[tail].x = nextx;
                queue[tail].y = nexty;
                queue[tail].step = queue[head].step + 1;
                queue[tail].pre = head;
                ++tail; // 移动tail

                // 以下两行用于搜索过程可视化，没有实际算法意义
                draw();
                system("pause");
            }

            if (nextx == endx && nexty == endy)
            {
                flag = 1;
                break;
            }
        } /*End for()*/

        if (flag != 0)
            break;
        else
            ++head;
        // 执行else，表明该点的所有方向已完成搜索，因此++head进入下一深度的搜索
    } /*End while()*/
}

int main(int argc, char **argv)
{
    int i = 0, j = 0;

    // 为障碍物、起点终点等对应的数组元素赋值
    for (i = 0; i < sizeof(stop) / sizeof(int) / 2; ++i)
    {
        arr[stop[i][0]][stop[i][1]] = -1; // 障碍物
    }
    arr[endx][endy] = -2;     // 目的地
    arr[startx][starty] = -3; // 出发ç¹

    draw();
    bfs();

    return 0;
}