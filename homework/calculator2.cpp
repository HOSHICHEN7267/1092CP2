#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <charconv>

using namespace std;

int priority(char op){
    if(op == '*' || op == '/') return 2;
    else if(op == '+' || op == '-') return 1;
    return 0;
}

int main(){

    string input;
    vector<string> postfix;
    string numtmp;
    stack<char> operators;
    stack<int> num;

    getline(cin, input);
    
    for(int i = 0 ; i < input.size() ; ++i){
        if(input[i] == '('){
            operators.push(input[i]);
        }
        else if(input[i] == ')'){
            while(operators.top() != '('){
                string tmp;
                tmp += operators.top();
                postfix.push_back(tmp);
                operators.pop();
            }
            operators.pop();
        }
        else if((i == 0 && input[i] == '-') || (input[i] == '-' && input[i-1] == '(')){
            string tmp;
            tmp += input[i];
            while(i + 1 < input.size() && input[i+1] >= '0' && input[i+1] <= '9'){
                ++i;
                tmp += input[i];
            }
            //cout << "minus: " << tmp << '\n';
            postfix.push_back(tmp);
        }
        else if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'){
            while(!operators.empty() && priority(input[i]) <= priority(operators.top())){
                string tmp;
                tmp += operators.top();
                postfix.push_back(tmp);
                operators.pop();
            }
            operators.push(input[i]);
        }
        else if(input[i] >= '0' && input[i] <= '9'){
            string tmp;
            tmp += input[i];
            while(i + 1 < input.size() && input[i+1] >= '0' && input[i+1] <= '9'){
                ++i;
                tmp += input[i];
            }
            postfix.push_back(tmp);
        }
    }

    while(!operators.empty()){
        string tmp;
        tmp += operators.top();
        postfix.push_back(tmp);
        operators.pop();
    }

    /*for(int i = 0 ; i < postfix.size() ; ++i){
        cout << postfix[i] << ' ';
    }
    cout << '\n';*/

    for(int i = 0 ; i < postfix.size() ; ++i){
        if(postfix[i] == "+" || (postfix[i] == "-" && i != 0) || postfix[i] == "*" || postfix[i] == "/"){
            //cout << "operator: " << postfix[i] << '\n';
            if(num.size() >= 2){
                int a = 0, b = 0;
                b = num.top();
                num.pop();
                a = num.top();
                num.pop();

                if(postfix[i] == "+"){
                    num.push(a + b);
                }
                else if(postfix[i] == "-"){
                    num.push(a - b);
                }
                else if(postfix[i] == "*"){
                    num.push(a * b);
                }
                else if(postfix[i] == "/"){
                    num.push(a / b);
                } 
            }            
        }
        else if(i == 0 && postfix[i] == "-"){
            int now;
            ++i;
            now = stoi(postfix[i]);
            num.push(now * -1);
        }
        else{
            //cout << "number or -: " << postfix[i] << '\n';
            int now;
            now = stoi(postfix[i]);
            num.push(now);
        }


        //cout << "i: " << i << " stacktop: " << num.top() << " stacksize: " << num.size() << '\n';
    }

    cout << num.top() << '\n';
}
