#include "test.hpp"
//#if 0
//vector<vector<int>> res;
//vector<int> path;
//void BT_2(int n, int k, int pos) {
//	if(path.size() == k) {
//		res.push_back(path);
//		return;
//	}

//	for(int i = pos; i <= n; i++) {
//		path.push_back(i);
//		BT_2(n, k, i + 1);
//		path.pop_back();
//	}
//}

//int main(void) {
//	BT_2(4, 2, 1);

//	for(auto it : res) {
//		for(auto it_ : it) {
			// cout << it_ << " ";
//		}
		// cout << endl;
//	}

//	for(int i = 0; i < res.size(); i++) {
//		for(int j = 0; j < res[0].size(); j++) {
//			cout << res[i][j] << " ";
//		}
//		cout << endl;
//	}
//
//	return 0;
//}
//#endif


void robot_game(int m,int n)
{
	int i = 0;
	int j = 0;
	int dp[m][n] = {0};

#include <iostream>
#include <cstdlib>



int main() {
	// int x = 5;
	int left = (1 << 4) - 1;
	int right = (1 << 2) - 1;

	printf("0x%x\n", left);
	printf("0x%x\n", right);
	printf("0x%x\n", left - right);

	return 0;

}
