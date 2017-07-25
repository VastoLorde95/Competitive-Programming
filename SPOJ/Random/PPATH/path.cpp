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
#include<stack>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d %d",&x,&y);
#define sd3(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define sull(x) scanf("%ull",&x);
#define print(x) printf("%d\n",x);
#define print2(x,y) printf("%d %d\n",x,y);
#define print3(x,y,z) printf("%d %d %d\n",x,y,z);
#define printull(x) printf("%ull\n",x);

using namespace std;

map<int, vector<int> > graph;
int primes[9000], temp;
int inf = 1000000;
int shortest(int p1, int p2){
	int dist[10000];
	int visited[10000];
	int prev[10000];
	int x;
	stack<int> q;
	for(int i = 168; i <= 1228; i++){
		if(primes[i] != p1){
			dist[primes[i]] = inf;
			prev[primes[i]] = inf;
		}
		q.push(primes[i]);
	}
	while(!q.empty()){
		x = q.top();
		q.pop();
		visitied[x] = 1;
		for(int i = 0; i < graph[x].size(); i++){
			
		}
	}
	
}
int main(){
	int flag;
	temp = 1;
	primes[0] = 2;
	for(int i = 3; i < 10000; i+=2){
		flag  = 0;
		for(int j = 0; j < temp; j++){
			if(i%primes[j] == 0){
				j = temp; 
				flag = 1;
			}
		}
		if(flag == 0){
			primes[temp] = i;
			temp++;
		}
	}
	for(int i = 168; i <= 1228; i++){
		for(int j = i + 1; j <= 1228; j++){
			if(primes[j]/1000 == primes[i]/1000 or (primes[j]/100)%10 == (primes[i]/100)%10 or (primes[j]/10)%10 == (primes[i]/10)%10 or primes[j]%10 == primes[i]%10){
				graph[primes[i]].push_pack(primes[j]);
			}
		}
	}
	int t, p1, p2;
	sd(t);
	while(t--){
		sd2(p1,p2);
		printf("%d\n",shortest(p1,p2));
	}
	return 0;
}
