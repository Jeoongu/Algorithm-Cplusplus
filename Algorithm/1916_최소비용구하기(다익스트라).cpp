#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair<int, int> edge;
static int N, M;
static vector<int> dist;
static vector<bool> visited;
static vector<vector<edge>> mlist;
int dijkstra(int start, int end);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	dist.resize(N + 1);
	fill(dist.begin(), dist.end(), INT_MAX);
	visited.resize(N + 1);
	fill(visited.begin(), visited.end(), false);
	mlist.resize(N + 1);

	for (int i = 0; i < M; i++) { // 가중치가 있는 인접 리스트 초기화
		int start, end, weight;
		cin >> start >> end >> weight;
		mlist[start].push_back(make_pair(end, weight));
	}

	int startIndex, endIndex;
	cin >> startIndex >> endIndex;
	int result = dijkstra(startIndex, endIndex);
	cout << result << '\n';
}

int dijkstra(int start, int end) {
	priority_queue<edge, vector<edge>, greater<edge>> pq;

	pq.push(make_pair(0, start));
	dist[start] = 0;

	while (!pq.empty()) {
		edge nowNode = pq.top();
		pq.pop();
		int now = nowNode.second;

		if (visited[now]) {
			visited[now] = true;

			// 선택 노드 + 비용 < 타깃 노드일 때 값을 갱신하는 부분
			for (edge n : mlist[now]) {
				if (!visited[n.first] && dist[n.first] > dist[now] + n.second) {
					dist[n.first] = dist[now] + n.second;
					pq.push(make_pair(dist[n.first], n.first));
				}
			}
		}
	}
	return dist[end];
}
