#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
using namespace std;
typedef pair<double,int> P;
#define fi first
#define sec second
int n,k;
int v[100100],w[100100];
bool comp(P a,P b)
{
	return a.fi > b.fi;
}
bool C(double x)
{
	vector<double> vec;
	for(int i=0;i<n;i++)vec.push_back(v[i]-w[i]*x);
	sort(vec.begin(),vec.end(),greater<double>());
	double res=0;
	for(int i=0;i<k;i++)res+=vec[i];
	return res>=0.0;
}
void restoration(double x)
{
	vector<P> vec;
	for(int i=0;i<n;i++)vec.push_back(P(v[i]-w[i]*x,i));
	sort(vec.begin(),vec.end(),comp);
	for(int i=0;i<k;i++)
	{
		if(i==k-1)printf("%d\n",vec[i].sec+1);
		else printf("%d ",vec[i].sec+1);
	}
	return;
}
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d %d",&v[i],&w[i]);
	double l=0,r=100000000;
	for(int i=0;i<50;i++)
	{
		double mid=(l+r)/2.0;
		if(C(mid))l=mid;
		else r=mid;
	}
	restoration(l);
	return 0;
}
