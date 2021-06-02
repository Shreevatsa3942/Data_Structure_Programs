/*Program to evaluate prefix expression*/
//Name:Shreevatsa
//Regno: 200970093
//Modified Date: 28-05-2021
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class stack{
    float stack[100];
    int top=-1;
public:
    void push(float var){
        //cout<<"\n"<<var<<" pushed";
        top++;
        stack[top]=var;
    }
    float pop(){
        float item=stack[top];
        top--;
        return item;
    }
};
class Eval_prefix{
    stack s;
public:
    float operation(char op,float a,float b){
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

    float evaluate(string prefix){
        float result;
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

                    //cout<<"\nOperator "<<c;
                    float a = s.pop();
                    //cout<<"\n"<<a<<" Popped";
                    float b = s.pop();
                    //cout<<"\n"<<b<<" Popped";

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
