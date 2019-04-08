// 로봇 청소기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

using namespace std;

int N, M;	//세로 가로
int map[51][51];
int clean[51][51];
int x, y, d; //r, c , d
//d가 0인 경우에는 북쪽을, 1인 경우에는 동쪽을, 2인 경우에는 남쪽을, 3인 경우에는 서쪽을 바라보고 있는 것이다.
//	0위	1오른	2아래	3왼
//빈 칸은 0, 벽은 1

int cnt = 0;//청소횟수
bool loop = true;

void process() {
	//process 1
	if (map[x][y] == 0 && clean[x][y] == 0) {
		cnt++;
		clean[x][y] = 1;
	}
	while (1) {
		//process 2
		if (d == 0) {
			//위쪽 -> 왼쪽은 왼쪽
			//proess 2-3
			if ((clean[x][y + 1] == 1 || map[x][y + 1] == 1) && (clean[x - 1][y] == 1 || map[x - 1][y] == 1) &&
				(clean[x][y - 1] == 1 || map[x][y - 1] == 1)) {
				if (clean[x + 1][y] == 1 && map[x + 1][y] == 0) {
					x = x + 1;
					printf("x:%d y:%d d:%d \n", x, y,d);
					continue;
				}
				//process 2-4
				else if ( map[x + 1][y] == 1) {
					loop = false;
					break;
				}
				/*
					(clean[x + 1][y] == 1 && clean[x][y + 1] == 1 && clean[x - 1][y] == 1 && clean[x][y - 1] == 1) ||
					(map[x - 1][y] == 1 && map[x][y - 1] == 1 && map[x][y + 1] == 1)) {
					if (map[x + 1][y] == 1) {
						loop = false;
						break;
					}
					x = x + 1;
					//printf("x:%d y:%d \n", x, y);
					continue;
					*/
			}
			//process 2-1
			if (map[x][y - 1] == 0 && clean[x][y - 1] == 0) {
				cnt++;
				clean[x][y - 1] = 1;
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						printf("%d ", clean[i][j]);
					}
					printf("\n");
				}
				y = y - 1;
				d = 3;
				printf("x:%d y:%d d:%d \n", x, y, d);
				//flag = 1;
				//break;
				return;
			}
			//process 2-2
			else {
				d = 3;
				printf("x:%d y:%d d:%d \n", x, y, d);
				continue;
			}
		}
		else if (d == 1) {
			//오른쪽 -> 왼쪽은 위쪽
			if ((clean[x][y + 1] == 1 || map[x][y + 1] == 1) && (clean[x + 1][y] == 1 || map[x + 1][y] == 1) &&
				(clean[x - 1][y] == 1 || map[x - 1][y] == 1)) {
				if (clean[x][y - 1] == 1 && map[x][y - 1] == 0) {
					y = y - 1;
					printf("x:%d y:%d d:%d \n", x, y, d);
					continue;
				}
				else if ( map[x][y - 1] == 1) {
					loop = false;
					break;
				}
			}

			//	(clean[x + 1][y] == 1 && clean[x][y + 1] == 1 && clean[x - 1][y] == 1 && clean[x][y - 1] == 1) ||
			//	(map[x][y + 1] == 1 && map[x + 1][y] == 1 && map[x - 1][y] == 1)) {
			/*	if (map[x][y - 1] == 1) {
					loop = false;
					break;
				}
				y = y - 1;
				//printf("x:%d y:%d \n", x, y);
				continue;
			}*/
			if (map[x - 1][y] == 0 && clean[x - 1][y] == 0) {
				cnt++;
				clean[x - 1][y] = 1;
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						printf("%d ", clean[i][j]);
					}
					printf("\n");
				}
				x = x - 1;
				d = 0;
				printf("x:%d y:%d d:%d \n", x, y, d);
				//flag = 1;
				//break;
				return;
			}
			else {
				d = 0;
				printf("x:%d y:%d d:%d \n", x, y, d);
				continue;
			}
		}
		else if (d == 2) {
			//아래 -> 왼쪽은 오른쪽
			if ((clean[x + 1][y] == 1 || map[x + 1][y] == 1) && (clean[x][y + 1] == 1 || map[x][y + 1] == 1) ||
				(clean[x][y - 1] == 1 || map[x][y - 1] == 1)) {
				if (clean[x - 1][y] == 1 && map[x - 1][y] == 0) {
					x = x - 1;
					printf("x:%d y:%d d:%d \n", x, y, d);
					continue;
				}
				else if (map[x - 1][y] == 1) {
					loop = false;
					break;
				}
			}


			//	(clean[x + 1][y] == 1 && clean[x][y + 1] == 1 && clean[x - 1][y] == 1 && clean[x][y - 1] == 1) ||
			//	(map[x + 1][y] == 1 && map[x][y + 1] == 1 && map[x][y - 1] == 1)) {
			/*	if (map[x - 1][y] == 1) {
					loop = false;
					break;
				}
				x = x - 1;
				//printf("x:%d y:%d \n", x, y);
				continue;
			}*/
			if (map[x][y + 1] == 0 && clean[x][y + 1] == 0) {
				cnt++;
				clean[x][y + 1] = 1;
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						printf("%d ", clean[i][j]);
					}
					printf("\n");
				}
				y = y + 1;
				d = 1;
				printf("x:%d y:%d d:%d \n", x, y, d);
				//flag = 1;
				//break;
				return;
			}
			else {
				d = 1;
				printf("x:%d y:%d d:%d \n", x, y, d);
				continue;
			}
		}
		else if (d == 3) {
			//왼쪽 -> 왼쪽은 아래
			if ((clean[x][y - 1] == 1 || map[x][y - 1] == 1) && (clean[x + 1][y] == 1 || map[x + 1][y] == 1) &&
				(clean[x - 1][y] == 1 || map[x - 1][y] == 1)) {
				if (map[x][y + 1] == 1 && map[x][y + 1] == 0) {
					y = y + 1;
					printf("x:%d y:%d d:%d \n", x, y, d);
					continue;
				}
				else if (map[x][y + 1] == 1) {
					loop = false;
					break;
				}
			}
			/*
				(clean[x + 1][y] == 1 && clean[x][y + 1] == 1 && clean[x - 1][y] == 1 && clean[x][y - 1] == 1) ||
				(map[x][y - 1] == 1 && map[x + 1][y] == 1 && map[x - 1][y] == 1)) {
				if (map[x][y + 1] == 1) {
					loop = false;
					break;
				}
				y = y + 1;
				//printf("x:%d y:%d \n", x, y);
				continue;
			}*/
			if (map[x + 1][y] == 0 && clean[x + 1][y] == 0) {
				cnt++;
				clean[x + 1][y] = 1;
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						printf("%d ", clean[i][j]);
					}
					printf("\n");
				}
				x = x + 1;
				d = 2;
				printf("x:%d y:%d d:%d \n", x, y, d);
				//flag = 1;
				//break;
				return;
			}
			else {
				d = 2;
				printf("x:%d y:%d d:%d \n", x, y, d);
				continue;
			}
		}
	}
}


int main()
{
	cin >> N >> M;
	cin >> x >> y >> d;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	//printf("cnt:%d\n", cnt);
	while (loop) {
		process();
	}
	printf("%d\n", cnt);
}

/*
1.현재 위치를 청소한다.
2.현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
2-1.왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
2-1.왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
2-2.왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
2-3.네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
2-4.네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.*/
