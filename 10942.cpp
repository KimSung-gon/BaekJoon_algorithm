#include <iostream>
#include <algorithm>

using namespace std;

int input[2001];
int dp[2001][2][2];
//	dp[(end+start/2) : �߽���ǥ][0:�߽����κ��ͰŸ�, 1:����][Ȧ¦]

int palindrome(int start, int end);

int main() {

	int numOfInput;
	cin >> numOfInput;

	for (int i = 1; i <= numOfInput; i++)
		cin >> input[i];

	int request;
	scanf("%d", &request);

	int start, end;
	for (int i = 1; i <= request; i++) {
		scanf("%d %d", &start, &end);

		printf("%d\n", palindrome(start, end));
	}
}

int palindrome(int start, int end) {

	if (start >= end)
		return 1;
	if (start + 1 == end)
		if (input[start] == input[end])
			return 1;
		else
			return 0;

	int distance = end - start;
	int sniffing = distance % 2;
	int midTemp = (end + start) / 2;
	
	if (dp[midTemp][1][sniffing] == 1) { // ���� dp�� �߽���ǥ�� ������ ���
		int recordedDistance = dp[midTemp][0][sniffing];
		if (distance > recordedDistance) {	// �߽ɺ����ǰŸ��� �����Ÿ����� ũ�� ��˻�
			for (int i = midTemp - distance / 2; i < midTemp - distance / 2 + (distance - recordedDistance) / 2; i++)
				if (input[i] != input[end - i + midTemp - distance / 2]) {
					dp[midTemp][1][sniffing] = -1;
					return 0;
				}
			dp[midTemp][0][sniffing] = distance;
		}
		return 1;
	}
	else if (dp[midTemp][1][sniffing] == -1) {			// ���� dp�� �߽���ǥ�� ������ ���
		int recordedDistance = dp[midTemp][0][sniffing];

		if (distance < recordedDistance) {				// �߽ɺ����ǰŸ��� �����Ÿ����� ������ ��˻�
			for (int i = start; i < start + distance / 2; i++) {
				if (input[i] != input[end - i + start]) {
					dp[midTemp][0][sniffing] = distance;
					return 0;
				}
			}
			dp[midTemp][0][sniffing] = distance;
			dp[midTemp][1][sniffing] = 1;
		}
		return 0;
	}
	else {											   	// ���� dp�� ���� ��
		for (int i = start; i < start + distance / 2; i++) {
			if (input[i] != input[end - i + start]) {
				dp[midTemp][1][sniffing] = -1;
				return 0;
			}
		}
		dp[midTemp][0][sniffing] = distance;
		dp[midTemp][1][sniffing] = 1;
		return 1;
	}
}

//#include <cstdio>
//
//int N, M;
//int data[2001];
//
//int isPalin(int a, int b)
//{
//	if (a >= b)
//		return 1;
//	if (data[a] == data[b])
//		return isPalin(a + 1, b - 1);
//	else
//		return 0;
//}
//
//int main(void)
//{
//	scanf("%d", &N);
//	for (int i = 1; i <= N; i++)
//		scanf("%d", &data[i]);
//	scanf("%d", &M);
//	for (int i = 0; i < M; i++)
//	{
//		int a, b;
//		scanf("%d%d", &a, &b);
//		printf("%d\n", isPalin(a, b));
//	}
//}