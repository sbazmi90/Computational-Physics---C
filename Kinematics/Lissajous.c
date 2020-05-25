/******************************************************/



/**************** Author: Saman Bazmi ******************/


/* This program solves and computes numercial values for the Lissajous */
/* graph in kinematics, Motion in space */
/* This is anisotripic harmonic osscialtor */
/* We need to define the force for this kind of oscillator */
/* Fx = m w**2 x ; Fy = m w**2 y */
/* Omega in x and y axis are not the same*/







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
  double x,y,A,t,ti,dt,tf;
  double vx,vy;
  double w1,w2;
  // Initial variables //
  ti = 0.0;          // Initial Time
  tf = 10;          // Final Time
  dt = 0.01;       // Time steps
  w1 = 3.0;       // Omega 1
  w2 = 5.0;        // Omega 2
  A = 10.0;        // Common amplitude
  /************ Release the period of the oscillation **********/
  double T1 = 2*pi / w1;
  double T2 = 2*pi / w2;
  printf("Period of the first oscillators is %0.5lf \n ",T1);
  printf("Period of the second oscillators is %0.5lf \n ",T2);
  printf("***************************************************\n");
  FILE* answers;
  answers = fopen("Lissajous.dat","w");
  t = ti;
  while(t <= tf)
    {
      fprintf(answers, "%.5f\t %.5f\t %.5f\t %.5f\t %.5f \n",t,x,y,vx,vy);
      x = A * cos(w1 * t);
      y = A * sin(w2 * t );
      vx = -A * w1 * sin(w1 * t);
      vy = A * w2 * cos(w2 * t);
      t += dt;
    }
  fclose(answers);
  return 0;
}


