#include<stdio.h>
#include<math.h>
#define alpha 0.00000001
#define desired_error 0.10
#define no_of_sample 5
void testing();
float h[no_of_sample];
float cal_h(int);
void w_initialisation();
int x[no_of_sample][2]={{1156,2},{2100,3},{517,1},{1028,2},{3075,4}};
int test[no_of_sample][2]={{1500,2},{2500,3}};
float y[no_of_sample]={10,20,5,9.5,30};
float w[3];
float sum();
float error1();
main()
{
	int i,j;
	float error =1;
	w_initialisation();
	for(i=0;i< no_of_sample&&error>desired_error;i++)
    {
    	printf("\n H for the training sample %d=%f",i+1,cal_h(i));
    	error = error1();
    	printf("\n cost=%f",error);
    	for(j=0;j<3;j++)
    	{
    		if(j==0)
    		{
    			w[0]=w[0]+alpha*sum();
    			
			}
			else 
			{
			
			w[j]=w[j]+alpha*sum()*x[i][j];
		}
		}}	
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
		
		test_y=w[0];
		else
		test_y=test_y+w[j]*test[i][j-1];
		}
		printf("\n test_y=%f",test_y);
	}
}
float cal_h(int i)
{
	int j;
	float temp=0.0;
	for(j=0;j<3;j++)
	{
		if(j==0)
		{
			temp=w[0];
		}
		else 
		temp=temp+w[j]*x[i][j-1];
		
	}
	h[i]=temp;
	return h[i];
	
}
float error1(){
	float er=0;
	int i;
	for(i=0;i<no_of_sample;i++)
	{
	er	=er+pow((h[i]-y[i]),2);
	}
	return er/(2*no_of_sample);
	
}

float sum()
{
	int i,j;
	float tesw=0.0;
	for(i=0;i<no_of_sample;i++)
	{
	 	tesw=tesw+(y[i]-cal_h(i));
	}
	return tesw/no_of_sample;
}
void w_initialisation()
{
	w[0]=0.01;
	w[1]=0.009;
	w[2]=.03;
}
