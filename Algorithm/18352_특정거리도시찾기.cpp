#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void bfs(int node);
static vector<vector<int>> A;
static vector<int> answer;
static vector<int> visited;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K, X;
	cin >> N >> M >> K >> X; // 노드 수, 엣지 수, 거리, 시작 도시
	A.resize(N + 1); // 0번째 인덱스는 사용하지 않기 때문

	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		A[s].push_back(e); // s노드에 e노드로 가는 엣지가 있다는걸 알려주는 것
	}

	visited.resize(N + 1); // 0번째 인덱스는 사용하지 않기 때문

	for (int i = 0; i <= N; i++) { // N+1개 크기의 배열을 순환하기 위함
		visited[i] = -1;
	}

	bfs(X);

	for (int i = 0; i <= N; i++) {
		if (visited[i] == K) { // 목표거리 K와 값이 같다면
			answer.push_back(i); // answer벡터에 해당 도시의 번호를 push_back()
		}
	}

	if (answer.empty()) { // answer벡터가 비어있다면 목표거리K에 있는 도시 노드 번호가 없다는 뜻이니
		cout << -1 << '\n';
	}
	else { // 비워져있지 않다면
		sort(answer.begin(), answer.end());
		for (int temp : answer) {
			cout << temp << "\n";
		}
	}

}

void bfs(int node) {
	queue<int> queue;
	queue.push(node);
	visited[node]++;

	while (!queue.empty()) {
		int now_node = queue.front();
		queue.pop();

		for (int i : A[now_node]) {
			if (visited[i] == -1) {
				visited[i] = visited[now_node] + 1;
				queue.push(i);
			}
		}
	}
}