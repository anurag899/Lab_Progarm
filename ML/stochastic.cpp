#include<stdio.h>
#include<math.h>

#define alpha .00000001
#define desired_error 0.10
#define no_of_sample 5

void testing();
float h[no_of_sample];
float cal_h(int a);
void w_initialisation();

int x[no_of_sample][2]={{1156,2},{2100,3},{517,1},{1028,2},{3075,4}};

int test[no_of_sample][2]={{1500,2},{2500,3}};

float y[no_of_sample]={10,20,5,9.5,30};

float w[3];

main()
{
 int i,j;
 float error=1;
 w_initialisation();
for(i=0;i<no_of_sample && error>desired_error;i++)
{
  printf("\nH for training sample:%d=%f",i+1,cal_h(i));
  error=0.5*pow((h[i]-y[i]),2);
  printf("\ncost=%f",error);
  printf("\n\n");
  for(j=0;j<3;j++)
  {
   if(j==0)
    w[0]=w[0]+alpha*(y[i]-h[i])*1;
   else
      w[j]=w[j]+alpha*(y[i]-h[i])*x[i][j-1];
  }
h[i]=cal_h(i);
error=0.5*pow((h[i]-y[i]),2);
}
testing();
}


void testing()
{
int i,j;
float test_y=0.0;
for(i=0;i<2;i++)
{ 
 test_y=0.0;
 for(j=0;j<3;j++)
  { 
    if(j==0)
     {
      test_y=w[0];
     }
    else
        test_y=test_y +w[j]*test[i][j-1];
  }
 printf("\ntest_y=%f",test_y);
}
}

float cal_h(int i)
{
int j;
float temp=0.0;
for(j=0;j<3;j++)
{
 if(j==0)
   temp=w[0];   
 else
   temp=temp+w[j]*x[i][j-1];
}
h[i] =temp;
//printf("\n\ncal_h=%f....",h[i]);
return h[i];
}    
 
void w_initialisation()
{
w[0]=0.01;
w[1]=0.009;
w[2]=0.03;
}
  