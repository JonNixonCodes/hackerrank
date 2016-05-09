#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        int R; 
        int C; 
        scanf("%d %d",&R,&C);
        char* G[R];
        for(int G_i = 0; G_i < R; G_i++){
           G[G_i] = (char *)malloc(1024 * sizeof(char));
           scanf("%s",G[G_i]);
        }
        int r; 
        int c; 
        scanf("%d %d",&r,&c);
        char* P[r];
        for(int P_i = 0; P_i < r; P_i++){
        P[P_i] = (char *)malloc(1024 * sizeof(char));
        scanf("%s",P[P_i]);
        }

        //Locating pattern
	int row, col;
	int needle = 0;
	for (row = 0; row < R; row++) {
	    for (col = 0; col <= (C- c); col++) {
		int rrow;
		char* coord = (char*) (G[row] + col*sizeof(char));
		needle = 0;
		if (strncmp(coord, P[needle], c) == 0) {
		    for(rrow = row; rrow < R; rrow++) {
			if (strncmp(G[rrow] + col*sizeof(char), P[needle], c) == 0) {
			    needle++;
			} else {
			    break;
			}
			if (needle == r) {
			    printf("YES\n");
			    break;
			}
		    }
		}
		if (needle == r) {
		    break;
		}
	    }
	    if (needle == r) {
		break;
	    }
	}
	if (needle != r) {
	    printf("NO\n");
	}	    
    }    
    return 0;
}

