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
const int maxn = 1e5 + 5;
int n , a[maxn] , nRoots = 0;
struct Trie{
    int child[2];
    int val;
}node[maxn * 30];
void add(int x){
    int pos = 0;
    Forn(i , 29 , 0){
        int id = getbit(i , x);
        if(node[pos].child[id] == 0) node[pos].child[id] = ++nRoots;
        pos = node[pos].child[id];
    }
    node[pos].val = x;
}
int found(int x){
    int pos = 0;
    Forn(i , 29 , 0){
        int id = getbit(i , x);
        if(node[pos].child[1 - id] > 0) pos = node[pos].child[1 - id];
        else pos = node[pos].child[id];
    }
    return max((x ^ node[pos].val) , x);
}
int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
   // freopen("task.inp","r",stdin);
   // freopen("task.out","w",stdout);
    cin >> n;
    int ans = 0;
    For(i,1,n){
        cin >> a[i];
        a[i] = a[i] ^ a[i - 1];
        add(a[i]);
        ans = max(ans , found(a[i]));
    }
    cout << ans;
    return 0;
}