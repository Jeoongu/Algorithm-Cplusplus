#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> A(N, 0);
	vector<int> ans(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	stack<int> myStack;
	myStack.push(0);

	for (int i = 1; i < N; i++) {
		// 스택이 비지 않고 현재 수열이 스택 top위치의 값보다 크면
		while (!myStack.empty() && A[myStack.top()] < A[i]){
			ans[myStack.top()] = A[i];
			myStack.pop();
		}
		myStack.push(i);
	}
	while (!myStack.empty()) {
		// 반복문을 다 돌고 나왔는데 스택이 비지 않다면 빌 때까지
		ans[myStack.top()] = -1;
		myStack.pop();
	}
	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}
}