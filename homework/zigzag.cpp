#include <stdio.h>
#include <string.h>

int main(){

    char input[1001] = {};
    char str[1001][1001] = {};
    int n = 0;
    int cnt[1001] = {0};
    int nowrow = 0;
    int down = 1;
    
    scanf("%s", input);
    scanf("%d", &n);

    for(int i = 0 ; i < strlen(input) ; ++i){

        str[nowrow][cnt[nowrow]] = input[i];
        ++cnt[nowrow];

        if(nowrow == n - 1){
            down = 0;
        }
        else if(nowrow == 0){
            down = 1;
        }

        down ? ++nowrow : --nowrow;
    }

    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < cnt[i] ; ++j){
            printf("%c", str[i][j]);
        }
    }

    return 0;
}
