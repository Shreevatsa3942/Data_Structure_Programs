/*Program to evaluate prefix expression*/
//Name:Shreevatsa
//Regno: 200970093
//Modified Date: 28-05-2021
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class stack{
    int stack[100];
    int top=-1;
public:
    void push(int var){
        cout<<"\n"<<var<<" pushed";
        top++;
        stack[top]=var;
    }
    int pop(){
        int item=stack[top];
        top--;
        return item;
    }
};
class Eval_prefix{
    stack s;
public:
    int operation(char op,int a,int b){
        switch(op){
            case '+' : return (a+b);
                        break;
            case '-' : return (a-b);
                        break;
            case '*' : return (a*b);
                        break;
            case '/' : return (a/b);
                        break;
            case '^' : return (pow(b,a));
                        break;
        }
	}

    int evaluate(string prefix){
        int result;
        char c;
        for(int i=prefix.length()-1;i>=0;i--){
            c=prefix[i];
            if(c == ' ' || c == ',')
                continue;
            else
            if(isdigit(c)){
                string temp;
                while(c != ' ' && c != ','){
                    if(isdigit(c)){
                        temp=c+temp;
                    }
                    else{
                        cout<<"Delimiter \' \' or \',\' should be there!!\n\n";
                        exit(0);
                    }
                    i--;
                    c=prefix[i];
                }
                i++;
                //convert temp string to an integer value
                int var=stoi(temp);
                s.push(var);
            }
            else
            if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){

                    cout<<"\nOperator "<<c;
                    int a = s.pop();
                    cout<<"\n"<<a<<" Popped";
                    int b = s.pop();
                    cout<<"\n"<<b<<" Popped";

                    if(c == '^')
                        result=operation(c,b,a);
                    else
                        result=operation(c,a,b);

                    s.push(result);
                } 
        }
        return s.pop();
    }

};

int main(){
    string expr;
    cout<<"Enter the Prefix Expression: ";
    getline(cin,expr);
    Eval_prefix ev;
    float result = ev.evaluate(expr);

    cout<<"\nResult  :"<<result<<endl;
    
}
