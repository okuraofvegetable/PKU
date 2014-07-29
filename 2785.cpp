#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
int n;
int A[4010],B[4010],C[4010],D[4010];
vector<int> AB,CD;
int ans=0;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d %d %d %d",&A[i],&B[i],&C[i],&D[i]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			AB.pb(A[i]+B[j]);
			CD.pb(C[i]+D[j]);
		}
	}
	sort(AB.begin(),AB.end());
	sort(CD.begin(),CD.end());
	for(int i=0;i<AB.size();i++)
	{
		ans+=upper_bound(CD.begin(),CD.end(),0-AB[i])-lower_bound(CD.begin(),CD.end(),0-AB[i]);
	}
	printf("%d\n",ans);
	return 0;
}
