#include <bits/stdc++.h>

#define pb push_back
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

const int N = 10 + 1, M = 42 + 1;

int n, sz;

vector<int> tmp;
vector<vector<int> > part;

double m[M][M], f[M];

void GaussianElimination(){
	for(int i = 1; i <= sz; i++){
		int id = i;
		for(int j = i; j <= sz; j++) if(abs(m[j][i]) > abs(m[id][i])) id = j;
		for(int j = 1; j <= sz; j++) swap(m[i][j], m[id][j]);
		swap(f[i], f[id]);
		
		for(int j = i+1; j <= sz; j++){
			double r = m[j][i] / m[i][i];
			for(int k = 1; k <= sz; k++) m[j][k] -= r * m[i][k];
			f[j] -= r * f[i];
		}
	}
	
	for(int i = sz; i > 0; i--){
		for(int j = i+1; j <= sz; j++) f[i] -= m[i][j] * f[j];
		f[i] /= m[i][i];
	}
}

void generate(int tot, int prev){
	if(tot == n){
		part.pb(tmp); return;
	}
	for(int i = prev; i <= n - tot; i++){
		tmp.pb(i);
		generate(tot + i, i);
		tmp.pop_back();
	}
}

vector<int> getCycle(vector<int> &p){
	int vis[N] = {0};
	vector<int> cycle_len;
	for(int i = 1; i < p.size(); i++){
		int x = p[i], len = 0; if(vis[x]) continue;
		do{
			vis[x] = 1, x = p[x], len++;
		} while(x != p[i]);
		cycle_len.pb(len);
	}
	sort(cycle_len.begin(), cycle_len.end());
	return cycle_len;
}

vector<int> getPermutation(vector<int> &cycle_len){
	vector<int> p(n+1);
	int sum = 0;
	foreach(it, cycle_len){
		for(int i = 0; i < *it; i++) p[sum + i + 1] = sum + i + 2;
		p[sum + *it] = sum + 1, sum += *it;
	}
	return p;
}

int getindex(vector<int> &p){
	return upper_bound(part.begin(), part.end(), p) - part.begin();
}

void solve(){
	cin >> n;
	part.clear();
	
	generate(0, 1);
	
	sort(part.begin(), part.end());
	
	sz = part.size();
	
	for(int i = 1; i <= sz; i++){
		for(int j = 1; j <= sz; j++) m[i][j] = 0;
		m[i][i] = f[i] = 1;
	}
	
	vector<int> sorted(n, 1);
	f[getindex(sorted)] = 0;

	for(int i = 0; i < sz; i++){
		vector<int> cycle_len1 = part[i];
		if(cycle_len1.size() == n) continue;
		
		vector<int> p = getPermutation(cycle_len1);
		for(int x = 1; x <= n; x++){
			for(int y = x+1; y <= n; y++){
				swap(p[x], p[y]);
				vector<int> cycle_len2 = getCycle(p);
				m[getindex(cycle_len1)][getindex(cycle_len2)] += (-2.0 / n) / (n-1);
				swap(p[x], p[y]);
			}
		}
	}
	
	GaussianElimination();
	
	vector<int> p(n+1);
	for(int i = 1; i <= n; i++) cin >> p[i];
	vector<int> cycle_len = getCycle(p);
	cout << fixed << setprecision(20) << f[getindex(cycle_len)] << endl;
}

int main(){ _
	int t; cin >> t;
	while(t--) solve();
	return 0;
}
