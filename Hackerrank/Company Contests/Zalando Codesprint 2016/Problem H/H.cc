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

const long double PI = 3.1415926535897932384626433832795;

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

typedef struct node{
    int prior,size;
    int val;
    struct node *l,*r;
}node;

typedef node* pnode;
int sz(pnode t){
    return t?t->size:0;
}

void upd_sz(pnode t){
    if(t)t->size=sz(t->l)+1+sz(t->r);
}

void split(pnode t,pnode &l,pnode &r,int pos,int add=0){
    if(!t)return void(l=r=NULL);
    int curr_pos = add + sz(t->l);
    if(curr_pos<=pos)
        split(t->r,t->r,r,pos,curr_pos+1),l=t;
    else 
        split(t->l,l,t->l,pos,add),r=t;
    upd_sz(t);
}

void merge(pnode &t,pnode l,pnode r){
    if(!l || !r) t = l?l:r;
    else if(l->prior>r->prior)merge(l->r,l->r,r),t=l;
    else    merge(r->l,l,r->l),t=r;
    upd_sz(t);
}

pnode init(int val){
    pnode ret = new node;
    ret->prior=rand();ret->size=1;
    ret->val=val;
    return ret;
}

pnode root;

int main(){
	int n;
	sd(n);
	
	for(int i = 0; i < n; i++){
		int x; sd(x);
		pnode tmp = init(x);
		if(i == 0) root = tmp;
		else merge(root, root, tmp);
	}
	
	int m; sd(m);
	while(m--){
		int l, r;
		sd2(l,r);
		l--, r--;
				
		pnode left,mid,right;
		
		split(root,left,mid,l-1);
		split(mid,root,right,r - l);
		
		merge(mid,left,right);
		merge(root,root,mid);
	}
	
	for(int i = 1; i < n; i++){
		pnode l, r;
		split(root, l, r, 0);
		
		printf("%d ", l->val);
		root = r;
	}
	printf("%d\n", root->val);
	
	return 0;
}
