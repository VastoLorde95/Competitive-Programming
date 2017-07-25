    #include <cstdio>
    #include <iostream>
    #include <cmath>
    #include <algorithm>
    #include <cstring>
    #include <map>
    #include <set>
    #include <vector>
    #include <utility>
    #include <queue>
    #include <stack>
     
    #define sd(x) scanf("%d",&x)
    #define sd2(x,y) scanf("%d%d",&x,&y)
    #define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
     
    #define fi first
    #define se second
    #define pb(x) push_back(x)
    #define mp(x,y) make_pair(x,y)
    #define LET(x, a)  __typeof(a) x(a)
    #define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
     
    #define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
     
    #define tr(x) cout<<x<<endl;
    #define tr2(x,y) cout<<x<<" "<<y<<endl;
    #define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
    #define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
    #define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
    #define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
     
    using namespace std;
     
    int t, n;
    vector<pair<pair<int,int>, int > > v;
     
    int main(){
    	sd(t);
    	while(t--){
    		sd(n);
    		
    		int maxx = -1e9, minx = 1e9, maxy = -1e9, miny = 1e9;
    		
    		v.clear();
    		
    		for(int i = 0; i < n; i++){
    			int x, y; sd2(x,y);
    			maxx = max(maxx, x);
    			minx = min(minx, x);
    			maxy = max(maxy, y);
    			miny = min(miny, y);
    			v.pb(mp(mp(x,y),i+1));
    		}
    		
    		if(n == 1){
    			printf("1\n");
    			printf("1 NE\n"); continue;
    		}
    		
    		sort(v.begin(), v.end());
    		
    		bool ok = false;		
    				
    		for(int i = 0; i < n; i++){
    			if(v[i].fi.fi == minx and v[i].fi.se == miny){
    				printf("1\n");
    				printf("%d NE\n", v[i].se);
    				ok = true;
    				break;
    			}
    			else if(v[i].fi.fi == minx and v[i].fi.se == maxy){
    				printf("1\n");
    				printf("%d SE\n", v[i].se);
    				ok = true;
    				break;
    			}
    			else if(v[i].fi.fi == maxx and v[i].fi.se == miny){
    				printf("1\n");
    				printf("%d NW\n", v[i].se);
    				ok = true;
    				break;
    			}
    			else if(v[i].fi.fi == maxx and v[i].fi.se == maxy){
    				printf("1\n");
    				printf("%d SW\n", v[i].se);
    				ok = true;
    				break;
    			}
    		}
    		
    		if(!ok){
    			int i1 = v[0].se, i2 = v[n-1].se;
    			
    			if(maxx == minx){
    				printf("1\n");
    				printf("%d NE\n",i1);
    			}
    			else if(miny == maxy){
    				printf("1\n");
    				printf("%d NE\n",i1);
    			}
    			else{
    				printf("2\n");
    				if(v[0].fi.se > v[n-1].fi.se){
    					printf("%d SE\n", i1);
    					printf("%d NW\n", i2);
    				}
    				else{
    					printf("%d NE\n", i1);
    					printf("%d SW\n", i2);
    				}
    			}
    			
    		}
    		
    	}
    	return 0;
    } 
