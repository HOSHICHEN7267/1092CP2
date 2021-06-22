#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int target = 0;
    int now = 0;
    int l = 0, r = 0, m = 0;
    int cnt = 0;
    vector<int> num;

    cin >> target;

    while(cin >> now){
        num.push_back(now);
    }

    l = 0, r = num.size() - 1;

    while(l <= r){

        ++cnt;

        if((l + r) % 2){
            m = (l + r) / 2 + 1;
        }
        else{
            m = (l + r) / 2;
        }

        if(target == num[m]){
            cout << m << '\n';
            cout << cnt << '\n';
            return 0;
        }
        else if(target > num[m]){
            l = m + 1;
        }
        else if(target < num[m]){
            r = m - 1;
        }
    }

    cout << -1 << '\n';
    return 0;
}
