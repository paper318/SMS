#include<iostream>
void load(int &a) {
	a = 12;
	std::cout << a;
}
int main() {
	int a = 10;
	load(a);
	std::cout << a;
}