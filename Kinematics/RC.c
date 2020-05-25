/* This program sole the equation for Resistor,capacitor circuit */
/* based on the Euler method */


#include<math.h>
#include<stdio.h>


int main(){
  // ************ Introduce variables ************* //
  double V, R, C, Q;
  // Voltage, Resitance, Capacitance, Charge
  double t = 0;         // Initial time
  double t_max;         // Final time
  double h;             // time steps
  FILE* answer;
  answer = fopen("answer.dat","w");
  printf("Determine the initial charge: ");
  scanf("%lf",&Q);
  printf("Determine the capacitance: ");
  scanf("%lf",&C);
  printf("Determine the resistor: ");
  scanf("%lf",&R);
  printf("Determine the voltage: ");
  scanf("%lf",&V);
  printf("Determine the maximum time: ");
  scanf("%lf",&t_max);
  printf("Determine the time steps: ");
  scanf("%lf",&h);
  // *************** Apply Euler methods ************* //
  for(t; t < t_max; t++)
    {
      fprintf(answer, "%0.5lf \t %0.5lf \t \n",t ,Q);
      Q = Q + (h/R) * (V - Q/C);
      t = t + h;
    }
  fclose(answer);
  return 0;  
}
