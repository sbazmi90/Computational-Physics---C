/******* Saman Bazmi *********/


/* This program demonstrates the pebble game in the very simple way */
/* This is a imhomogeneous pebble game */
/* In this case, imhomogenity means ther are different wight for each lattice point */


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
  static int X = 10;
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
  printf("**********************\n");
  // Define histo array to save the numbers of pick

  char histo[10];
  for(int i = 0; i < 10; i++)
    {
      histo[i] = 0;
      printf("%d\t",histo[0]);
    }
  // Define weight
  char weight[9] = [3.0,1.0,0.5,1.5,2.0,1.0,2.5,3.0,1.0];
  for(int i = 0; i < 10000; i++)
    {
      int newpos = 0;
    }
  //histo[0] = 1;
  //printf("%d\n",histo[0]);
  return 0;
}
