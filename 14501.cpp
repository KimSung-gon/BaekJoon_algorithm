#include <algorithm>
#include <iostream>
using namespace std;

int num;
pair<int, int> input[16];
int dp[16];

int main() {

	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
		scanf("%d %d", &input[i].first, &input[i].second);
		
	int temp = 0;
	for (int i = 1; i <= num; i++) {
		dp[i + input[i].first] = max(dp[i + input[i].first], dp[i] + input[i].second);
		temp = dp[i + input[i].first];
		for (int j = i + input[i].first; j <= num + 1; j++) {
			if(dp[j] < temp)
				dp[j] = temp;
		}
	}
	cout << dp[num + 1] << endl;
}