#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--)
		{
		int n,fl=0;
		string s;
		cin>>n>>s;
		char ex = 'H';
		for(int i=0;i<n;i++)
			{
			if(s[i]=='.')
				continue;
			else if(s[i]!=ex)
				{
				cout<<"Invalid"<<endl;
				fl=1;
				break;
				}
			else if(s[i]=='H')
				{
				ex = 'T';
				}
			else
				ex = 'H';
			}
		if(!fl && ex == 'T')
			{
			cout<<"Invalid"<<endl;
			}
		else if(!fl)
			{
			cout<<"Valid"<<endl;
			}
		}
	return 0;
}
