//Author name:Shreevatsa
//Registration no:200970093
//Modified Date: 24-05-2021
//Program to convert infix expression to postfix Expression using stack
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class infixToPostfix{
	char stack[100];
	int top=-1;	
	string infix;
	int len=0;
public:
	infixToPostfix(string infix){
		this->infix=infix;
	}
	void push(char val){
		top++;
		stack[top]=val;
	}
	void pop(){
		if(top > -1){
			top--;
		}
	}
	int operator_precedence(char c){
    	if(c == '^')
    		return 3;
  		else if(c == '*' || c == '/')
        	return 2;
   		else if(c == '+' || c == '-')
        	return 1;
  		else
       		return -1;
	}

    string convert_expression(){

        string postfix;

        for(int i=0;i<infix.length();i++){
            //checking whether it's an operand or not 
            char c=infix[i];
            //if it's an operand append it to the Postfix string
            if(isalpha(c) || isdigit(c)) postfix+=c;
            else
                if(c == '(') push(c);
			else
				if(c == ')'){

					while(stack[top] != '(' && top != -1){
						postfix+=stack[top];
						pop();
					}
					//and popping opening brace
					if(stack[top] == '(') pop();

				}
            //if it's an operator 
            else if(c == '*' || c == '+' || c == '-' || c == '/' || c == '^'){
                //if incoming operator is less than or equal to operators in the stack then pop 
                while( top != -1 && operator_precedence(c) <= operator_precedence(stack[top])) {
				    char temp = stack[top];
				    pop();
				    postfix += temp;
			    }
			    push(c);

            }

        }
        //popping all the elements from stack 
        while(top != -1){
			postfix+=stack[top];
			pop();
		}

        return postfix;
      
    }
};
int main(){
    string infix;
	cout<<"\nEnter the Infix expression :";
	cin>>infix;
	infixToPostfix expr1(infix);
	cout<<"\nPostfix Expression: "<<expr1.convert_expression();
	cout<<endl;
	return 0;
}