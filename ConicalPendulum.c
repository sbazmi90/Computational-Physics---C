/******* Saman Bazmi *********/


/* This program describes the conical pendulum with a very tiny theta */
/* The difference between this program and simple pendulum is related */
/* to the z coordiante that we add to the problem. */


#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define pi 3.141892
#define g  9.81

int main(){
  /********* Define initial variables ***********/
  double l,x,y,z,vx,vy,vz,t,ti,dt,tf,r;
  double theta, cos_theta, sin_theta,omega;
  ti = 0.0;
  tf = 20;
  dt = 0.1;
  /************ Assign numbers to initial variables *********/
  FILE* answers;
  answers = fopen("ConicalPendulum.dat","w");
  l = 1.0 ;
  omega = 6.28;  // The angular frequency
  printf("The angular frequency of the motion is = %0.5f \t",omega);
  printf("*****************************************");
  double T = 2*pi*omega;  // The period of the motion
  printf("The period of the motion is = %0.5f \t",T);
  printf("*****************************************");
  t = ti;
  cos_theta = g / (omega*omega*l);
  if(cos_theta >=1){
    printf("cos(theta) >= 1 is not acceptable.");
    exit(1);
  }
  sin_theta = sqrt(1 - cos_theta * cos_theta);
  z = -g / (omega*omega);
  vz = 0.0;
  r = g / (omega*omega)* sin_theta/cos_theta;
  while(t <= tf)
    {
      fprintf(answers, "%.5f\t %.5f\t %.5f\t %.5f\t %.5f\t %.5f\t %.5f\n",t,x,y,z,vx,vy,vz);
      x = r * cos(omega*t);
      y = r * cos(omega*t);
      vx = -r*omega*sin(omega*t);
      vy = r*omega*cos(omega*t);
      t += dt;
    }
  fclose(answers);
  return 0;
}


