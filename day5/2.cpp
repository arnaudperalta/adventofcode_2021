#include <bits/stdc++.h>
using namespace std;

typedef struct coords {
	int x1;
	int y1;
	int x2;
	int y2;
} coords;


int find_max_x(vector<coords> v) {
	int max_x = 0;
	for (coords c : v) {
		if (c.x1 > max_x) {
			max_x = c.x1;
		}
		if (c.x2 > max_x) {
			max_x = c.x2;
		}
	}
	return max_x;
}

int find_max_y(vector<coords> v) {
 	int max_y = 0;
	for (coords c : v) {
		if (c.y1 > max_y) {
			max_y = c.y1;
		}
		if (c.x2 > max_y) {
			max_y = c.y2;
		}
	}
	return max_y;
}

int main(void) {
	FILE *file = fopen("input.txt", "r");
	vector<coords> coords_list;
	int _x1;
	int _y1;
	int _x2;
	int _y2;
	
	int max_x = 0;
	int max_y = 0;

	while (fscanf(file, "%d,%d -> %d,%d", &_x1, &_y1, &_x2, &_y2) != EOF) {
		coords_list.push_back({_x1, _y1, _x2, _y2});
	}
	max_x = find_max_x(coords_list);
	max_y = find_max_y(coords_list);
	char grid[max_x][max_y];
	for (int i = 0; i < max_x; i++) {
		for (int j = 0; j < max_y; j++) {
			grid[i][j] = '.';
		}
	}

	for (coords c : coords_list) {
		// Horizontal line
		if (c.x1 == c.x2) {
			if (c.y1 < c.y2) {
				for (int i = c.y1; i <= c.y2; i++) {
					if (grid[c.x1][i] == '.') {
						grid[c.x1][i] = '1';
					} else {
						grid[c.x1][i] += 1;
					}
				}
			} else{
				for (int i = c.y2; i <= c.y1; i++) {
					if (grid[c.x1][i] == '.') {
						grid[c.x1][i] = '1';
					} else {
						grid[c.x1][i] += 1;
					}
				}
			}
		}
		// Vertical line
		else if (c.y1 == c.y2) {
			if (c.x1 < c.x2) {
				for (int i = c.x1; i <= c.x2; i++) {
					if (grid[i][c.y1] == '.') {
						grid[i][c.y1] = '1';
					} else {
						grid[i][c.y1] += 1;
					}
				}
			} else {
				for (int i = c.x2; i <= c.x1; i++) {
					if (grid[i][c.y1] == '.') {
						grid[i][c.y1] = '1';
					} else {
						grid[i][c.y1] += 1;
					}
				}
			}
		}
		// Diagonale
		else {
			if (c.x1 < c.x2 && c.y1 < c.y2) {
				for (int i = 0; i <= c.x2 - c.x1; i++) {
					if (grid[c.x1 + i][c.y1 + i] == '.') {
						grid[c.x1 + i][c.y1 + i] = '1';
					} else {
						grid[c.x1 + i][c.y1 + i] += 1;
					}
				}
			} else if (c.x1 < c.x2 && c.y1 > c.y2) {
				for (int i = 0; i <= c.x2 - c.x1; i++) {
					if (grid[c.x1 + i][c.y1 - i] == '.') {
						grid[c.x1 + i][c.y1 - i] = '1';
					} else {
						grid[c.x1 + i][c.y1 - i] += 1;
					}
				}
			} else if (c.x1 > c.x2 && c.y1 < c.y2) {
				for (int i = 0; i <= c.x1 - c.x2; i++) {
					if (grid[c.x1 - i][c.y1 + i] == '.') {
						grid[c.x1 - i][c.y1 + i] = '1';
					} else {
						grid[c.x1 - i][c.y1 + i] += 1;
					}
				}
			} else if (c.x1 > c.x2 && c.y1 > c.y2) {
				for (int i = 0; i <= c.x1 - c.x2; i++) {
					if (grid[c.x1 - i][c.y1 - i] == '.') {
						grid[c.x1 - i][c.y1 - i] = '1';
					} else {
						grid[c.x1 - i][c.y1 - i] += 1;
					}
				}
			}
		}
	}

	int res = 0;
	for (int i = 0; i < max_x; i++) {
		for (int j = 0; j < max_y; j++) {
			if (grid[i][j] > '1') {
				res++;
			}
		}
	}
	cout<<res<<endl;
}
