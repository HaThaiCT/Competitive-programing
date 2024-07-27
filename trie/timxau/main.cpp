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
int n , m;
struct TrieNode{
    TrieNode* child[26];
    int cnt;
    TrieNode(){
        For(i , 0 , 25) child[i] = NULL;
        cnt = 0;
    }
};
TrieNode *root = new TrieNode();
void add(const string &s){
    int n = s.length();
    TrieNode *p = root;
    for(char c : s){
        int id = c - 'a';
        if(p->child[id] == NULL) p->child[id] = new TrieNode();
        p = p->child[id];
    }
    p->cnt ++;
}
bool is_found(const string &s){
    int n = s.length();
    TrieNode *p = root;
    for(char c : s){
        int id = c - 'a';
        if(p->child[id] == NULL) return 0;
        p = p->child[id];
    }
    return (p->cnt > 0);
}
int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("","r",stdin);
    freopen("","w",stdout);
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
        cout << is_found(s) << '\n';
    }
    return 0;
}
