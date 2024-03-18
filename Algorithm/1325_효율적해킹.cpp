#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void bfs(int node);
static vector<vector<int>> A;
static vector<int> answer;
static vector<bool> visited;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long N, M;
	cin >> N >> M;
	A.resize(N + 1);
	answer.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		A[s].push_back(e);
	}

	visited.resize(N + 1);

	for (int i = 0; i <= N; i++) {
		fill(visited.begin(), visited.end(), false);
		bfs(i);
	}

	int maxval = 0;

	for (int i = 1; i <= N; i++) {
		maxval = max(maxval, answer[i]);
	}

	for (int i = 0; i <= N; i++) {
		// answer�迭���� maxval�� ���� ���� ���� index�� �������� ���
		if (answer[i] == maxval) {
			cout << i << " ";
		}
	}
}


void bfs(int node) {
	queue<int> queue;
	queue.push(node);
	visited[node] = true;

	while (!queue.empty()) {
		int now_node = queue.front();
		queue.pop();

		for (int i : A[now_node]) {
			if (visited[i] == false) {
				visited[i] = true;
				answer[i]++;
				queue.push(i);
			}
		}
	}
}