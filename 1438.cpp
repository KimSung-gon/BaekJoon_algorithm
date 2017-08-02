#include <algorithm>

using namespace std;
void findOverHalf();

int XY[100][2];
int num;
int overHalf[1001][1001];

int main() {

	scanf("%d", &num);

	for (int i = 1; i <= num; i++) 
		scanf("%d %d", &XY[i][0], &XY[i][1]);

	findOverHalf();

	int min = 100000000;
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			if ((overHalf[i][j] < min) && (overHalf[i][j] != 0))
				min = overHalf[i][j];
			printf("i:%d j:%d data:%d\n", i, j, overHalf[i][j]);
		}
	}
	if (num == 2) {
		printf("4");
		return 0;
	}
	printf("%d", min);
}

void findOverHalf() {
	
	int half = num/2;
	int numOfSpot;

	int minTemp = 100000000;
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			minTemp = 100000000;
			numOfSpot = 0;
			if (i == j)
				continue;
			for (int k = 1; k <= num; k++) {
				if ((k == j) || (k == i))
					continue;
				if (((XY[i][0] <= XY[k][0]) && (XY[k][0] <= XY[j][0]) && (XY[i][1] <= XY[k][1]) && (XY[k][1] <= XY[j][1])) ||
					((XY[i][0] >= XY[k][0]) && (XY[k][0] >= XY[j][0]) && (XY[i][1] >= XY[k][1]) && (XY[k][1] >= XY[j][1])) ||
					((XY[i][0] >= XY[k][0]) && (XY[k][0] >= XY[j][0]) && (XY[i][1] <= XY[k][1]) && (XY[k][1] <= XY[j][1])) ||
					((XY[i][0] <= XY[k][0]) && (XY[k][0] <= XY[j][0]) && (XY[i][1] >= XY[k][1]) && (XY[k][1] >= XY[j][1]))){
					numOfSpot++;
					if (numOfSpot + 2 >= half) {
						minTemp = min( ( abs(XY[j][0] - XY[i][0]) + 2) * (abs(XY[j][1] - XY[i][1]) + 2) , minTemp);
						overHalf[i][j] = minTemp;
					}
				}
			}
		}
	}
}