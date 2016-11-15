#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;

void kMeansAlgo(int color[], int centroid[]);

int main()
{
    int color[256];
    for(int i = 0;i<256;i++)
    {
        color[i] = rand() % 256;
                     //cout<<color[i]<<"\t";
    }
    //cout<<color[3];
    int centroid[16];
    //initialize centroid
    cout<<"Centroid initialisation\n";
    int j = 0;
    for(int i = 0;i < 16;i++)
    {
    		//int k = 8*j;
            centroid[i] = color[j];
            j = j+16;
    }
    for(int i = 0;i < 16;i++)
        cout<<centroid[i]<<"  ";
        cout<<"\n\n";
    kMeansAlgo(color,centroid);
    return 0;
}



void kMeansAlgo(int color[], int centroid[])
{
    int C[256];
    int changeColor[256];
    int flag = 1;
    while(flag == 1)
	{
        
        for(int i = 0; i < 256;i++)
        {
        	int dist = 9999;
            for(int j = 0;j < 16;j++)
            {
                int  d = fabs(color[i]- centroid[j]);
                //cout<<"\tdistance is"<<d;
                if(d < dist)
                {
                    C[i] = centroid[j];
                    dist = d;
                }
            }
        }                            
        int sum[16] = {0};
        int num[16] = {0};
        for(int i=0;i < 256; i++)
        {
                for(int j = 0;j < 16;j++)
                {
                    if(C[i] == centroid[j])
                    {
                        sum[j] += color[i];
                        num[j]++;
                        break;
                    }
                }
        }
        flag = 0;
        for(int i = 0;i < 16;i++)
        {
            int s = centroid[i];
        centroid[i] = sum[i]/num[i];
            if(s != centroid[i] )
                {
                flag = 1;}
        }
        cout<<"intermediate updation\n";
        for(int i = 0;i < 16;i++)
            cout<<centroid[i]<<" ";
        //cout<<"---------------------\n";
        cout<<endl;

    }
    cout<<"\n\nUpdated centroid values\n\n";
    for(int i = 0;i < 16;i++)
        cout<<centroid[i]<<"  ";
    cout<<"\nOriginal Gray Image Pixel Values:\n";
    for(int i=0;i<256;i++){
            if(i%16==0){
                cout<<endl;
            }
            cout<<"\t"<<color[i];
    }
    cout<<"\nAfter Clustering Gray Image Pixel Values:\n";
    for(int i=0;i<256;i++){
            if(i%16==0){
                cout<<endl;
            }
            cout<<"\t"<<C[i];
    }
}
