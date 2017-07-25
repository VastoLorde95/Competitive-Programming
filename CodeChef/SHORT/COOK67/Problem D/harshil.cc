#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll  long long int
#define pi pair<ll,ll>
#define pii pair<pi,pi>
#define f first
#define mp make_pair
#define mod 1000000007
#define s second
#define pb push_back
string s;
  int L;
  vector<vector<int> > P;
  vector<pair<pair<int,int>,int> > M;
 
  void build() {
    L=s.length();
    P.push_back(vector<int>(L, 0));
    M.resize(L);
    for (int i = 0; i < L; i++) P[0][i] = int(s[i]);
    for (int skip = 1, level = 1; skip < L; skip *= 2, level++) {
      P.push_back(vector<int>(L, 0));
      for (int i = 0; i < L; i++)
	M[i] = make_pair(make_pair(P[level-1][i], i + skip < L ? P[level-1][i + skip] : -1000), i);
      sort(M.begin(), M.end());
      for (int i = 0; i < L; i++)
	P[level][M[i].second] = (i > 0 && M[i].first == M[i-1].first) ? P[level][M[i-1].second] : i;
    }
  }
 
  vector<int> GetSuffixArray() { return P.back(); }
 
  // returns the length of the longest common prefix of s[i...L-1] and s[j...L-1]
  int LongestCommonPrefix(int i, int j) {
    int len = 0;
    if (i == j) return L - i;
    for (int k = P.size() - 1; k >= 0 && i < L && j < L; k--) {
      if (P[k][i] == P[k][j]) {
	i += 1 << k;
	j += 1 << k;
	len += 1 << k;
      }
    }
    return len;
  }
 
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    string sr;
    while(t--){
        int n,k;
        cin >> n >> k;
        cin >> s;
        sr=s;
        reverse(sr.begin(),sr.end());
        s+='$';
        s+=sr;
        build();
        ll st,ed;
        ll ans=0;
        rep(i,n){
            // odd length
            st=i;
            ed=2*n-i;
 
            rep(kk,k+1){
                if(st<0 or ed<=n) break;
                ll lo=0;
                ll hi=min(st,2*n-ed)+1;
                int mid;
                while(hi-lo>1){
                    mid=(hi+lo)/2;
                    if(LongestCommonPrefix(st-mid,ed-mid)>=mid) lo=mid;
                    else hi=mid;
                }
                st-=lo;
                st--;
                ed-=lo;
                ed--;
            }
            st++;
            ed--;
            ans+=(ll) (i-st+1)*(i-st+1);
 
            // even length
            st=i+1;
            ed=2*n-i;
            rep(kk,k+1){
                if(st<0 or ed<=n) break;
                int lo=0;
                int hi=min(st,2*n-ed)+1;
                int mid;
                while(hi-lo>1){
                    mid=(hi+lo)/2;
                    if(LongestCommonPrefix(st-mid,ed-mid)>=mid) lo=mid;
                    else hi=mid;
                }
                st-=lo;
                st--;
                ed-=lo;
                ed--;
            }
            st++;
            ed--;
            ans+=(ll) (i-st+1)*(i-st+2);
        }
        P.clear();
        M.clear();
        cout<<ans<<"\n";
    }
}
