#include <algorithm>
using namespace std;
int num;

int input[601];
int temp[201];
int dp[201];

int main() {

	scanf("%d", &num);

	int len = 0;
	dp[1] = 1;
	int pos = 1;

	for (int i = 1; i <= num; i++) {
		scanf("%d", &input[i]);
		auto pos = lower_bound(temp + 1, temp + len + 1, input[i]);
		*pos = input[i];
		dp[i] = distance(temp, pos);
		if (pos == temp + len + 1)
			len++;
	}
	printf("%d\n", num - len);
}