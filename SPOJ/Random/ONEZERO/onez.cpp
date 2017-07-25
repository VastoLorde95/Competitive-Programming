#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<math.h>
#include<queue>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d %d",&x,&y);
#define sd3(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define sull(x) scanf("%ull",&x);
#define print(x) printf("%d\n",x);
#define print2(x,y) printf("%d %d\n",x,y);
#define print3(x,y,z) printf("%d %d %d\n",x,y,z);
#define printull(x) printf("%ull\n",x);

using namespace std;
int t, num, states[10000000], n, i;
queue<int> q, empty;
int bfs(){
	int cur;
	states[1] = 1%num;
	q = empty;
	q.push(1);
	while(!q.empty()){
		cur = q.front();
		//cout<<cur<<endl;
		q.pop();
		if(states[cur] == 0)
			return cur;
		else{
			q.push((cur<<1));
			states[(cur<<1)] = (states[cur]*10)%num;
			q.push((cur<<1) + 1);
			states[((cur<<1) + 1)] = (states[cur]*10 + 1)%num;
		}
	}
	
}

int main(){
	string ans;
	sd(t);
	while(t--){
			sd(num);
			ans = "";
			n = bfs();
			//cout<<n<<endl;
			for(i = 0; i < 32; i++){	
				if((n&(1<<i)) == 0)
					ans = '0' + ans;
				else
					ans = '1' + ans;
			}
			i = 0;	
			while(ans[i] == '0') i++;
			while(i < 32) cout<<ans[i++];
			cout<<endl;
	}
	return 0;
}



