#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;
int n;
int a[105];
priority_queue<double> q;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		q.push(a[i]);
	}
	while(q.size()>1)
	{
		double a=q.top();q.pop();
		double b=q.top();q.pop();
		q.push(2*sqrt(a*b));
	}
	printf("%.3f\n",q.top());
	return 0;
}
