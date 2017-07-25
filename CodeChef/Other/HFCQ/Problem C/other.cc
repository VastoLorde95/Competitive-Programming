    #include <bits/stdc++.h>
     
    #define sd(x) scanf("%d",&x)
    #define sd2(x,y) scanf("%d%d",&x,&y)
    #define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
     
    #define fi first
    #define se second
    #define pb push_back
    #define mp make_pair
    #define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it != (v).end(); ++it)
    #define meta __FUNCTION__,__LINE__
     
    #define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
     
    using namespace std;
     
    template<typename S, typename T> 
    ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}
     
    template<typename T>
    ostream& operator<<(ostream& out,vector<T> const& v){
    int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}
     
    void tr(){cout << endl;}
    template<typename S, typename ... Strings>
    void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}
     
    typedef long long ll;
    typedef pair<int,int> pii;
     
    const ll MOD = 1e9 + 7;
    ll dp[110][201][101][3];
     
    ll go(int score, int r, int f, int cnt){
    	ll &ret = dp[score][r][f][cnt];
    	if(ret != -1) return ret;
    	
    	if(r == 0 or score >= 100){
    		if(score >= 100)
    			ret = 1;
    		else
    			ret = 0;
    		return ret;
    	}
    	
    	ret = 0;
    	
    	ret += go(score + 1, r-1, f, 0);
    	ret += go(score + 2, r-1, f, 0);
    	ret += go(score + 4, r-1, f, 0);
    	ret += go(score + 6, r-1, f, 0);
    	if(cnt < 2){
    		ret += go(score, r-1, f, cnt+1);
    	}
    	
    	if(f > 0){
    		ret += go(score, r, f-1, cnt);
    		ret += go(score + 1, r, f-1, cnt);
    		ret += go(score + 2, r, f-1, cnt);
    		ret += go(score + 4, r, f-1, cnt);
    		ret += go(score + 6, r, f-1, cnt);
    	}

		ret %= MOD;
    	
    	return ret;
    }
     
    void solve(){
    	int b, n; sd2(b, n);
    	for(int i = 0; i < 110; i++){
    		for(int j = 0; j <= b; j++){
    			for(int k = 0; k <= n; k++){
    				for(int l = 0; l < 3; l++){
    					dp[i][j][k][l] = -1;
    				}
    			}
    		}
    	}
    	
    	printf("%lld\n", go(0, b, n, 0));
    	
    }
     
    int main(){
    	int t; sd(t);
    	while(t--) solve();	
    	return 0;
    }
