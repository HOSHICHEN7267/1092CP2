#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define SIZE1 100

using namespace std;

int main(){

    int n = 0;
    vector< vector<int> > num;
    queue<int> sorted[SIZE1];
    int now = 0;
    cin >> n;

    for(int i = 0 ; i < n ; ++i){
        vector<int> tmp;
        while(cin >> now){
        
            //cout << now << '\n';
            tmp.push_back(now);

            char check = getchar();
            if(check == '\n') break;
            //cout << now;
        }
        num.push_back(tmp);
    }

    for(int i = 0 ; i < n ; ++i){
        sort(num[i].begin(), num[i].end());
        for(int j = 0 ; j < num[i].size() ; ++j){
            sorted[i].push(num[i][j]);
        }
    }

    while(1){
    
        int k = 0;
        while(k < n - 1 && sorted[k].front() == sorted[k+1].front()){
            ++k;
        }

        if(k == n - 1){
            cout << sorted[k].front() << ' ';
            for(int i = 0 ; i < n ; ++i){
                sorted[i].pop();
                if(sorted[i].empty()) return 0;
            }
        }
        else{
            int minfront = sorted[k].front();
            int minqueue = k;
            
            for(int i = k + 1 ; i < n ; ++i){
                if(sorted[i].front() < minfront){
                    minfront = sorted[i].front();
                    minqueue = i;
                }
            }

            sorted[minqueue].pop();
            if(sorted[minqueue].empty()) return 0;
        }
    }

    return 0;
}
