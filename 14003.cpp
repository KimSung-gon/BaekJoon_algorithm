#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;

int input[1000001];
int dp[1000001];
int lb[1000001];

int lowerBound(int start, int end, int target);

int main() {
	ios_base::sync_with_stdio(false);

	int num;
	scanf("%d", &num);

	dp[1] = 1;
	int dpTemp;
	int maxDp = 1;

	stack<int> arr;
	int compare = 0;
	int len = 0;
	int pos = 1;

	for (int i = 1; i <= num; i++) {

		scanf("%d", &input[i]);

		/*int lenTemp = 1;
		if (compare < input[i]) {
			compare = input[i];
			len++;
			lb[len] = input[i];
			lenTemp = len;
		}
		else {
			pos = lowerBound(1, len, input[i]);
			lb[pos] = input[i];
		}*/
		auto pos = lower_bound(lb + 1, lb + len + 1, input[i]);
		*pos = input[i];
		//dp[i] = lenTemp;
		dp[i] = distance(lb, pos);
		if (pos == lb + len + 1)
			len++;
	}

	printf("%d\n", len);

	int k = len;
	for (int i = num; i > 0; i--) {
		if (dp[i] == k) {
			arr.push(input[i]);
			k--;
		}
	}
	while (!arr.empty()) {
		printf("%d ", arr.top());
		arr.pop();
	}
}

//int lowerBound(int start, int end, int target) {
//
//	int mid = (start + end) / 2;
//	
//	if (target == lb[mid])
//		return mid;
//	if ((start == end) || (start + 1 == end))
//		return start + 1;
//	if (target > lb[mid]) {
//		return lowerBound(mid, end, target);
//	}
//	else {
//		return lowerBound(start, mid, target);
//	}
//}