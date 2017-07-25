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

priority_queue<ll> k1, k2;
priority_queue<ll> w1, w2;

int main(){ _
	int n;
	cin >> n;
	
	ll m = 0;
	
	for(int i = 0; i < n; i++){
		int w, c;
		cin >> w >> c;
		if(w == 1) w1.push(c);
		else w2.push(c);
		
		m += w;
	}

	if(w1.empty()){
		ll cur = 0;
		
		for(int i = 1; i <= m; i++){
			if(i%2 == 0){
				cur += w2.top();
				w2.pop();
			}
			cout << cur << ' ';
		}
		
		cout << endl;
		
		return 0;
	}

	ll cur = w1.top();
	w1.pop();

	k1.push(-cur);
	int cap = 1;

	cout << cur << ' ';

	int inf = 1e9;
	for(int i = 2; i <= m; i++){
		int del1 = 0, del2 = 0;
		
		if(!w1.empty()){
			del1 = w1.top();
		}
		
		if(i - cap == 1){
			if(!w2.empty() and !k1.empty()){
				int val1 = -k1.top();
				int val2 = w2.top();
			
				del2 = val2 - val1; 
			}
		}
		else{
			if(!w2.empty()){
				del2 = w2.top();
			}
		}
		
		if(max(del1, del2) <= 0){
			cout << cur << ' ';
			continue;
		}
		
		if(del1 >= del2){
			k1.push(-w1.top()); w1.pop();
			cap++;
		}
		else{
			if(i-cap == 1){
				k2.push(w2.top()); w2.pop();
				w1.push(-k1.top()); k1.pop();
				cap++;
			}
			else{
				k2.push(w2.top()); w2.pop();
				cap += 2;
			}
		}
		
		cur += max(del1, del2);
		cout << cur << ' ';
	}

	cout << endl;
	
	return 0;
}
