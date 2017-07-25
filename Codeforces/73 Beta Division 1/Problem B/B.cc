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

int n;
string operation, a, b;

map<string, pair<string, pair<int, int> > > dict;

string strip(string s, int &x, int &y){
	int l = s.length(); string ret = "";
	
	for(int i = 0; i < l; i++){
		if(s[i] == '&') x++;
		else if(s[i] == '*') y++;
		else ret += s[i];
	}
	
	if(dict.count(ret)){
		x += dict[ret].se.fi;
		y += dict[ret].se.se;
	}
	
	if(x > y) return "errtype";
	
	y -= x;
	x = 0;
	
	if(dict.count(ret)) return dict[ret].fi;
	else if(ret == "void") return ret;
	else return "errtype";
	
}

int main(){ _
	cin >> n;
	while(n--){
		cin >> operation;
		if(operation == "typedef"){
			cin >> a >> b;
			int cnt1 = 0, cnt2 = 0;
			a = strip(a, cnt1, cnt2);
			if(a == "errtype"){
				dict[b] = mp(a,mp(0,0));
			}
			else{
				dict[b] = mp(a,mp(cnt1,cnt2));
			}
		}
		else{
			cin >> a;
			int cnt1 = 0, cnt2 = 0;
			string output = strip(a, cnt1, cnt2);
		
			if(output == "errtype" or cnt1 > cnt2){
				cout << "errtype\n";
			}
			else{
				cnt2 -= cnt1;
				cout << output;
				for(int i = 0; i < cnt2; i++) cout << "*";
				cout << "\n";
			}
			
		}
	}
	return 0;
}
