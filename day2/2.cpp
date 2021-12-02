#include <bits/stdc++.h>
using namespace std;

int main(void) {
	FILE *file = fopen("input.txt", "r");

	char orientation[50000];
	int value;

	int position = 0;
	int depth = 0;
	int aim = 0;

	while (fscanf(file, "%s %d", orientation, &value) != EOF) {
		if (strcmp(orientation, "forward") == 0) {
			position += value;
			depth += aim * value;
		} else if (strcmp(orientation, "up") == 0) {
			aim -= value;
		} else if (strcmp(orientation, "down") == 0) {
			aim += value;
		}
	}
	cout << position * depth << endl; 
}
