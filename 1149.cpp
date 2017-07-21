#include <iostream>
#include <algorithm>
using namespace std;
int dp[3];

int main() {
	
	int dataCases;
	cin >> dataCases;

	int input;

	int redTemp, blueTemp, greenTemp;
	int red, blue, green;

	for (int i = 0; i < dataCases; i++) {
		cin >> red >> blue >> green;

		redTemp = dp[0];
		blueTemp = dp[1];
		greenTemp = dp[2];

		dp[0] = min(blueTemp, greenTemp) + red;
		dp[1] = min(redTemp, greenTemp) + blue;
		dp[2] = min(redTemp, blueTemp) + green;
	}
	cout << min(dp[0], min(dp[1], dp[2])) << endl;
}