//============================================================================
// Name        : kupc2014_b.cpp
// Title       : 数当てゲーム
// Author      : mizo0203
// Status      : Accepted
// Date        : 2014/07/05 14:12:51
// Copyright   : copyright free
// Description : 素数
//============================================================================

#include <stdio.h>
#include <algorithm>
#define QLE 200

using namespace std;

bool prime_number[1001];
char judge[2];
int ans = 1;

void set_prime_number(bool* array, int num) {

	fill(array, array + num, true);
	array[0] = array[1] = false;
	for (int i = 2; i < num; i++) {
		if (!array[i])
			continue;
		for (int j = i * 2; j < num; j += i) {
			array[j] = false;
		}
	}

}

void func(int i) {
	for (; i * ans <= 1000; i++) {
		if (!prime_number[i]) {
			continue;
		}
		printf("? %d\n", i * ans);
		fflush(stdout);
		scanf("%s", judge);
		if (judge[0] == 'Y') {
			ans *= i;
			func(i);
			break;
		}

	}

}

int main() {

	set_prime_number(prime_number,
			sizeof(prime_number) / sizeof(prime_number[0]));

	func(1);
	printf("! %d\n", ans);
	fflush(stdout);

	return 0;
}
