#include <algorithm>
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

void dfs(int cur, int cnt, int sum);
int W[16][16];
int check[16];
int num;
int minCost;
int first;

int main() {
	
	cin >> num;

	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			cin >> W[i][j];
	
	minCost = 100000;
	for (int i = 0; i < num; i++) {
		first = i;
		dfs(i, 0, 0);
	}
	printf("%d", minCost);
}

void dfs(int cur, int cnt, int sum) {
	
	if (cnt == 3) {
		minCost = min(minCost, sum + W[cur][first]);
		return;
	}
	check[cur] = 1;

	for (int i = 0; i < num; i++) {
		if (check[i] != 1) {
			dfs(i, cnt + 1, sum + W[cur][i]);
			check[i] = 0;
		}
	}
}