/*
 * Lorenz Attractor
 * CSCI 4229/5229 Assignment 2
 *
 */

#include <stdio.h>

/*  Lorenz Parameters  */
double s  = 10;
double b  = 2.6666;
double r  = 28;

/*
 *  Main
 */
int main(int argc, char *argv[])
{
   int i;
   /*  Coordinates  */
   double x = 1;
   double y = 1;
   double z = 1;
   /*  Time step  */
   double dt = 0.001;

   printf("%8.3f#%8.3f#%8.3f\n",x,y,z);
   /*
    *  Integrate 50,000 steps (50 time units with dt = 0.001)
    *  Explicit Euler integration
    */
   for (i=0;i<50000;i++)
   {
      double dx = s*(y-x);
      double dy = x*(r-z)-y;
      double dz = x*y - b*z;
      x += dt*dx;
      y += dt*dy;
      z += dt*dz;
      printf("%8.3f#%8.3f#%8.3f\n",x,y,z);
   }
   return 0;
}
