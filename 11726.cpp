#include <algorithm>
#define division 10007

using namespace std;
int go(int k);

int d[1001];

int main() {

	int n;
	scanf("%d", &n);

	printf("%d", go(n));
}

int go(int k) {
	
	if ((k == 0) || (k == 1))
		return 1;
	
	if (d[k] == 0) 
		d[k] = go(k - 2) + go(k - 1);
	
	return d[k]%division;
}