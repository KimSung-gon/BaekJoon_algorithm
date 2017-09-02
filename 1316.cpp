#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

int checkAlpha[150];
char word[100];
int num;

int main() {

	cin >> num;
	
	int count = 0;
	int check;

	for (int i = 0; i < num; i++) {

		check = 1;
		cin >> word;

		int j = 0;
		char temp = 'A';

		while (word[j] != NULL) {
			if (temp != word[j]) {
				if (checkAlpha[(int)word[j]] == 1) {
					check = 0;
					break;
				}
				checkAlpha[(int)word[j]] = 1;
			}
			temp = word[j];
			j++;
		}
		memset(word, 0, sizeof(char) * 100);
		memset(checkAlpha, 0, sizeof(int) * 150);
		if (check == 1)
			count++;
	}
	printf("%d", count);
	return 0;
}