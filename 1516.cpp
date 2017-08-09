#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int num;
vector<int> buildings[501];
int dp[501];
int check[501];
int result[501];
int firstData[501];

int main() {

	scanf("%d", &num);

	int temp;
	for (int i = 1; i <= num; i++) {
		scanf("%d", &firstData[i]);
		while (scanf("%d", &temp) && temp != -1) {
			buildings[temp].push_back(i);
			check[i]++;
		}
	}
	queue<int> print;
	for (int i = 1; i <= num; i++) {
		if (check[i] == 0) {
			print.push(i);
			check[i] = -1;
		}
	}

	while(print.size() > 0) {

		int pIndex = print.front();
		print.pop();
		int data = firstData[pIndex];

		if(dp[pIndex] == 0)
			dp[pIndex] = data;

		while(buildings[pIndex].size() > 0) {
			int vIndex = buildings[pIndex].back();
			buildings[pIndex].pop_back();
			
			dp[vIndex] = max(dp[vIndex], dp[pIndex] + firstData[vIndex]);
			check[vIndex]--;
			if (check[vIndex] == 0) {
				print.push(vIndex);
				check[vIndex] = -1;
			}
		}
	}

	for (int i = 1; i <= num; i++)
		printf("%d\n", dp[i]);
}