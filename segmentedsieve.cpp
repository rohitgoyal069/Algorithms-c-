#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back 
#define mp make_pair
#define inf 2000000009
using namespace std;
vector<ll> prime;

void sieve()
{
    ll MAX=100009;
    bool f[MAX];
    memset(f,true,sizeof(f));
    f[0]=f[1]=0;

    for(ll i=2;i*i<MAX;i++)
    {
        if(f[i])
        {
            for(ll j=i*i;j<MAX;j+=i)
            f[j]=0;
        }
    }

    for(ll i=2;i<MAX;i++)
        if(f[i])
            prime.pb(i);
}


void  fun(ll l,ll r)
{
    if(l<2)
    l=2;
   vector<bool> ans(r-l+1,true);

       for(ll i=0;prime[i]*prime[i]<=r;i++)
       {
           ll j=(l/prime[i])*prime[i];
           
           if(j<l) j+=prime[i];
           
        for( ll k=j;k<r+1;k+=prime[i])
             ans[k-l]=0;
             
             if(j==prime[i])
             ans[j-l]=1;
       }

       for(ll i=0;i<r-l+1;i++)
        if(ans[i])
            cout<<l+i<<endl;
}


int main()
{  
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

  fast;
    ll t,l,r;
    cin>>t;
    sieve();
    while(t--)
    {
        cin>>l>>r;
        fun(l,r);
        cout<<"next case"<<endl;
    }

}