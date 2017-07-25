#include <bits/stdc++.h>

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
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define func __FUNCTION__
#define line __LINE__

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

const int N = 5010;

string s;
int grundy[N], n;
set<int> m;

int mex(){
	int cnt = 0;
	while(m.count(cnt)) cnt++;
	return cnt;
}


int main(){ _
	cin >> s;
	n = s.length();
	
	for(int i = 1; i <= n; i++){
		m.clear();
		for(int j = 1; j <= i; j++){
			int l1 = max(j-2,0);
			int l2 = max(i-j-1,0);
			m.insert(grundy[l1]^grundy[l2]);
		}
		grundy[i] = mex();
	}
	
	vector<pair<int, int> > l;
	int st = -1, e = -1;
	for(int i = 1; i < n-1; i++){
		if(s[i-1] == s[i+1]){
			if(st == -1) st = e = i;
			else e++;
		}
		else if(st != -1){
			l.pb(mp(st,e));
			st = e = -1;
		}
	}
	
	if(st != -1){
		l.pb(mp(st,e));
	}
	
	int x = 0;
	
	foreach(it, l){
		x ^= grundy[(it->se - it->fi + 1)];
	}
	
	if(x){
		puts("First");
		foreach(it, l){
			int a = it->fi, b = it->se;
			int y = (x^grundy[b-a+1]);
			int l = b-a+1;
			for(int i = 1; i <= l; i++){
				int l1 = max(0, i-2);
				int l2 = max(0, l-i-1);
				if((grundy[l1]^grundy[l2]^y) == 0){
					printf("%d\n", a+i);
					return 0;
				}
			}
		}
		
	}
	else{
		puts("Second");
	}
	
	return 0;
}
