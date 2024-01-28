#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> A(N, 0);
	vector<int> S(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		int insert_point = i;
		int insert_value = A[i];
		for (int j = i - 1; j >= 0; j--) {
			if (A[i] < A[j]) {
				insert_point = j + 1;
				break;
			}
			if (j == 0) {
				insert_point = 0;
			}
		}
		for (int j = i; j > insert_point; j--) {
			A[j] = A[j - 1];
		}
		A[insert_point] = insert_value;
	}
	S[0] = A[0];

	for (int i = 1; i < N; i++) {
		S[i] = S[i - 1] + A[i];
	}

	int sum = 0;

	for (int i = 0; i < N; i++) {
		sum = sum + S[i];
	}
	cout << sum;
}