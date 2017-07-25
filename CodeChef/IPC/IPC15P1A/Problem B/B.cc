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

const long double PI = 3.1415926535897932384626433832795;

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

struct Queue{
    stack<pair<int,int> > in, out;
    void push(int x){
        if(in.empty()) in.push(make_pair(x,x));
        else in.push(make_pair(x, __gcd(in.top().second, x)));
    }
   
    void pop(){
        if(out.empty()){
            int x = in.top().fi; in.pop();
            out.push(make_pair(x, x));
           
            while(!in.empty()){
                int x = in.top().fi; in.pop();
                out.push(make_pair(x, __gcd(out.top().second, x)));
            }
        }
        out.pop();
    }
   
   bool empty(){
        return (in.empty() and out.empty());
   }
   
   	int getgcd(){
        if(!in.empty() and !out.empty()) return __gcd(in.top().second, out.top().second);
        else if(in.empty()) return out.top().second;
        else if(out.empty()) return in.top().second;
        else return -1;
    }
};

const int N = 500100;

int a[N];

int main(){
	int n, k;
	sd2(n,k);

	for(int i = 0; i < n; i++){
		sd(a[i]);
	}	
	
	Queue q = Queue();
	int mx = 0, cur = 0;
	for(int i = 0; i < n; i++){
		q.push(a[i]);
		cur++;
		while(!q.empty() and q.getgcd() < k){
			q.pop();
			cur--;
		}
		
		mx = max(mx, cur);
	}
	
	printf("%d\n", mx);
	
	return 0;
}
