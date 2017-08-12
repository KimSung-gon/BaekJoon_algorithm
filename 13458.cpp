#include <algorithm>

using namespace std;
int numOfEachRoom[1000001];
int main() {

	int numOfRoom;
	scanf("%d", &numOfRoom);

	for (int i = 1; i <= numOfRoom; i++)
		scanf("%d", &numOfEachRoom[i]);
	
	int mDirector, sDirector;
	scanf("%d %d", &mDirector, &sDirector);
	
	int minDirector = 0;
	//if (mDirector > sDirector) {
		
		for (int i = 1; i <= numOfRoom; i++) {
			numOfEachRoom[i] -= mDirector;
			minDirector++;
		}
		for (int i = 1; i <= numOfRoom; i++) {
			while (numOfEachRoom[i] > sDirector) {
				int temp = numOfEachRoom[i] / sDirector;
				numOfEachRoom[i] -= sDirector * temp;
				minDirector += temp;
			}
			if (numOfEachRoom[i] != 0)
				minDirector++;
		}
	//}
	/*else {
		for (int i = 1; i <= numOfRoom; i++) {
			while (numOfEachRoom[i] > sDirector) {
				int temp = numOfEachRoom[i] / sDirector;
				numOfEachRoom[i] -= sDirector * temp;
				minDirector+=temp;
			}
			if (numOfEachRoom[i] != 0)
				minDirector++;
		}
	}*/
	printf("%d", minDirector);
}