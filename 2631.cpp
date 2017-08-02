#include <algorithm>

using namespace std;
int num;

int input[201];
int temp[201];
int dp[201];

int main() {

	scanf("%d", &num);
	
	int len = 0;

	for (int i = 1; i <= num; i++) {
		scanf("%d", &input[i]);
		
		int start = 0;
		int end = len + 1;
		int mid;

		while (start < end) {
			mid = (start + end) / 2;
			if (input[i] > dp[mid])
				start = mid + 1;
			else
				end = mid;
		}

		if (len < end)
			len = end;
		dp[end] = input[i];
	}
	printf("%d\n", num - len);
}