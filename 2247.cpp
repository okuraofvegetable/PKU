#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define pb push_back
vector<ll> vec;
int main()
{
	vec.pb(1ll);
	int sz=vec.size();
	for(int i=0;i<sz;i++)
	{
		ll cur=vec[i]*2;
		while(cur<=2000000000ll)
		{
			vec.pb(cur);
			cur*=2;
		}
	}
	sz=vec.size();
	for(int i=0;i<sz;i++)
	{
		ll cur=vec[i]*3;
		while(cur<=2000000000ll)
		{
			vec.pb(cur);
			cur*=3;
		}
	}
	sz=vec.size();
	for(int i=0;i<sz;i++)
	{
		ll cur=vec[i]*5;
		while(cur<=2000000000ll)
		{
			vec.pb(cur);
			cur*=5;
		}
	}
	sz=vec.size();
	for(int i=0;i<sz;i++)
	{
		ll cur=vec[i]*7;
		while(cur<=2000000000ll)
		{
			vec.pb(cur);
			cur*=7;
		}
	}
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(!n)break;
		if(n%10==1&&(n%100)!=11)printf("The %dst humble number is %lld.\n",n,vec[n-1]);
		else if(n%10==2&&(n%100)!=12)printf("The %dnd humble number is %lld.\n",n,vec[n-1]);
		else if(n%10==3&&(n%100)!=13)printf("The %drd humble number is %lld.\n",n,vec[n-1]);
		else printf("The %dth humble number is %lld.\n",n,vec[n-1]);
	}
	return 0;
}
