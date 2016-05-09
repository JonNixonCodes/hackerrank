#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//constants
#define INT_MAX 999999
#define MAX_ROLLS 6
#define BOARD_SIZE 100

struct ladder {
    int start;
    int end;
};

struct snake {
    int start;
    int end;
};

int nextNode(int visited[], int dist[]);

int main () {
    int T, n, m;
    int i, j, t;
    /*
      read input
     */
    scanf("%d", &T);
    for (t = 0; t < T; t ++) {    
	scanf("%d", &n);
	struct ladder lladders[n]; //array of ladders   
	for (i = 0; i < n; i++) {
	    scanf("%d %d", &lladders[i].start, &lladders[i].end);
	}
	scanf("%d", &m);
	struct snake lsnakes[m]; //array of snakes
	for (i = 0; i < m; i++) {
	    scanf("%d %d", &lsnakes[i].start, &lsnakes[i].end);
	}
	/*
	  TESTING INPUT
	*/
	/*printf("t = %d\nn = %d\nm = %d\n", t, n, m);
	printf("ladders\n");
	for (i = 0; i < n; i++) {
	    printf("%d %d\n", lladders[i].start, lladders[i].end);
	}
	printf("snakes\n");
	for (i = 0; i < m; i++) {
	    printf("%d %d\n", lsnakes[i].start, lsnakes[i].end);
	}    
	*/

	/*
	  Dijkstra's algorithm - shortest path
	*/
	int currNode = 1;
	int destNode = 100;
	int dist[BOARD_SIZE+1];
	int visited[BOARD_SIZE+1];
	//init arrays
	dist[1] = 0;
	visited[1] = 0;
	for (i = 2; i <= BOARD_SIZE; i++) {
	    dist[i] = INT_MAX;
	    visited[i] = 0;
	}
	while (currNode != destNode) {
	    //obtain adjacent nodes
	    int adj[n+m+MAX_ROLLS]; //array of adjacent nodes
	    /*
	      update adj[] to contain all adjacent nodes that haven't been visited
	      return value is the number of adjacent nodes
	    */
	    int nadj = 0; //number of adjacent nodes
	    for (i = 0; i < 6; i++) {
		int adjNode = currNode + i + 1;
		if ( adjNode <= 100) {
		    if (visited[adjNode] == 0) {
			adj[nadj] = adjNode;
			nadj++;
			//check if adjNode has ladder or snake
			for (j = 0; j < n; j++) {
			    if (lladders[j].start == adjNode) {
				if (visited[lladders[j].end] == 0) {
				    adj[nadj] = lladders[j].end;
				    nadj++;
				}
			    }
			}
			for (j = 0; j < m; j++) {
			    if (lsnakes[j].start == adjNode) {
				if (visited[lsnakes[j].end] == 0) {
				    adj[nadj] = lsnakes[j].end;
				    nadj++;
				}
			    }
			}
			
		    }
		} else {
		    break;
		}
	    }
	    //check adjacent nodes
	    int tmpDist = dist[currNode] + 1; //minimum distance of adj nodes
	    for (i = 0; i < nadj; i++) {
		if (dist[adj[i]] > tmpDist) {
		    dist[adj[i]] = tmpDist;
		}
	    }
	    visited[currNode] = 1; //update visited array	    
	    //obtain next node
	    currNode = nextNode(visited, dist);
	    if (currNode == -1) {
		printf("error in minAdj");
		return -1;
	    }
	}
	//print number of rolls
	printf("%d\n", dist[destNode]);
    }
    return 0;
}

/*
  returns the unvisited node with the smallest distance
 */
int nextNode(int visited[], int dist[]) {
    int i;
    int min = INT_MAX;
    int retNode = -1;
    for (i = 1; i <= BOARD_SIZE; i++) {
	if (visited[i] == 0 && dist[i] < min) {
	    min = dist[i];
	    retNode = i;
	}
    }
    return retNode;
}
