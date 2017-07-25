#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

const int MAXN=2147483647;

int mtr[6][6]={
	0,1,2,3,4,5,
	0,4,1,2,3,5,
	0,3,4,1,2,5,
	0,2,3,4,1,5,
	1,2,0,4,5,3,
	3,2,5,4,0,1
};

int i,j,k,n,m,t,x,y,ans,cnt;
char a[10],b[10];
string s,ts;
map<string,int> mp;

// LFTBDR

void rotate4()
{
	char t;
	t=b[0];
	b[0]=b[1];
	b[1]=b[5];
	b[5]=b[3];
	b[3]=t;
}

void putInMap(string s)
{
	int i,j,k;
	for (i=0;i<6;i++)//the ith case
	{
		for (j=0;j<6;j++)//the jth cell
		{
			b[j]=s[mtr[i][j]];
		}
		for (k=0;k<4;k++)
		{
			ts=b;
			mp[ts]=ans;
			
			cout << b << endl;
			
			rotate4();
		
		}
	}
	
}

int main()
{
	while (~scanf("%s",&a))
	{
		sort(a,a+6);
		mp.clear();
		ans=1;
		s=a;
		putInMap(s);
		while (next_permutation(a,a+6))
		{
			s=a;
			if (mp.find(s)==mp.end())
			{
				ans++;
				putInMap(s);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
