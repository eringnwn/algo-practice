#include <bits/stdc++.h>
using namespace std;
#define out(x,y) cout << (x) << " " << (y) << " " << endl;
#define db(x) cout << ">>>" << #x << " -> " << (x) << endl;
#define endl "\n"

using ll = long long;
using vi = vector <int>;
using vll = vector <ll>;
#define pb push_back
#define sz(x) int((x).size())

using pii = pair <int, int>;
#define mp make_pair
#define fi first
#define se second

const int MAXN = 1000;
vector <bool> vis[MAXN]; //row col
vi g[MAXN]; // row col
vi mxr, mxc;
int idx = 0;

void debug(){
    db("row");
    for (auto el: mxr) db(el);
    db("col");
    for (auto el: mxc) db(el);
}
void findmx(){
    int col = sz(g[0]);
    for (int i=0; i<idx; i++) mxr.pb(0);
    for (int i=0; i<col; i++) mxc.pb(0);

    for (int r=0; r<idx; r++){
        for (int c=0; c<col; c++){
            if (g[r][c] > g[r][mxr[r]]){
                mxr[r] = c;
            }
            if (g[r][c] > g[mxc[c]][c]){
                mxc[c] = r;
            }
        }
    }
    //debug();
}

void cnt(){
    int ret = 0;
    for (int r=0; r<idx; r++){
        for (int c=0; c < sz(g[0]); c++){
//            cout << vis[r][c] << " ";
            if (vis[r][c]) ret ++;
        }
//        cout << endl;
    }
    cout << ret << endl;
}

void solve(){
    findmx();
    //from left and right
    int mx;
    for (int i=0; i<idx; i++){ //for every row
        vis[i].resize(sz(g[0]));
        int l = 0;
        int m = mxr[i];
        int r = sz(g[0]) - 1;
        mx = -1;
        vis[i][m] = 1;
        while(l != m){
            if (g[i][l] > mx){
                vis[i][l] = 1;
                mx = g[i][l];
            }
            l++;
        }
        mx = -1;
        while(r != m){
            if (g[i][r] > mx){
                vis[i][r] = 1;
                mx = g[i][r];
            }
            r--;
        }
    }
    for (int i=0; i<sz(g[0]); i++){ //for every col
        int top = 0;
        int m = mxc[i];
        int bot = idx-1;
        mx = -1;
        vis[m][i] = 1;
        while(top != m){
            if (g[top][i] > mx){
                vis[top][i] = 1;
                mx = g[top][i];
            }
            top++;
        }
        mx = -1;
        while(bot != m){
            if (g[bot][i] > mx){
                vis[bot][i] = 1;
                mx = g[bot][i];
            }
            bot--;
        }
    }
    cnt();
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    freopen("input.txt", "r", stdin);
    string str; int tmp;
    while(cin >> str){
        for (int i=0; i < str.length(); i++){
            tmp = str[i] - '0';
            g[idx].pb(tmp);
        }
        idx++;
    }
    solve();
    return 0;
}
