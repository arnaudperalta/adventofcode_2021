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
	sort(crabs.begin(), crabs.end());

	int goal_position = crabs.at(crabs.size()/2);
	int fuel_cost = 0;
	for (int crab : crabs) {
		fuel_cost += abs(crab - goal_position);
	}

	cout<<fuel_cost<<endl;
}
