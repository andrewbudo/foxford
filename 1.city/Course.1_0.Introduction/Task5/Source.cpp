#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> btn(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> btn.at(i);
	}
	int k;
	cin >> k;
	vector<int> sequence(k);
	vector<int> push_count(n + 1, 0);
	int press = 0;
	for (int i = 0; i < k; ++i) {
		cin >> press;
		push_count.at(press) += 1;
	}
	for (int i = 1; i <= n; ++i) {
		if (btn.at(i) < push_count.at(i)) {
			cout << "yes" << "\n";
		}
		else {
			cout << "no" << "\n";
		}
	}
	return 0;
}