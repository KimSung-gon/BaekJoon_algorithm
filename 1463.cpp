#include <iostream>
#include <algorithm>

using namespace std;
int dpProcess(int);

int d[1000000];

int main() {

	int num;
	cin >> num;
	
	cout << dpProcess(num);
}

int dpProcess(int n) {

	if (n == 1)
		return 0;
	if (d[n] > 0)
		return d[n];
	d[n] = dpProcess(n - 1) + 1;
	if (n % 2 == 0) {
		int temp = dpProcess(n / 2) + 1;
		if (d[n] > temp)
			d[n] = temp;
	}
	if (n % 3 == 0) {
		int temp = dpProcess(n / 3) + 1;
		if (d[n] > temp)
			d[n] = temp;
	}
	return d[n];
}