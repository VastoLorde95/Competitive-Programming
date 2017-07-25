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

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int main(){ _
	int x, y, z, x1, y1, z1, a[6], sum = 0;
	cin >> x >> y >> z;
	cin >> x1 >> y1 >> z1;
	for(int i = 0; i < 6; i++) cin >> a[i];
	
	if(y < 0) sum += a[0];
	else if(y > y1) sum += a[1];
	
	if(z < 0) sum += a[2];
	else if(z > z1) sum += a[3];
	
	if(x < 0) sum += a[4];
	else if(x > x1) sum += a[5];
	
	printf("%d\n",sum);
	
	return 0;
}
