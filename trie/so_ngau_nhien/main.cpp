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
const int maxn = 3e5 + 5;
int n;
struct TrieNode{
    TrieNode* child[2];
    int cnt;
    int value;
    TrieNode(){
        child[0] = child[1] = NULL;
        cnt = value = 0;
    }
};
TrieNode* root = new TrieNode();
void add(int x){
    TrieNode *p = root;
    Forn(i , 29 , 0){
        int id = getbit(i , x);
        For(j , 0 , 1) if(p->child[j] == NULL) p->child[j] = new TrieNode();
        p = p->child[id];
        p->cnt++;
    }
    p->value = x;
}
int Found(int &k){
    TrieNode *p = root;
    For(i,0,29){
        if(k > (p->child[0]->cnt)){

            k -= (p->child[0]->cnt);
            p = p->child[1];
        }
        else p = p->child[0];
    }
    return p->value;
}
int is_found(int x){
    TrieNode *p = root;
    Forn(i,29,0){
        int id = getbit(i , x);
        if(p->child[id] == NULL) return 0;
        p = p->child[id];
    }
    return (p->value) > 0;
}
int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("task.inp","r",stdin);
    //freopen("task.out","w",stdout);
    cin >> n;
    while(n--){
        int t , x;
        cin >> t >> x;
        if(t == 1){
            add(x);
        }
        else{
            //cout << is_found(x) << '\n';
            cout << Found(x) << '\n';
        }
    }

    return 0;
}
