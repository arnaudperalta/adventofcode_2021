#include <bits/stdc++.h>
using namespace std;

int main(void) {
	FILE *file = fopen("input.txt", "r");
	char line[500000];

	fgets(line, sizeof(line), file);
	stringstream ss(line);
	vector<int> crabs;

	for (int x; ss >> x;) {
		if (ss.peek() == ',')
			ss.ignore();
		crabs.push_back(x);
	}

	int goal_position = 0;
	for (int crab: crabs) {
		goal_position += crab;
	}
	goal_position /= crabs.size();

	int fuel_cost = 0;
	for (int crab: crabs) {
		fuel_cost += (abs(crab - goal_position) * (abs(crab - goal_position) + 1))/2;
	}

	cout<<fuel_cost<<endl;
}
