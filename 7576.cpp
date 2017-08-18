#include <algorithm>
#include <queue>

using namespace std;

queue<pair<int, int>> q;
int input[1001][1001];
int N, M;

void bfs();
int cnt;
int main() {

	scanf("%d %d", &N, &M);

	int temp;
	pair<int, int> pairTmp;

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &temp);
			input[i][j] = temp;
			if (temp == 1) {
				pairTmp = make_pair(i, j);
				q.push(pairTmp);
			}
		}
	}
	cnt = -1;
	bfs();
	for (int i = 1; i <= M; i++) 
		for (int j = 1; j <= N; j++) 
			if (input[i][j] == 0) {
				printf("-1");
				return 0;
			}
	printf("%d", cnt);
	return 0;
}

void bfs() {

	if (q.size() == 0)
		return;

	pair<int, int> tmp = q.front();
	int y = tmp.first;
	int x = tmp.second;
	input[y][x] = 1;

	while (!q.empty()) {
		pair<int, int> pushTmp;
		int size = q.size();
		
		for (int i = 0; i < size; i++) {
			tmp = q.front();
			y = tmp.first;
			x = tmp.second;
			q.pop();
			if ((x == 1) && (input[y][x + 1] == 0)) {
				pushTmp = make_pair(y, x + 1);
				input[y][x + 1] = 1;
				q.push(pushTmp);
			} 
			else if ((x == N) && (input[y][x - 1] == 0)) {
				pushTmp = make_pair(y, x - 1);
				input[y][x - 1] = 1;
				q.push(pushTmp);
			}
			else if((x != 1) && (x != N)) {
				if (input[y][x + 1] == 0) {
					pushTmp = make_pair(y, x + 1);
					input[y][x + 1] = 1;
					q.push(pushTmp);
				}
				if (input[y][x - 1] == 0) {
					pushTmp = make_pair(y, x - 1);
					input[y][x - 1] = 1;
					q.push(pushTmp);
				}
			}
			if ((y == 1) && (input[y + 1][x] == 0)) {
				pushTmp = make_pair(y + 1, x);
				input[y + 1][x] = 1;
				q.push(pushTmp);
			}
			else if ((y == M) && (input[y - 1][x] == 0)) {
				pushTmp = make_pair(y - 1, x);
				input[y - 1][x] = 1;
				q.push(pushTmp);
			}
			else if ((y != 1) && (y != M)) {
				if (input[y + 1][x] == 0) {
					pushTmp = make_pair(y + 1, x);
					input[y + 1][x] = 1;
					q.push(pushTmp);
				}
				if (input[y - 1][x] == 0) {
					pushTmp = make_pair(y - 1, x);
					input[y - 1][x] = 1;
					q.push(pushTmp);
				}
			}
		}
		cnt++;
	}
}