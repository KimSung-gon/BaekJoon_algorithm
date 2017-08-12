#include <algorithm>

using namespace std;

int input[501];
int sortInput[501];
int main() {

	int testCases;

	scanf("%d", &testCases);

	for (int i = 1; i <= testCases; i++) {

		int numOfInput;
		scanf("%d", &numOfInput);
		
		for (int j = 1; j <= numOfInput; j++)
			scanf("%d", &input[j]);

		int sum = 0;
		for (int j = 1; j <= numOfInput - 1; j++) {
			sort(input + 1, input + numOfInput + 1);
			sum += input[1] + input[2];
			input[1] += input[2];
			input[2] = 10000;
		}
		printf("%d\n", sum);
		memset(input + 1, 0, (numOfInput + 1) * 4);
	}
}