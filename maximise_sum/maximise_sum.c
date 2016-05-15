#include <stdlib.h>
#include <stdio.h>

int sumSubArr (int start, int end, int* arr);

int main (int argc, char* argv[]) {
    int t, T;
    scanf("%d", &T);
    for (t = 0; t < T; t++) {
	int n, i, j, N, M;
	scanf("%d %d", &N, &M);
	int arr[N];
	for (n = 0; n < N; n++) {
	    scanf("%d", &arr[n]);
	}
	//max = 0
	int max = 0;
	//for i from 0 to N
	for (i = 0; i < N; i++) {
	    //for j from i to N
	    for (j = i; j < N; j++) {
		//if bigger than max set new max
		int sum = sumSubArr(i, j, arr);
		if ((sum%M) > max) max = sum;
	    }

	}
	printf("%d\n", max);
    }
}

int sumSubArr (int start, int end, int* arr) {
    int sum = 0;
    int i;
    for (i = start; i <= end; i++) {
	sum += arr[i];
    }
    return sum;
}
