#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int i, t, N, T;
    scanf("%d", &T);
    for (t = 0; t < T; t++) {
	scanf("%d", &N);
	int array[N];
	int leftSum = 0;
	int rightSum = 0;	
	for (i = 0; i < N; i++) {
	    scanf("%d", &array[i]);
	    rightSum += array[i];	    
	}
	/*
	  TESTING
	
	printf("Array = ");
	for (i = 0; i < N; i++) {
	    printf("%d ", array[i]);
	}
	printf("\n");
	*/

	for (i = 0; i < N; i++) {
	    rightSum -= array[i];	    
	    if (leftSum == rightSum) {
		printf("YES\n");
		break;
	    }
	    leftSum += array[i];
	}
	if (leftSum != rightSum) printf("NO\n");
    }
    return 0;
    
}
