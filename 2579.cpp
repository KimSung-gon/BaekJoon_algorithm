#include <iostream>
#include <algorithm>

using namespace std;

int dp[300];
int num[300];

int main() {

	int testCases;
	cin >> testCases;

	if (testCases < 4) {
		for (int i = 0; i < testCases; i++) {
			cin >> num[i];
		}
		cout << max((num[0] + num[2]), (num[1] + num[2]));
	}
	else {
		for (int i = 0; i < 3; i++) {
			cin >> num[i];
		}
		dp[1] = num[0];
		dp[2] = num[0] + num[1];
		dp[3] = max((num[0] + num[2]), (num[1] + num[2]));
		for (int i = 3; i < testCases; i++) {
			cin >> num[i];
			dp[i + 1] = max((num[i] + dp[i - 1]), (num[i] + num[i - 1] + dp[i - 2]));
		}
	}
	cout << dp[testCases];
}