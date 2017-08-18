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
		vectorSort[i] = from;								// 자식노드를 가진 벡터입력
	}

	for (int i = 1; i <= numOfLine; i++)					// 각 벡터 정렬(numOfLine이 그렇게 크지않다고 생각하여 중복체크 안함)
		sort(graph[vectorSort[i]].begin(), graph[vectorSort[i]].end());

	dfs(start);
	printf("\n");

	memset(check, 0, sizeof(int) * 1001);
	bfs(start);

	return 0;
}

void bfs(int root) {				// level이라는 큐에 graph[level.front()] 벡터의 간선들을 넣고 빼고 반복
	
	level.push(root);
	
	while (!level.empty()) {

		int tmp = level.front();

		if (check[tmp] == 0) {		// 방문체크

			printf("%d ", tmp);
			check[tmp] = 1;

			for (int i = 0; i < graph[tmp].size(); i++)		// 해당 노드의 자식노드를 전부 level에 push
				level.push(graph[tmp].at(i));
		}
		level.pop();
	}
}

void dfs(int root) {

	if (check[root] == 1)
		return;

	printf("%d ", root);
	check[root] = 1;			// 방문체크

	for (int i = 0; i < graph[root].size(); i++) {		// 모든 자식노드로 접근하여 재귀
		int rootTmp = graph[root].at(i);
		dfs(rootTmp);
	}
}