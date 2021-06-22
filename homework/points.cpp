#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int gcd(int m, int n) {
    if(n == 0) {
        return m;
    }
    else {
        return gcd(n, m % n);
    }
}

long getSlope(int x1, int y1, int x2, int y2){
   int dx = x1 - x2;
   int dy = y1 - y2;

   if(dy == 0){
        return (long)y1 << 32 | 0;
   }

   if(dx == 0){
        return (long)0 << 32 | x1;
   }

   int d = gcd(dx, dy);
   return (long)(dy / d) << 32 | (dx / d);
}

int main(){

    int num = 0;
    int points[10000][2] = {0};
    int output = 0;

    cin >> num;

    for(int i = 0 ; i < num ; ++i){
        cin >> points[i][0] >> points[i][1];
    }

    for(int i = 0 ; i < num ; ++i){

        unordered_map<long, int> cnt;
        int same = 1;
        int Max = 0;
        int p1x = points[i][0], p1y = points[i][1];
        
        for(int j = i + 1 ; j < num ; ++j){
            int p2x = points[j][0], p2y = points[j][1];
            if(p1x == p2x && p1y == p2y){
                ++same;
            }
            else{
                Max = max(Max, ++cnt[getSlope(p1x, p1y, p2x, p2y)]);
            }
        }

        output = max(output, same + Max);
    }
    
    cout << output << '\n';
}
