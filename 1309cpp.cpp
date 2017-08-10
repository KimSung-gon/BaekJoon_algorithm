#include <algorithm>

#define divide 9901;

using namespace std;

int dp[100001];

int main() {

	int num;
	scanf("%d", &num);
	dp[1] = 3;
	dp[2] = 7;

	for (int i = 3; i <= num; i++)
		dp[i] = (dp[i - 2] + dp[i - 1] * 2) % 9901;

	printf("%d", dp[num] % 9901);
}