#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int num[110];
int rem[110];
vector<int> v;
int N,T;
bool found;
void dfs(int x,int sum)
{
	//printf("%d %d\n",x,sum);
	if(sum==T)
	{
		found=true;
		bool first=true;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<(num[v[i]]-rem[v[i]]);j++)
			{
				if(first)
				{
					printf("%d",v[i]);
					first=false;
					continue;
				}
				printf("+%d",v[i]);
			}
		}
		puts("");
		return;
	}
	if(x==N||sum>T)return;
	for(int i=rem[v[x]];i>=0;i--)
	{
		rem[v[x]]-=i;
		dfs(x+1,sum+v[x]*i);
		rem[v[x]]+=i;
	}
	return;
}
int main()
{
	while(1)
	{
		v.clear();
		found = false;
		memset(num,0,sizeof(num));
		memset(rem,0,sizeof(rem));
		scanf("%d %d",&T,&N);
		if(T==0&&N==0)break;
		for(int i=0;i<N;i++)
		{
			int k;
			scanf("%d",&k);
			num[k]++;
			rem[k]++;
			v.push_back(k);
		}
		sort(v.begin(),v.end(),greater<int>());
		v.erase(unique(v.begin(),v.end()),v.end());
		N=v.size();
		printf("Sums of %d:\n",T);
		dfs(0,0);
		if(!found)printf("NONE\n");
	}
	return 0;
}

