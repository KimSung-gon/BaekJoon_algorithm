#include <algorithm>

using namespace std;
long long numOfEachRoom[1000001];
long long numOfRoom;

int main() {

	scanf("%d", &numOfRoom);

	for (int i = 1; i <= numOfRoom; i++)
		scanf("%lld", &numOfEachRoom[i]);

	long long mDirector, sDirector;
	
	scanf("%lld %lld", &mDirector, &sDirector);

	long long minDirector = 0;

	for (int i = 1; i <= numOfRoom; i++) {
		numOfEachRoom[i] -= mDirector;
		minDirector++;
		if (numOfEachRoom[i] > 0) {
			long long int temp = numOfEachRoom[i] / sDirector;
			numOfEachRoom[i] -= sDirector * temp;
			minDirector += temp;
		}
		
		if (numOfEachRoom[i] > 0)
			minDirector++;
	}

	printf("%lld", minDirector);
}
