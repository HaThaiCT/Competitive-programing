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
const int maxn = 1e6;
int n , m , nRoot = 0;
struct Node{
    int child[26]; // so thu tu cua dinh con neu di theo canh i
    bool isEnd = 0;
}tree[maxn];
void add(string &s){
    int x = 0;
    for(char c : s){
        int id = c - 'a';
        if(tree[x].child[id] == 0) tree[x].child[id] = ++nRoot;
        x = tree[x].child[id];
    }
    tree[x].isEnd = 1;
}
bool is_found(string &s){
    int x = 0;
    for(char c : s){
        int id = c - 'a';
        if(tree[x].child[id] == 0) return 0;
        x = tree[x].child[id];
    }
    return tree[x].isEnd;
}
int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    For(i,1,n){
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
