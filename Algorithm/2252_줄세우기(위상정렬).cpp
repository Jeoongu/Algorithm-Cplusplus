#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> A;
	vector<int> indegree;

	A.resize(N + 1);
	indegree.resize(N + 1);

	// 이 부분 잘 넣기
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		A[s].push_back(e);
		indegree[e]++; // 진입 차수 배열 데이터 저장
	}
	
	queue<int> queue;

	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			queue.push(i);
		}
	}

	// BFS 사용시 자주 나오는 부분
	while (!queue.empty()) {
		int now = queue.front();
		queue.pop();
		cout << now << " ";

		for (int next : A[now]) {
			indegree[next]--;
			if (indegree[next] == 0) {
				queue.push(next);
			}
		}
	}
}