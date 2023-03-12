#include<iostream>
#include<cstring>
#include<sys/time.h>
#include<cmath>
using namespace std;
long long sum,sum1,sum2;
long long head,tail,freq;
const long long up=pow(2,25); 
int a[34000005];
void recursion(long long n)
{
	if(n==1) return;
	else
	{
		for(long long i=1;i<=n/2;i++) a[i]+=a[n-i+1];
		n>>=1;
		recursion(n);
	}
}
int main()
{
	memset(a,1,sizeof(a));
	struct timeval start, end;
	float timecount;
	for(long long n=pow(2,10);n<=up;n<<=1)
	{
		sum=0;timecount=0.0;
		gettimeofday(&start, NULL);
		for(long long i=1;i<=n;i++) sum+=a[i];
		gettimeofday(&end, NULL);
		timecount += (double)(end.tv_sec - start.tv_sec)*1000+(double)(end.tv_usec-start.tv_usec)/1000;
		cout<<n<<','<<timecount<<',';
		sum=0;sum1=0;sum2=0;timecount=0.0;
		gettimeofday(&start, NULL);
		for(long long i=1;i<=n;i+=2)
		{
			sum1+=a[i];
			sum2+=a[i+1];
		}
		sum=sum1+sum2;
		gettimeofday(&end, NULL);
		timecount += (double)(end.tv_sec - start.tv_sec)*1000+(double)(end.tv_usec-start.tv_usec)/1000;
		cout<<timecount<<',';
		sum=0;sum1=0;sum2=0;timecount=0.0;
		gettimeofday(&start, NULL);
		recursion(n);
		sum=a[1];
		gettimeofday(&end, NULL);
		timecount += (double)(end.tv_sec - start.tv_sec)*1000+(double)(end.tv_usec-start.tv_usec)/1000;
		cout<<timecount<<endl;
	}
} 
