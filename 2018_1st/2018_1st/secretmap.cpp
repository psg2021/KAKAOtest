#include <iostream>
#include <string>

using namespace std;


void findMap(int n, int arr1[], int arr2[]) {
	string *result = new string[n];

	for (int i = 0; i < n; i++) {
		string temp;
		for (int j = 0; j < n; j++) {
			if (arr1[i] % 2 | arr2[i] % 2) {
				temp += "#";
			}
			else {
				temp += " ";
			}
			arr1[i] = arr1[i] / 2;
			arr2[i] = arr2[i] / 2;
		}
		reverse(temp.begin(), temp.end());
		result[i] = temp;
	}

	for (int i = 0; i < n; i++) {
		cout << result[i] << endl;
	}

	delete[] result;

	return;
}

int main() {
	int n;

	cin >> n;

	int *arr1 = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}

	int *arr2 = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr2[i];
	}

	findMap(n, arr1, arr2);

	delete[] arr1;
	delete[] arr2;

}