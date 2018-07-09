#include <math.h>
#include <stdlib.h>
#include <stdio.h> 
#include <time.h>
double randn (double mu, double sigma)
{
  srand(time(NULL));
  double U1, U2, W, mult;
  static double X1, X2;
  static int call = 0;
 
  if (call == 1)
    {
      call = !call;
      return (mu + sigma * (double) X2);
    }
 
  do
    {
      U1 = -1 + ((double) rand () / RAND_MAX) * 2;
      U2 = -1 + ((double) rand () / RAND_MAX) * 2;
      W = pow (U1, 2) + pow (U2, 2);
    }
  while (W >= 1 || W == 0);
 
  mult = sqrt ((-2 * log (W)) / W);
  X1 = U1 * mult;
  X2 = U2 * mult;
 
  call = !call;
 
  return (mu + sigma * (double) X1);
}

void main()
{
	int i;
	double h;
	
	for(i=0;i<10;i++)
	{
		h=randn(0,1);
		printf("%f\n",h);
	
	}
	
	
}


