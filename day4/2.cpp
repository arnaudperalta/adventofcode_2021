#include <bits/stdc++.h>
using namespace std;

typedef struct bingo_nb {
	int nb;
	bool marked;
} bingo_nb;

int sum_of_unmarked(bingo_nb **board) {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (!board[i][j].marked) {
				sum += board[i][j].nb;
			}
		}
	}
	return sum;
}

int main(void) {
	FILE *file = fopen("input.txt", "r");
	vector<int> bingo_numbers;
	vector<bingo_nb **> bingo_tables;
	char line[5000];

	fscanf(file, "%s", line);
	stringstream ss(line);
	for (int x; ss >> x;) {
		bingo_numbers.push_back(x);
		if (ss.peek() == ',')
			ss.ignore();
	}

	bingo_nb **actual_board = new bingo_nb*[5];
	for (int i = 0; i < 5; i++) {
		actual_board[i] = new bingo_nb[5];
	}

	int i = 0;
	int j = 0;
	while (fgets(line, sizeof line, file) != NULL) {
		if (line[0] == '\n')
			continue;
		stringstream ss(line);
		for (int x; ss >> x;) {
			actual_board[i][j].nb = x;
			i++;
		}
		i = 0;
		j++;
		if (j == 5) {
			bingo_tables.push_back(actual_board);
			actual_board = new bingo_nb*[5];
			for (int i = 0; i < 5; i++) {
				actual_board[i] = new bingo_nb[5];
			}
			j = 0;
		}
	}

	map<int, bool> bingo_winning_map;
	
	for (int nb: bingo_numbers) {
		int table_nb = 0;
		for (auto& table: bingo_tables) {
			if (bingo_winning_map[table_nb]) {
				table_nb++;
				continue;
			}
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (table[i][j].nb == nb) {
						table[i][j].marked = true;

						// Check line
						for (int k = 0; k < 5; k++) {
							if (!table[i][k].marked)
								break;
							if (k == 4) {
								cout<< sum_of_unmarked(table) * table[i][j].nb << endl;
								bingo_winning_map[table_nb] = true;
								break;
							}
						}

						// Check column
						for (int k = 0; k < 5; k++) {
							if (!table[k][j].marked)
								break;
							if (k == 4) {
								cout<< sum_of_unmarked(table) * table[i][j].nb << endl;
								bingo_winning_map[table_nb] = true;
								break;
							}
						}
						if (bingo_winning_map[table_nb]) 
							break;
					}
					if (bingo_winning_map[table_nb]) 
							break;
				}
				if (bingo_winning_map[table_nb]) 
							break;
			}
			table_nb++;
		}
	}
}