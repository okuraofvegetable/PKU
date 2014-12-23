#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int,int> P;
#define pb push_back
#define all(x) (x).begin(),(x).end()
map<P,int> m;
vector<int> vx,vy;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		vx.pb(a);vy.pb(b);
		if(m.find(P(a,b))==m.end())m[P(a,b)]=c;
		else m[P(a,b)]+=c;
	}
	sort(all(vx));
	sort(all(vy));
	vx.erase(unique(all(vx)),vx.end());
	vy.erase(unique(all(vy)),vy.end());
	printf("-1 ");
	for(int i=0;i<vx.size();i++)
	{
		printf("%d",vx[i]);
		if(i==vx.size()-1)printf("\n");
		else printf(" ");
	}
	for(int i=0;i<vy.size();i++)
	{
		printf("%d ",vy[i]);
		for(int j=0;j<vx.size();j++)
		{
			if(m.find(P(vx[j],vy[i]))==m.end())printf("0");
			else printf("%d",m[P(vx[j],vy[i])]);
			if(j==vx.size()-1)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
