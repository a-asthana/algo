#include <bits/stdc++.h>
#define n 4


using namespace std;

bool issafe(int arr[n][],i, col) {

}

bool nq(int arr[n][],int col) {
	if (col > 4) {
		return true;
	}

	for (i = 0; i < n; i++) {
		if (issafe(arr, i, col)) {
			arr[i][col] = 1; 
			if (nq(arr, col + 1) == TRUE) {
				return TRUE;
			}
			arr[i][col] = 0;

		}
	}
	return FALSE;
}


int main() {

	int arr[4][4];

	memset(arr, 0, sizeof(arr));

	if (nq(arr, 0)) {
		printsol();
	}

	return 0;
}