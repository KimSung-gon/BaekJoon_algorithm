#include <algorithm>
int dpProcess(int num, int rest);
using namespace std;

int N[1001];
int P[10001];
int dp[1001];

int main() {

	int num;
	scanf("%d", &num);

	for (int i = 1; i <= num; i++)
		scanf("%d", &P[i]);

	dp[1] = P[1];
	printf("%d", dpProcess(num, num));
}

int dpProcess(int num, int rest) {

	if (rest == 0)
		return 0;
	if (dp[rest] != 0)
		return dp[rest];
	int temp;
	for (int i = 1; i <= rest; i++) {
		temp = max(dp[i] + dpProcess(num, rest - i), P[i]);
		if (temp > dp[rest])
			dp[rest] = temp;
	}
	return dp[rest];
}
