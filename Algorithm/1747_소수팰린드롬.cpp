#include <iostream>
#include <cmath>
#include <string>
using namespace std;

bool isPalindrome(int target);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long N;
	cin >> N;
	long A[10000001];

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

	int i = N;

	while (true) { // N���� 1�� �����ϸ鼭 �Ҽ��� �Ӹ���� ���� �´��� Ȯ��
		if (A[i] != 0) {
			int result = A[i];
			if (isPalindrome(result)) {
				cout << result << '\n';
				break;
			}
		}
		i++;
	}
}

bool isPalindrome(int target) {
	string temp_str = to_string(target); // ���ڸ� ���ڿ����� ��ȯ
	char const* temp = temp_str.c_str(); // ���ڿ��� char �迭�� ��ȯ
	int s = 0;
	int e = temp_str.size() - 1;

	while (s < e) {
		if (temp[s] != temp[e]) {
			return false;
		}
		s++;
		e--;
	}
	return true;
}