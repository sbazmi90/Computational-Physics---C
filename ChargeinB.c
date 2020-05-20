/******************************************************/



/**************** Author: Saman Bazmi ******************/

/* This code analyze the motion of a charged particle with charge q */
/* in  homogeneous magnetic field. The field is in z direction.     */
/* The charge enters to the field with vx=0, and vy = v0 cos(theta) */
/* and vz = v0 sin(theta). Also, w = qB/m                           */








#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define pi 3.141592

int main(){
  /********* Define initial variables ***********/
  double x,y,z,x0,y0,z0,R,t,dt,tf;
  double v0x,v0y,v0z,vx,vy,vz,v0;
  double theta,w;
  // Initial variables //
  w = 10;
  v0 = 1.0;
  v0x = 0.0;
  theta = 37;           // Should be in the range of 0, 90 //
  /*************** Initialization process ****************/
  if(theta < 0.0 || theta >=90){
    exit(1);
  }
  theta = (pi/180.0)*theta;                  // Should be in the radian //  
  v0y = v0 * cos(theta);
  v0z = v0 * sin(theta);
  x0 = -v0y/w;
  y0 = 0.0;
  z = 3.11248e-317;
  t = 0.0;
  tf = 10;
  dt = 0.01;
  /************ Assign numbers to initial variables *********/
  FILE* answers;
  answers = fopen("ChargeinB.dat","w");
  vz = v0z;
  while(t <= tf)
    {
      fprintf(answers, "%.5f\t %.5f\t %.5f\t %.5f\t %.5f\t %0.5f\t %0.5f \n",t,x,y,z,vx,vy,vz);
      x = x0 * cos(w*t);
      y = -x0 * sin(w*t);
      z = v0z * t;
      vx = v0y * sin(w*t);
      vy = v0y * cos(w*t);
      t += dt;
    }
  fclose(answers);
  return 0;
}
