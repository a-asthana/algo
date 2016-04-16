#include <bits/stdc++.h>

using namespace std;

int countOnes(bool arr[], int low, int high) {
	if (high >= low) {
		int mid = low + (high - low) / 2;
		cout << mid << " " << high << endl;
		if (((mid  == high) || (arr[mid + 1] == 0)) && (arr[mid] == 1)) {
			cout <<" fucked up \n";
			return (mid + 1);
		}
		if (arr[mid] == 1) {
			cout << mid << " fis " << high << "\n";
			return countOnes(arr, mid + 1, high);
		}
			
		cout << mid << " sec " << low << "\n";
		return countOnes(arr, low, mid - 1);
	}
	return 0;
}

int main() {	
	bool arr[] = {1, 1, 1, 1, 0, 0, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Count of 1's in given array is " << countOnes(arr, 0, n-1);
	return 0;
}