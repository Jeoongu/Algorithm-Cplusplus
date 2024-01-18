#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> A(N, 0);
	vector<char> resultV;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	stack<int> myStack;

	int num = 1;
	bool result = true;

	for (int i = 0; i < A.size(); i++) {
		int su = A[i];

		// 현재 수열 값 >= 오름차순 자연수 : 값이 같아질 때까지 push()수행
		if (su >= num) {
			while (su>=num)
			{
				myStack.push(num++);
				resultV.push_back('+');
			}
			myStack.pop();
			resultV.push_back('-');
		}
		// 현재 수열 값 < 오름차순 자연수 : pop()을 수행하여 수열 원소를 꺼냄
		else
		{
			int n = myStack.top();
			myStack.pop();
			// 스택의 가장 위의 수가 만들어야 하는 수열의 수보다 크다면 수열 출력 불가능
			if (n > su) {
				cout << "NO";
				result = false;
				break;
			}
			else {
				resultV.push_back('-');
			}
		}

	}
	if (result) {
		for (int i = 0; i < resultV.size(); i++) {
			cout << resultV[i] << '\n';
		}
	}
}