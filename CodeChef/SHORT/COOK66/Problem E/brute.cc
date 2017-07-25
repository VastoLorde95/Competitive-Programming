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

int t;
string a, b, c;

int ispalindrome(string &s){
	int l = s.length();
	for(int i = 0, j = l-1; i < j; i++, j--){
		if(s[i] != s[j]) return 0;
	}
	return 1;
}

int main(){ _
	cin >> t;
	while(t--){
		cin >> a >> b >> c;
		int l1 = a.length();
		int l2 = b.length();
		int l3 = c.length();
		
		int cnt = 0;
		
		for(int i = 0; i < l1; i++){
			for(int j = 0; j < l2; j++){
				for(int k = 0; k < l3; k++){
					for(int x = 1; x <= l1-i; x++){
						string p = a.substr(i,x);
						for(int y = 1; y <= l2-j; y++){
							string q = b.substr(j,y);
							for(int j = 1; j <= l3-k; j++){
								string r = p+q+c.substr(k,j);
								if(ispalindrome(r)){
									cnt++;
									tr(p,q,c.substr(k,j));
								}
								
							}
						}
					}	
				}
			}
		}
		
		printf("%d\n", cnt);
		
	}
	
	return 0;
}
