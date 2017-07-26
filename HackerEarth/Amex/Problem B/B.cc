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

typedef pair<int, pii> triple;

#define fst first
#define snd second.first
#define thd second.second

triple add(triple &t1, triple &t2){
	return mp((t1.fst + t2.fst)/2, mp((t1.snd + t2.snd)/2, (t1.thd + t2.thd)/2));
}

double diff(triple &t1, triple &t2){
	double total = pow(abs(t1.fst - t2.fst),2) + pow(abs(t1.snd - t2.snd),2) + pow(abs(t1.thd - t2.thd),2);
	
	return sqrt((double) total / 3.0f);
}


int main(){
	int n; sd(n);

	int x1, y1, x2, y2;
	double scale;
	
	scanf("%d %d %d %d %lf", &x1, &y1, &x2, &y2, &scale);
	
	n -= x1 * y1;
	n /= x2 * y2;
	
	vector<vector<triple> > image(x1);
	for(int i = 0; i < x1; i++){
		image[i].resize(y1);
	}
		
	for(int i = 0; i < x1; i++){
		for(int j = 0; j < y1; j++){
			int x, y, r, g, b;
			sd2(x,y);
			sd3(r,g,b);
			image[x][y] = mp(r,mp(g,b));
		}
	}
	
	vector<vector<triple> > temp(x2);
	for(int i = 0; i < x2; i++){
		temp[i].resize(y2);
	}
	
	for(int tcase = 0; tcase < n; tcase++){
		for(int i = 0; i < x2; i++){
			for(int j = 0; j < y2; j++){
				int x, y, r, g, b;
				sd2(x,y);
				sd3(r,g,b);
				temp[x][y] = mp(r,mp(g,b));
			}
		}
		
		if(scale < 1){
			int x3 = ceil(scale * x1);
			int y3 = ceil(scale * y1);
			vector<vector<triple> > nimage(x3);
			for(int i = 0; i < x3; i++) nimage[i].resize(y3);
			
			assert(x3 != 0 and y3 != 0);
			
			for(int i = 0; i < x3; i++){
				for(int j = 0; j < y3; j++){
					double xd = (double) i / scale;
					double yd = (double) j / scale;
					
					int lx = floor(xd), ux = min((int)ceil(xd), x1-1);
					int ly = floor(yd), uy = min((int)ceil(yd), y1-1);

					nimage[i][j] = image[lx][ly];
//					nimage[i][j] = add(image[lx][ly], image[lx][uy]);
//					nimage[i][j] = add(nimage[i][j], image[ux][ly]);
//					nimage[i][j] = add(nimage[i][j], image[ux][uy]);
				}
			}
			
			bool found = false;
			for(int i = 0; i + x3 - 1 < x2; i++){
				for(int j = 0; j + y3 - 1 < y2; j++){
					double del = 0;
					for(int t1 = 0; t1 < x3; t1++){
						for(int t2 = 0; t2 < y3; t2++){
							del += diff(nimage[t1][t2], temp[i+t1][j+t2]);
						}
					}
					
					if (del <= 0.2f * x3 * y3 * 255){
						found = true;
						printf("Y\n");
						printf("%d %d\n", i, j);
						j = 100000000;
						i = 100000000;
						break;
					}
				}
			}

//			assert(found == false);
			assert(x3 * y3 > 0);
						
			if(!found){
				puts("N");
			}
			
		}
		else{
			int x3 = scale * x1;
			int y3 = scale * y1;
			vector<vector<triple> > nimage(x3);
			for(int i = 0; i < x3; i++) nimage[i].resize(y3);
			
			for(int i = 0; i < x3; i++){
				for(int j = 0; j < y3; j++){
					double xd = (double) i / scale;
					double yd = (double) j / scale;
					
					int lx = floor(xd), ux = min((int)ceil(xd), x1-1);
					int ly = floor(yd), uy = min((int)ceil(yd), y1-1);
					
					nimage[i][j] = add(image[lx][ly], image[lx][uy]);
				}
			}

			
			bool found = false;
			for(int i = 0; i + x3 - 1 < x2; i++){
				for(int j = 0; j + y3 - 1 < y2; j++){
					double del = 0;
					for(int t1 = 0; t1 < x3; t1++){
						for(int t2 = 0; t2 < y3; t2++){
							del += diff(nimage[t1][t2], temp[i+t1][j+t2]);
						}
					}
					
					if (del <= 0.001f * x3 * y3 * 255){
						found = true;
						printf("Y\n");
						printf("%d %d\n", i, j);
						j = 100000000;
						i = 100000000;
						break;
					}
				}
			}
			
			if(!found){
				puts("N");
			}
			
		}
		
	}
	
	return 0;
}
