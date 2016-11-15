#include<iostream>
#include<math.h>
#define N 8
using namespace std;

struct Set
{
	char gender;
	float h;
	float w;
	float fSize;
};

float liklihood(float x,float u,float var)
{
	float a = 1/(sqrt(2*3.14*var));
	float b = pow(x-u,2)/(2*var);
	return a * pow(2.71828,-b);
}

int main()
{
	cout<<"\nEnter 10 training Set : \n";
	cout<<"Gender\t"<<"Height\t"<<"Weight\t"<<"Foot Size\n";
	struct Set training[N];
	int male = 0,female = 0;
	for(int i = 0;i < N;i++)
		cin>>training[i].gender>>training[i].h>>training[i].w>>training[i].fSize;
	struct Set testing;
	cout<<"Enter Testing Data :\n";
	cout<<"Height\t"<<"Weight\t"<<"Foot Size\n";
	cin>>testing.h>>testing.w>>testing.fSize;
	float meanH[2] = {0},meanW[2] = {0},meanFSize[2] = {0};
	float varH[2] = {0},varW[2] = {0},varFSize[2] = {0};
	for(int i = 0;i < N;i++)
	{
		if(training[i].gender == 'M')
		{
			meanH[0] += training[i].h;
			meanW[0] += training[i].w;
			meanFSize[0] += training[i].fSize;
			male++;
		}
		else if(training[i].gender == 'F'){
			meanH[1] += training[i].h;
			meanW[1] += training[i].w;
			meanFSize[1] += training[i].fSize;	
			female++;
		}
	}
	for(int i = 0 ;i < 2;i++)
	{
		meanH[i] = meanH[i]/(i == 0 ?male:female);
		meanW[i] = meanW[i]/(i == 0 ?male:female);
		meanFSize[i] = meanFSize[i]/(i == 0 ?male:female);
		//cout<<meanH[i]<<" "<<meanW[i]<<" "<<meanFSize[i]<<endl;
	}

	for(int i = 0; i< N;i++)
	{
		if(training[i].gender == 'M')
		{
			varH[0] += pow(training[i].h-meanH[0],2);
			varW[0] += pow(training[i].w-meanW[0],2);
			varFSize[0] += pow(training[i].fSize-meanFSize[0],2);
		}
		else if(training[i].gender == 'F')
		{
			varH[1] += pow(training[i].h-meanH[1],2);
			varW[1] += pow(training[i].w-meanW[1],2);
			varFSize[1] += pow(training[i].fSize-meanFSize[1],2);
		}
	}
	for(int i = 0;i < 2;i++)
	{
		varH[i] = varH[i]/(i == 0 ?male-1:female-1);
		varW[i] = varW[i]/(i == 0 ?male-1:female-1);
		varFSize[i] = varFSize[i]/(i == 0 ?male-1:female-1);
		//cout<<varH[i]<<" "<<varW[i]<<" "<<varFSize[i]<<endl;
	}
	//cout<<male<<" "<<female;
	float priorMale = float(male)/N;
	float priorFemale = float(female)/N;
	//cout<<liklihood(testing.h,meanH[0],varH[0]);
	double posterior[2];
	for(int i = 0; i < 2;i++)
	{
		posterior[i] = (i == 0 ? priorMale : priorFemale)*liklihood(testing.h,meanH[i],varH[i])*liklihood(testing.w,meanW[i],varW[i])*liklihood(testing.fSize,meanFSize[i],varFSize[i]);
		cout<<posterior[i]<<endl;
	}
	if(posterior[0] > posterior[1])
		cout<<"\n! Your Testing Result Is Male !"<<"\n\t!Thank U !\n";
	else
		cout<<"\n! Your Testing Result Is Female !"<<"\n\t!Thank U !\n";
	return 0;
}
