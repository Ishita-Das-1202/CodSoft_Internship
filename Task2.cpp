//SIMPLE CALCULATOR
/*Develop  a calculator program  that performs basic arithmetic operations such as addition, subtraction ,multiplication 
,and division. Allow the user to input two  numbers and choose an operation to perform*/
#include <iostream>
using namespace std;
int main() {
    double num1, num2, result;
    char operation;

    // Get user input
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    // Get the operation choice from the user
    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    // Perform the selected operation
    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
                return 1; // Exit with an error code
            }
            break;
        default:
            cout << "Invalid operation. Please choose +, -, *, or /." << endl;
            return 1; // Exit with an error code
    }

    // Display the result
    cout << "Result: " << num1 << " " << operation << " " << num2 << " = " << result << endl;

    return 0;
}

/*// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    double num1,num2,result;
    char operation;
     cout<<"Enter the 1st number:";
     cin>>num1;
     cout<<"Enter the 2nd number:";
     cin>>num2;
     cout<<"Choose the operation (+, -, *, /): ";
    cin>>operation;
    switch(operation)
    {
        case '+':
        result = num1 + num2;
        break;
        case '-':
        result=num1-num2;
        break;
        case '*':
        result=num1*num2;
        break;
        case '/':
          if(num2 !=0)
           {
               result=num1/num2;
           }
           else
           {
               cout<<"Division by 0 is not possible"<<endl;
               //return 1;
           }
           break;
         default :
           cout<<"Invalid operation must choose among(+,-,*,/)"<<endl;
           //return 1;
             
    }
    cout<<"Result "<<num1<<" "<<operation<<" "<<num2<<" "<<"="<<result ;
    return 0;
}*/