    #include <iostream>
    #include <algorithm>
     
    using namespace std;
     
    bool isSubsetSum (long long int arr[], long long int n, long long int sum)
    {
    // Base Cases
    if (sum == 0)
    return true;
    if ((n == 0 || arr[n-1]==0) && sum!=0)
    return false;
    // If last element is greater than sum, then ignore it
    if (arr[n-1] > sum)
    return isSubsetSum (arr, n-1, sum);
    /* else, check if sum can be obtained by any of the following
    (a) including the last element
    (b) excluding the last element
    */
    else
    {
    if(isSubsetSum (arr, n-1, sum-arr[n-1]))
    {
    arr[n-1]=0;
    return true;
    }
    else return isSubsetSum (arr, n-1, sum);
    }
    }
    
    
    int main() {
    long long int t,e = 0,n,k;cin>>t;
    while(++e <= t)
    {
    cin>>n;
    k = 3;
    long long int a[n],sum=0;
    for(long long int i=0;i<n;i++)
    {
    cin>>a[i];
    sum+=a[i];
    }
    if(k==1)
    {
    cout<<"Case "<<e<<": Happy Eid Day"<<endl;
    continue;
    }
    else if(n<k)
    {
    cout<<"Case "<<e<<": Lov-e Pap Pap-e Polti"<<endl;
    continue;
    }
    if(sum%k!=0)
    {
    cout<<"Case "<<e<<": Lov-e Pap Pap-e Polti"<<endl;
    continue;
    }
    else
    {
    long long int m=sum/k,flag=0,count=0;
    for(long long int i=0;i<n;i++)
    {
    if(a[i]>m)
    {
    flag=1;
    break;
    }
    else if(a[i]==m)
    {
    a[i]=0;
    count++;
    }
    }
    if(flag==1)
    {
    cout<<"Case "<<e<<": Lov-e Pap Pap-e Polti"<<endl;
    continue;
    }
    flag=0;
    for(long long int i=0;i<k-count;i++)
    {
    sort(a,a+n);
    if(isSubsetSum(a,n,m)==false)
    {
    flag=1;break;
    }
    }
    if(flag==1)
    {
    cout<<"Case "<<e<<": Lov-e Pap Pap-e Polti"<<endl;
    continue;
    }
    else
    {
    cout<<"Case "<<e<<": Happy Eid Day"<<endl;
    continue;
    }
    }
    //e++;
    //cout<<e<<endl;
    }
    return 0;
    } 

