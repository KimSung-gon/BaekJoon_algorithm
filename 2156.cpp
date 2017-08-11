#include <algorithm>

using namespace std;

int num;
int input[10001];
int dp[10001];
//void dfs(int cnt, int last, int sum);
//int lastSum;

int main() {
	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		scanf("%d", &input[i]);
	}

	dp[1] = input[1];
	dp[2] = input[1] + input[2];
	for (int i = 3; i <= num; i++) {
		dp[i] = max(max(dp[i - 1], dp[i - 2] + input[i]), dp[i - 3] + input[i - 1] + input[i]);
	}

	int ans = 0;
	for (int i = 1; i <= num; i++) {
		ans = max(ans, dp[i]);
	}

	printf("%d\n", ans);
	return 0;
}

// backtracking timeover

//int main() {
//
//	scanf("%d", &num);
//	
//
//	scanf("%d", &input[1]);
//	dp[1] = input[1];
//
//	scanf("%d", &input[2]);
//	dp[2] = input[1] + input[2];
//
//	for (int i = 3; i <= num; i++) 
//		scanf("%d", &input[i]);
//
//	dfs(1, 1, input[1]);
//	printf("%d", lastSum);
//}
//
//void dfs(int cnt, int last, int sum) {
//	
//	if (last >= num) {
//		if (lastSum < sum)
//			lastSum = sum;
//		return;
//	}
//
//	for (int i = last; i <= num; i++) {
//		if (i > last + 3)
//			return;
//		if (cnt == 2) {
//			dfs(cnt - 1, i + 2, sum + input[i + 2]);
//		}
//		else {
//			dfs(cnt + 1, i + 1, sum + input[i + 1]);
//		}
//	}
//}