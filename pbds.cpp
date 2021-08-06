
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>    //-----------
#include<ext/pb_ds/tree_policy.hpp>     //-----------


using namespace __gnu_pbds;    //-----------
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


//-----------


#define ordered_set1 tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_set2 tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update>


//-----------
int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    ll T=1;
   // cin>>T;
    while(T--)
    {
        ordered_set1 s;
        s.insert(5);
        s.insert(1);
        s.insert(2);
        cout<<*(s.find_by_order(1))<<nline;

        cout<<s.order_of_key(5)<<nline;


        //----- order_of_key (k) : Number of items strictly smaller than k .
        //----- find_by_order(k) : K-th element in a set (counting from zero).
        


        
    
    }



}





