#include<iostream>
#include<stdlib.h>
#include<vector>

using namespace std;

int main() {
	vector<int> num;
	int score = 0;
	int add_score = 2;
	int point;
	while((cin >> point) && (point != 0)) {
		num.push_back(point);
	}
	
	for(vector<int>::iterator iter = num.begin(); iter != num.end(); iter++) {
		if(*iter == 1) {
			add_score = 2;
			score++;
		}
		else {
			score += add_score;
			add_score += 2;
		}
	}
	
	cout << score << endl;
	
	return 0;
} 
