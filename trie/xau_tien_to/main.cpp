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
struct Node{
    int child[26];
    int pass = 0;
}Trie[maxn];
int n , m , nRoots = 0;
void add(string &s){
    int x = 0;
    for(char c : s){
        int id = c - 'a';
        if(Trie[x].child[id] == 0) Trie[x].child[id] = ++nRoots;
        x = Trie[x].child[id];
        Trie[x].pass++;
    }
}
int cnt(string &s){
    int x = 0;
    for(char c : s){
        int id = c - 'a';
        if(Trie[x].child[id] == 0) return 0;
        x = Trie[x].child[id];
    }
    return Trie[x].pass;
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
    cin >> m;
    while(m--){
        string s;
        cin >> s;
        cout << cnt(s) << '\n';
    }
    return 0;
}