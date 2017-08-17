#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int dp[1001][1001];

int main() {

	string first, second;

	cin >> first >> second;
	
	for (int i = 0; i < first.length(); i++) {
		for (int j = 0; j < second.length(); j++) {
			if (first[i] == second[j])
				dp[i + 1][j + 1] = dp[i][j] + 1;
			else
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
		}
	}

	printf("%d", dp[first.length()][second.length()]);
}