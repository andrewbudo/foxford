#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int count_of_fun = 0;
	cin >> count_of_fun;	
	
	vector<int> score_of_fun;
	for (int i = 0; i < count_of_fun; i++) {
		int score = 0;
		cin >> score;
		score_of_fun.push_back(score);
	}
	int score_of_girl;
	cin >> score_of_girl;
	sort(begin(score_of_fun), end(score_of_fun));

	double temp = score_of_girl;
	for (size_t i = 0; i < score_of_fun.size(); i++) {
		if (score_of_girl < score_of_fun.at(i)) {
			temp = (temp + score_of_fun.at(i)) / 2.0;
		}		
	}
	cout << temp << endl;
	return 0;
}