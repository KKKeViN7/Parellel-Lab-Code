#include<iostream>
#include<windows.h>
using namespace std;
int a[10005][10005];
int b[10005];
int sum[10005];
int n;
long long head, tail , freq ;
void init()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]=i+j;
		}
	}
	for(int i=1;i<=n;i++) b[i]=i;
}
int main()
{
	int step=10;
	for(n=1;n<=10000;n+=step)
	{
	init();
	for(int i=1;i<=n;i++) sum[i]=0;
	QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
	QueryPerformanceCounter((LARGE_INTEGER *)&head);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			sum[i]+=a[j][i]*b[j];
		}
	}
	QueryPerformanceCounter((LARGE_INTEGER *)&tail);
	cout<<"Æ½·² "<<n<<' '<<(tail-head)*1000000/freq<<' ';
	for(int i=1;i<=n;i++) sum[i]=0;
	QueryPerformanceFrequency((LARGE_INTEGER *)&freq );
	QueryPerformanceCounter((LARGE_INTEGER *)&head);
	for(int j=1;j<=n;j++)
	{
		for(int i=1;i<=n;i++)
		{
			sum[i]+=a[j][i]*b[j];
		}
	}
	QueryPerformanceCounter((LARGE_INTEGER *)&tail);
	cout<<"cache "<<n<<' '<<(tail-head)*1000000/freq<<endl;
	if(n>=1000) step=1000;
	else if(n>=100) step=100;
	}
}
