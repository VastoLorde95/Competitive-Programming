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

const int N = 200100;

int n, m;
int a[N];
int f[N];

set<int> d;

int main(){ _
	cin >> n >> m;
	
	int e = 0, o = 0;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] % 2 == 0) e++; else o++;
	}
	
	int x = 1, y = 2;
	
	for(int i = 0; i < n; i++){
		if(d.count(a[i])){
			f[i] = 1;
			
			if(a[i] % 2 == 0){
				if(e > o){
					while(d.count(x)) x += 2;
					d.insert(x);
					a[i] = x;
					
					if(x > m){
						cout << -1 << endl;
						return 0;
					}
					
					e--;
					o++;
				}
				else{
					while(d.count(y)) y += 2;
					d.insert(y);
					a[i] = y;
					
					if(y > m){
						cout << -1 << endl;
						return 0;
					}
				}
			}
			else{
				if(o > e){
					while(d.count(y)) y += 2;
					d.insert(y);
					a[i] = y;
					
					if(y > m){
						cout << -1 << endl;
						return 0;
					}
					
					e++;
					o--;
				}
				else{
					while(d.count(x)) x += 2;
					d.insert(x);
					a[i] = x;
					
					if(x > m){
						cout << -1 << endl;
						return 0;
					}
				}
			}
			
			d.insert(a[i]);
		}
		else{
			d.insert(a[i]);
		}
	}
	
	if(o == e){
		int cnt = 0;
		for(int i = 0; i < n; i++){
			cnt += f[i];
		}
		
		cout << cnt << endl;
		for(int i = 0; i < n; i++){
			cout << a[i] << ' ';
		}
		cout << endl;
		
		return 0;
	}

	

	for(int i = 0; i < n and o != e; i++){
		if(f[i]){
			if(o > e and a[i] % 2 == 1){
				while(d.count(y)) y += 2;
				d.insert(y);
				if(y > m){
					cout << -1 << endl;
					return 0;
				}
				
				a[i] = y;
				
				o--;
				e++;
			}
			else if(o < e and a[i] % 2 == 0){
				while(d.count(x)) x += 2;
				d.insert(x);
				if(x > m){
					cout << -1 << endl;
					return 0;
				}
				
				a[i] = x;
				o++;
				e--;
			}
		}
	}	
	
	if(o != e){
		for(int i = 0; i < n; i++){
			if(!f[i]){
				if(o > e and a[i] % 2 == 1){
					f[i] = 1;
					while(d.count(y)) y += 2;
					d.insert(y);
					if(y > m){
						cout << -1 << endl;
						return 0;
					}
				
					a[i] = y;
				
					o--;
					e++;
				}
				else if(o < e and a[i] % 2 == 0){
					f[i] = 1;
					while(d.count(x)) x += 2;
					d.insert(x);
					if(x > m){
						cout << -1 << endl;
						return 0;
					}
				
					a[i] = x;
					o++;
					e--;
				}
			}
		}
	}
	
	int cnt = 0;
	for(int i = 0; i < n; i++){
		cnt += f[i];
	}
	
	cout << cnt << endl;
	
	for(int i = 0; i < n; i++){
		cout << a[i] << ' ';
	}
	cout << endl;
	
	return 0;
}
