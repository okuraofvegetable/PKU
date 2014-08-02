#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
#define INF 100000000000000ll
#define pb push_back
int n;
char s[30],ig;
vector<int> v;
int main()
{
	scanf("%d",&n);
	scanf("%c",&ig);
	for(int t=0;t<n;t++)
	{
		ll ans=INF;
		v.clear();
		//for(int i=0;i<30;i++)s[i]='\0';
		fgets(s,sizeof(s),stdin);
		int len=strlen(s);
		for(int i=0;i<len;i++)if('0'<=s[i]&&s[i]<='9')v.pb(s[i]-'0');
		int sz=v.size();
		if(sz==2)
		{
			printf("%d\n",v[1]-v[0]);
			continue;
		}
		if(sz%2==0)
		{
			ll ans=INF;
			for(int i=1;i<sz;i++)
			{
				if(v[i-1]==0)continue;
				vector<int> vec;
				for(int j=0;j<sz;j++)if(j!=i&&j!=i-1)vec.pb(v[j]);
				ll v1=v[i],v2=v[i-1];
				//for(int i=0;i<vec.size();i++)printf("%d ",vec[i]);
				for(int i=0;i<(sz/2)-1;i++)
				{
					v1*=10;
					v1+=vec[i];
				}
				for(int i=vec.size()-1;i>=(sz/2)-1;i--)
				{
					v2*=10;
					v2+=vec[i];
				}
				//printf("%lld %lld\n",v1,v2);
				ans=min(ans,v1-v2);
			}
			printf("%lld\n",ans);
		}
		else
		{
			if(v[0]==0)swap(v[0],v[1]);
			int b=(sz+1)/2;
			ll v1=0,v2=0;
			for(int i=0;i<b;i++)
			{
				v1*=10;
				v1+=v[i];
			}
			for(int i=sz-1;i>=b;i--)
			{
				v2*=10;
				v2+=v[i];
			}
			printf("%lld\n",v1-v2);
		}
	}
	return 0;
}
