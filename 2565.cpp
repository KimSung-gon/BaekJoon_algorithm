#include <algorithm>
using namespace std;

int lowerBound(int start, int last, int target);

pair<int, int> lines[100001];
int first[100001];
int second[100001];

int main() {

	int num;
	scanf("%d", &num);

	int len = 0;
	int posTemp = 0;
	int pos = 0;
	for (int i = 1; i <= num; i++) 
		scanf("%d %d", &lines[i].first, &lines[i].second);
	
	sort(lines + 1, lines + num + 1);

	for (int i = 1; i <= num; i++) {
		
		pos = lowerBound(1, len + 1, lines[i].second);
		if (pos <= len) 
			second[i] = i - 1;
		
		first[pos] = lines[i].second;
		if (pos == len + 1)
			len++;
	}
	printf("%d\n", num - len);
	/*sort(second + 1, second + num + 1);
	for (int i = 1; i <= num; i++)
		if(second[i] != 0)
			printf("%d\n", lines[second[i]].first);*/
}

int lowerBound(int start, int last, int target) {

	int midTemp = start;
	int mid = (start + last) / 2;

	if (start == last)
		return start;

	if (target == first[mid])
		return mid;

	if (target > first[mid])
		lowerBound(mid + 1, last, target);
	else if (target < first[mid])
		lowerBound(start, mid, target);

}