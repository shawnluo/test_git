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

	for(j = 0;j <n;j++)
	{
		dp[0][j] = 1;
	}

	for(i = 0;i < m;i++)
	{
		dp[i][0] = 1;
	}
	for(i = 0;i < m;i++)
	{
		for(j = 0;j < n;j++)
		{
			if((i != 0) || (j != 0))
			{
				dp[i][j] = dp[i-1][j] + d[i][j-1];
			}

		}
	}
	
	printf("/n ============print out result==================\n");

	for(i = 0;i < m;i++)
	{
		printf("\n")
		for(j = 0;j < n;j++)
		{
			printf("%d",dp[i][j]);
		}
	}
	printf("\b ==========END====================");

}


int main(void)
{
	int m =3;
	int n =3;

	robot_game(m,n);

	return 0;

}
