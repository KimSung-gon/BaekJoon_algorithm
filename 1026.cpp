#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>

using namespace std;

int main() {

	int num;
	cin >> num;

	vector<int> A, B;
	int temp;
	for (int i = 0; i < num; i++) {
		cin >> temp;
		A.push_back(temp);
	}
	for (int i = 0; i < num; i++) {
		cin >> temp;
		B.push_back(temp);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());

	int sum = 0;
	for (int i = 0; i < num; i++) {
		sum += A.back() * B.back();
		A.pop_back();
		B.pop_back();
	}
	printf("%d", sum);
}