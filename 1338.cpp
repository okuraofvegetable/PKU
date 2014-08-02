#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 400000000
vector<int> ugly;
int main()
{
	ugly.push_back(1);
	int sz=ugly.size();
	for(int i=0;i<sz;i++)
	{
		int cur=ugly[i];
		while(cur<=MAX)
		{
			cur*=2;
			ugly.push_back(cur);
		}
	}
	sz=ugly.size();
	for(int i=0;i<sz;i++)
	{
		int cur=ugly[i];
		while(cur<=MAX)
		{
			cur*=3;
			ugly.push_back(cur);
		}
	}
	sz=ugly.size();
	for(int i=0;i<sz;i++)
	{
		int cur=ugly[i];
		while(cur<=MAX)
		{
			cur*=5;
			ugly.push_back(cur);
		}
	}
	sort(ugly.begin(),ugly.end());
	ugly.erase(unique(ugly.begin(),ugly.end()),ugly.end());
	printf("finish.\n");
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)break;
		printf("%d\n",ugly[n-1]);
	}
	return 0;
}
