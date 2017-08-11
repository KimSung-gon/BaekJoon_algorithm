#include <algorithm>

using namespace std;

long long int num;
long long int dp[91];

int main() {

	scanf("%d", &num);
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= num; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	printf("%lld", dp[num]);
}