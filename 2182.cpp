#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int n;
int a[8010];
int ans[8010];
vector<int> s;
int get(int p)
{
	int l=1,r=n+1;
	vector<int>::iterator it;
	while(r-l>1)
	{
		int mid=(l+r)/2;
		int k=lower_bound(s.begin(),s.end(),mid)-s.begin();
		k++;
		if(k>p)r=mid;
		else l=mid;
	}
	it=lower_bound(s.begin(),s.end(),l);
	s.erase(it);
	return l;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)scanf("%d",&a[i+1]);
	for(int i=1;i<=n;i++)s.push_back(i);
	for(int i=n-1;i>=0;i--)ans[i]=get(a[i]+1);
	for(int i=0;i<n;i++)printf("%d\n",ans[i]);
	return 0;
}
