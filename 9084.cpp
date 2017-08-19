#include <algorithm>
#include <string.h>

using namespace std;
int numOfCoins;
int coins[21];
int dp[10001];
//void dfs(int target);
int cnt;

int main() {

	int numOfCases;
	scanf("%d", &numOfCases);

	for (int i = 1; i <= numOfCases; i++) {

		scanf("%d", &numOfCoins);

		for (int j = 1; j <= numOfCoins; j++) 
			scanf("%d", &coins[j]);
		int target;
		scanf("%d", &target);
		cnt = 0;
		//dfs(target);

		for (int i = 1; i <= target; i++) {
			for (int j = 1; j <= numOfCoins; j++) {
				if (i == coins[j]) {
					dp[i] += dp[i - coins[j]];
				}
			}
		}
		memset(dp, 0, sizeof(int) * 10001);
		printf("%d", dp[target]);
	}
}

//void dfs(int target) {
//
//	if (target == 0) {
//		cnt++;
//		return;
//	}
//
//	for (int i = 1; i <= numOfCoins; i++) {
//		if (target >= coins[i])
//			dpProcess(target-coins[i]); 
//		else
//			return;
//	}
//}