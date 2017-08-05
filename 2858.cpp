#include <algorithm>
#include <iostream>
using namespace std;

int main() {

	int R, B;

	cin >> R >> B;

	int tempR, tempB;

	int rows, cols;
	for (int i = 3; i <= 1450; i++) {
		for (int j = 3; j <= 1450; j++) {
			tempR = (i + j) * 2 - 4;
			tempB = i * j - tempR;
			if (tempR == R && tempB == B) {
				rows = i;
				cols = j;
				i += 2000;
			}
		}
	}
	
	cout << max(rows, cols) << " " << min(rows, cols);
}