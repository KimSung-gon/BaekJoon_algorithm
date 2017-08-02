#include <algorithm>

using namespace std;

int A[1001];
int dp[1001];

int targetNum;

int main() {

	scanf("%d", &targetNum);
	for (int i = 1; i <= targetNum; i++) 
		scanf("%d", &A[i]);

	dp[1] = 0;

	for (int i = 1; i <= targetNum; i++) {
		for (int j = 1; j <= A[i]; j++) {
			if (dp[i] == 0 && i != 1)
				dp[i] = -1;
			if (dp[i + j] != 0)
				dp[i + j] = min(dp[i] + 1, dp[i + j]);
			else
				dp[i+ j] = dp[i] + 1;
		}
	}
	
	if (dp[targetNum] == 0) {
		printf("-1");
		return 0;
	}

	printf("%d", dp[targetNum]);
}
