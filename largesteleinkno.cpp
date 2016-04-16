#include <bits/stdc++.h>

using namespace std;

//most largest element at the front

void getsol(int a[], int n, int k) {
	deque <int> deq(k);

	int i;
	for (i = 0; i < k; i++) {
		while((!deq.empty()) && (a[i] >= a[deq.back()])) {
			deq.pop_back();
		}
		deq.push_back(i);
	}

	for (; i < n; i++) {
		cout << a[deq.front()] << " ";

		while ((!deq.empty()) && (deq.front() <= i - k)) {
			deq.pop_front();
		}

		while ((!deq.empty()) && a[i] >= (a[deq.back()])) {
			deq.pop_back();
		}

		deq.push_back(i);
	}

	cout << a[deq.front()] << " ";
	cout <<"\n";

}

int main() {
	int n, k, i;
	cin >> n >> k;

	int a[n];
	for (i = 0; i < n; i++) {
		cin >> a[i];
	} 
	
	getsol(a,n,k);
	return 0;
}