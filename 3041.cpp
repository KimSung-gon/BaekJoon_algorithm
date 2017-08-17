#include <algorithm>

using namespace std;

int main() {

	char square[4][4] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O'};
	char input[4][4];

	for (int i = 0; i <= 3; i++) {
		char inputTmp;
		for (int j = 0; j <= 4; j++) {
			scanf("%c", &inputTmp);
			if (inputTmp == 10 || inputTmp == '.')
				continue;
			else
				input[i][j] = inputTmp;
		}
	}

	int result = 0;
	int index;

	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			if ((input[i][j] != square[i][j]) && (input[i][j] != -52)) {
				index = input[i][j] - 65;
				int quotient = index / 4;
				int remainder = index % 4;
				result += abs(quotient - i) + abs(remainder - j);
			}
		}
	}
	printf("%d", result);
}