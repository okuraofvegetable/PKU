#include <cstdio>
using namespace std;
int main()
{
	int x,y;
	while(1)
	{
		scanf("%d %d",&x,&y);
		if(x==0&&y==0)break;
		int k=0;
		int cnt=0;
		while(x>0||y>0)
		{
			int dx=x%10,dy=y%10;
			if(k+dx+dy>=10)
			{
				k=1;
				cnt++;
			}
			x/=10;
			y/=10;
		}
		if(cnt==0)printf("No carry operation.\n");
		else if(cnt==1)printf("1 carry operation.\n");
		else printf("%d carry operations.\n",cnt);
	}
	return 0;
}
