#include <iostream>
#include <algorithm>	

using namespace std;
int main() {

	int a, b, c;
	cin >> a >> b >> c;

	int maxTemp = max(c - b, b - a);
	cout << maxTemp - 1;
}