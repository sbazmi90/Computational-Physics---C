/******* Saman Bazmi *********/


/* This program describes the simple pendulum with a very tiny theta */


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
  double l,x,y,vx,vy,t,ti,dt,tf;
  double theta, thetai,dtheta_dt,omega;
  ti = 1.0;
  tf = 200;
  dt = 0.1;
  /************ Assign numbers to initial variables *********/
  FILE* answers;
  answers = fopen("SimplePendulum.dat","w");
  l = 1.0 ;
  thetai = 0.314;
  omega = sqrt(g/l);  // The angular frequency
  printf("The angular frequency of the motion is = %0.5f \t",omega);
  printf("*****************************************");
  double T = 2*pi*omega;  // The period of the motion
  printf("The period of the motion is = %0.5f \t",T);
  printf("*****************************************");
  t = ti;
  while(t <= tf)
    {
      fprintf(answers, "%.5f\t %.5f\t %.5f\t %.5f\t %.5f\t %.5f\t %.5f\n",t,x,y,vx,vy,theta,dtheta_dt);
      theta = thetai + cos(omega * (t-ti));
      dtheta_dt = -omega * thetai * sin(omega * (t-ti));
      x = l * sin(theta);
      y = -l * cos(theta);
      vx = l * dtheta_dt * cos(theta);
      vy = l * dtheta_dt * sin(theta);
      t += dt;
    }
  fclose(answers);
  return 0;
}


