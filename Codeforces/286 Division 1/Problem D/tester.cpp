// Enjoy your stay.
 
#include <bits/stdc++.h>
 
#define EPS 1e-9
#define INF 1070000000LL
#define MOD 1000000007LL
#define fir first
#define foreach(it,X) for(auto it=(X).begin();it!=(X).end();it++)
#define ite iterator
#define mp make_pair
#define mt make_tuple
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define pb push_back
#define sec second
#define sz(x) ((int)(x).size())
 
using namespace std;
 
typedef istringstream iss;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef stringstream sst;
typedef vector<ll> vi;
 
const int N = 100010;
 
//
int par_uf[N],rank_uf[N];
 
void init(int n){
for(int i = 0; i < n; i++){
par_uf[i] = i;
rank_uf[i] = 0;
}
}
int find(int x){
if(par_uf[x] == x)return x;
else return par_uf[x] = find(par_uf[x]);
}
void unite(int x, int y){
x=find(x); y=find(y);
if(x == y) return;
if(rank_uf[x] < rank_uf[y]) par_uf[x] = y;
else{
par_uf[y]=x;
if(rank_uf[x] == rank_uf[y]) rank_uf[x]++;
}
}
bool same(int x, int y){
return find(x) == find(y);
}
//
 
int n, m, q, qa[N], qb[N];
vector< pair<int,int> > edge[N];
vector< vector<int> > comp;
vector<int> appear[N];
 
const int B = 450;
vector<int> big;
int bigID[N];
int table[B+10][N];
 
int used[N];
vector<int> temp[N];
 
int main(){
cin.tie(0);
ios_base::sync_with_stdio(0);
 
cin >> n >> m;
rep(i, m){
int a, b, c;
cin >> a >> b >> c;
a--; b--; c--;
edge[c].pb(mp(a, b));
}
cin >> q;
rep(i, q){
cin >> qa[i] >> qb[i];
qa[i]--; qb[i]--;
}
 
init(n);
rep(c, N){
rep(i, sz(edge[c])){
int a = edge[c][i].fir, b = edge[c][i].sec;
unite(a, b);
}
rep(i, sz(edge[c])){
int a = edge[c][i].fir, b = edge[c][i].sec;
if(!used[a]){
temp[find(a)].pb(a);
used[a] = 1;
}
if(!used[b]){
temp[find(b)].pb(b);
used[b] = 1;
}
}
rep(i, sz(edge[c])){
int a = edge[c][i].fir, b = edge[c][i].sec;
if(sz(temp[a]) > 0){
comp.pb(temp[a]);
temp[a].clear();
}
if(sz(temp[b]) > 0){
comp.pb(temp[b]);
temp[b].clear();
}
used[a] = 0;
used[b] = 0;
par_uf[a] = a;
par_uf[b] = b;
rank_uf[a] = 0;
rank_uf[b] = 0;
}
}
 
rep(i, sz(comp)){
rep(j, sz(comp[i])){
appear[comp[i][j]].pb(i);
}
}
rep(i, n){
if(sz(appear[i]) > B){
bigID[i] = sz(big);
big.pb(i);
}else{
bigID[i] = -1;
}
}
 
rep(i, sz(big)){
int b = big[i];
rep(j, sz(appear[b])){
int c = appear[b][j];
rep(k, sz(comp[c])){
table[i][comp[c][k]]++;
}
}
}
 
rep(_,q){
int a = qa[_], b = qb[_];
if(bigID[a] == -1){
swap(a, b);
}
if(bigID[a] != -1){
cout << table[bigID[a]][b] << endl;
}else{
int cur1 = 0, cur2 = 0, res = 0;
while(cur1 < sz(appear[a]) && cur2 < sz(appear[b])){
if(appear[a][cur1] == appear[b][cur2]){
res++;
cur1++;
cur2++;
}else if(appear[a][cur1] < appear[b][cur2]){
cur1++;
}else{
cur2++;
}
}
cout << res << endl;
}
}
}
