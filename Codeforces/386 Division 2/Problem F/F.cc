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

int n, w, k;

int a[N];
int t[N];
int t2[N];

set<pii> q;

int main(){ _
	cin >> n >> w >> k;

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(int i = 0; i < n; i++){
		cin >> t[i];
		t2[i] = (t[i] + 1) / 2;
	}

	int mx = 0;
	int i = 0;
	while(i < n and t2[i] > k) i++;
	
	if(i == n){
		cout << 0 << endl;
		return 0;
	}

	int tot = 0;
	int cur = 0;
	
	int j = i;
	
	tot = t2[i];
	cur = a[i];
	
	q.insert(mp(t2[i], i));
	i++;
	
	mx = cur;
	
	while(i < n){
		
		tr(cur, tot, i);
		while(tot + t2[i] > k and j < i){
			if(q.count(mp(t2[j], j))){
				tot -= t2[j];
				cur -= a[j];
			}
			else{
				tot -= t[j];
				cur -= a[j];
			}
			j++;
		}
		
		if(tot + t2[i] > k){
			i++;
			continue;
		}
		else{
			q.insert(mp(t2[i], i));
			
			tot += t2[i];
			cur += a[i];
			
			if(q.size() > w){
				auto it = *q.begin();
				q.erase(it);
				
				if(it.se == i){
					tot -= t2[i];	
					cur -= a[i];
					
					while(j < i and tot + t[i] > k){
						if(q.count(mp(t2[j], j))){
							tot -= t2[j];
							cur -= a[j];
						}
						else{
							tot -= t[j];
							cur -= a[j];
						}
						j++;
					}
					
					if(tot + t[i] > k){
						i++;
						continue;
					}
					
					tot += t[i];
					cur += a[i];
					
					mx = max(mx, cur);
					i++;
					continue;
				}
				else{				
					tot -= t2[it.se];
					tot += t[it.se];
					
					tot -= t2[i];
					cur -= a[i];
				}
			}
			else{
				mx = max(mx, cur);
				i++;
			}
		}
	}
	
	cout << mx << endl;

	return 0;
}
