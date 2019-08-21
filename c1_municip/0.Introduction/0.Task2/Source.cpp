#include <iostream>
#include <vector>
using namespace std;

int main() {
	int volume;
	cin >> volume;
	if (volume <= 0) {
		return 0;
	}
	
	vector<int> divisors;
	divisors.push_back(1);
	for (int i = 2; i <= volume / 2; i++) {
		if (volume % i == 0) {
			divisors.push_back(i);
		}
	}
	divisors.push_back(volume);
	int a = 0, b = 0, c = 0;
	int square = 2147483647; // INT_MAX;
	for (const int k1 : divisors) {
		int volume2 = volume / k1;
		for (const int k2 : divisors) {
			for (const int k3 : divisors) {
				if (k2 * k3 == volume2) {
					const int temp = (k1 * k2 + k2 * k3 + k3 * k1) * 2;
					if (temp < square) {
						square = temp;
						a = k1;
						b = k2;
						c = k3;
					}
				}
			}
		}
	}
	cout << a << " " << b << " " << c << endl;

	return 0;
}