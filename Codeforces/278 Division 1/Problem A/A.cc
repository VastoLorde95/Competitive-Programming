#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int h1, a1, d1;
int h2, a2, d2;
int t1, t2;
int h, a, d, cost = 1000000000;

int main(){
	sd3(h1, a1, d1);
	sd3(h2, a2, d2);
	sd3(h, a, d);
	
	t1 = (a2 <= d1)? 1000000000: ceil((double)(h1)/(double)(a2-d1));
	t2 = (a1 <= d2)? 1000000000: ceil((double)(h2)/(double)(a1-d2));
	
	if(t1 > t2) cout<<0<<endl;
	else{
		for(int j = 0; j <= 200; j++){
			for(int k = 0; k <= 200; k++){
				if(a1+j > d2){
					int i = max(0, ((int)(ceil((double)(h2)/ (double)(a1+j-d2))) * (a2-d1-k)) +1- h1);
					cost = min(i*h + j*a + k*d, cost);
				}

			}
		}
		
		cout << cost << endl;	
	}
	
	return 0;
}
