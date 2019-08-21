#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int player = 1;
	while (N > 0) {
		if (N > 1002 && ((N - 1000) % 3) == 0) {
			N -= 1000;
		}		
		else if (N == 2) {
			N -= 2;
		}
		else if (N == 1) {
			N -= 1;
		}
		else if (((N - 1) % 3) == 0) {
			N -= 1;
		}
		else {
			N -= 2;
		}

		if (N == 0) {
			cout << player << "\n";
		}
		else if (player == 1) {
			player = 2;
		}
		else {
			player = 1;
		}	
	}
	return 0;
}