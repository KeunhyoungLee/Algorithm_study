#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int N, K, L;
int map[101][101];	//뱀:1 사과:2
int D; //0오른 1아래 2왼 3위
int time;
int head_x, head_y;		//뱀 머리
queue<pair<int, char>> q;	// 시간(초), 방향
deque<pair<int, int>> snake; // 뱀 몸통 좌표(순서대로, 마지막 벡터:꼬리)

int main()
{
	//초기설정
	map[1][1] = 1;
	head_x = 1; head_y = 1;
	snake.push_front(make_pair(1, 1));

	cin >> N >> K;
	//사과배치
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		map[x][y] = 2;
	}
	cin >> L;
	//시간(초), 방향 설정
	for (int i = 0; i < L; i++) {
		int X;
		char C;
		cin >> X >> C;
		q.push(make_pair(X, C));
	}
	
	int end = 0;// 게임 끝 플래그
	int q_time = q.front().first;//방향 전환 수, 방향 전환까지 걸리는 시간
	while (end==0) {//for (int i = 0; i < q_size && end == 0; i++) {
		for (int j = 0; j < q_time && end == 0; j++) {
			time++;
			//방향에 따른 뱀 머리 위치 변화
			if (D == 0) head_y++;
			else if (D == 1) head_x++;
			else if (D == 2) head_y--;
			else head_x--;

			if (head_x >= 1 && head_x <= N && head_y >= 1 && head_y <= N) {
				if (map[head_x][head_y] == 2){ //사과있을때 머리위치 이동, 뱀몸통벡터추가
					map[head_x][head_y] = 1;
					snake.push_front(make_pair(head_x, head_y));
				}
				else if (map[head_x][head_y] == 1) //게임끝
					end = 1;
				else { //map=0
					map[head_x][head_y] = 1;//맵의 뱀 머리 1로
					snake.push_front(make_pair(head_x, head_y)); //뱀 머리 좌표 추가
					map[snake.back().first][snake.back().second] = 0; //맵의 뱀 꼬리 0
					snake.pop_back();
					for (int k = 0; k < snake.size(); k++)
						map[snake[k].first][snake[k].second] = 1;
					/*if (D == 0) map[head_x][head_y - 1] = 0;
					else if (D == 1) map[head_x - 1][head_y] = 0;
					else if (D == 2) map[head_x][head_y + 1] = 0;
					else map[head_x + 1][head_y] = 0;*/
				}
			}
			else end = 1;
			
			/*for (int a = 0; a <= N; a++) {
				for (int b = 0; b <= N; b++)
					printf("%d ", map[a][b]);
				printf("\n");
			}
			printf("time : %d", time);
			printf("\n");*/
		}

		if (q.empty())	q_time = 1;
		else {
			if (q.front().second == 'D') {
				D++;	
				if (D > 3)
					D = 0;
			}
			else if (q.front().second == 'L') {
				D--;
				if (D < 0)
					D = 3;
			}
			int q_tmp = q.front().first;
			q.pop();
			if (q.empty())
				q_time = 1;
			else
				q_time = q.front().first - q_tmp;
		}
	}
	printf("%d", time);
}
