#include <iostream>
#include <vector>
using namespace std;

static vector<int> parent;
void unionfunc(int a, int b);
int find(int a);
bool checksame(int a, int b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	parent.resize(N + 1);

	for (int i = 0; i <= N; i++) { // ��ǥ ��带 �ڱ� �ڽ����� �ʱ�ȭ
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int question, a, b;
		cin >> question >> a >> b;

		if (question == 0) {
			unionfunc(a, b);
		}
		else {
			if (checksame(a, b)) {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
	}
}

void unionfunc(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		parent[b] = a;
	}
}

int find(int a) {
	if (a == parent[a]) {
		return a;
	}
	else {
		return parent[a] = find(parent[a]); // ����Լ� ����
	}
}

bool checksame(int a, int b) { // �� ���Ұ� ���� ��������
	a = find(a);
	b = find(b);

	if (a == b) {
		return true;
	}
	return false;
}