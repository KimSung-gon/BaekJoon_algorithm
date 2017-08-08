#include <iostream>
#include <algorithm>

using namespace std;

void findWay(int N, int curX, int curY);

unsigned long long dp[101][101];
int input[101][101];

int main() {

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> input[i][j];
		}
	}
	dp[1][1] = 1;
	
	//findWay(N, 1, 1);
	
	dp[1][1] = 1;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(dp[i][j]){
				if (i + input[i][j] <= N)	
					dp[i + input[i][j]][j] += dp[i][j];
				if (j + input[i][j] <= N) 
					dp[i][j + input[i][j]] += dp[i][j];
			}
		}
	}
	cout << dp[N][N];
}
/* Something wrong with lower bound
void findWay(int N, int curX, int curY) {

	if (input[curX][curY] == 0)
		return;
	if ((curX == N) && (curY == N))
		return;
	if ((curX > N) || (curY > N))
		return;

	if (curX + input[curX][curY] <= N) {
		dp[curX + input[curX][curY]][curY] += dp[curX][curY];
		findWay(N, curX + input[curX][curY], curY);
	}
	if (curY + input[curX][curY] <= N) {
		dp[curX][curY + input[curX][curY]] += dp[curX][curY];
		findWay(N, curX, curY + input[curX][curY]);
	}
}
*/
