#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Queue{
    stack<pair<ll,ll> > in, out;
    // First value in the pair is the element and second element
    // is the minimum of all elements below the current element in the stack
   
    void push(ll x){
        if(in.empty())
            in.push(make_pair(x,x));
        else
            in.push(make_pair(x, min(in.top().second, x)));
    }
   
    void pop(){
        if(out.empty()){ // empty in stack into out stack
            ll x = in.top().fi; in.pop();
            out.push(make_pair(x, x));
           
            while(!in.empty()){
                ll x = in.top().fi; in.pop();
                out.push(make_pair(x, min(out.top().second, x)));
            }
        }
       
        out.pop();
    }
   
   	ll getmin(){
        ll mn = 1ll << 60;
        if(!in.empty() and !out.empty())
            mn = min(in.top().second, out.top().second);
        else if(in.empty())
            mn = out.top().second;
        else
            mn = in.top().second;
        return mn;
    }
};

int main(){
	
	return 0;
}
