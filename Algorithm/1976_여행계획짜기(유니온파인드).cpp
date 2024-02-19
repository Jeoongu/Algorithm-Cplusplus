#include <iostream>
#include <vector>
using namespace std;

static vector<int> parent;

int find(int a) {
	if (a == parent[a]) {
		return a;
	}
	else {
		return parent[a] = find(parent[a]);
	}
}

void uni(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		parent[b] = a;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	int dosi[201][201];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> dosi[i][j];
		}
	}
	int route[1001];

	for (int i = 1; i <= M; i++) {
		cin >> route[i];
	}
	parent.resize(N + 1);
	// 여기까지해서 입력 받은거 할당 완료
	
	for (int i = 1; i <= N; i++) { // 대표 도시를 우선은 자기 자신으로 전부 초기화
		parent[i] = i;
	}

	for (int i = 1; i <= N; i++) { // dosi배열에서 1발견이 union 실행
		for (int j = 1; j <= N; j++) {
			if (dosi[i][j] == 1) {
				uni(i, j);
			}
		}
	}

	int idx = find(route[1]); // 시작 도시의 부모 노드 값을 idx에 저장
	bool connect = true;

	for (int i = 2; i <= M; i++) {
		if (idx != route[i]) {
			cout << "NO" << '\n';
			connect = false;
			break;
		}
	}

	if (connect) { // connect가 true라면
		cout << "YES" << '\n';
	}

}