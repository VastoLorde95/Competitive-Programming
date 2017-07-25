#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-10
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	for(int t =0; t < T; t++) {
		int N,M;
		cin >> N >> M;
		vector< vector<int> > G(N);
		vector< vector<long long> > adj(N,vector<long long>(N/60+2,0));
		for(int i =0; i < M; i++) {
			int a,b;
			cin >> a >> b;
			G[--a].push_back(--b);
			G[b].push_back(a);
			adj[a][b/60] ^=1LL<<(b%60);
			adj[b][a/60] ^=1LL<<(a%60);}

		// find triples
		vector< pair<int,int> > cand; // candidate edges
		for(int i = 0; i < N; i++)
			ALL_THE(G[i],it)
				if(*it > i) {
					long long b =0;
					for(int k = 0; k <= N/60; k++) b = b | (adj[i][k] & adj[*it][k]);
					if(b > 0) cand.push_back(make_pair(i,*it));
				}
		
		map< vector<int>, int> triangles;
		ALL_THE(cand,it) {
			vector<int> v;
			for(int i =0; i < N; i++) if(i != it->ff && i != it->ss)
				if((adj[it->ff][i/60]>>(i%60))&(adj[it->ss][i/60]>>(i%60))&1LL) v.push_back(i);
			ALL_THE(v,jt) {
				vector<int> v2 ={*jt,it->ff,it->ss};
				sort(begin(v2),end(v2));
				triangles[v2] =0;}
			}

		// construct the new graph
		int n =0;
		ALL_THE(triangles,it) it->ss =n++;
		vector< vector<int> > G2(n);
		ALL_THE(triangles,it) ALL_THE(triangles,jt) if(jt->ff > it->ff) {
			bool found =false;
			for(int k =0; k < 3; k++) for(int l =0; l < 3; l++) if(it->ff[k] == jt->ff[l] && !found) {
				G2[it->ss].push_back(jt->ss);
				G2[jt->ss].push_back(it->ss);
				found = true;}
			}

		// minimum edge cover
		vector<int> act; // active vertices
		vector<bool> proc(n,false); // processed vertices
		vector<int> cost(1,0), ord(n,n+1);
		
		for(int k = 0; k < n; k++) {
			int v =-1, dv =n+1;
			for(int i = 0; i < n; i++) {
				if(!proc[i] && !G2[i].empty()) {
					int d = n+1;
					ALL_THE(G2[i],it) d = min(d,ord[*it]);
					if(d <= dv) dv =d, v =i;
				}
			}
			
			if(v == -1) break;
			ord[v] = k;

			vector<int> cov(1 << G2[v].size(), 0), pe(1 << G2[v].size(), 0);
			
			for(int e = 0; e < (1 << G2[v].size()); e++) {
				for(int i = 0; i < (int) G2[v].size(); i++) if((e>>i)&1)
					for(int j = 0; j < (int) act.size(); j++) if(act[j] == G2[v][i]) {
						cov[e] += 1 << j;
						pe[e]++;
					}
				if(pe[e] > 0) cov[e] += 1 << act.size();
			}

			int l = act.size();
			vector<int> cost_nw(1<<(l+1),n+1);
			for(int i = 0; i < (1<<l); i++) 
				for(int e = 0; e < (1<<G2[v].size()); e++) 
					cost_nw[i|cov[e]] =min(cost_nw[i|cov[e]],cost[i]+pe[e]);
			cost = cost_nw;
			
			// compress
			act.push_back(v);
			proc[v] =true;
			vector<int> act_nw,id_nw(l+1,-1);
			for(int i =0; i <= l; i++) {
				int e =0;
				ALL_THE(G2[act[i]],it) if(!proc[*it]) e++;
				if(e > 0) {
					id_nw[i] =act_nw.size(); 
					act_nw.push_back(act[i]);}
				}

			int l2 =act_nw.size();
			cost.resize(1<<l2);
			for(int i =0; i < (1<<(l+1)); i++) {
				int b =0;
				bool ok =true;
				for(int j =0; j <= l; j++) {
					if(id_nw[j] == -1) {
						if(((i>>j)&1) == 0) ok =false;
						continue;}
					b +=((i>>j)&1)<<id_nw[j];}
				if(ok) cost[b] =cost_nw[i];}
			act =act_nw;
		
		}

		for(int i = 0; i < n; i++) if(G2[i].empty()) cost.back()++;

		cout << cost.back() << "\n";
	}
	
	return 0;
}

// look at my code
// my code is amazing
