#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

string s;
int f[1000001], l;
int m[1000001];

void build(){
	f[0] = f[1] = 0;
	int j;
	for(int i = 2; i <= l; i++){
		j = f[i-1];
		while(true){
			if(s[j] == s[i-1]){
				f[i] = j+1; break;	// match found, next char to match is j+1
			}
			else if(j == 0){
				f[i] = 0; break; // no match found
			}
			j = f[j];	// try next prefix/suffix
		}
	}
	return;	
}

int match(){
	for(int i = 0, j = 1; j < l;){
		if(s[j] == s[i]){
			j++, i++;
			if(j == l){
				while(i > 0 and m[i] == 0){
					i = f[i];
				}
				return i;
			}
			m[i] = 1;
		}
		else if(i > 0) i = f[i];
		else j++;
	}
	return 0;
}

int main(){ _
	cin >> s;
	l = s.length();
	
	build();
	
	int x = match();
	
	if(x == 0) puts("Just a legend");
	else{
		cout << s.substr(0,x) << "\n";
	}
	return 0;
}
