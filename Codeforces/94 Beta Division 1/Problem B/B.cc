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


class priortise
{
public:
    bool operator()(const pair<string, int> &p1,const pair<string, int> &p2)
    {
        return p1.first > p2.first;
    }
};

priority_queue<pair<string, int>, vector<pair<string, int> >, priortise > q;
string s;
long long n, k;

int main(){ _
	cin >> s;
	cin >> k;
	n = s.length();
	
	if(k > (n*(n+1))/2){
		puts("No such line.");
		return 0;
	}
	
	for(int i = 0; i < n; i++){
		string tmp = "";
		tmp +=  s[i];
		q.push(mp(tmp, i+1));
	}
	
	while(!q.empty()){
		pair<string,int> p = q.top(); q.pop();
		k--;
		if(k == 0){
			cout << p.fi << "\n";
			return 0;
		}
		if(p.se < n){
			p.fi += s[p.se];
			p.se = p.se + 1;
			q.push(p);
		}
	}
		
	return 0;
}
