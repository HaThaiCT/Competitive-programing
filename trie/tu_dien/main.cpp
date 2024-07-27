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
int n , t , nRoots = 0;
char x[20];
string a[maxn];
string ans;
struct Trie{
    int child[26];
    bool isEnd = 0;
    string val = "";
}node[maxn * 10];
void add(string s , string v){
    int num = 0;
    for(char c : s){
        int id = c - 'a';
        if(node[num].child[id] == 0) node[num].child[id] = ++nRoots;
        num = node[num].child[id];
    }
    node[num].isEnd = 1;
    if(node[num].val.size() == 0 || node[num].val > v) node[num].val = v;
}
void Try(int pos , int u , string s){
    For(i , x[pos - 1] + 1 , (int) s.size() - 1){
        x[pos] = i;
        int id = s[i] - 'a';
        int next_u = node[u].child[id];
        if(next_u > 0){
            if(node[next_u].isEnd == 1) if(node[next_u].val.size() > ans.size() ||
             (node[next_u].val.size() == ans.size() && node[next_u].val < ans)) ans = node[next_u].val;
            Try(pos + 1 , next_u , s);
        } 
    }
}
int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("task.inp","r",stdin);
    freopen("task.out","w",stdout);
    cin >> n;
    For(i,1,n){
        cin >> a[i];
        string s = a[i];
        sort(a[i].begin() , a[i].end());
        add(a[i] , s);
    }
    x[0] = -1;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        ans = "";
        sort(s.begin() , s.end());
        Try(1 , 0 , s);
        if(ans == "") cout << "IMPOSSIBLE";
        else cout << ans;
        cout << '\n';
    }
    return 0;
}