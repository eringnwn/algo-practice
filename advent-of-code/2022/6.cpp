#include <bits/stdc++.h>
using namespace std;
#define out(x,y) cout << (x) << " " << (y) << " " << endl;
#define db(x) cout << ">>>" << #x << " -> " << (x) << endl;
#define endl "\n"
#define sz(x) int((x).size())

string str;
void solve(){
    for (int idx=0; idx < str.length()-14; idx++){
        set <char> cnt;
        for (int i=idx; i<idx+14; i++){
            cnt.insert(str[i]);
        }
//        for (auto el: cnt) cout << el << " ";
//        cout << endl;
        //for challenge 1, the size required is 4
        if (sz(cnt) == 14){
            cout << idx+14 << endl;
            break;
        }
    }

}
int main(){
    //freopen("input.txt", "r", stdin);

    cin >> str;
    solve();
    return 0;
}
