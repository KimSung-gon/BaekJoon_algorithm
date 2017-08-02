#include <algorithm>

using namespace std;

void dfs(int loc, int cnt);

int numOfPrint;
int numOfInput;
char input[16];
char printTemp[16];
char leastArr[] = { 'a','e','i','o','u' };

int main() {

	scanf("%d", &numOfPrint);
	scanf("%d\n", &numOfInput);
	int i;
	for (i = 1; i <= numOfInput - 1; i++)
		scanf("%c ", &input[i]);
	scanf("%c", &input[i]);
	sort(input + 1, input + numOfInput + 1);
	dfs(1, 1);
}
 
void dfs(int loc, int cnt) {

	if (cnt == numOfPrint + 1) {
		int least1 = 0;
		for (int i = 0; i < sizeof(leastArr) / sizeof(char); i++) {
			for (int j = 1; j <= numOfInput; j++)
				if (leastArr[i] == printTemp[j])
					least1++;
		}
		if ((least1 >= 1) && (numOfPrint-least1 >= 2)) {
			for (int i = 1; i <= numOfPrint; i++)
				if (printTemp[i] != 0)
					printf("%c", printTemp[i]);
			printf("\n");
		}
	}
	for (int i = loc; i <= numOfInput; i++) {
		printTemp[cnt] = input[i];
		dfs(i + 1, cnt + 1);
	}
}