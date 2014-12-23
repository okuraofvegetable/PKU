#include <cstdio>
#include <cstring>
using namespace std;
int a[10010],b[10010];
int rui[10010];
int n;
//rui[]は累積和 mod n
//rui[i]==0の時、a[0]...a[i]の和がnの倍数なのでok
//どのiでもrui[i]!=0の時、鳩の巣原理よりrui[i]==rui[j]となる組が少なくともひとつある
//その時a[i]...a[j](i<jと仮定)の和がnの倍数。
//したがって、解なしとなることはない
int main()
{
	memset(b,-1,sizeof(b));
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<n;i++)rui[i]=(((i==0)?0:rui[i-1])+a[i])%n;
	for(int i=0;i<n;i++)
	{
		if(rui[i]==0)
		{
			printf("%d\n",i+1);
			for(int j=0;j<=i;j++)printf("%d\n",a[j]);
			break;
		}
		if(b[rui[i]]==-1)b[rui[i]]=i;
		else
		{
			printf("%d\n",i-b[rui[i]]);
			for(int j=b[rui[i]]+1;j<=i;j++)printf("%d\n",a[j]);
			break;
		}
	}
	return 0;
}
