#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 3001;
const int M = 41;
 
bitset<N> f[N], tmp;
vector<int> g[N];
 
vector<pair<pair<int, int>, int> > tr;
vector<int> what[N];
 
int ans;
 
int rem_v[N], rem_t[M];

int tv;

void go(int pos, int cnt) {
  if(cnt + (tr.size() - tv + 1) / 2 >= ans) return;

  if (pos == tr.size()) {
    ans = min(ans, cnt);
    return;
  }
 
  if (rem_t[pos]) {
    go(pos + 1, cnt);
    return;
  }
 
  int a = tr[pos].first.first;
  int b = tr[pos].first.second;
  int c = tr[pos].second;
 
  vector<int> two;
  if (what[a].size() == 2 and !rem_t[what[a][0]] and !rem_t[what[a][1]]) {
	two.push_back(a);
  }
  
  if (what[b].size() == 2 and !rem_t[what[b][0]] and !rem_t[what[b][1]] and what[b] != what[a]) {
    two.push_back(b);
  }
	
  if (what[c].size() == 2 and !rem_t[what[c][0]] and !rem_t[what[c][1]] and what[c] != what[a] and what[c] != what[b]) {
    two.push_back(c);
  }  
 
  if (two.size() == 0) two.push_back(c);
 
  for (int &x : two) {
    rem_v[x] = true;
    for (int &t : what[x]){
      if(++rem_t[t] == 1) ++tv;
    }
    go(pos + 1, cnt + 1);
    for (int &t : what[x])
      if(--rem_t[t] == 0) --tv;
    rem_v[x] = false;
  }
}
 
void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    g[i].clear(), f[i].reset(), what[i].clear();
  }
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    g[--a].push_back(--b);
    f[a].set(b, 1);
    f[b].set(a, 1);
  }

  tr.clear();
  for (int i = 0; i < n; ++i) {
    for (int &u : g[i]) {
      tmp = f[i] & f[u];
      if (tmp.count() > 0) {
        for (int j = max(i, u) + 1; j < n; ++j) {
          if (tmp.test(j)) {
            what[i].push_back(tr.size());
            what[u].push_back(tr.size());
            what[j].push_back(tr.size());
            tr.push_back({{i, u}, j});
          }
        }
      }
    }
  }

  ans = tr.size();
  memset(rem_v, 0, sizeof(rem_v));
  memset(rem_t, 0, sizeof(rem_t));
  
  tv = 0;
  go(0, 0);
  printf("%d\n", ans);
}
 
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
