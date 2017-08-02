#include <algorithm>

using namespace std;

int input[10001];

int main() {

	int n;
	scanf("%d", &n);

	int temp;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &temp);
		input[temp]++;
	}

	for (int i = 1; i <= 10000; i++)
		if (input[i] != 0)
			for (int j = 0; j < input[i]; j++) 
				printf("%d\n", i);
}