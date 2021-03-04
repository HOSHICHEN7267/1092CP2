#include <stdio.h>

int main(){

    long long start = 0;
    long long end = 0;
    long long now = 0;

    if(scanf("%lld", &start) == EOF){
        return 0;
    }
    end = start;

    while(scanf("%lld", &now) != EOF){

        if(now != (end + 1)){
            if(start == end){
                printf("%lld\n", start);
            }
            else{
                printf("%lld->%lld\n", start, end);
            }
            start = now;
        }

        end = now;
    }

    if(start == end){
        printf("%lld\n", start);
    }
    else{
        printf("%lld->%lld\n", start, end);
    }

    return 0;
 
}
