#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
 
#include <cassert>
#include <limits>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#define each(it,o) for(auto it= (o).begin(); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define inrep int t;cin>>t; while(t--)
using namespace std;
 
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii > vpii;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll > vpll;
typedef vector<string> vs;
typedef long double ld;
 
template<typename T> ostream& operator<< ( ostream &o,vector<T> v ) {
    if ( v.size() >0 )
        o<<v[0];
    for ( unsigned   i=1; i<v.size(); i++ )
        o<<" "<<v[i];
    return o<<endl;
}
template<typename U,typename V> ostream& operator<< ( ostream &o,pair<U,V> p ) {
    return o<<"("<<p.first<<", "<<p.second<<") ";
}
template<typename T> istream& operator>> ( istream &in,vector<T> &v ) {
 
    for ( unsigned   i=0; i<v.size(); i++ )
        in>>v[i];
    return in;
}
pii findPerFloyd ( int st, int ( *nxt ) ( int ) ) {
    int a=nxt ( st );
    int b=nxt ( a );
    while ( a!=b ) {
        a=nxt ( a );
        b = nxt ( nxt ( b ) );
    }
    int mu=0;
    a=st;
    while ( a!=b ) {
        a=nxt ( a );
        b=nxt ( b );
        mu++;
    }
    int l=1;
    b=nxt ( a );
    while ( a!=b ) {
        b=nxt ( b );
        l++;
 
    }
    return mp ( mu,l );
}
int a,b,m;
int nxt ( int ind ) {
    return ( ( ll ) a*ind+b ) %m;
}
void showP(int i0, int n, const vi &d){
 rep(i,n){
     cout<<d[i0]<<" ";
     i0=nxt(i0);
 }
 cout<<endl;
}
void showP2(int i0, int n, const vi &d){
 rep(i,n){
     cout<<i0<<" ";
     i0=nxt(i0);
 }
 cout<<endl;
}
int main() {
    ios_base::sync_with_stdio ( false );
    inrep {
        int h;
        cin>>h;
        int n;
        cin>>n>>m;
        n--;
        int i0;
        cin>>a>>b>>i0;
        vi d ( m );
        cin>>d;
        int pst,plen;
        tie ( pst,plen ) =findPerFloyd ( i0,nxt );
        int rem= ( n-pst ) %plen;
        int nper= ( n-pst ) /plen;
        ll a2=0;
        int ind=i0;
        rep ( i,pst ) {
            int d1=d[ind];
            ind=nxt ( ind );
            a2+= ( ll ) h*d1;
        }
        ll aper=0;
        rep ( i,plen ) {
            int d1=d[ind];
            ind=nxt ( ind );
            aper+= ( ll ) h*d1;
        }
        a2+=aper*nper;
        rep ( i,rem ) {
                int d1=d[ind];
                ind=nxt ( ind );
                a2+= ( ll ) h*d1;
            
        }
        cout<<a2/2<<"."<< ( a2&1?5:0 ) <<endl;
    }
 
 
}
