#include <iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[100000] = {0};
    int len = 0;
    int i = 0;
    int peakpos = 0;
    int output = 0;

    while(cin >> arr[len]) ++len;

    while(i < len){
        for(int j = i ; j < len ; ++j){
            if(j == i) peakpos = j;
            else if(arr[j] > arr[peakpos]) peakpos = j;
        }
        
        while(i < peakpos){
            int tmp = arr[peakpos] - arr[i];
            if(tmp > output){
                output = tmp; 
            }
            ++i;
        }

        ++i;
    }

    cout << output << '\n';
}
