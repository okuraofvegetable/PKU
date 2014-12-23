#include <cstdio>
#include <cstring>
using namespace std;
bool b[10010];
int a[100100];
int main()
{
	int N,K;
	scanf("%d %d",&N,&K);
	for(int i=0;i<N;i++)scanf("%d",&a[i]);
	int cnt=0,id=0;
	while(1)
	{
		memset(b,false,sizeof(b));
		bool flag = false;
		int c=0;
		for(;id<N;id++)
		{
			if(!b[a[id]])
			{
				b[a[id]]=true;
				c++;
			}
			if(c==K)
			{
				flag = true;
				break;
			}
		}
		id++;
		if(!flag)break;
		cnt++;
	}
	printf("%d\n",cnt+1);
	return 0;
}
