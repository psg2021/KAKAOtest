#include <iostream>
#include <string>
#include "ctype.h"

using namespace std;

int score(string input) {
	const int length = 3;
	int array[length];
	int temp = -1;
	int result = 0;

	for (int i = 0; i < (int)input.length() ; i++) {
		if (isdigit(input[i])) {
			temp++;
			array[temp] = input[i] - '0';
			while (isdigit(input[i + 1])) {
				i++;
				array[temp] = array[temp] * 10 + input[i] - '0';
			}
		}else {
			switch (input[i]) {
			case 'S' :
				break;
			case 'D' :
				array[temp] = (int)pow(array[temp], 2);
				break;
			case 'T' :
				array[temp] = (int)pow(array[temp], 3);
				break;
			case '*' :
				if (temp != 0) {
					array[temp - 1] *= 2;
				}
				array[temp] *= 2;
				break;
			case '#' :
				array[temp] *= -1;
				break;
			}
		}
	}

	for (int i = 0; i < length; i++) {
		result += array[i];
	}

	return result;
}

int main() {
	string input;
	int result;

	cin >> input;

	result = score(input);
	cout << result << endl;

	return 0;
}