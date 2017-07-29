#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main() {

	string first, second;

	cin >> first >> second;
	
	int firstSize, secondSize;
	firstSize = first.length();
	secondSize = second.length();

	int lastMax = 0;
	for (int i = 1; i <= secondSize - firstSize + 1; i++) {
		int equal = 0; 
		for (int j = 1; j <= firstSize; j++) {
			if (first.at(j-1) == second.at(j+i-2)) {
				equal++;
			}
		}
		lastMax = max(lastMax, equal);
	}

	printf("%d", firstSize - lastMax);
}