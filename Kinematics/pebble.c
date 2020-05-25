/******* Saman Bazmi *********/


/* This program demonstrates the pebble game in the very simple way */
/* This is a homogeneous pebble game */


#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


int main(){
  srand(time(NULL));
  /* At the first, we should make array for sites, it is like a 2 dim lattice*/
  /* I am using allocation method for the memory*/
  int **lattice;
  int X = 12;
  /* Initialize the pointer to allocate the memory*/
  lattice = new int* [X];
  
  for (int i = 0; i < X; i++)  
	{
	  lattice[i]=new int[X]; 
	}
  
  /* Determine the initial values */
  for(int i = 0; i < X; i++)
    {
      for(int j = 0; j < X; j++)
	{
	  double r = rand();
	  r = r / RAND_MAX;
	  r = r * 10;
	  int R = int(r);
	  lattice[i][j] = R;
	  printf("%d\t",lattice[i][j]);
	}
      printf("\n");
    }
  /* Do the algorithm, pick a random point and see is it accept the condition or not*/
  int TMAX = 1000;
  int hist = 0;
  for(int T = 0; T < TMAX; T++)
    {
      double r1 = rand();
      double r2 = rand();
      r1 = r1 / RAND_MAX;
      r2 = r2 / RAND_MAX;
      r1 = r1 * 10 + 2;
      r2 = r2 * 10 + 2;
      int R1 = int(r1);
      int R2 = int(r2);
      if(lattice[R1][R2] < 3)
	{
	  hist++;
	}
      if(lattice[R1][R2] >= 3)
	{
	  hist--;
	}
    }
      printf("%d",hist);
  return 0;
}
