#include <cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int ret=1;
	while(ret*(ret+1)/2<n)ret++;
	while(1)
	{
		if((ret-1)%4>=2&&n%2==0)break;
		if((ret-1)%4<2&&n%2==1)break;
		ret++;
	}
	printf("%d\n",ret);
	return 0;
}
