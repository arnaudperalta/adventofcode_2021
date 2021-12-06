#include <bits/stdc++.h>
using namespace std;

int main(void) {
	FILE *file = fopen("input.txt", "r");
	char line[500000];

	fgets(line, sizeof(line), file);
	stringstream ss(line);
	unsigned long long int groups[9] = { 0 };

	for (int x; ss >> x;) {
		if (ss.peek() == ',')
			ss.ignore();
		groups[x]++;
	}

	for (int i = 0; i < 256; i++) {
		unsigned long long int old_group = 0;
		old_group = groups[0];
		for (int j = 0; j < 9; j++) {
			if (j == 6) {
				groups[j] = groups[j + 1] + old_group;
			} else if (j == 8) {
				groups[j] = old_group;
			} else {
				groups[j] = groups[j + 1];
			}
		}
	}
	unsigned long long int sum = 0;
	for (int i = 0; i < 9; i++) {
		sum += groups[i];
	}
	cout<<sum<<endl;
}
