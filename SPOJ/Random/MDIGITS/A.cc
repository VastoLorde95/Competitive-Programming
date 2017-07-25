#include<bits/stdc++.h>
typedef int64_t q;q a,b,d,B,f=10;q s(q x,q l,q p){if(p>x)return 0;B=x/p%10;return(p/f*l*B)+(p*(d<B))+((x%p+1)*(d==B))+s(x,l+1,p*f);}int main(){while(std::cin>>a>>b)if(a){if(a>b)std::swap(a,b);for(d=0;d<f;d++)std::cout<<s(b,0,1)-s(a-1,0,1)<<" \n"[d==9];}return 0;}
