#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool visit[1001];
vector<int> v[1001];
queue<int> Q;

int N, M, V; // N 정점개수 M 간선개수 V 시작할 정점 번호

void init() {
	for (int i = 0; i < 1001; i++)	visit[i] = false;
}
void dfs(int x) {
	if (visit[x]) return;

    visit[x] = true;
	printf("%d ", x);
	for (int i = 0; i < v[x].size(); i++)
		dfs(v[x].at(i));
}

void bfs(int st) {
	Q.push(st);
	visit[st] = true;

	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		printf("%d ", x);
		for (int i = 0; i < v[x].size(); i++)
			if (!visit[v[x].at(i)]) {
				Q.push(v[x].at(i));
				visit[v[x].at(i)] = true;
			}
	}
}

void test_print() {

	for (int i = 0; i < 1001; i++) {
		if (!v[i].empty()) {
			cout << "#" << i << " : ";
			for (int j = 0; j < v[i].size(); j++) {
				cout << v[i][j] << " ";
			}
			cout << endl;
		}
	}
}

int main()
{
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int st, des;
		cin >> st >> des;
		v[st].push_back(des);
		v[des].push_back(st);
	}
	
	for (int i = 1; i <= N; i++)
		sort(v[i].begin(), v[i].end());

	dfs(V);
	printf("\n");
	init();
	bfs(V);
}
