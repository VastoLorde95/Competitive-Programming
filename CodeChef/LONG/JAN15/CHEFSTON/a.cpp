#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<utility>
#include<math.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

using namespace std;	

int main(){
	ios_base::sync_with_stdio(false);
	int t, n, k;
	long long m, a[100000], b[100000];
	cin>>t;
	while(t--){
		cin>>n>>k;
		m = 0;
		for(int i = 0; i < n; i++) cin>>a[i];
		
		for(int i = 0; i < n; i++){
			cin>>b[i];
			if((k/a[i])*b[i] > m){
				m = (k/a[i])*b[i];
			}
		}
		cout<<m<<endl;
	}	
	return 0;
}
