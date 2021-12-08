#include <bits/stdc++.h>
using namespace std;

int main(void) {
	FILE *file = fopen("input.txt", "r");
	char line[500000];
	vector<int> nbs_length = { 2, 3, 4, 7 };
	bool is_output = false;
	int res = 0;

	while (fgets(line, sizeof(line), file)) {
		stringstream ss(line);
		for (string s; ss >> s;) {
			if (s.compare("|") == 0)
				is_output = true;
			else if (is_output) {
				for (int i = 0; i < nbs_length.size(); i++) {
					if (s.length() == nbs_length[i]) {
						res++;
						break;
					}
				}
			}
		}
		is_output = false;
	}
	cout<<res<<endl;
}
