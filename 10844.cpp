#include <iostream>	
#include <algorithm>
#include <string.h>

using namespace std;

int dpProcess(int num, int depth);
int dp[101][10];
#define divide 1000000000

int main() {

	int depth;
	cin >> depth;

	int sum = 0;
	for (int i = 1; i < 10; i++) {
		sum += dpProcess(i, depth);
		memset(dp, 0, 4040);
	}
	cout << sum;
}

int dpProcess(int num, int depth) {
	
	if (depth == 1)
		return 1;
	
	if (num == 0)
		dp[num][depth] = dpProcess(num + 1, depth - 1);
	else if (num == 9)
		dp[num][depth] = dpProcess(num - 1, depth - 1);
	//else
	if (dp[num][depth] == 0)
		dp[num][depth] = dpProcess(num + 1, depth - 1) + dpProcess(num - 1, depth - 1);

	return dp[num][depth];
}