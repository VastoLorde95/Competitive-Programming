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

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);
#define fi first
#define se second

using namespace std;

string name, n1, n2;
int n, cnt, x, y, p[100][100];
string word;
vector<string> action, ppl;
map<string, int> ind;


vector<string> split(string x){
	string tmp = "";
	int l = x.length();
	vector<string> w;
	
	for(int i = 0; i < l; i++){
		if(x[i] != ' ')
			tmp += x[i];
		else{
			w.push_back(tmp);
			tmp = "";
		}
	}
	w.push_back(tmp);
	
	return w;
}

int main(){
	cin>> name;
	cin>> n;
	getline(cin, word);
	ind[name] = 0;
	cnt++;
	
	for(int i = 0; i < n; i++){
		getline(cin, word);
		action = split(word);
		if(action.size() == 4){
			n1 = action[0];
			n2 = action[2].substr(0, action[2].length()-2);
			
			if(ind.find(n1) != ind.end()){
				x = ind[n1];
			}
			else{
				ind[n1] = cnt++;
				x = ind[n1];	
				ppl.push_back(n1);			
			}
			
			if(ind.find(n2) != ind.end()){
				y = ind[n2];
			}
			else{
				ind[n2] = cnt++;
				y = ind[n2];	
				ppl.push_back(n2);			
			}
			
			p[x][y] += 5;
			p[y][x] += 5;
		}
		
		else{
			if(action[1] == "posted"){
				n1 = action[0];
				n2 = action[3].substr(0, action[3].length()-2);
			
				if(ind.find(n1) != ind.end()){
					x = ind[n1];
				}
				else{
					ind[n1] = cnt++;
					x = ind[n1];
					ppl.push_back(n1);				
				}
			
				if(ind.find(n2) != ind.end()){
					y = ind[n2];
				}
				else{
					ind[n2] = cnt++;
					y = ind[n2];	
					ppl.push_back(n2);			
				}
			
				p[x][y] += 15;
				p[y][x] += 15;
			}
			else{
				n1 = action[0];
				n2 = action[3].substr(0, action[3].length()-2);
			
				if(ind.find(n1) != ind.end()){
					x = ind[n1];
				}
				else{
					ind[n1] = cnt++;
					x = ind[n1];	
					ppl.push_back(n1);			
				}
			
				if(ind.find(n2) != ind.end()){
					y = ind[n2];
				}
				else{
					ind[n2] = cnt++;
					y = ind[n2];	
					ppl.push_back(n2);			
				}
			
				p[x][y] += 10;
				p[y][x] += 10;
			}
		}
		
		//cout << n1 << " " << n2 << endl;
		
	}
	
	//cout << cnt << endl;
	
	vector<pair<int, string> > s;
	
	
	for(int i = 1; i < cnt; i++){
		
		//cout << p[0][i] << " " << ppl[i-1] << endl;
		s.push_back(make_pair(-p[0][i], ppl[i-1]));
	}
	
	sort(s.begin(), s.end());
	
	for(int i = 0; i < s.size(); i++){
		cout<< s[i].se << endl;
	}
		
	return 0;
}
