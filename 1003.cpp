#include <iostream>

using namespace std;

int fibonacci(int n);
int x, y;
int main() {
	
	int testCases;
	cin >> testCases;

	int *input = (int*)malloc(testCases * sizeof(int));
	for (int i = 0; i < testCases; i++) {
		cin >> input[i];
	}
	for (int i = 0; i < testCases; i++) {
		x = y = 0;
		fibonacci(input[i]);
		cout << x << " " << y << endl;
	}
}

int fibonacci(int n) {
	if (n == 0) {
		x++;
		return 0;
	}
	else if (n == 1) {
		y++;
		return 1;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}
