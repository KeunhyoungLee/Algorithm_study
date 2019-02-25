#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int profit; //최대이윤
vector<pair<int, int>> v; //일 수, 비용 
int N;  //퇴사 남은 날

//day와 sum(이윤)
void dfs(int day, int sum) {
	if (day == N) { //상담하고 지나간 날이 퇴사날과 똑같은 경우 
		profit = max(sum, profit);// profit을 max값으로 계속 갱신
		return;
	}

	for (int i = day; i < N; i++) { //퇴사날짜가 더 남았을때 계속 탐색(dfs)
		if (i + v[i].first <= N)  //퇴사 전날까지만 상담이 가능하므로
			dfs(i + v[i].first, sum + v[i].second);
	}
	
	profit = max(sum, profit);//day==N이 아닐 때, 그 전까지의 profit 중 max
}

int main()
{
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int T, P;
		cin >> T;	cin >> P;
		v.push_back(make_pair(T, P));
	}
	dfs(0, 0);

	printf("%d", profit);
    return 0;
}
