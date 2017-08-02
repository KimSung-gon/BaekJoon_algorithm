#include <algorithm>
using namespace std;

int main() {

	int data;
	scanf("%d", &data);

	int arr[] = { 64,32,16,8,4,2,1 };

	int result = 0;
	for (int i = 0; i < 7; i++) {
		if (data >= arr[i]) {
			data -= arr[i];
			result++;
		}
	}
	printf("%d", result);
}