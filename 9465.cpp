#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

int num;
int input[100001][2];
int dp[100001][2];
int d[100001];

int main() {

	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		int numOfData;
		scanf("%d", &numOfData);
		for (int k = 0; k <= 1; k++) {
			for (int j = 1; j <= numOfData; j++) {
				scanf("%d", &input[j][k]);
			}
		}
		dp[1][0] = input[1][0];
		dp[1][1] = input[1][1];
		d[1] = max(dp[1][0], dp[1][1]);
		dp[2][0] = dp[1][1] + input[2][0];
		dp[2][1] = dp[1][0] + input[2][1];
		d[2] = max(dp[2][0], dp[2][1]);

		for (int j = 3; j <= numOfData; j++) {
			int temp1, temp2;
			for (int k = 0; k <= 1; k++) {
				if (k == 0) {
					temp1 = max(dp[j - 2][1] + input[j][0], dp[j - 2][0] + input[j - 1][1] + input[j][0]);
					temp2 = dp[j - 1][1] + input[j][0];
					dp[j][0] = max(temp1, temp2);
				}
				else {
					temp1 = max(dp[j - 2][0] + input[j][1], dp[j - 2][1] + input[j - 1][0] + input[j][1]);
					temp2 = dp[j - 1][0] + input[j][1];
					dp[j][1] = max(temp1, temp2);
				}
			}
			d[j] = max(dp[j][0], dp[j][1]);
		}
		cout << d[numOfData] << endl;
		memset(input, 0, 200002);
		memset(dp, 0, 200002);
		memset(d, 0, 100001);
	}
}