#include <cstdio>
using namespace std;
double a[10000];
int main()
{
	int n=0;
	while(1)
	{
		scanf("%lf",&a[n]);
		if(a[n]==999)break;
		n++;
	}
	for(int i=0;i<n-1;i++)printf("%.2f\n",a[i+1]-a[i]);
	printf("End of Output\n");
	return 0;
}
