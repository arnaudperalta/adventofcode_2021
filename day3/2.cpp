#include <bits/stdc++.h>
using namespace std;

int main(void) {
	FILE *file = fopen("input.txt", "r");

	char number[500];
	vector<char *> oxygen;
	vector<char *> co2;
	
	vector<char *>tmp_delete;

	while (fscanf(file, "%s", number) != EOF) {
		oxygen.push_back(strdup(number));
		co2.push_back(strdup(number));
	}

	for (int i = 0; i < strlen(number); i++) {
		int oxy_count_0 = 0;
		int oxy_count_1 = 0;
		int co2_count_0 = 0;
		int co2_count_1 = 0;
		if (oxygen.size() != 1) {
			for (int j = 0; j < oxygen.size(); j++) {
				if (oxygen[j][i] == '0') {
					oxy_count_0++;
				} else {
					oxy_count_1++;
				}
			}
			for (char *value: oxygen) {
				if (oxy_count_0 <= oxy_count_1 && value[i] == '1') {
					tmp_delete.push_back(value);
				} else if (oxy_count_0 > oxy_count_1 && value[i] == '0') {
					tmp_delete.push_back(value);
				}
			}
			oxygen.clear();
			for (char *s: tmp_delete)
				oxygen.push_back(s);
			tmp_delete.clear();
		}

		if (co2.size() != 1) {
			for (int j = 0; j < co2.size(); j++) {
				if (co2[j][i] == '0') {
					co2_count_0++;
				} else {
					co2_count_1++;
				}
			}
			for (char *value: co2) {
				if (co2_count_0 > co2_count_1 && value[i] == '1') {
					tmp_delete.push_back(value);
				} else if (co2_count_0 <= co2_count_1 && value[i] == '0') {
					tmp_delete.push_back(value);
				}
			}
			co2.clear();
			for (char *s: tmp_delete)
				co2.push_back(s);
			tmp_delete.clear();
		}

		if (oxygen.size() == 1 && co2.size() == 1) {
			break;
		}
	}

	cout << stoi(oxygen[0], 0, 2) * stoi(co2[0], 0, 2) << endl; 
}
