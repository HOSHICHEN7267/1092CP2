#include <stdio.h>
#include <string.h>

#define SIZE 100001

int main(){

    char input[SIZE];
    int cnt = 0;

    fgets(input, SIZE, stdin);
    
    int len = strlen(input);
    for(int i = 0 ; i < len ; ++i){
        if(input[i] == 'L'){
            if(cnt){
                ++cnt;

                int j = 0;

                for(j = 0 ; j < cnt / 2 ; ++j){
                    input[i - j] = 'L';
                }
                if(cnt % 2 == 1){
                    input[i - j] = '.';
                }
            }
            else{
                for(int j = i - 1 ; j >= 0 ; --j){
                    if(input[j] == 'L'){
                        break;
                    }
                    input[j] = 'L';
                }
            }
            cnt = 0;
        }
        else if(input[i] == 'R'){
            cnt = 1; 
        }
        else if(input[i] == '.' && cnt){
            ++cnt;
            input[i] = 'R';
        }
    }
    puts(input);

    return 0;
}
