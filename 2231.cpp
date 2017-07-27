#include <algorithm>

using namespace std;

int main() {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp = i;
		int sum = temp;
		while (temp > 0) {
			sum += temp % 10;
			temp /= 10;
		}
		if (sum == n) {
			printf("%d", i);
			return 0;
		}
	}
	printf("0");
}