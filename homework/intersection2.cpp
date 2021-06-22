#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define SIZE1 101
#define SIZE2 5001

using namespace std;

int main(){

    int n = 0;
    int num[SIZE1][SIZE2] = {0};
    int len[SIZE1] = {0};
    int pos[SIZE1] = {0};
    int now = 0;
    cin >> n;

    for(int i = 0 ; i < n ; ++i){
        int j = 0;
        while(cin >> num[i][j]){
            char check = getchar();
            if(check == '\n'){
                len[i] = j + 1;
                break;
            }
            ++j;
        }
    }

    for(int i = 0 ; i < n ; ++i){
        sort(num[i], num[i] - 1 + len[i]);
    }

    while(1){
    
        int k = 0;
        while(k < n - 1 && num[k][pos[i]] == num[k+1][]){
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
