#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K; //N:땅크기, M:양분, K:년
int map[10][10];//양분

//int tree[10][10][1000];//트리 나이
vector<int> tree[10][10]; //트리좌표,나이
//vector<int> tree;

int r[8] = { -1,-1,-1,0,0,1,1,1 };
int c[8] = { -1,0,1,-1,1,-1,0,1 };
int map_tmp[10][10];
int answer;

void season() {
	//spring & summer
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!tree[i][j].empty()) {
				sort(tree[i][j].begin(), tree[i][j].end());

				vector<int> tree_tmp1;//살아있는 나무
				vector<int> tree_tmp2;//죽은 나무
				for (int k = 0; k < tree[i][j].size(); k++)
					if (map[i][j] >= tree[i][j][k]) {
						map[i][j] -= tree[i][j][k];
						tree_tmp1.push_back(++tree[i][j][k]);
					}
					else {
						//map[i][j] += tree[i][j][k] / 2;
						//tree[i][j].erase(tree[i][j].begin() + k);
						//k--;
						tree_tmp2.push_back(tree[i][j][k]);
					}
				tree[i][j].clear();
				for (int k = 0; k < tree_tmp1.size(); k++)
					tree[i][j].push_back(tree_tmp1[k]);
				for (int k = 0; k < tree_tmp2.size(); k++)
					map[i][j] = map[i][j] + tree_tmp2[k] / 2;
			}
	//fall
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!tree[i][j].empty())
				for (int k = 0; k < tree[i][j].size(); k++)
					if (tree[i][j][k] % 5 == 0)
						for (int d = 0; d < 8; d++)
							if (i + r[d] >= 0 && i + r[d] < N &&
								j + c[d] >= 0 && j + r[d] < N)
								tree[i + r[d]][j + c[d]].push_back(1);

	//winter 양분추가 
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			map[i][j] += map_tmp[i][j];
}

void print() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			//if (!tree[i][j].empty())
			//	for (int k = 0; k < tree[i][j].size(); k++)
			answer += tree[i][j].size();

	printf("%d", answer);
}

int main()
{
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = 5;
			cin >> map_tmp[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		int x, y, num;
		cin >> x >> y >> num;
		tree[x][y].push_back(num);
	}

	for (int i = 0; i < K; i++)
		season();

	print();
}
