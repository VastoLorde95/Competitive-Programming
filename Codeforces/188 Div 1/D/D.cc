#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

const ld PI = 3.1415926535897932384626433832795;

map<int, int> s;
unordered_set<int> done;

const int N = 30;

int gr[N];

int main(){ _
	int n;
	cin >> n;
	
	int lim = 1;
	while(lim * lim <= n) lim++;
	lim--;
	
	int tot = 0;
	for(int i = 2; i <= lim; i++){
		if(done.count(i)) continue;
		
		int len = 1;
		ll num = i;
		done.insert(i);		
		
		while(num * i <= n){
			num *= i;
			done.insert(num);
			len++;
		}
		
		s[len] ^= 1;
		tot += len;
	}
	
	int res = (n - tot) % 2;
	
	gr[0] = 0;
	gr[1] = 1;
	gr[2] = 2;
	gr[3] = 1;
	gr[4] = 4;
	gr[5] = 3;
	gr[6] = 2;
	gr[7] = 1;
	gr[8] = 5;
	gr[9] = 6;
	gr[10] = 2;
	gr[11] = 1;
	gr[12] = 8;
	gr[13] = 7;
	gr[14] = 5;
	gr[15] = 9;
	gr[16] = 8;
	gr[17] = 7;
	gr[18] = 3;
	gr[19] = 4;
	gr[20] = 7;
	gr[21] = 4;
	gr[22] = 2;
	gr[23] = 1;
	gr[24] = 10;
	gr[25] = 9;
	gr[26] = 3;
	gr[27] = 6;
	gr[28] = 11;
	gr[29] = 12;
	
	foreach(it, s){
		if(it->se){
			res ^= gr[it->fi];
		}
	}
	
	if(res) cout << "Vasya\n";
	else cout << "Petya\n";
	
	return 0;
}
