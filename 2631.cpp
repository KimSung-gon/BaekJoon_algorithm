#include <algorithm>
using namespace std;
int num;

int lowerBound(int start, int last, int target);

int input[601];
int temp[201];
int dp[201];

int main() {

	scanf("%d", &num);

	int len = 0;
	int pos = 0;

	for (int i = 1; i <= num; i++) {
		scanf("%d", &input[i]);
		pos = lowerBound(1, len + 1, input[i]);
		
		dp[i] = pos;
		temp[pos] = input[i];
		if (pos == len + 1)
			len++;
	}
	printf("%d\n", num - len);
}

int lowerBound(int start, int last, int target) {

	int midTemp = start;
	int mid = (start + last) / 2;

	if (start == last)
		return start;

	if (target == temp[mid])
		return mid;

	if (target > temp[mid])
		lowerBound(mid + 1, last, target);
	else if (target < temp[mid])
		lowerBound(start, mid, target);

}