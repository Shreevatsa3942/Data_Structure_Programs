//Name:Shreevatsa
//Reg no:200970093
//Modified Date: 21-05-2021
//Program:Program to convert infix expression to prefix Expression using stack
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class infixToPrefix{
	char stack[100];
	int top=-1;	
	string infix;
	int len=0;
public:
	infixToPrefix(string infix){
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
        string prefix;
        //reverse the string expression using prebuild function
        reverse(infix.begin(),infix.end());
        //swap the '(' and ')' braces
        for(int j=0;j<infix.length();j++){

            if(infix[j] == ')') infix[j]='(';
            else
                if(infix[j] == '(') infix[j]=')';
        }

        //loop
        for(int i=0;i<infix.length();i++){
            //checking whether it's an operand or not 
            char c=infix[i];
            //if it's an operand append it to the prefix string
            if(isalpha(c) || isdigit(c)) prefix+=c;
            //if its a opening brace just push it to the stack
            else
                if(c == '(') push(c);
			else
				if(c == ')'){

					while(stack[top] != '(' && top != -1){
						prefix+=stack[top];
						pop();
					}
					//and popping opening brace
					if(stack[top] == '(') pop();

				}
			else if(c == '*' || c == '+' || c == '-' || c == '/' || c == '^'){
				if(top == -1) push(c);
				else{
					if(operator_precedence(c) > operator_precedence(stack[top])) push(c);
					//check wheather there's two '^' operators coming 
					else
						if(operator_precedence(c) == operator_precedence(stack[top]) && c == '^'){

							while(stack[top] == '^'){
								prefix+=stack[top];
								pop();
							}
							push(c);
							
						}
					else
						//not included in the first condition because there might be a chance of getting '^'
						if(operator_precedence(c) == operator_precedence(stack[top])) push(c);
					//if precedence of c is less than precedence of top element in the stack then replace 
					else{
						while(operator_precedence(c) < operator_precedence(stack[top]) && top != -1){
							//popping elements until it's not less than infix charecter 'c' 
							prefix+=stack[top];
							pop();
						}
						//pushing the operator into the stack
						push(c);
					}
				}
			}
			
        }

		//popping all the elements from stack 
		while(top != -1){
			prefix+=stack[top];
			pop();
		}

		//reversing prefix expression
		reverse(prefix.begin(),prefix.end());

        return prefix;
    }
};
int main(){
    string infix;
	cout<<"\nEnter the Infix expression :";
	cin>>infix;
	infixToPrefix expr1(infix);
	cout<<"\nPrefix Expression: "<<expr1.convert_expression();
	cout<<endl;
	return 0;
}