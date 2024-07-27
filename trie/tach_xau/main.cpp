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
const int mod = 1e9 + 7;
int n , nRoots = 0;
long long dp[maxn];
string x;
struct Node{
    int child[26];
    bool isEnd = 0;
}trie[maxn];
void add(string &s){
    int x = 0;
    for(char c : s){
        int id = c - 'a';
        if(trie[x].child[id] == 0) trie[x].child[id] = ++nRoots;
        x = trie[x].child[id];
    }
    trie[x].isEnd = 1;
}
int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("task.inp","r",stdin);
    freopen("task.out","w",stdout);
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        add(s);
    }
    cin >> x;
    int m = x.size();
    x = " " + x;
    dp[0] = 1;
    For(i , 0 , m - 1){
        int j = i + 1;
        int num = 0;
        while(j <= m){
            int id = x[j] - 'a';
            if(trie[num].child[id] == 0) break;
            num = trie[num].child[id];
            if(trie[num].isEnd == 1){
                dp[j] = (dp[j] + dp[i]) % mod;
                //break;
            }
            j++;
        }
    }
    cout << dp[m];
    return 0;
}