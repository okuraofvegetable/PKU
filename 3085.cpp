#include <cstdio>
using namespace std;
void solve(int x)
{
	int a=x/25;
	x-=a*25;
	int b=x/10;
	x-=b*10;
	int c=x/5;
	x-=c*5;
	printf("%d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n",a,b,c,x);
	return;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		printf("%d ",i+1);
		solve(x);
	}
	return 0;
}
