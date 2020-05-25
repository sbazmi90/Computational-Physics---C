/******* Saman Bazmi *********/


/* This program compute the pi number based on the Monte Carlo Method */


#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


int main(){
  srand(time(NULL));
  double x,y;          // Need two random number
  double N = 100000000;       // Number of trials
  int Ncir = 0;       // Number of stone in the circle
  for(int i = 0; i < N; i++)
    {
      x = rand();         // Pick a random number
      y = rand();
      
      //printf("%lf\n",x);
      //printf("%lf\n",y);
      /* We need to generate a random number between -1 , 1 */

      
      x = x / RAND_MAX;
      x = x * 2 - 1;
      y = y / RAND_MAX;
      y = y * 2 - 1;
      //printf("%lf\n",x);
      //printf("%lf\n",y);
      if(x*x + y*y < 1)          // Check the condition
	{
	  Ncir++;
	}
    }
  double p;
  p = 4*Ncir/N;
  printf("%lf\n",p);
  return 0;
}
