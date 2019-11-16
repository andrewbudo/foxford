#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void Test1() {
	istringstream iss("2 4");
	std::ostringstream oss;

	int a, b, c;
	iss >> a >> b;
	c = a + b;
	oss << c << "\n";

	std::string s = oss.str();
	if (s == "7") {
		std::cout << "Test 1 OK" << "\n";
	}
	else {
		std::cout << "Test 1 fail" << "\n";
	}
}

int getSum(int a, int b) {
	int c = a + b;
	return c;
}

void Test2() {
	int a = -5, b = -3;
	int c = getSum(a, b);
	string s;
	(c == -8) ? s = "Test 2 OK" : s = "Test 2 fail";
	cout << s << "\n";
}

void TestAll() {
	Test1();

	Test2();
	/*
	Test3();
	*/
}


int main1() {
	int a, b, c;
	cin >> a >> b;
	c = getSum(a, b);
	cout << c << "\n";
	return 0;
}

void getSolution() {
	int a, b, c;
	cin >> a >> b;
	c = getSum(a, b);
	cout << c << "\n
}

int main() {
	TestAll();
	getSolution();

	return 0;
}