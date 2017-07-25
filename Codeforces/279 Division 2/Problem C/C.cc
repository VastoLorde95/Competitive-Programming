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
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

string s;
int a, b, l;

int r1[1000000], r2[1000000];

int main(){ _
	cin >> s;	
	cin >> a >> b;
	l = s.length();
	
	if(l == 1){
		cout << "NO\n"; return 0;
	}
	
	r1[0] = (s[0]-'0')%a;
	for(int i = 1; i < l; i++){
		r1[i] = (((r1[i-1]*10)%a) + (s[i]-'0'))%a;
//		tr2(i, r1[i]);
	}	
	
	r2[l-1] = (s[l-1]-'0')%b;
	int p = 1;
	for(int i = l-2; i >= 0; i--){
		p = (p*10)%b;
		r2[i] = (((p*(s[i]-'0'))%b) + r2[i+1])%b;
	}
	
	for(int i = 0; i < l-1; i++){
		if(r1[i] == 0 and r2[i+1] == 0 and s[i+1] != '0'){
			cout << "YES\n";
			for(int j = 0; j <= i; j++){
				cout <<s[j];
			}
			cout << "\n";
			for(int j = i+1; j < l; j++){
				cout << s[j];
			}
			cout << "\n";
			return 0;
		}
	}
	
	cout << "NO\n";
	return 0;
}
