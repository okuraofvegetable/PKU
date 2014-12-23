#include <cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int s,d;
		scanf("%d %d",&s,&d);
		if((s+d)%2!=0||s-d<0)printf("impossible\n");
		else printf("%d %d\n",(s+d)/2,(s-d)/2);
	}
	return 0;
}
