#include <iostream>
using namespace std;
int money1[22];
int money2[32];
void money();
int main() {
	money();
	int tcCnt, res = 0;
	cin >> tcCnt;
	for (int t = 0; t < tcCnt; t++) {
		int a, b;
		cin >> a >> b;
		if (a > 21 && b > 31) res = 0;
		if (a < 22 && b >31) res = money1[a];

	}


	return 0;
}
void money() {
	int k = 0;
	for (int i = 1; i <= 6; i++) {
		for (int j = 0; j < i; j++) {
			money1[i+j] = i;
		}
	}
	 k = 0;
	 for (int i = 0; i < 5; i++) {
		 for (int j = 0; j < (1 << i); j++) {
			 money2[++k] = i + 1;
		 }
	 }
}