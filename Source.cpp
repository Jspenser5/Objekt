#include <iostream>
#include <algorithm>
#include <string>
#include<iostream>
#include <vector>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}
bool have_nul(vector<bool> v) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 0)
			return 1;
	}
	return 0;
}
int main() {
	int count_rooms = 0,count;
	int left, right;
	vector<pair<int, int>> room;
	cin >> count;
	for(int i=0;i<count;i++){
		cin >> left >> right;
		room.push_back(make_pair(left, right));
	}
	vector<bool> flags(room.size(),0);
	sort(room.begin(), room.end(), comp);
	cout << room[0].second << endl;
	while (have_nul(flags)) {
		right = 0;
		for (int i = 0;i<room.size();i++) {
			if (flags[i] != 1) {
				if (room[i].first >= right) {
					flags[i] = 1;
					right = room[i].second;
				}
			}
		}
		count_rooms++;
	}
	cout << count_rooms << endl;
	return 0;
}
