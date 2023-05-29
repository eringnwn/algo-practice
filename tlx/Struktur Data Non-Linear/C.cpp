#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define out(x,y) cout << (x) << " " << (y) << " " << endl;
#define db(x) cout << ">>>" << #x << " -> " << (x) << endl;
#define endl "\n"

priority_queue<int, vector<int>, greater<int>> sisa;
bool flag = 1;
int now, goal, req, k, l;
ll cnt=0;

void nextstage(){
    if (now >= req){
        if (l <= k){
            cnt += l;
            now++;
        }
        else{
            cnt += k;
            sisa.push(l-k);
        }
    }
    else{
        bool can = 1;
        while(! sisa.empty()){
            if (now >= req) break;
            cnt += sisa.top();
            sisa.pop();
            now++;
        }
        if (now < req) flag = false;
        else{
            if (l <= k){
                cnt += l;
                now++;
            }
            else{
                cnt += k;
                sisa.push(l-k);
            }
        }
    }
}

void last(){
    while(! sisa.empty()){
        if (now >= goal) break;
        cnt += sisa.top();
        sisa.pop();
        now++;
    }
    if (now < goal) flag = false;
}

int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    string str;
    cin >> str;

    int lvl;
    cin >> lvl >> now >> goal;
    for (int i=0; i<lvl-1; i++){
        cin >> req >> k >> l;
        if (flag) nextstage();
    }
    last();
    if (!flag) cout << -1 << endl;
    else cout << cnt << endl;
    return 0;
}
