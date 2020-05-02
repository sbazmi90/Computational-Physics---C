/******* Saman Bazmi *********/


/* This program compute the pi number based on the Markov Chain Method */


#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


int main(){
  srand(time(NULL));
  /* Determine the initial position */
  double x = 1.0;
  double y = 1.0;
  double deltax, deltay;             // Need two random number between -0.1 , 0.1
  double N = 100000000;                // Number of trials
  int Ncir = 0;                    // Number of stone in the circle
  for(int i = 0; i < N; i++)
    {
      deltax = rand();         // Pick a random number
      deltay = rand();
      
      //printf("%lf\n",x);
      //printf("%lf\n",y);
      /* We need to generate a random number between -0.1 , 0.1 */

      
      deltax = deltax / RAND_MAX;
      deltax = deltax * 2 - 1;
      deltax = deltax / 10;
      deltay = deltay / RAND_MAX;
      deltay = deltay * 2 - 1;
      deltay = deltay / 10;
      
      //printf("%lf\n",deltax);
      //printf("%lf\n",deltay);
      if(fabs(x + deltax) < 1.0 && fabs(y + deltay) < 1.0) // Check the condition
	{
	  x = x + deltax;
	  y = y + deltay;
	}
      if(x*x + y*y < 1)          // Check the condition
	{
	  Ncir++;
	}
    }
  double p;    // pi number
  p = 4*Ncir/N;
  printf("%lf\n",p);
  return 0;
}
