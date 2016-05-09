#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int nch, nprob;
  scanf("%d %d", &nch, &nprob);
  int i;
  int nChProb[nch];
  for (i = 0; i < nch; i++) {
    scanf("%d", &nChProb[i]);
  }
  /*TESTING*/
  /*
  printf("nch = %d\nnprob = %d\n", nch, nprob);
  for (i = 0; i < nch; i++) {
    printf("%d ", nChProb[i]);
  }
  */
  int currP = 1;
  int counter = 0;
  for (i = 0; i < nch; i++) {
    int prob;
    for (prob = 1; prob <= nChProb[i]; prob++) {
      if (prob == currP) {
        counter++;
      }
      if ((prob % nprob) == 0 && prob != nChProb[i]) {
        currP++;
      }
    }
    currP++;
  }
  printf("%d\n", counter);
  return 0;
}

