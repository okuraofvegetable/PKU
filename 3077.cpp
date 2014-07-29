#include <cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		int base=10;
		while(x>base)
		{
			int d=x%base,s=x/base;
			if(d>=base/2)s++;
			x=s*base;
			base*=10;
		}
		printf("%d\n",x);
	}
	return 0;
}
