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
	// ��������ؼ� �Է� ������ �Ҵ� �Ϸ�
	
	for (int i = 1; i <= N; i++) { // ��ǥ ���ø� �켱�� �ڱ� �ڽ����� ���� �ʱ�ȭ
		parent[i] = i;
	}

	for (int i = 1; i <= N; i++) { // dosi�迭���� 1�߰��� union ����
		for (int j = 1; j <= N; j++) {
			if (dosi[i][j] == 1) {
				uni(i, j);
			}
		}
	}

	int idx = find(route[1]); // ���� ������ �θ� ��� ���� idx�� ����
	bool connect = true;

	for (int i = 2; i <= M; i++) {
		if (idx != route[i]) {
			cout << "NO" << '\n';
			connect = false;
			break;
		}
	}

	if (connect) { // connect�� true���
		cout << "YES" << '\n';
	}

}