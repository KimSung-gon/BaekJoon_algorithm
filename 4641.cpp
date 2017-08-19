#include <algorithm>

using namespace std;

int arr[16];

int main() {

	int temp;
	int i = 0;
	int cnt;
	while (scanf("%d", &temp)) {

		if (temp == -1)
			break;

		cnt = 0;
		if (temp == 0) {
			for (int j = 0; j < i; j++) {
				for (int k = 0; k < i; k++) {
					if (arr[j] * 2 == arr[k])
						cnt++;
				}
			}
			printf("%d\n", cnt);
			i = 0;
		}
		else {
			arr[i] = temp;
			i++;
		}
	}
}