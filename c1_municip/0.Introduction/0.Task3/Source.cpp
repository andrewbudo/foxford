#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Bet {
	int A = -1;
	int B = -1;
	int C = -1;
	int D = -1;
};

int main() {
	int K; // number of cockroaches [2; 10]
	int N; // number of funs [1; 100];
	cin >> K >> N;

	vector<Bet> bets;
	for (int i = 0; i < N; ++i) {
		Bet b;
		cin >> b.A >> b.B >> b.C >> b.D;
		bets.push_back(b);
	}

	vector<int> all(K);
	for (int i = 0; i < K; ++i) {
		all.at(i) = i + 1;
	}

	bool flag;
	do {
		flag = true;
		for (auto b : bets) {
			std::vector<int>::iterator it1 = std::find(all.begin(), all.end(), b.A);
			std::vector<int>::iterator it2 = std::find(all.begin(), all.end(), b.B);
			std::vector<int>::iterator it3 = std::find(all.begin(), all.end(), b.C);
			std::vector<int>::iterator it4 = std::find(all.begin(), all.end(), b.D);

			int d1 = std::distance(all.begin(), it1);
			int d2 = std::distance(all.begin(), it2);
			int d3 = std::distance(all.begin(), it3);
			int d4 = std::distance(all.begin(), it4);

			if (it1 != all.end() && it2 != all.end() && it3 != all.end() && it4 != all.end()) {
				if ((d1 < d2 && d3 >= d4) || (d1 >= d2 && d3 < d4)) {
				}
				else {
					flag = false;
					break;
				}
			}
			else {
				flag = false;
				break;
			}
			
		}
		if (flag) {
			for (auto a : all) {
				cout << a << " ";
			}
			return 0;
		}
	} while (next_permutation(all.begin(),all.end()));

	cout << 0 << "\n";
	return 0;
}
