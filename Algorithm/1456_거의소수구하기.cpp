#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long min, max;
	cin >> min >> max;

	long A[100000001];

	for (int i = 2; i < 10000001; i++) {
		A[i] = i;
	}

	for (int i = 2; i <= sqrt(10000001); i++) {
		if (A[i] == 0) {
			continue;
		}
		for (int j = i + i; j <= 10000001; j = j + i) {
			A[j] = 0;
		}
	}
	int count = 0;

	// 이 부분 이해하기
	for (int i = 2; i < 10000001; i++) {
		if (A[i] != 0) {
			long temp = A[i];

			while ((double)A[i] <= (double)max / (double)temp) {
				if ((double)A[i] >= (double)min / (double)temp) {
					count++;
				}
				temp = temp * A[i];
			}
		}
	}
	cout << count << '\n';
}