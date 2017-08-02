#include <algorithm>
#include <stack>
using namespace std;

int input[1001];
int dp[1001];

int main() {

	int num;
	scanf("%d", &num);

	dp[1] = 1;
	int dpTemp;
	int maxDp = 1;

	stack<int> arr;
	for (int i = 1; i <= num; i++) {

		scanf("%d", &input[i]);
		dpTemp = 0;

		for (int k = 1; k < i; k++) {
			if(input[i] > input[k])
				dpTemp = max(dpTemp, dp[k]);
		}
		dp[i] = dpTemp + 1;
		maxDp = max(dp[i], maxDp);
	}

	printf("%d\n", maxDp);

	int k = maxDp;
	for (int i = num; i > 0; i--) {
		if (dp[i] == k) {
			arr.push(input[i]);
			k--;
		}
	}
	while (!arr.empty()) {
		printf("%d ", arr.top());
		arr.pop();
	}
}