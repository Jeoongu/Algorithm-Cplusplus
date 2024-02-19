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
	cin >> N >> M >> K >> X; // ��� ��, ���� ��, �Ÿ�, ���� ����
	A.resize(N + 1); // 0��° �ε����� ������� �ʱ� ����

	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		A[s].push_back(e); // s��忡 e���� ���� ������ �ִٴ°� �˷��ִ� ��
	}

	visited.resize(N + 1); // 0��° �ε����� ������� �ʱ� ����

	for (int i = 0; i <= N; i++) { // N+1�� ũ���� �迭�� ��ȯ�ϱ� ����
		visited[i] = -1;
	}

	bfs(X);

	for (int i = 0; i <= N; i++) {
		if (visited[i] == K) { // ��ǥ�Ÿ� K�� ���� ���ٸ�
			answer.push_back(i); // answer���Ϳ� �ش� ������ ��ȣ�� push_back()
		}
	}

	if (answer.empty()) { // answer���Ͱ� ����ִٸ� ��ǥ�Ÿ�K�� �ִ� ���� ��� ��ȣ�� ���ٴ� ���̴�
		cout << -1 << '\n';
	}
	else { // ��������� �ʴٸ�
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