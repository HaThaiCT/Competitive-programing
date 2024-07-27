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
const int maxn = 5e5 + 5;
int n , m , nRoots;
struct Node{
    bool isEnd = 0;
    int child[26];
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
bool is_Found(string &s){
    int x = 0;
    for(char c : s){
        int id = c - 'a';
        if(trie[x].child[id] == 0) return 0;
        x = trie[x].child[id];
    }
    return trie[x].isEnd;
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
        cout << is_Found(s) << '\n';
    }
    return 0;
}