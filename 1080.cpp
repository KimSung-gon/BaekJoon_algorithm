#include <algorithm>

using namespace std;

int arr[51][51][3];

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (k != 2) 
					scanf("%1d", &arr[i][j][k]);
				else if (k == 2) {
					if (arr[i][j][0] != arr[i][j][1])
						arr[i][j][2] = 1;
				}
			}
		}
	}

	int result = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (arr[i][j][2] == 1) {
				result++;
				for (int k = i; k < i + 3; k++) {
					for (int l = j; l < j + 3; l++) {
						if (arr[k][l][2] == 1)
							arr[k][l][2] = 0;
						else
							arr[k][l][2] = 1;
					}
				}
			}
		}
	}
	int numOfSame = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j][2] == 0)
				numOfSame++;
		}
	}

	if (numOfSame == (n * m))
		printf("%d", result);
	else
		printf("-1");
}