#include <iostream>
#include <string.h>
#include <vector>
#include <memory>
#include "common.h"
using namespace std;

template<class T>
void printVector(vector<vector<T>> const &matrix) {
    for (vector<T> row: matrix) {
        for (T val: row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void test_2_wei_bag_problem1() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    // 二维数组
    vector<vector<int>> dp(weight.size() + 1, vector<int>(bagWeight + 1, 0));

    // 初始化 
    for (int j = bagWeight; j >= weight[0]; j--) {
        dp[0][j] = dp[0][j - weight[0]] + value[0];
    }

    // weight数组的大小 就是物品个数
    for(int i = 1; i < weight.size(); i++) { // 遍历物品
        for(int j = 0; j <= bagWeight; j++) { // 遍历背包容量
            if (j < weight[i]) 	dp[i][j] = dp[i - 1][j];
            else 				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
    }

    cout << dp[weight.size() - 1][bagWeight] << endl;
}


void spiral_mat() {
	int m = 3;
	//int mat[m][m] = {	{1, 2, 3},
	//					{4, 5, 6},
	//					{7, 8, 9}};
	//vector<vector<int>> mat(m, vector<int> (m, 0));

	vector<vector<int>> mat {
						{1, 2, 3},
						{4, 5, 6},
						{7, 8, 9}
						};

	int loop = m / 2;
	int startx = 0;
	int starty = 0;
	int offset = 1; //?

	while(loop--) {
		int x = startx;
		int y = starty;

		for(y = starty; y < m - offset; y++) printf("%d ", mat[x][y]);
		//printf("\n");

		for(x = startx; x < m - offset; x++) printf("%d ", mat[x][y]);
		//printf("\n");
		
		for( ; y > starty; y--) printf("%d ", mat[x][y]);
		//printf("\n");
		
		for( ; x > startx; x--) printf("%d ", mat[x][y]);
		//printf("\n");

		startx++, starty++;
		offset++;
	}
	if(loop % 2)	printf("%d ", mat[m / 2][m / 2]);
}

int spiral_mat_2(vector<vector<int>> matx, int m, int n) {
	vector<vector<int>> mat {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
	int row = 4;
	int col = 3;
	int count = row * col;
	int offset = 1;
	int startx = 0;
	int starty = 0;

	#if 1
	printVector(mat);

	return 0;
	#endif

	while(count) {
		int x = startx;
		int y = starty;
		for(y = starty; y < col - offset; y++) {
			//printf("%d, ", mat[x][y]);
			cout << mat[x][y] << " ";
			count--;
		}
		for(x = startx; y < row - offset; x++) {
			printf("%d, ", mat[x][y]);
			count--;
		}
		for( ; y > starty; y--) {
			printf("%d, ", mat[x][y]);
			count--;
		}
		for( ; x > startx; x--) {
			printf("%d, ", mat[x][y]);
			count--;
		}
		startx++;
		starty++;
		offset++;
	}
	return 0;
}

int main() {
	vector<vector<int>> mat {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
	spiral_mat_2(mat, 3, 4);
}
