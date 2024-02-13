#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long min, max;
	cin >> min >> max;

	// 최댓값과 최솟값의 차이만큼 배열 선언
	vector<bool> check(max - min + 1);

	// 2의 제곱수인 4부터 max보다 작거나 같은 값까지 반복
	for (long i = 2; i * i <= max; i++) {
		long pow = i * i; // 제곱수
		long start_index = min / pow;

		if (min % pow != 0) {
			// 나머지가 있으면 1을 더해주어야 min보다 큰 제곱수부터 시작됨
			start_index++;
		}
		for (long j = start_index; pow * j <= max; j++) {
			check[(int)((j * pow) - min)] = true;
		}
	}

	int count = 0;

	for (int i = 0; i <= max - min; i++) {
		if (!check[i]) {
			count++;
		}
	}
	cout << count << '\n';
}