#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	int start = 0;
	int end = 0; // 왜 0인거지?

	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (start < A[i]) {
			start = A[i]; // 레슨 최댓값을 시작 인덱스로 저장
		}
		end = end + A[i]; // 모든 레슨의 값을 종료 인덱스로 저장
	}

	while (start <= end) {
		int middle = (start + end) / 2;
		int sum = 0;
		int count = 0;

		// middle 값으로 모든 레슨을 저장할 수 있는지 확인
		for (int i = 0; i < N; i++) {
			if (sum + A[i] > middle) {
				count++;
				sum = 0;
			}
			sum = sum + A[i];
			if (sum != 0) {
				count++;
			}
			if (count > M) {
				start = middle + 1;
			}
			else {
				end = middle - 1;
			}
		}
	}
	cout << start << "\n";
}