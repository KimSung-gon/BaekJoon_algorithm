#include <iostream>	
#include <algorithm>
#include <string.h>

using namespace std;

//int dpProcess(int num, int depth);
int dp[101][10];
#define divide 1000000000

int main() {

	int depth;
	cin >> depth;

	int sum = 0;
	//for (int i = 1; i < 10; i++) {
		//sum += dpProcess(i, depth);
		//memset(dp, 0, 4040);
	//}

	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= depth; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0)
				dp[i][0] = dp[i - 1][1] % divide;
			else if (j == 9)
				dp[i][9] = dp[i - 1][8] % divide;
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % divide;
		}
	}
	for (int i = 1; i < 10; i++)
		sum = (sum + dp[depth][i]) % divide;
	printf("%d\n", sum % divide);
}

//int dpProcess(int num, int depth) {
//	
//	if (depth == 1)
//		return 1;
//	
//	if (num == 0)
//		dp[num][depth] = dpProcess(num + 1, depth - 1);
//	else if (num == 9)
//		dp[num][depth] = dpProcess(num - 1, depth - 1);
//	else
//		dp[num][depth] = dpProcess(num + 1, depth - 1) + dpProcess(num - 1, depth - 1);
//
//	return dp[num][depth];
//}