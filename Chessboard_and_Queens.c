#include "bits/stdc++.h"
using namespace std;

int helper(int index, const vector<vector<char>> mat,unordered_set<int> d1 = {} /* i - j */, unordered_set<int> d2 = {}/* i + j */, unordered_set<int> c = {}) {
	if (index == 8) return 1;
	else {
		int out = 0;
		for (int j = 1; j <= 8; j++) {
			if (!c.count(j) && !d1.count(index - j) && !d2.count(index + j) && (mat[index][j-1] != '*')) {
				unordered_set<int> d1_t = d1; 
				unordered_set<int> d2_t = d2;
				unordered_set<int> c_t = c;
				d1_t.insert(index - j);
				d2_t.insert(index + j);
				c_t.insert(j);
				out += helper(index + 1,mat ,d1_t, d2_t, c_t);
			}
		}
		return out;
	}
}

int main() {
	
	vector<vector<char>> c(8,vector<char>(8,'.'));
	
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++) {
			char in;
			cin >> in;
			if (in != c[i][j]) c[i][j] = in;
		}
	}

	int out = helper(0,c);
	cout << out << endl;
	
}
