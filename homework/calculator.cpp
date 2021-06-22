#include <iostream>
#include <string>
#include <stack>
#include <charconv>

using namespace std;

int priority(char op){
    if(op == '*' || op == '/') return 2;
    else if(op == '+' || op == '-') return 1;
    return 0;
}

int main(){

    string input;
    string postfix;
    string numtmp;
    stack<char> operators;
    stack<int> num;

    getline(cin, input);

    if(input.size() == 0){
        return 0;
    }
    
    for(int i = 0 ; i < input.size() ; ++i){
        if(input[i] == '('){
            operators.push(input[i]);
        }
        else if(input[i] == ')'){
            while(operators.top() != '('){
                postfix += operators.top();
                postfix += ' ';
                operators.pop();
            }
            operators.pop();
        }
        else if(i == 0 && input[i] == '-'){
            postfix += input[i];
        }
        else if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'){
            while(!operators.empty() && priority(input[i]) <= priority(operators.top())){
                postfix += operators.top();
                postfix += ' ';
                operators.pop();
            }
            operators.push(input[i]);
        }
        else if(input[i] >= '0' && input[i] <= '9'){
            postfix += input[i];
            while(i + 1 < input.size() && input[i+1] >= '0' && input[i+1] <= '9'){
                ++i;
                postfix += input[i];
            }
            postfix += ' ';
        }
    }

    while(!operators.empty()){
        postfix += operators.top();
        postfix += ' ';
        operators.pop();
    }

    //cout << postfix << '\n';

    for(int i = 0 ; i < postfix.size() ; ++i){
        if((postfix[i] >= '0' && postfix[i] <= '9') || (i == 0 && postfix[i] == '-')){
            string tmp;
            int now;
            tmp += postfix[i];
            while(i + 1 < postfix.size() && postfix[i+1] >= '0' && postfix[i+1] <= '9'){
                tmp += postfix[++i];
            }
            from_chars(tmp.c_str(), tmp.c_str() + tmp.size(), now);
            num.push(now);
        }
        /*else if(i == 0 && postfix[i] == '-'){
            string tmp;
            int now;

        }*/
        else if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/'){
            int a = 0, b = 0;
            if(num.size() >= 2){
                b = num.top();
                num.pop();
                a = num.top();
                num.pop();
            }

            switch(postfix[i]){

                case '+':
                    num.push(a + b);
                    break;

                case '-':
                    num.push(a - b);
                    break;

                case '*':
                    num.push(a * b);
                    break;

                case '/':
                    num.push(a / b);
                    break;

                default:
                    break;
            }
        }

        //cout << "i: " << i << " stacktop: " << num.top() << " stacksize: " << num.size() << '\n';
    }

    cout << num.top() << '\n';
}
