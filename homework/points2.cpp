#include <iostream>
#include <algorithm>
#define SIZE 10000

using namespace std;

int main(){

    int num = 0;
    int ans = 0;
    float slope[SIZE] = {};
    int points[SIZE][2] = {};

    cin >> num;

    for(int i = 0 ; i < num ; ++i){
        cin >> points[i][0] >> points[i][1];
    }

    for(int i = 0 ; i < num ; ++i){
        int cnt = 0;
        int sum = 1;

        for(int j = i + 1 ; j < num ; ++j){
            if(i != j){
                slope[cnt++] = (float)(points[i][1] - points[j][1]) / (float)(points[i][0] - points[j][0]);
            }
        }

        sort(slope, slope + cnt);

        for(int j = 0 ; j < cnt - 1 ; ++j){
            if(slope[j] == slope[j+1]){
                ++sum;
            }
            else{
                ans = max(ans, sum);
                sum = 1;
            }
        }
    }

    cout << ans + 1 << '\n';

    return 0;
}
