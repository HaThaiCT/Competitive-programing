#include <bits/stdc++.h>
#define For(i,a,b) for(int i = (a) ; i <= (b) ; i++)
#define Forn(i,a,b) for(int i = (a) ; i >= (b) ; i--)
#define F first
#define S second
#define ll long long
#define db double
#define pii pair<int,int>
#define PB push_back
#define mp make_pair
#define getbit(i,x) ( (x >> i) & 1 )
#define CNT(x) __builtin_popcountll(x)
using namespace std;
const int maxn = 1e6 + 5;
struct Trie{
    int child[2];
    int val;
}node[maxn * 29];
int n , a[maxn] , nRoots = 0 , ans = 0;
void add(int x){
    int num = 0;
    Forn(i , 29 , 0){
        int id = getbit(i , x);
        if(node[num].child[id] == 0) node[num].child[id] = ++nRoots;
        num = node[num].child[id];
    }
    node[num].val = x;
}
int found(int x){
    int num = 0;
    Forn(i , 29 , 0){
        int id = getbit(i , x);
        if(node[num].child[1 - id] != 0) num = node[num].child[1 - id];
        else num = node[num].child[id];
    }
    return (x ^ node[num].val); 
}
int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("task.inp","r",stdin);
    freopen("task.out","w",stdout);
    cin >> n;
    For(i,1,n){
        cin >> a[i];
        add(a[i]);
    }
    For(i,1,n){
        ans = max(ans , found(a[i]));
    }
    cout << ans;
    return 0;
}