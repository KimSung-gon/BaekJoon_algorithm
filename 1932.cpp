#include <iostream>
#include <algorithm>

using namespace std;

int dp[500];
int num[500];
int temp[500];

int main() {

	int testLine;
	cin >> testLine;

	int first;
	cin >> first;
	
	dp[0] = first;
	temp[0] = dp[0];

	for (int i = 1; i < testLine; i++) {
		for (int j = 0; j < i+1; j++) {
			cin >> num[j];

			temp[j] = dp[j];

			if (j == 0) {
				dp[j] = num[j] + temp[j];
			}
			else if (j == i) {
				dp[j] = num[j] + temp[j - 1];
			}
			else {
				dp[j] = num[j] + max(temp[j - 1], temp[j]);
			}
		}
	}
	sort(dp,dp + testLine);
	cout << dp[testLine-1];
}