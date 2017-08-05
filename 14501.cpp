#include <algorithm>
#include <iostream>
using namespace std;

int dpProcess(int loc, int rest);
int num;
pair<int, int> input[16];
int dp[16];

int main() {

	scanf("%d", &num);
	for (int i = 1; i <= num; i++) 
		scanf("%d %d", &input[i].first, &input[i].second);

	dp[0] = 0;
	dp[1] = 0;
	cout << dpProcess(num, num);
}

int dpProcess(int loc, int rest) {

	if (input[loc].first > rest)
		return 0;
	int temp;
	int lastLoc;
	for (int i = 1; i <= num; i++) {
		rest = input[loc + i].first;
		temp = max(dp[i], dpProcess(loc + i, rest) + input[loc + i].second);
		if (dp[loc + i] < temp) {
			dp[loc + i] = temp;
			lastLoc = loc + i;
		}
	}
	return dp[lastLoc];
}