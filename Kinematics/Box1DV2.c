/******************************************************/



/**************** Author: Saman Bazmi ******************/

/*This program analyze the free particle in an one-dimensional box.*/









#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


int main(){
  /********* Define initial variables ***********/
  double x,x0,L,t,dt,tf,ti;
  double vx,v0x;
  // Initial variables //
  L = 20;
  x0 = 0.0;
  v0x = 1.0;
  x = x0;
  vx = v0x;
  ti = 0.0;
  tf = 100.0;
  dt = 0.01;
  /*************** Initialization process ****************/

  /************ Assign numbers to initial variables *********/
  FILE* answers;
  answers = fopen("Box1D.dat","w");
  t = ti;
  while(t <= tf)
    {
      fprintf(answers, "%.5f\t %.5f\t %.5f \n",t,x,vx);
      x += x0 + vx * (t-ti);
      t += dt;
      // We need to apply boundary condition
      if(x < 0.0 || x > L)
	{
	  x0 = x;
	  ti = t;
	  vx = -vx;
	}
    }
  fclose(answers);
  return 0;
}
