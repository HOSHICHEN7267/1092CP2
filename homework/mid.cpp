#include <iostream>
#include <queue>
#define SIZE 10000

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int lena = 0, lenb = 0;
    int arra[SIZE] = {0}, arrb[SIZE] = {0};
    int line = 0;
    int la = 0, ra = 0, lb = 0, rb = 0;
    int mid = 0;

    cin >> lena;
    for(int i = 0 ; i < lena ; ++i){
        cin >> arra[i];
    }

    cin >> lenb;
    for(int i = 0 ; i < lenb ; ++i){
        cin >> arrb[i];
    }
    
    cin >> line;
    for(int i = 0 ; i < line ; ++i){

        queue<int> qa, qb;

        cin >> la >> ra >> lb >> rb;
        int cnt = (ra - la) + (rb - lb);
        
        for(int j = la ; j < ra ; ++j){
            qa.push(arra[j]);
        }
        for(int j = lb ; j < rb ; ++j){
            qb.push(arrb[j]);
        }

        if(cnt % 2){
            for(int j = 0 ; j < cnt / 2; ++j){
                if(!qa.empty() && !qb.empty()){
                    qa.front() <= qb.front() ? qa.pop() : qb.pop();
                }
                else if(qa.empty()){
                    qb.pop();
                }
                else{
                    qa.pop();
                }
            }

            if(!qa.empty() && !qb.empty()){
                mid = (qa.front() <= qb.front()) ? qa.front() : qb.front();
            }
            else if(qa.empty()){
                mid = qb.front();
            }
            else{
                mid = qa.front();
            }

            cout << mid << '\n';
        }
        else{
            int a = 0, b = 0;
            for(int j = 0 ; j < cnt / 2 ; ++j){
                if(!qa.empty() && !qb.empty()){
                    if(j == cnt / 2 - 1){
                        a = qa.front() <= qb.front() ? qa.front() : qb.front();
                    }
                    qa.front() <= qb.front() ? qa.pop() : qb.pop();
                }
                else if(qa.empty()){
                    if(j == cnt / 2 - 1){
                        a = qb.front();
                    }
                    qb.pop();
                }
                else{
                    if(j == cnt / 2 - 1){
                        a = qa.front();
                    }
                    qa.pop();
                }
            }
           
            if(!qa.empty() && !qb.empty()){
                b = (qa.front() <= qb.front()) ? qa.front() : qb.front();
            }
            else if(qa.empty()){
                b = qb.front();
            }
            else{
                b = qa.front();
            }

            cout << a << ' ' << b << '\n';
        }
    }

    return 0;
}
