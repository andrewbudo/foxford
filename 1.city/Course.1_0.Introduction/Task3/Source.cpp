#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int K; // number of cockroaches [2; 10]
	int N; // number of funs [1;100];
	cin >> K >> N;
	for (int i = 0; i < N; ++i) 
	{
		int A, B, C, D;
		cin >> A >> B >> C >> D;
	}
	vector<int> allCockroaches;
	for (int i = 1; i <= K; ++i) 
	{
		allCockroaches.push_back(i);
	}
	vector< vector<int> > combinations;
	// combinations.push_back(allCockroaches);

	do {
		combinations.push_back(allCockroaches);
	} while (next_permutation(allCockroaches.begin(),allCockroaches.end()));


	/*
	// bubble sort
	for (size_t j = 0; j < allCockroaches.size(); j++) 
	{
		for (size_t i = 0; i < allCockroaches.size() - 1; i++)
		{
			if (allCockroaches.at(i) < allCockroaches.at(i + 1)) {
				int temp = allCockroaches.at(i);
				allCockroaches.at(i) = allCockroaches.at(i + 1);
				allCockroaches.at(i + 1) = temp;
				combinations.push_back(allCockroaches);
			}
		}
	}
	*/

	return 0;
}
