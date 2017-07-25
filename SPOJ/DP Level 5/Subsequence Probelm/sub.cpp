#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<utility>
#include<map>

#define SD(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define print(x,y,z) printf("%d %d %d\n",x,y,z);
#define print2(x) printf("%d\n",x);
#define SULL(x) scanf("%ull",&x)
#define MOD 1000000007

using namespace std;
int l;
map<pair<char, int>, long long> x;
string inp;
long long recur(char p_c, int i){
		pair<char,int> temp(p_c, i);
		if( i >= l and p_c == ' ')
			return 0;
		else if(i >= l)
			return 1;
		else if(x.find(temp) != x.end())
			return x[temp];
		else{
			if(p_c != ' '){
				if( inp[i] > p_c)
					x[temp] = (recur(inp[i], i + 1) + recur(p_c, i + 1))%MOD;
				else
					x[temp] = recur(p_c, i + 1)%MOD;
			}
			else
				x[temp] = (recur(inp[i], i + 1) + recur(p_c, i + 1))%MOD;
		}
		return x[temp]%MOD;
	}

int main(){
	int t, i = 1;
	cin>>t;
	while(i <= t){
		cin>>inp;
		x.clear();
		l = inp.length();
		cout<<"Case "<<i<<": "<<recur(' ', 0)<<endl;
		i++;
	}
	return 0;
	}
