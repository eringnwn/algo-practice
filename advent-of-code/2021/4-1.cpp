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

const int MAXN = 5;
const int MAXB = 500;
//int g[3][MAXN][MAXN];
vi col[MAXB][MAXN];
vi row[MAXB][MAXN];
vi seq;
ll sum[MAXB];
int ke = 0;
bool win = false;

void getsequence(){
    string str;
    cin >> str;
    stringstream ss(str);
    while(ss.good()){
        int n;
        string subs;
        getline(ss, subs, ',');
        n = stoi(subs);
        seq.pb(n);
    }
}

bool exist(int idx, int key){
    bool flag = false;
    for (int i=0; i<5; i++){
        auto itr = find(row[idx][i].begin(), row[idx][i].end(), key);
        if (itr != row[idx][i].end()){
            row[idx][i].erase(itr);
            flag = true;
            if (sz(row[idx][i]) == 0) win = true;
        }
    }
    for (int i=0; i<5; i++){
        auto itr = find(col[idx][i].begin(), col[idx][i].end(), key);
        if (itr != col[idx][i].end()){
            col[idx][i].erase(itr);
            flag = true;
            if (sz(col[idx][i]) == 0) win = true;
        }
    }
    return flag;
}
ll solve(){
    ll ans;
    for (auto el: seq){
        for (int i=0; i<=ke; i++){
            if (exist(i,el)){
                sum[i] -= el;
            }
            if (win){
                ans = sum[i] * el;
                return ans;
            }
        }
    }
}
void debug(){
//    for (int ke=0; ke<3; ke++){
//        db(ke);
//        for(int i=0; i<5; i++){
//            for (int j=0; j<5; j++){
//                cout << g[ke][i][j] << " ";
//            }
//            cout << endl;
//        }
//    }
    for (int ke=0; ke<3; ke++){
        db(ke);
        for (int i=0; i<5; i++){
            for (auto el: row[ke][i]) cout << el << " ";
            cout << endl;
        }
        for (int i=0; i<5; i++){
            for (auto el: col[ke][i]) cout << el << " ";
            cout << endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    getsequence();
    int tmp;
    string s;
    while(getline(cin,s)){
        for(int i=0; i<5; i++){
            for (int j=0; j<5; j++){
                cin >> tmp;
                sum[ke] += tmp;
                row[ke][i].pb(tmp);
                col[ke][j].pb(tmp);
            }
        }
        ke++;
    }
    debug();
    ll ret = solve();
    cout << ret << endl;
    return 0;
}
