#include <bits/stdc++.h>
using namespace std;

int main(void) {
	FILE *file = fopen("input.txt", "r");

	int prev = -1;
	int actual;

	size_t increased = 0;

	while (fscanf(file, "%d", &actual) != EOF) {
		if (prev == -1) {
			prev = actual;
			continue;
		}

		if (actual > prev) {
			increased++;
		}

		prev = actual;
	}
	cout << increased << endl; 
}
