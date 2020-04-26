/* This code solve the equation of motion for an ordinary oscillator */
/* The methos that we used to solve this is Forward Euler method */


#include<stdio.h>
#include<math.h>


int main(){
  /***************** Define variables******************/
  double m, xi, vi, fi, k, omega, b;
  double ti = 0.0;                   // Time to start
  double h = 0.1;                    // Time steps
  double t_max = 100;                 // Time at the end
  FILE* answers;
  answers = fopen("oscillator.dat","w");            // Open file for answers
  /***************** Introduce variables *************/

  printf("Enter the mass: ");
  scanf("%lf",&m);
  printf("Enter the initial postion: ");
  scanf("%lf",&xi);
  printf("Enter the initial velocity: ");
  scanf("%lf",&vi);
  printf("Enter the initial force: ");
  scanf("%lf",&fi);
  printf("Enter the force constant: ");
  scanf("%lf",&k);
  printf("Enter the frequency: ");
  scanf("%lf",&omega);
  printf("Enter the damping coefficient: ");
  scanf("%lf",&b);

  /*************** Euler method *******************/
  for(ti; ti <= t_max; ti++)
    {
      fprintf(answers, "%.5f\t%.5f\t%.5f\n",ti,xi,vi);
      xi = xi + h * vi;
      vi = vi + h * (-k * xi - b * vi + fi * cos(omega * ti))/m;
      ti = ti + h;
    }
  fclose(answers);                         // Close the file
  return (0);
}
