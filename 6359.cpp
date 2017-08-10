#include <algorithm>
#include <string.h>
using namespace std;

int room[101];

int main() {

	int testCases;
	scanf("%d", &testCases);

	for (int i = 0; i < testCases; i++) {

		int num;
		scanf("%d", &num);

		for (int j = 1; j <= num; j++) {
			
			int k = 1;
			while (k * j <= num) {
				if (room[k * j] == 0)
					room[k * j] = 1;
				else
					room[k * j] = 0;
				k++;
			}
		}
		int sum = 0;
		for (int j = 1; j <= 100; j++)
			sum += room[j];
		printf("%d\n", sum);
		memset(room + 1, 0, 400);
	}
}