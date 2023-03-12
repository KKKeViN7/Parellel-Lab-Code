#include<iostream>
#include<windows.h>
#include<cmath>
using namespace std;
long long head,tail,freq;
const long long up=pow(2,25); 
int a[34000005];
void recursion(long long n)
{
	if(n==1) return;
	else
	{
		for(long long i=1;i<=n/2;i+=3) 
		{
			a[i]+=a[n-i+1];
			a[i+1]+=a[n-i];
			a[i+2]+=a[n-i-1];
		}
		n>>=1;
		recursion(n);
	}
}
int main()
{
	long long sum,sum1,sum2,sum3;//避免全局变量调用的损耗 
	memset(a,1,sizeof(a));
	for(long long n=pow(2,10);n<=up;n<<=1)
	{
		sum=0;
		QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
		QueryPerformanceCounter((LARGE_INTEGER *)&head);
		for(long long i=1;i<=n;i++) sum+=a[i];
		QueryPerformanceCounter((LARGE_INTEGER *)&tail);
		cout<<n<<','<<(double(tail-head)*1000/freq)<<',';
		sum=0;
		QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
		QueryPerformanceCounter((LARGE_INTEGER *)&head);
		for(long long i=1;i<=n;i+=3)
		{
			sum+=a[i];
			sum+=a[i+1];
			sum+=a[i+2];
		}
		QueryPerformanceCounter((LARGE_INTEGER *)&tail);
		cout<<(double(tail-head)*1000/freq)<<',';
		sum=0;sum1=0;sum2=0;sum3=0;
		QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
		QueryPerformanceCounter((LARGE_INTEGER *)&head);
		for(long long i=1;i<=n;i+=3)
		{
			sum1=sum1+a[i];
			sum2=sum2+a[i+1];
			sum3=sum3+a[i+2];
		}
		sum=sum1+sum2+sum3;
		QueryPerformanceCounter((LARGE_INTEGER *)&tail);
		cout<<(double(tail-head)*1000/freq)<<',';
		sum=0;
		QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
		QueryPerformanceCounter((LARGE_INTEGER *)&head);
		recursion(n);
		sum=a[1];
		QueryPerformanceCounter((LARGE_INTEGER *)&tail);
		cout<<(double(tail-head)*1000/freq)<<endl;
	}
} 
