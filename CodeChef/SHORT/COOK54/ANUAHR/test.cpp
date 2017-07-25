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
     
    int t, n, m, min_b[100010], min_l[100010], m_b, m_l, removed[100010], cnt;
    pair<long long, pair<long long, int> > p1, p2;
    vector<pair<long long, pair<long long, int> > > v1, v2;
    long long l, b;
     
    int main(){
    sd(t);
    while(t--){
    sd2(n,m);
    v1.clear(); v2.clear(); cnt = 0;
    for(int i = 0; i < n; i++){
    scanf("%lld%lld",&l,&b);
    p1 = make_pair(l, make_pair(b,i)); //sort by smallest l
    p2 = make_pair(b, make_pair(l,i)); //sort by smallest b
    v1.push_back(p1);
    v2.push_back(p2);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for(int i = 0; i < n; i++) removed[i] = 0;
    int ptr1 = 0, ptr2 = 0;
    while(ptr1 != n-1 and ptr2 != n-1 and cnt < m){
    if(removed[v1[ptr1].se.se] == 1){
    ptr1++; continue;
    }
    if(removed[v2[ptr2].se.se] == 1){
    ptr2++; continue;
    }
    if(v1[ptr1].se.se == v2[ptr2].se.se){
    removed[v1[ptr1].se.se] = 1;
    cnt++; ptr1++; ptr2++;
    continue;
    }
    long long a1 = (v1[ptr1].fi * v2[ptr2 + 1].fi);
    long long a2 = (v2[ptr2].fi * v1[ptr1 + 1].fi);
    if(a1 > a2){
    removed[v2[ptr2].se.se] = 1;
    ptr2++;
    cnt++;
    }
    else{
    removed[v1[ptr1].se.se] = 1;
    ptr1++;
    cnt++;
    }
    }
    cout<<(v1[ptr1].fi*v2[ptr2].fi)<<endl;
    }
    return 0;
    } 
