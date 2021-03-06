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
        color[i] = i;
                     //cout<<color[i]<<"\t";
    }
    int centroid[16],n;
    cout<<"Enter the value of N:";
    cin>>n;
    int image[n][n];
    cout<<"\nEnter Image(N*N):";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>image[i][j];
        }
    }
    int j=1;
    for(int i=0;i<16;i++){
        centroid[i]=8*j-5;
        j+=2;
    }
    //initialize centroid
    // cout<<"Centroid initialisation\n";
    // int j = 0;
    // for(int i = 0;i < 16;i++)
    // {
    // 		//int k = 8*j;
    //         centroid[i] = color[j];
    //         j = j+16;
    // }
    // for(int i = 0;i < 16;i++)
    //     cout<<centroid[i]<<"  ";
    //     cout<<"\n\n";
    kMeansAlgo(color,centroid);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int d=9999;
            int index;
            for(int k=0;k<16;k++){
                int s=fabs(image[i][j]-centroid[k]);
                if(s<d){
                    d=s;
                    index=k;
                }
            }
            image[i][j]=index;
        }
    }
    cout<<endl;
    for(int i=0;i<16;i++){
        cout<<centroid[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<image[i][j]<<" ";
        }
        cout<<endl;
    }
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
    //     cout<<"intermediate updation\n";
    //     for(int i = 0;i < 16;i++)
    //         cout<<centroid[i]<<" ";
    //     //cout<<"---------------------\n";
    //     cout<<endl;

    // }
    // cout<<"\n\nUpdated centroid values\n\n";
    // for(int i = 0;i < 16;i++)
    //     cout<<centroid[i]<<"  ";
    // cout<<"\nOriginal Gray Image Pixel Values:\n";
    // for(int i=0;i<256;i++){
    //         if(i%16==0){
    //             cout<<endl;
    //         }
    //         cout<<"\t"<<color[i];
    // }
    // cout<<"\nAfter Clustering Gray Image Pixel Values:\n";
    // for(int i=0;i<256;i++){
    //         if(i%16==0){
    //             cout<<endl;
    //         }
    //         cout<<"\t"<<C[i];
    // }
}
}
