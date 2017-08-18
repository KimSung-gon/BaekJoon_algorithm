#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

vector<int> graph[100001];

queue<int> level;
int vectorSort[100001];
int check[100001];
void dfs(int root);
void bfs(int root);

int start;

int numOfVertex;
int numOfLine;

int main() {

	scanf("%d %d %d", &numOfVertex, &numOfLine, &start);

	int from, to;
	for (int i = 1; i <= numOfLine; i++) {
		scanf("%d %d", &from, &to);
		graph[from].push_back(to);
		graph[to].push_back(from);
		vectorSort[i] = from;								// �ڽĳ�带 ���� �����Է�
	}

	for (int i = 1; i <= numOfLine; i++)					// �� ���� ����(numOfLine�� �׷��� ũ���ʴٰ� �����Ͽ� �ߺ�üũ ����)
		sort(graph[vectorSort[i]].begin(), graph[vectorSort[i]].end());

	dfs(start);
	printf("\n");

	memset(check, 0, sizeof(int) * 1001);
	bfs(start);

	return 0;
}

void bfs(int root) {				// level�̶�� ť�� graph[level.front()] ������ �������� �ְ� ���� �ݺ�
	
	level.push(root);
	
	while (!level.empty()) {

		int tmp = level.front();

		if (check[tmp] == 0) {		// �湮üũ

			printf("%d ", tmp);
			check[tmp] = 1;

			for (int i = 0; i < graph[tmp].size(); i++)		// �ش� ����� �ڽĳ�带 ���� level�� push
				level.push(graph[tmp].at(i));
		}
		level.pop();
	}
}

void dfs(int root) {

	if (check[root] == 1)
		return;

	printf("%d ", root);
	check[root] = 1;			// �湮üũ

	for (int i = 0; i < graph[root].size(); i++) {		// ��� �ڽĳ��� �����Ͽ� ���
		int rootTmp = graph[root].at(i);
		dfs(rootTmp);
	}
}