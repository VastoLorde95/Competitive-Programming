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
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

struct node{
	node *edge[26];
	int index;
	
	int state;
	
	void setindex(int i){
		index = i;
	}
	void addedge(node* next, int posi){
		edge[posi] = next;
//		tr("this?");
		return;
	}
	node* go(int posi){
		return edge[posi];
	}
	
};	

node *ROOT;

int n, k;
string s;

void insert(node *cur, int pos){
	if(pos == s.length()) return;
	
	node *next = new node;
	for(int i = 0; i < 26; i++) next->edge[i] = NULL;
	
	next->setindex(pos);
	if(cur->go(s[pos]-'a') == NULL){
		cur->addedge(next, (int)(s[pos]-'a'));
		insert(next, pos+1);
	}
	else{
		insert(cur->go(s[pos]-'a'), pos+1);
	}
	return;
}

void build(node* cur, int pos){
	bool last = true;
	
	for(int i = 0; i < 26; i++){
		if(cur->go(i) != NULL){
//			tr2("Going to",char(i+'a'));
			last = false;
			build(cur->go(i), pos+1);
		}
	}
	
	if(last){
//		tr("At leaf");
		if(pos%2 == 0){
			cur->state = 0; // First loses
		}
		if(pos%2 == 1){
			cur->state = 1; // First wins
		}
//		tr(cur->state);
	}
	else{
//		tr2("Exploring children", pos);
		bool a = false, b = false, c = false, d = false;
		for(int i = 0; i < 26; i++){
			node* next = cur->go(i);
			if(next != NULL){
				if(next->state == 0) a = true;
				if(next->state == 1) b = true;
				if(next->state == 2) c = true;
				if(next->state == -2) d = true;
			}
		}
		
		if(pos%2 == 0){
			if((a and b) or c) cur->state = 2;
			else if(a) cur->state = 0;
			else if(b) cur->state = 1;
			else if(d) cur->state = -2;
		}
		else{
			if((a and b) or d) cur->state = -2;
			else if(!c){
				if(a and !b) cur->state = 0;
				else if(!a and b) cur->state = 1;
			}
			else{
				if(!a and !b) cur->state = 2;
				else if(a and !b) cur->state = 0;
				else if(!a and b) cur->state = 1;
			}
		}
//		cout << a << " " << b  << " " <<  c  << " " <<  d  << " " <<  cur->state << endl;
	}
	return;
}

int main(){
	sd2(n, k);
	
	ROOT = new node;
	
	for(int i = 0; i < 26; i++) ROOT->edge[i] = NULL;
	
	for(int i = 0; i < n; i++){
		cin >> s;
		insert(ROOT, 0);
	}
	
	build(ROOT, 0);
	
	int state = ROOT->state;
	
	if(state == 0){
		puts("Second");
	}
	else if(state == 1){
		if(k%2) puts("First");
		else puts("Second");
	}
	else if(state == 2){
		puts("First");
	}
	else{
		puts("Second");
	}
	
	return 0;
}
