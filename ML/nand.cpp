#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

void wUpdate(int x[][3],int z[],float w[])
{
    int flag = 1;
    while(flag == 1){
        for(int i = 0;i < 4;i++)
        {
                //calculate sum
            flag = 0;
            float sum = 0.0;
            float t = 0.5;
            for(int j = 0;j < 3;j++)
                sum += x[i][j] * w[j];
            int n;
            if(sum > t)
                n =1;
            else
                n = 0;
            float e = z[i] - n;
            if(e != 0)
                flag = 1;
            float r = 0.1;
            float d = r * e;
            for(int j = 0;j < 3;j++)
            {
                w[j] = w[j] + x[i][j] * d;
            }
            for(int i = 0; i< 3;i++)
                cout<<w[i]<<" ";
            cout<<endl;
        }
    }
}
int main()
{
    int x[4][3] = {
        {1,0,0},
        {1,0,1},
        {1,1,0},
        {1,1,1}

    };
    int z[4] = {1,1,1,0};
    float w[3] = {0.3,0.1,0.1};
    wUpdate(x,z,w);
    for(int i = 0; i< 3;i++)
        cout<<w[i]<<" ";
    int a,b;
    cout<<"\nEnter input data : ";
    cin>>a>>b;
    float sum;
    sum = w[0]*1.0+ w[1]*a+w[2]*b;

    cout<<sum<<"\n";
    cout<<"\nYour output Is : ";
    //sum = 0.5;
    sum = floor(sum * 10);
    sum = sum/10;

    if(sum > 0.5)
        cout<<1;
    else
        cout<<0;
    return 0;
}
