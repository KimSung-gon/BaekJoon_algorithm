#include <algorithm>
using namespace std;

void dfs(int loc, int cnt);

int k;
int num[13];
int numTemp[7];

int main() {

	while (1) {
		scanf("%d", &k);

		if (k == 0)
			break;

		for (int j = 1; j <= k; j++)
			scanf("%d", &num[j]);

		dfs(1, 1);
		printf("\n");
	}
}

void dfs(int loc, int cnt) {

	if (cnt == 7) {
		for (int i = 1; i <= 6; i++)
			printf("%d ", numTemp[i]);
		printf("\n");
		return;
	}
	
	for (int i = loc; i <= k; i++) {
		numTemp[cnt] = num[i];
		dfs(i + 1, cnt + 1);
	}
}