//============================================================================
// Name        : kupc2014_a.cpp
// Title       : マッサージチェア
// Author      : mizo0203
// Status      : Accepted
// Date        : 2014/07/05 13:21:54
// Copyright   : copyright free
// Description : 順列による全探索
//============================================================================

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int a[3], b[3];

	for (int i = 0; i < 3; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < 3; i++) {
		scanf("%d", &b[i]);
	}

	int index[3];
	for (int i = 0; i < 3; ++i) {
		index[i] = i;
	}

	// 全ての組み合わせを試行
	int min = -1;
	do {
		int sum = 0;
		for (int i = 0; i < 3; i++) {
			sum += abs(a[index[i]] - b[i]);
		}
		if (min > sum || min == -1) {
			min = sum;
		}
	} while (next_permutation(index, index + 3));
	printf("%d\n", min);

	return 0;
}
