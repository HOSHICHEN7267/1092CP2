#include <stdio.h>
#include <algorithm>
#define SIZE 101

using namespace std;

int a = 0;
int b = 0;

int find(int start, int end, int arr[], int turn){
    if(start == end - 1){
        if(turn){
            b += max(arr[start], arr[end]);
            a += min(arr[start], arr[end]);
        }
        else{
            a += max(arr[start], arr[end]);
            b += min(arr[start], arr[end]);
        }
        return max(arr[start], arr[end]);
    }
    else{
        if(find(start+1, end, arr, !turn) < find(start, end-1, arr, !turn)){
            turn ? b += start : a += start;
            return start;
        }
        else{
            turn ? b += end : a += end;
            return end;
        }
    }
}

int main(){

    int len = 0;
    int arr[SIZE] = {0};

    scanf("%d", &len);
    for(int i = 0 ; i < len ; ++i){
        scanf("%d", &arr[i]);
    }
    
    find(0, len-1, arr, 0);

    a >= b ? printf("True") : printf("False");
    putchar('\n');

    return 0;
}
