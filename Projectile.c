/******************************************************/



/**************** Author: Saman Bazmi ******************/


/* This program solve equations of projectile motion near the earth's surface */
/* We neglect any air resistance in this problem */







#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define pi 3.141592
#define g  9.81

int main(){
  /********* Define initial variables ***********/
  double x,y,x0,y0,R,t,ti,dt,tf;
  double v0x,v0y,vx,vy,v,v0;
  double theta;
  // Initial variables //
  x0 = y0 = 0;
  v0 = 10.0;
  theta = 45;           // Should be in the range of 0, 90 //
  theta = (pi/180.0)*theta;                  // Should be in the radian //
  ti = 0.0;
  tf = 200;
  dt = 0.1;
  /*************** First Computation **************/
  v0x = v0 * cos(theta);
  v0y = v0 * sin(theta);
  /************ Assign numbers to initial variables *********/
  FILE* answers;
  answers = fopen("Projectile.dat","w");
  t = ti;
  while(t <= tf)
    {
      fprintf(answers, "%.5f\t %.5f\t %.5f\t %.5f\t %.5f \n",t,x,y,vx,vy);
      x = v0x * t;
      y = v0y - 0.5 * g * t*t;
      vx = v0x;
      vy = -g * t + v0y;
      t += dt;
    }
  fclose(answers);
  return 0;
}


