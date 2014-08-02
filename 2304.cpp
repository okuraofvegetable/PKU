#include <cstdio>
using namespace std;
int a,b,c,d;
//ダイヤルを左に回すと番号は右向きにまわる
void solve()
{
	int res=120;
	if(a<b)res+=a+40-b;
	else res+=a-b;
	if(b>c)res+=c+40-b;
	else res+=c-b;
	if(c<d)res+=c+40-d;
	else res+=c-d;
	printf("%d\n",res*9);
	return;
}
int main()
{
	while(1)
	{
		scanf("%d %d %d %d",&a,&b,&c,&d);
		if(a==0&&b==0&&c==0&&d==0)break;
		solve();
	}
	return 0;
}
