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
	int t, n, b[10000], a[10000], tot, tot2, flag;
	cin>>t;
	while(t--){
		cin>>n;
		tot = 0, tot2 = 0;
		for(int i = 0; i < n; i++){
			cin>>b[i];
			a[i] = (b[i] == 0)?0:b[i]-1;
			tot += b[i];
			tot2 += a[i];
		}
		if(tot >= 100 and tot2 < 100){
			cout<<"YES"<<endl;
		}
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
