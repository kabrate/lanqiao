#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
  double price[50],total_price;
  double discount[50];
  int i,j;
  int m=0; 
  total_price = 0;
  FILE *fp1;
  fp1 = fopen ("data.csv", "r");

  rewind(fp1);

  for(i=0;i<50;i++)
   {fscanf(fp1,"%lf %lf",&price[i],&discount[i]);
   
   }
  for(j=0;j<50;j++)
   {
    total_price = total_price + price[j]*discount[j];
     
   }
   printf("%lf",total_price/100);

  
 
   fclose(fp1);
   return 0;
}
