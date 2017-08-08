#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> vt[1001];
int check[1001];
int result[1001];

int main() {

	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		
		int numOfInput;
		scanf("%d", &numOfInput);

		int data, prevData;

		scanf("%d", &prevData);
		for (int j = 1; j <= numOfInput - 1; j++) {

			scanf("%d", &data);
			
			vt[prevData].push_back(data);
			prevData = data;
			check[data]++;
		}
	}
	
	queue<int> print;
	for (int i = 1; i <= n; i++)
		if (check[i] == 0)
			print.push(i);

	for (int i = 1; i <= n; i++) {

		if (print.empty()) {
			printf("0");
			return 0;
		}

		int data = print.front();
		print.pop();

		result[i] = data;
		int sizeOfVector = vt[data].size();
		for (int j = 1; j <= sizeOfVector; j++) {
			int next = vt[data].back();
			vt[data].pop_back();
			if (--check[next] == 0)
				print.push(next);
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d\n", result[i]);
	/*int countN = n;
	queue<int> print;
	while (countN > 0) {
		for (int i = 1; i <= n; i++) {
			if (check[i] == 0) {
				int size = vt[i].size();
				for (int j = 1; j <= size; j++) {
					int disconnect = vt[i].back();
					vt[i].pop_back();
					check[disconnect]--;
					if (check[disconnect] == -2) {
						printf("-1");
						return 0;
					}
				}
				print.push(i);
				countN--;
				check[i]--;
				if (check[i] == -2) {
					printf("-1");
					return 0;
				}
			}
		}
	}*/
	/*int queueSize = print.size();
	for (int i = 0; i < queueSize; i++) {
		printf("%d\n", print.front());
		print.pop();
	}*/
}