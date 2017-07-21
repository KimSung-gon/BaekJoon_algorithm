#include <iostream>
#include <algorithm>
void dpProcess(int numOfType, int target);
using namespace std;

int coins[10001];
int dp[10001];

int main() {

	int numOfType, target;
	cin >> numOfType >> target;

	for (int i = 1; i <= numOfType; i++) 
		cin >> coins[i];
	dp[0] = 1;
	
	dpProcess(numOfType, target);
	cout << dp[target] << endl;
}

void dpProcess(int numOfType, int target) {
	for (int i = 1; i <= numOfType; i++) {
		for (int j = coins[i]; j <= target; j++) {
			dp[j] += dp[j - coins[i]];
		}
	}
}