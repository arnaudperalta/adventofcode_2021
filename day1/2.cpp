#include <bits/stdc++.h>
using namespace std;

int main(void) {
	FILE *file = fopen("input.txt", "r");

	vector<int> depths;
	int actual_depth = 0;
	int prev_depth = -1;

	size_t increased = 0;

	while (fscanf(file, "%d", &actual_depth) != EOF) {
		depths.push_back(actual_depth);
		if (depths.size() < 3) {
			continue;
		}
		actual_depth = accumulate(depths.begin(), depths.end(), 0);
		if (prev_depth != -1) {
			if (prev_depth < actual_depth) {
				increased++;
			}
		}
		prev_depth = actual_depth;
		depths.erase(depths.begin());
	}
	cout << increased << endl; 
}
