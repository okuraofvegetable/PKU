#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;
vector<long long> ugly;
long long MAX;
int main()
{
	// Quote from 1338 solution
	long long p1,p2,p3;
	int n;
	scanf("%lld %lld %lld %d",&p1,&p2,&p3,&n);
	MAX=1e18/(max(p1,max(p2,p2)));
	ugly.push_back(1);
	int sz=ugly.size();
	for(int i=0;i<sz;i++)
	{
		long long cur=ugly[i];
		cur*=p1;
		if(cur<0)break;
		while(cur<=MAX)
		{
			ugly.push_back(cur);
			cur*=p1;
		}
	}
	sz=ugly.size();
	for(int i=0;i<sz;i++)
	{
		long long cur=ugly[i];
		cur*=p2;
		if(cur<0)break;
		while(cur<=MAX)
		{
			ugly.push_back(cur);
			cur*=p2;
		}
	}
	sz=ugly.size();
	for(int i=0;i<sz;i++)
	{
		long long cur=ugly[i];
		cur*=p3;
		if(cur<0)break;
		while(cur<=MAX)
		{
			ugly.push_back(cur);
			cur*=p3;
		}
	}
	//cout << ugly.size() << endl;
	sort(ugly.begin(),ugly.end());
	ugly.erase(unique(ugly.begin(),ugly.end()),ugly.end());
	printf("%lld\n",ugly[n]);
	return 0;
}
