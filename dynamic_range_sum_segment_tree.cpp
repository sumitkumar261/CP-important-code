#include<bits/stdc++.h>
 
using namespace std;
 
 
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define abe(x) x.begin(), x.end()
#define dbe(x) x.rbegin(), x.rend()
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
vector<ll> arr;
 
ll query(ll node,ll query_low,ll query_high,ll node_low, ll node_high)
{
    if(query_low <= node_low && query_high >= node_high)
    {
        return arr[node];
    }
    if(query_low > node_high || query_high < node_low)
    {
        return 0;
    }
    ll x = (node_low + node_high)/2;
    return query(2*node,query_low,query_high,node_low,x) + query(2*node + 1,query_low,query_high,x+1,node_high);
}
 
 
void update(ll c, ll a,ll ans)
{
    arr[c+a] = ans;
    for(ll i = (a+c)/2;i>=1;i = i/2)
    {
        arr[i] = arr[2*i] + arr[2*i+1];
    }
}
 
 
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    ll T=1;
    //cin>>T;
    while(T--)
    {
        ll n,q;
        cin>>n>>q;
        ll a = 1;
        while(a<n)
        {
            a = a*2;
        }
 
        arr.resize(2*a + 1);
        for(int i = 0;i<2*a;i++)
        {
            arr[i] = 0;
        }
        for(ll i = 0;i<n;i++)
        {
            ll c;
            cin>>c;
            arr[a+i] = c;
        }
        for(ll i = a-1;i>=0;i--)
        {
            arr[i] = arr[2*i] + arr[2*i+1];
        }
        for(ll i = 0;i<q;i++)
        {
            ll k,l,r;
            cin>>k;
            if(k==1)
            {
                cin>>l>>r;
                l--;
                update(l,a,r);
               
            }
            else
            {
                cin>>l>>r;
                l--;
                r--;
                ll ans = query(1,a+l,a+r,a,2*a-1);
                cout<<ans<<endl;
            }
            //cout<<endl;
 
 
        }
 
 
 
 
 
        
 
 
    
    }
 
 
 
}