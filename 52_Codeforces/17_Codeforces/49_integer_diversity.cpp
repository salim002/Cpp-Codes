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
#define mp make_pair
#define pb push_back

const int mod = 1000000007;
// const int mod = 998244353; 

void solve(){
    ll n, i;
    cin>>n;
    vl v(n);
    map<ll, ll> m;
    for(i=0; i<n; i++){
        cin>>v[i];
        if(v[i]<0){
            v[i] *= -1;
        }
        m[v[i]]++;
    }
    ll ans=0;
    for(auto it:m){
        if(it.first==0){
            ans++;
        }
        else{
            if(it.second==1){
                ans++;
            }
            else{
                ans += 2;
            }
        }
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}