#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N,S;
int L[20010];
int main()
{
	scanf("%d %d",&N,&S);
	for(int i=0;i<N;i++)scanf("%d",&L[i]);
	sort(L,L+N);
	int ans = 0;
	for(int i=0;i<N;i++)
	{
		ans += upper_bound(L,L+N,S-L[i])-L;
		if(L[i]*2<=S)ans--;
	}
	printf("%d\n",ans/2);
	return 0;
}
