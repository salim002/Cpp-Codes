#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;

#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

const int mod = 1000000007;
const ll M = 998244353;

ll mul(ll a, ll b){
    return ((a%mod)*(b%mod))%mod;
}

ll modPower(ll a, ll b){
    if(b==0){
        return 1;
    }
    a = a%mod;
    ll res=1;
    while(b>0){
        if(b&1){
            res = mul(res, a);
        }
        b = b>>1;
        a = mul(a, a);
    }
    return res;
}

ll fac(ll n){
    ll res=1;
    for(ll i=2; i<=n; i++){
        res = mul(res, i);
    }
    return res;
}

ll dv(ll a, ll b){
    return mul(a, modPower(b, mod-2));
}

ll nCr(ll n, ll r){
    return dv(fac(n), mul(fac(r), fac(n-r)));
}

void solve(){
    int n, k;
    cin>>n>>k;
    vl v(n, 1e15), pre(n, 1e15), suff(n, 1e15);
    vl idx(k), cost(k);
    for(int i=0; i<k; i++) cin>>idx[i];
    for(int i=0; i<k; i++) cin>>cost[i];
    for(int i=0; i<k; i++){
        v[idx[i]-1]=cost[i];
    }
    ll curr=1e15;
    for(int i=0; i<n; i++){
        curr=min(v[i], curr+1);
        pre[i]=curr;
    }
    curr=1e15;
    for(int i=n-1; i>=0; i--){
        curr=min(v[i], curr+1);
        suff[i]=curr;
    }
    for(int i=0; i<n; i++){
        cout<<min(pre[i], suff[i])<<" ";
    }
    cout<<endl;
}
int main(){
    fast_io
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}