#include<stdio.h>
#include<stdlib.h>


void main()
{
	long long int n=1000;
	printf("%lld\n",n);
	for(int i=0;i<n;i++)
	{
		printf("%d %d\n",rand(),rand());
	}
}
