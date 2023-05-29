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


void solve(){

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string key;
    int n;
    ll dep = 0, aim = 0;
    ll hor=0;
    while(cin >> key >> n){
        if (key == "forward"){
            hor += n;
            dep += (n*aim);
        }
        else if (key == "up") aim -= n;
        else aim +=n;
    }
    cout << hor*dep << endl;

    return 0;
}
