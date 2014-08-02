#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char s[256];
int main()
{
	s['S']='A';
	s['D']='S';
	s['F']='D';
	s['G']='F';
	s['H']='G';
	s['J']='H';
	s['K']='J';
	s['L']='K';
	s[';']='L';
	s['\'']=';';
	s['W']='Q';
	s['E']='W';
	s['R']='E';
	s['T']='R';
	s['Y']='T';
	s['U']='Y';
	s['I']='U';
	s['O']='I';
	s['P']='O';
	s['[']='P';
	s[']']='[';
	s['\\']=']';
	s['X']='Z';
	s['C']='X';
	s['V']='C';
	s['B']='V';
	s['N']='B';
	s['M']='N';
	s[',']='M';
	s['.']=',';
	s['/']='.';
	s['1']='`';
	s['2']='1';
	s['3']='2';
	s['4']='3';
	s['5']='4';
	s['6']='5';
	s['7']='6';
	s['8']='7';
	s['9']='8';
	s['0']='9';
	s['-']='0';
	s['=']='-';
	char c;
	while(scanf("%c",&c)!=EOF)
	{
		if(c==' '||c=='\n')printf("%c",c);
		else printf("%c",s[c]);
	}
	printf("\n");
	return 0;
}

