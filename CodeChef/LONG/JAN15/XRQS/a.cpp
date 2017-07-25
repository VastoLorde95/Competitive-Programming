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
	int m, a[100000], type, l, r, x, k, ind = 0, ma, ans, c;
	vector<int> n;
	cin>>m;
	for(int i = 0; i < m; i++){
		cin>>type;
		if(type == 0){
			cin>>x;
			a[ind] = x;
			ind++;
		}
		else if(type == 1){
			cin>>l>>r>>x;
			ma = 0;
			//cout<<"type 1 "<<l<<" "<<r<<" "<<x<<endl;
			for(int j = l-1; j < r; j++){
				//cout<<a[j]<<" "<< (a[j]^x) <<" ";
				if((a[j]^x) > ma){
					ma = a[j]^x;
					ans = a[j];
				}
			}
			//cout<<endl;
			cout<<ans<<endl;
		}
		else if(type == 2){
			cin>>k;
			ind -= k;
		}
		else if(type == 3){
			cin>>l>>r>>x;
			c = 0;
			for(int j = l-1; j < r; j++){
				if(a[j] <=  x){
					c++;
				}
			}
			cout<<c<<endl;
		}
		else{
			cin>>l>>r>>k;
			n.clear();
			for(int j = l-1; j < r; j++){
				n.push_back(a[j]);	
			}
			sort(n.begin(), n.end());
			cout<<n[k-1]<<endl;
		}
	}
	return 0;
}
