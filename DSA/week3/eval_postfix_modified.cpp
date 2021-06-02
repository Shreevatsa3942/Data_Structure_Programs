/*Program to evaluate postfix expression*/
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
class Eval_postfix{
    stack s;
public:
    float operation(char op,int a,int b){
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

    float evaluate(string postfix){
        float result;
        char c;
        for(int i=0;i<postfix.length();i++){
            c=postfix[i];
            //if charecter is ' ' or ','
            if(c == ' ' || c == ',')
                continue;
            else
            if(isdigit(c)){
                string temp;
                while(c != ' ' && c != ','){
                    if(isdigit(c)){
                        temp+=c;
                    }
                    else{
                        cout<<"Delimiter \' \' or \',\' should be there!!\n\n";
                        exit(0);
                    }
                    i++;
                    c=postfix[i];
                }
                i--;
                //convert temp string to an integer value
                int var=stoi(temp);
                s.push(var);
            }
            //checking whether charecter is an operator or not
            if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){

                    
                    int a = s.pop();
                   
                    int b = s.pop();
                    
                    if(c == '^')
                        result=operation(c,a,b);
                    else
                        result=operation(c,b,a);

                    s.push(result);
            }
            
        }
        return s.pop();
    }

};

int main(){
    string expr;
    cout<<"Enter the Postfix Expression: ";
    getline(cin,expr);
    Eval_postfix ev;
    float result = ev.evaluate(expr);
    cout<<"\nResult  :"<<result<<endl;
    //cout<<expr<<endl;
    
}
