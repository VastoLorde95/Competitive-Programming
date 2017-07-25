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

const int N = 1010;

// z[i] = the length of the longest substring of 's' starting at index 'i' which is at the same time a prefix of the string 's'
// l, r are the invariant variables => [l,r] is the maximum interval such that s[l,r] is a prefix substring
void build_z(string &s, int *z){
	int len = s.length(), l = 0, r = 0, k;
	z[0] = len;
	
	for(int i = 1; i < len; i++){
		if(r < i){
			// make a new interval l,r and find the substring starting at i which is a prefix substring
			l = r = i; 
			while(r < len and s[r-l] == s[r]) r++;
			z[i] = r-l; r--;
		}
		else{
			// try to expand the current interval by observing the value of z[k]
			k = i-l;
			if(z[k] < r-i+1){
				// can't be more than z[k] since s[i..R] matches with s[k...z[k]]
				z[i] = z[k];
			}
			else{
				// we can expand the current r since z[k] allows us to do so
				l = i;
				while(r < len and s[r-l] == s[r]) r++;
				z[i] = r-l; r--;
			}
		}
	}
	return;	
}

int t;
string a, b, c;

int p[N][N], q[N];

int z1[N][N];
int z2[N][N];
int z3[N][N];

int bc[N];
int ba[N];

int main(){ _
	cin >> t;
	while(t--){
		cin >> a >> b >> c;
		
		int l1 = a.length();
		int l2 = b.length();
		int l3 = c.length();
		
		memset(p, 0, sizeof p);
		
		long long cnt1 = 0, ans = 0;
		
		for(int i = 0; i < l2; i++){
			p[i][i] = 1;
			cnt1++;
			if(i+1 < l2 and b[i] == b[i+1]){
				p[i][i+1] = 1;
				cnt1++;
			}
		}
		
		for(int i = 3; i <= l2; i++){
			for(int j = 0; j+i-1 < l2; j++){
				if(b[j] == b[j+i-1] and p[j+1][j+i-2] == 1){
					p[j][j+i-1] = 1;
					cnt1++;
				}
			}
		}
		
		string tc = c;
		reverse(tc.begin(), tc.end());
		
		string tb = b;
		reverse(tb.begin(), tb.end());
		
		string ta = a;
		reverse(ta.begin(), ta.end());
		
		// Case 1
		memset(z1, 0, sizeof z1);
		for(int i = 1; i <= l1; i++){
			string suf = a.substr(l1-i,i);
			suf = suf + "$" + tc;
			build_z(suf, z1[i]);
			
			for(int j = i+1; j < i+l3+1; j++){
				ans += cnt1*z1[i][j];
			}
		}
		
		tr("#",ans);

		// q[i] = number of substrings starting at i+1 in B such that they are palindromes
		memset(q, 0, sizeof q);
		for(int i = 0; i < l2; i++){
			q[i] = 1;
			for(int j = i+1; j < l2; j++){
				q[i] += p[i+1][j];
			}
		}
		
		for(int i = l2-1; i >= 0; i--){
			q[i] += q[i+1];
		}
		
		// Case 2
		memset(z2, 0, sizeof z2);
		memset(bc, 0, sizeof bc);
		for(int i = 1; i <= l2; i++){
			string suf = b.substr(l2-i,i);
			suf = suf + "$" + tc;
			build_z(suf, z2[i]);
			for(int j = i+1; j < i+l3+1; j++){
				int k = z2[i][j];
				if(k == 0) continue;
				
				int id = (l3-1)-(j-i-1);
				int bid1 = (l2-i+k);
				int bid2 = (l2-i);
				bc[id] += q[bid2] - q[bid1];
			}
		}
		
		memset(z3, 0, sizeof z3);
		for(int i = 1; i <= l3; i++){
			string suf = c.substr(l3-i, i);
			suf = suf + "$" + ta;
			build_z(suf, z3[i]);
			for(int j = i+1; j < i+l1+1; j++){
				int k = z3[i][j];
				
				int id = l3-i;
				if(id > 0){
					ans += (long long) bc[id-1] * k;
				}
			}
		}
		
		tr("#",ans);

		memset(q, 0, sizeof q);
		for(int i = 0; i < l2; i++){
			q[i] = 1;
			for(int j = 0; j < i; j++){
				q[i] += p[j][i-1];
			}
		}
		
		for(int i = 1; i < l2; i++){
			q[i] += q[i-1];
		}

		// Case 3
		memset(z2, 0, sizeof z2);
		memset(ba, 0, sizeof ba);
		for(int i = 1; i <= l1; i++){
			string suf = a.substr(l1-i,i);
			suf = suf + "$" + tb;
			build_z(suf, z2[i]);
			
			for(int j = i+1; j < i+l2+1; j++){
				int k = z2[i][j];
				if(k == 0) continue;
				
				int id = l1-i;
				int bid1 = (l2-1) - (j-i-1);
				int bid2 = bid1-k+1;
				ba[id] += (bid2-1 >= 0)? q[bid1] - q[bid2-1] : q[bid1];
			}
		}
		
		for(int i = 0; i < l1; i++){
			tr(i, ba[i]);
		}
		
		memset(z3, 0, sizeof z3);
		for(int i = 1; i <= l3; i++){
			string suf = c.substr(l3-i, i);
			suf = suf + "$" + ta;
			build_z(suf, z3[i]);
			
			for(int j = i+1; j < i+l1+1; j++){
				int k = z3[i][j];
				int id = (l1-1) - (j-i-1);
				if(id+1 < l1){
					ans += (long long) ba[id+1] * k;
				}
			}
		}
		
		cout << ans << endl;
	}
	return 0;
}
