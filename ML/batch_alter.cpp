#include<iostream>
#include<math.h>
#define alpha 0.00000000001
#define desired_error 0.1
#define no_of_sample 5
using namespace std;

int x[no_of_sample][2] = {{1156,2},{2100,3},{517,1},{1028,2},{3075,4}};
float y[5] = {10,20,5,9.5,30};
int test[2][2] = {{1500,2},{2500,3}};
float h[no_of_sample];
float w[3];
void w_initialization();
void testing();
void cal_h(int i);

float sum1();
float sum2();

int main()
{
    w_initialization();
    for(int i = 0;i < no_of_sample;i++)
        cal_h(i);
    float error = 1;
    for(int i = 0;i < no_of_sample && error > desired_error;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            if(j == 0)
                w[j] += alpha * sum1();
            else
                w[j] += alpha * sum1() * x[i][j-1];
        }
        cal_h(i);
        error = 0.5 * sum2();

    cout<<"Error : "<<error<<endl;
    }
    testing();
    return 0;
}

void cal_h(int i)
{
    h[i] = w[0] + w[1]*x[i][0] + w[2]*x[i][1];
}

void testing()
{
    cout<<"\nArea : "<<test[0][0]<<"\tBedrooms : "<<test[0][1]<<"\tPrice : "<<w[0] + w[1] * test[0][0] + w[2] * test[0][1];
    cout<<"\nArea : "<<test[1][0]<<"\tBedrooms : "<<test[1][1]<<"\tPrice : "<<w[0] + w[1] * test[1][0] + w[2] * test[1][1];
}

void w_initialization()
{
    w[0] = 0.02;
    w[1] = 0.009;
    w[3] = 0.03;
}

float sum1()
{
    float sum = 0;
    for(int i = 0;i < no_of_sample;i++)
    {
        sum += y[i] - h[i];
    }
    return sum/no_of_sample ;
}

float sum2()
{
    float sum = 0.0;
    for(int i = 0;i < no_of_sample;i++)
        sum += pow(y[i]-h[i],2);
    return sum/no_of_sample ;
}
