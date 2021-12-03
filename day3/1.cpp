#include <bits/stdc++.h>
using namespace std;

int main(void) {
	FILE *file = fopen("input.txt", "r");

	char number[50000];
	vector<char *> numbers;

	char gamma_rate[50000];
	char epsilon_rate[50000];

	while (fscanf(file, "%s", number) != EOF) {
		numbers.push_back(strdup(number));
	}
	reverse(numbers.begin(), numbers.end());


	for (int i = 0; i < strlen(number); i++) {
		int count_0 = 0;
		int count_1 = 0;
		for (int j = 0; j < numbers.size(); j++) {
			if (numbers[j][i] == '0') {
				count_0++;
			} else {
				count_1++;
			}
		}
		gamma_rate[i] = count_0 > count_1 ? '0' : '1';
		epsilon_rate[i] = count_0 > count_1 ? '1' : '0';
	}
	cout << stoi(gamma_rate, 0, 2) * stoi(epsilon_rate, 0, 2) << endl; 
}
