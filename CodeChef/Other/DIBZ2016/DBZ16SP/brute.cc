// There is nothing in a caterpillar that tells you its going to be a butterfly --------------------- !
#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll  long long int
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define f first
#define mp make_pair
#define mod 1000000007
#define s second
#define pb push_back
 
vector<pi>g[100011];
ll d[100011];
ll dp[100011]={0};
vector<int>P[100011];
ll inc[100011];
ll K;
ll calc(ll a,ll b){
    if(a<b) swap(a,b);
    double r=(double)K/ (double)a;
    if(b>=r) return K+1;
    return a*b;
}
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    int u,v;
    char c;
    cin >> N >> M >> K;
    rep(i,M){
        cin >> u >> v >> c;
        g[u].pb({v,c-'a'});
        g[v].pb({u,c-'a'});
    }
    rep(i,N+1) d[i]=1e18;
    queue<int>q;
    q.push(N);
    int t;
    d[N]=0;
    while(q.size()){
        t=q.front();
        q.pop();
        for(auto x:g[t]){
            if(d[x.f]>d[t]+1){
                q.push(x.f);
                d[x.f]=d[t]+1;
            }
        }
    }
    assert(d[1]!=1e18);
    for(int i=1;i<=N;i++){
        if(d[i]<=N){
            P[d[i]].pb(i);
        }
    }
    vector<pi>state;
    state.pb({1,1});
    int cur=0;
    string s="";
    dp[N]=1;
 
    for(int i=1;i<=d[1];i++){
        for(auto x:P[i]){
            for(auto y:g[x]){
                if(d[y.f]==i-1){
                    dp[x]+=dp[y.f];
                    if(dp[x]>K) dp[x]=K+1;
                }
            }
        }
        if(P[i].size()==0){
            cout<<-1<<endl;
            return 0;
        }
    }
 
    if(dp[1]<K){
        cout<<-1<<endl;
        return 0;
    }
 
    while(cur!=d[1]){
        ll sum=0;
        set<pi>ns;
        rep(c,26){
            ll tot=0;
            for(auto x:state){
                for(auto u:g[x.f]){
                    if(d[u.f]==d[x.f]-1 and u.s==c){
                        tot+=calc(dp[u.f],x.s);
                        if(tot>K) tot=K+1;
                    }
                }
            }
 
            if(tot>=K){
                s+=char(c+'a');
                for(auto x:state){
                    for(auto u:g[x.f]){
                        if(d[u.f]==d[x.f]-1 and u.s==c){
                            ns.erase({u.f,inc[u.f]});
                            inc[u.f]+=x.s;
                            if(inc[u.f]>=K) inc[u.f]=K+1;
                            ns.insert({u.f,inc[u.f]});
                        }
                    }
                }
                state.clear();
                state=vector<pi>(ns.begin(),ns.end());
                break;
            }
            K-=tot;
        }
        cur++;
    }
    cout<<s<<endl;
    return 0;
}
