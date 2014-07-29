#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define fi first
#define sec second
#define pb push_back
#define mp make_pair
typedef pair<int,string> P;
string haabmonth[21];
string tzolkinmonth[21];
vector<P> v;
int haabtoday(int day,string month,int year)
{
	int ret=0;
	ret+=365*year;
	for(int i=0;i<19;i++)
	{
		if(haabmonth[i]==month)
		{
			ret+=20*i;
			break;
		}
	}
	ret+=day;
	return ret;
}
void daytotzolkin(int days)
{
	int year,day;
	string month;
	year=days/260;
	days%=260;
	month=v[days].sec;
	day=v[days].fi;
	cout << day << ' ' << month << ' ' << year << '\n';
	return;
}
int main()
{

	haabmonth[0]="pop";
	haabmonth[1]="no";
	haabmonth[2]="zip";
	haabmonth[3]="zotz";
	haabmonth[4]="tzec";
	haabmonth[5]="xul";
	haabmonth[6]="yoxkin";
	haabmonth[7]="mol";
	haabmonth[8]="chen";
	haabmonth[9]="yax";
	haabmonth[10]="zac";
	haabmonth[11]="ceh";
	haabmonth[12]="mac";
	haabmonth[13]="kankin";
	haabmonth[14]="muan";
	haabmonth[15]="pax";
	haabmonth[16]="koyab";
	haabmonth[17]="cumhu";
	haabmonth[18]="uayet";
	tzolkinmonth[0]="imix";
	tzolkinmonth[1]="ik";
	tzolkinmonth[2]="akbal";
	tzolkinmonth[3]="kan";
	tzolkinmonth[4]="chicchan";
	tzolkinmonth[5]="cimi";
	tzolkinmonth[6]="manik";
	tzolkinmonth[7]="lamat";
	tzolkinmonth[8]="muluk";
	tzolkinmonth[9]="ok";
	tzolkinmonth[10]="chuen";
	tzolkinmonth[11]="eb";
	tzolkinmonth[12]="ben";
	tzolkinmonth[13]="ix";
	tzolkinmonth[14]="mem";
	tzolkinmonth[15]="cib";
	tzolkinmonth[16]="caban";
	tzolkinmonth[17]="eznab";
	tzolkinmonth[18]="canac";
	tzolkinmonth[19]="ahau";
	for(int i=0;i<260;i++)v.pb(mp(i%13+1,tzolkinmonth[i%20]));
	int n;
	scanf("%d",&n);
	printf("%d\n",n);
	for(int i=0;i<n;i++)
	{
		int day,year;
		string month,ig;
		cin >> day >> ig >> month >> year;
		daytotzolkin(haabtoday(day,month,year));
	}
	return 0;
}
