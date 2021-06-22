#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

    char c;
    while(scanf("%c", &c) != EOF){
        if(c == '\n') printf("hi");
        printf("The char is %c\n", c);
        //cout << "The char is: " << c << '\n';
    }

    return 0;
}
