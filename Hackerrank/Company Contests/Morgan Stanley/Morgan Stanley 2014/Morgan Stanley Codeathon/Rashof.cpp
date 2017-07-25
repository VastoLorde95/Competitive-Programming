#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include <queue>
#include<set>
#include<vector>
#include<utility>
#include<math.h>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);

using namespace std;

int t, n, k, x, y, a, b, degree[100001], cur, visited[100001], l;
long long sum, temp2, cont[100001];
vector<int> adj[100001];
vector<long long> repl;
map<pair<int,int>, pair<int,int> > edges;
pair<int,int> temp;
queue<int> q;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    sd(t);
    while(t--){
        sd2(n,k);
        
        edges.clear();
        repl.clear();
        sum = 0;
        for(int i = 1; i <= n; i++){
            degree[i] = 0;
            cont[i] = 1;
            visited[i] = 0;
            adj[i].clear();
        }
        
        for(int i = 1; i < n; i++){
            scanf("%d%d%d%d",&x,&y,&a,&b);
            
            adj[x].push_back(y);
            adj[y].push_back(x);
            degree[x]++;
            degree[y]++;
            edges[make_pair(x,y)] = make_pair(a,b);
            edges[make_pair(y,x)] = make_pair(a,b);
        }
        
        for(int i = 1; i <= n; i++){
            if(degree[i] == 1){
                q.push(i);
            }
        }
        
        while(!q.empty()){
        
            cur = q.front();
            q.pop();
            
            visited[cur] = 1;
            for(int i = 0; i < adj[cur].size(); i++){
                if(visited[adj[cur][i]] == 0){
                
                    degree[adj[cur][i]]--;
                    cont[adj[cur][i]] += cont[cur];
                    
                    temp = edges[make_pair(cur, adj[cur][i])];
                    temp2 = cont[cur]*((long long) n-cont[cur]);
                    
                    sum += temp2*temp.first;
                    
                    if(temp.first >= temp.second)
                    	repl.push_back((temp.first-temp.second)*temp2);
                    
                    if(degree[adj[cur][i]] == 1)
                        q.push(adj[cur][i]);
                }
            }
        }
        
        sort(repl.begin(), repl.end(), greater<long long>());
        
        l = repl.size();
        k = l < k? l : k;
        
        for(int i = 0; i < k; i++){
            if(repl[i] > 0){
                sum -= repl[i];
            }
            else break;
        }
        
        cout<<sum<<endl;
        
    }
    return 0;
}

