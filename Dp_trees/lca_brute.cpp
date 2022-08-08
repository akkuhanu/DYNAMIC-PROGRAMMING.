#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define yes cout<<"YES";
#define no cout<<"NO";
#define vec vector<ll>
#define f_a(arr,it) for(auto it:arr)
#define vec_pair vector<pair<ll,ll>>
#define us  unordered_set<ll>
#define us_pair unordered_set<pair<ll,ll>>
#define mapi map<ll,ll>
#define map_vec map<ll,vec> 
#define fr(a,b) for(ll i = a; i < b; i++)
#define rep(i,a,b) for(ll i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define nline cout<<'\n';
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
 
bool is_prime(ll n){
    if (n <= 1ll)
        return false;
    if (n <= 3ll)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll i = 5; i * i <= n; i = i + 6ll)
        if (n % i == 0 || n % (i + 2ll) == 0)
            return false;
    return true;
}

ll child_count(ll par,ll child,vector<vec>& tree,vec& child_c){
    ll c = 0;
    f_a(tree[child],it){
        if(it!=par){
            c = c + child_count(child,it,tree,child_c);
        }
    }
    child_c[child] = c; 
    return child_c[child]+1;}
ll height_c(ll par,ll child,vector<vec>& tree,vec& height){
    ll c = 1;
    f_a(tree[child],it){
        if(it!=par){
            c = max(c,1+height_c(child,it,tree,height));
        }
    }
    return height[child]=c;}
void dis_subset(ll n_subset){
    // 0^0 = 0 , 1^0 = 1 
    fr(0,10){

        if(n_subset & (1<<i) ){

            cout<<i+1<<" ";
        }

    }
}
void rem_bit(ll n_subset,ll bit_no){
    // bit_no is element you want to remove from set.
    if( n_subset & (1<<(bit_no-1) ) ){

       n_subset = n_subset ^ (1<<(bit_no-1)) ;

    } // Since 0^1 = 1 and 1^1 = 0
}
void add_bit(ll n_subset,ll bit_no){

    n_subset = n_subset ^ (1<<(bit_no-1)) ;
}

ll form_set(ll n){

    ll i_set = 0;
    fr(0,n){

        i_set = i_set^(1<<i);

    }

    return i_set;


}
// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

int BitsSetTable256[256];

// Function to initialise the lookup table
void initialize(){   
    BitsSetTable256[0] = 0;
    for (int i = 0; i < 256; i++)
    {
        BitsSetTable256[i] = (i & 1) +
        BitsSetTable256[i / 2];
    }
}
// Initialise the lookup table
int countSetBits(int n)  // o(1)
{
    return (BitsSetTable256[n & 0xff] +
            BitsSetTable256[(n >> 8) & 0xff] +
            BitsSetTable256[(n >> 16) & 0xff] +
            BitsSetTable256[n >> 24]);
}

//-----------------------------------------------------------------------------------// 
ll b_lift(vector<vec>& tree,ll child,ll par,vector<vec>& parent,vec& height){

    if(parent[child].size()==0){

        parent[child] = parent[par];
        parent[child].pb(par);
    }
    bool a = true;

    f_a(tree[child],it){

        if(it!=par){

            a = false;

            height[child] = max(1 + b_lift(tree,it,child,parent,height),height[child]);

        }

    }
    if(a){

        return height[child] = 1;
    }

    return ;

}
int main(){

    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("inputf.in","r",stdin);
    freopen("outputf.in","w",stdout);
    #endif

    // CONSTRUCTING THE TREE.

    ll n;
    cin>>n;

    vector<vec> v(n+1);

    fr(0,n-1){

        ll x;
        cin>>x;

        ll y;
        cin>>y;


        v[x].pb(y);
        v[y].pb(x);

    }

    // LCA


    // Brurte-force


    vector<vec> par(n+1);
    vec height(n+1,-1);

    b_lift(v,1,0,par,height);

    fr(1,n+1){

        reverse(par.begin(), par.end());
    }

    // Also first reach the same height then start searching.

    // Now run the for loop to get the answer.





}
