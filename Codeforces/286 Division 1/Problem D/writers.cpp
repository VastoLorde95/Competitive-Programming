#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
 
 
typedef long long int lint;
typedef pair<int,int> pi;
 
const int N=100005,M=100005,Q=100005;
struct uf{
 
static const int MAXN=2*M;
int par[MAXN];
int size[MAXN];
void init(){
memset(par,-1,sizeof(par));
for(int i=0;i<MAXN;++i) size[i]=1;
}
int root(int a){
if(par[a]==-1) return a;
return par[a]=root(par[a]);
}
void unite(int a,int b){
a=root(a);b=root(b);
if(a==b) return;
if(size[a]<size[b]) swap(a,b);
 
par[b]=a;
size[a]+=size[b];
}
bool same(int a,int b){
return root(a)==root(b);
}
};
 
uf u;
 
int n,m,q;
 
vector<int> adjcol[N];
pair<pi,int> es[M];
int degsum[N];
 
int getpos(const vector<int>& ar,int indx,int c){
return degsum[indx]+lower_bound(ar.begin(),ar.end(),c)-ar.begin();
}
int main(){
cin>>n>>m;
for(int i=0;i<m;++i){
int a,b,c;scanf("%d%d%d",&a,&b,&c);--a;--b;
adjcol[a].push_back(c);
adjcol[b].push_back(c);
 
es[i]=make_pair(make_pair(a,b),c);
}
 
for(int i=0;i<n;++i){
sort(adjcol[i].begin(),adjcol[i].end());
adjcol[i].erase(unique(adjcol[i].begin(),adjcol[i].end()),adjcol[i].end());
degsum[i+1]=degsum[i]+adjcol[i].size();
}
u.init();
for(int i=0;i<m;++i){
int a=es[i].first.first,b=es[i].first.second,c=es[i].second;
int A=getpos(adjcol[a],a,c),B=getpos(adjcol[b],b,c);
u.unite(A,B);
}
 
int q;cin>>q;
 
map<pi,int> memo;
for(int qcnt=0;qcnt<q;++qcnt){
int a,b;scanf("%d%d",&a,&b);--a;--b;
int res=0;
if(adjcol[a].size()>adjcol[b].size()){
swap(a,b);
}
 
pi p=make_pair(a,b);
if(memo.count(p)){
res=memo[p];
}else{
for(int i=0;i<adjcol[a].size();++i){
int c=adjcol[a][i];
if(binary_search(adjcol[b].begin(),adjcol[b].end(),c)){
int trg=getpos(adjcol[b],b,c);
if(u.same(trg,degsum[a]+i)){
++res;
}
}
}
memo[p]=res;
}
printf("%d\n",res);
}
return 0;
}
