#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long min, max;
	cin >> min >> max;

	// �ִ񰪰� �ּڰ��� ���̸�ŭ �迭 ����
	vector<bool> check(max - min + 1);

	// 2�� �������� 4���� max���� �۰ų� ���� ������ �ݺ�
	for (long i = 2; i * i <= max; i++) {
		long pow = i * i; // ������
		long start_index = min / pow;

		if (min % pow != 0) {
			// �������� ������ 1�� �����־�� min���� ū ���������� ���۵�
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