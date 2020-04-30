/* This program solve the radioactive decay problem */
/* based on the Monte Carlo method */


#include<stdio.h>
#include<math.h>
#include<time.h>


int main(){
  // Introduce variables:
  // Maximum time, initialization, Initial value of particles
  int T, i, N0;
  // Random number, initial time, time step, decay constant
  double R, T0, dt, C;
  FILE *answer;
  srand(time(0));
  answer = fopen("decay.txt","w");
  printf("Enter the number of particles :\n");
  scanf("%d", &N0);
  printf("Enter the decay constant: \n");
  scanf("%lf", &C);
  printf("Enter the maximum time: \n");
  scanf("%d", &T);
  dt = 1/C;


  // Apply Monte Carlo method //
  for(T0 = 0; T0 < T; T0++)
    {
      fprintf(answer,"%lf \t %d\n", T0, N0); // Print to file
      T0 = T0 + dt;
      for(i = 0; i < N0; i++)
	{
	  R = rand()/10000000000;
	  if(R < 0.5)
	    {
	      N0 --;
	    }
	  if(N0 <= 0)
	    {
	      goto X;
	    }
	}
    }
 X : fclose(answer);
  return 0;
}
