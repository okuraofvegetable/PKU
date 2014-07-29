#include <cstdio>
#include <utility>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> T;
#define fi first
#define sec second
#define INF 2000000000
#define sq(X) ((X)*(X))
T points[20];
int a,b,c;
int dist(int x)
{
	return sq(points[x].fi-a)+sq(points[x].sec.fi-b)+sq(points[x].sec.sec-c);
}
int main()
{
	for(int i=0;i<16;i++)scanf("%d %d %d",&points[i].fi,&points[i].sec.fi,&points[i].sec.sec);
	while(1)
	{
		scanf("%d %d %d",&a,&b,&c);
		if(a==-1&&b==-1&&c==-1)break;
		int d=INF,id=-1;
		for(int i=0;i<16;i++)
		{
			if(d>dist(i))
			{
				d=dist(i);
				id=i;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n",a,b,c,points[id].fi,points[id].sec.fi,points[id].sec.sec);
	}
	return 0;
}
