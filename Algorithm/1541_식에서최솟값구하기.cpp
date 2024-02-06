#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// ���ڿ��� Ư�� �����ڷ� �߶� ���Ϳ� �����ϴ� �Լ�
vector<string> split(string input, char delimiter) {
	vector<string> result;
	stringstream mystream(input);
	string splitdata;

	while (getline(mystream, splitdata, delimiter)) {
		result.push_back(splitdata);
	}
	return result;
}

// ���� �׷��� ���ϱ� ���� �����Լ�
int mySum(string a){
	int sum = 0;
	vector<string> temp = split(a, '+');

	for (int i = 0; i < temp.size(); i++) {
		sum += stoi(temp[i]);
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int answer = 0;
	string example;
	cin >> example;
	vector<string> str = split(example, '-');

	for (int i = 0; i < str.size(); i++) {
		int temp = mySum(str[i]);
		if (i == 0) {
			answer = answer + temp; // ���� �պκи� ����
		}
		else {
			answer = answer - temp; // �ڿ� �κ��� ���� ���� ����.
		}
	}
	cout << answer << '\n';
}