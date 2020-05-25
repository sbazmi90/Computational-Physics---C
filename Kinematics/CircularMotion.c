/******* Saman Bazmi *********/


/* This program describes the circular motion */


#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define pi 3.141892

int main(){
  /********* Define initial variables ***********/
  double xi,x,yi,y,vx,vy,R,theta,omega,t,ti,dt,tf;
  ti = 1.0;
  tf = 200;
  dt = 0.1;
  /************ Assign numbers to initial variables *********/
  FILE* answers;
  answers = fopen("CircularMotion.dat","w");
  printf("Enter the center of the circle in x coordinate :\n");
  scanf("%lf", &xi);
  printf("Enter the center of the circle in y coordinate :\n");
  scanf("%lf", &yi);
  printf("Enter the radius :\n");
  scanf("%lf", &R);
  printf("Enter omega:\n");
  scanf("%lf", &omega);
  double T = 2*pi*omega;  // The period of the motion
  printf("The period of the motion is = %0.5f \t",T);
  printf("*****************************************");
  t = ti;
  while(t <= tf)
    {
      fprintf(answers, "%.5f\t %.5f\t %.5f\t %.5f\t %.5f\n",t,x,y,vx,vy);
      theta = omega * (t-ti);
      x = xi + R * cos(theta);
      y = yi + R * sin(theta);
      vx = -omega*R*sin(theta);
      vy = -omega*R*cos(theta);
      t += dt;
    }
  fclose(answers);
  return 0;
}


