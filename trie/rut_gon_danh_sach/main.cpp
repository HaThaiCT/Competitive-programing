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
    int child[26];
    int length = 0;
    bool isEnd = 0;
}node[maxn];
int n , nRoots = 0;
long long dp[maxn];
void add(string s){
    int num = 0;
    int cnt = 0;
    for(char c : s){
        int id = c - 'a';
        if(node[num].child[id] == 0) node[num].child[id] = ++nRoots;
        cnt++;
        num = node[num].child[id];
        node[num].length = cnt;
    }
    node[num].isEnd = 1;
}
void dfs(int u){
    dp[u] = (1ll << (40 - node[u].length));
    if(node[u].isEnd == 1) return;
    long long res = 0;
    For(id , 0 , 25) if(node[u].child[id] != 0){
        if(dp[node[u].child[id]] == 0) dfs(node[u].child[id]);
        res += dp[node[u].child[id]];
    }
    if(res > 0) dp[u] = min(dp[u] , res);
}
int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("task.inp","r",stdin);
    freopen("task.out","w",stdout);
    cin >> n;
    For(i,1,n){
        string s;
        cin >> s;
        add(s);
    }
    dfs(0);
    long long ans = 0;
    For(id , 0 , 25) if(node[0].child[id] != 0) ans += dp[node[0].child[id]];
    cout << ans;
    return 0;
}