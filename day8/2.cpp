#include <bits/stdc++.h>
using namespace std;

int main(void) {
	FILE *file = fopen("input.txt", "r");
	char line[500000];
	bool is_output = false;
	int total_res = 0;

	while (fgets(line, sizeof(line), file)) {
		stringstream ss(line);
		string line_res;
		map<char, int> m_1 = {
			{'a', 0},
			{'b', 0},
			{'c', 0},
			{'d', 0},
			{'e', 0},
			{'f', 0},
			{'g', 0},
		};
		map<char, int> m_7 = {
			{'a', 0},
			{'b', 0},
			{'c', 0},
			{'d', 0},
			{'e', 0},
			{'f', 0},
			{'g', 0},
		};
		map<char, int> m_4 = {
			{'a', 0},
			{'b', 0},
			{'c', 0},
			{'d', 0},
			{'e', 0},
			{'f', 0},
			{'g', 0},
		};
		for (string s; ss >> s;) {
			if (s.compare("|") == 0)
				is_output = true;
			else if (is_output) {
				if (s.length() == 2) {
					line_res.append("1");
				} else if (s.length() == 3) {
					line_res.append("7");
				} else if (s.length() == 4) {
					line_res.append("4");
				} else if (s.length() == 5) { // Soit un 2, un 3 ou un 5
					int common_letter_7 = 0;
					int common_letter_4 = 0;
					for (char c: s) {
						if (m_7[c] == 7)
							common_letter_7++;
						if (m_4[c] == 4) {
							common_letter_4++;
						}
					}
					if (common_letter_7 == 3) {
						line_res.append("3");
					} else if (common_letter_4 == 3) {
						line_res.append("5");
					} else {
						line_res.append("2");
					}
				} else if (s.length() == 6) { // Soit 6, un 9 ou un 0
					int common_letter_7 = 0;
					int common_letter_4 = 0;
					for (char c: s) {
						if (m_7[c] == 7)
							common_letter_7++;
						if (m_4[c] == 4)
							common_letter_4++;
					}
					if (common_letter_7 == 3) { // Soit un 9 ou un 0
						int common_letter_4 = 0;
						for (char c: s) {
							if (m_4[c] == 4)
								common_letter_4++;
						}
						if (common_letter_4 == 4) {
							line_res.append("9");
						} else {
							line_res.append("0");
						}
					} else {
						line_res.append("6");
					}
				} else if (s.length() == 7) {
					line_res.append("8");
				} else {
					cout<<"??"<<endl;
				}
			} else {
				if (s.length() == 2) {
					m_1[s[0]] = 1;
					m_1[s[1]] = 1;
				} else if (s.length() == 3) {
					m_7[s[0]] = 7;
					m_7[s[1]] = 7;
					m_7[s[2]] = 7;
				} else if (s.length() == 4) {
					m_4[s[0]] = 4;
					m_4[s[1]] = 4;
					m_4[s[2]] = 4;
					m_4[s[3]] = 4;
				}
			}
		}
		total_res += stoi(line_res);
		is_output = false;
	}
	cout<<total_res<<endl;
}
