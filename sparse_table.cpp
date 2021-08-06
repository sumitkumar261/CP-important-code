#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
const ll int inf = 1e9 + 7;
const int l  = 20;
using namespace std;
 
 
//<---------------------------------Code begins--------------------------------------->//
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
        
    int n,q;
    cin>>n;
    vector<ll int> v;
    v.pb(-1);
    ll int arr[n+1][l+1];
    for(int i = 1;i<=n;i++)
    {
        ll int c;
        cin>>c;
        v.pb(c);
        arr[i][0] = c;
    }
    const ll int l = 18;
    cin>>q;
    for(int i =1;i<l;i++)
    {
        for(int j = 1;j<=n-(1<<i)+1;j++)
        {
            arr[j][i] = min( arr[j][i-1] , arr[j + (1<<(i-1))][i-1]  );
        }
    }
    for(int i = 0;i<q;i++)
    {
        int a,b;
        cin>>a>>b;
        a++;
        b++;
        int x = log2(b-a + 1);
        cout<<min(arr[a][x],arr[b-(1<<x)+1][x])<<endl;
    }
    
 
 
    
 
    
 
        
 
    
 
    
}
 
 
 
 
 
 
 
 
 
 //<---------------------------------Code ends--------------------------------