#include <algorithm>	

using namespace std;

int num;

int main() {

	scanf("%d", &num);

	int i = 1;
	int sum = 0;
	while (sum < num) {
		sum = (i * (i + 1) / 2);
		i++;
	}

	int index = i - 2;
	int odd = index % 2;
	int rest = num - (index + 1) * index / 2;

	if (odd == 0) {
		int start = index + 1;
		for(int j = rest - 1; j > 0; j--) {
			start--;
		}
		printf("%d/%d", start, index+2-start);
	}
	else {
		int start = index + 1;
		for (int j = rest - 1; j > 0; j--) {
			start--;
		}
		printf("%d/%d", index + 2 - start, start);
	}
}