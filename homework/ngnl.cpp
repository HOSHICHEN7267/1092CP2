#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    
    int num = 0;
    int now = 0;
    long long sum = 0;
    int sumnum = 0;
    long long output = 0;
    vector<int> vec;

    cin >> num;
    for(int i = 0 ; i < num ; ++i){
        cin >> now;
        vec.push_back(now);
    }

    sort(vec.begin(), vec.end());

    for(int i = 0 ; i < vec.size() ; ++i){
        if(vec[i] < 0) continue;
        else{
            int cnt = 0;
            while(vec[i] == vec[i+1]){
                ++cnt;
                ++i;
            }
            ++cnt;
            ++i;

            if(sum < vec[i] * cnt){
                sum = vec[i] * cnt;
                sumnum = vec[i];
            }        
        }
    }

    cout << sumnum << '\n';
    cout << sum * 10000 << '\n';
    
}
