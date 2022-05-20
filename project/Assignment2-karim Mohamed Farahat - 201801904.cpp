/*
#include <iostream>
#include"ArrayStack.h"

int main()
{
    char x;
    char ex;
    std::string InFix;
    std::cout << "please enter the expression " << std:: endl ;
    std::cin >> InFix;
    int N = InFix.size();
    ArrayStack<char> PostFix(N);
    ArrayStack<char> Exprs(N);
    
    for (int i = 0; i < N; i++) {
        x = InFix[i];

        if (x == '+')
        {
            Exprs.peek(ex);
            if ( ex == '*' || ex == '/'  ) {
                while (Exprs.peek(ex))
                {

                    if (ex == '(')
                    {
                        Exprs.pop(ex);
                        Exprs.push(x);
                        break;
                      
                    }
                    else if (ex == '*' || ex == '/' || ex == '-' || ex == '+') {
                        Exprs.pop(ex);
                        PostFix.push(ex); }
                   
                }
                if (Exprs.isEmpty())Exprs.push(x);
            }
            else if (ex == '+'|| ex == '-' ) {
                
                Exprs.push(x);
            }
            else if (ex == '(') {
                Exprs.push(x);
            }
            else {
                Exprs.push(x);
            }

        }
        else if (x == '-')
        {
            Exprs.peek(ex);
            if (ex == '*' || ex == '/') {
                while (Exprs.peek(ex))
                {

                    if (ex == '(')
                    {
                        Exprs.pop(ex);
                        Exprs.push(x);
                        break;

                    }
                    else if (ex == '*' || ex == '/' || ex == '-' || ex == '+') {
                        Exprs.pop(ex);
                        PostFix.push(ex);
                    }

                }
                if (Exprs.isEmpty())Exprs.push(x);
            }
            else if (ex == '+' || ex == '-') {

                Exprs.push(x);
            }
            else if (ex == '(') {
                Exprs.push(x);
            }
            else {
                Exprs.push(x);
            }

        }
        else if (x == '*')
        {
            Exprs.push(x);
        }
        else if (x == '/')
        {
        Exprs.push(x);
        }
        else if (x == '(') {
        Exprs.push(x);
        }
        else if (x == ')') {
            while (Exprs.pop(ex)) 
            {

                if (ex == '(')
                {
                    break;
                }
                else { PostFix.push(ex); }

            }
        }
        else {
        PostFix.push(x);

        }
    }
    while (Exprs.pop(x)) {
        PostFix.push(x);
    }
    
    
    ArrayStack<char> print(N);
    while (PostFix.pop(x)) 
    {
        print.push(x);
    }
    while (print.pop(x)) {
        std::cout << x;
    }
    
}


*/