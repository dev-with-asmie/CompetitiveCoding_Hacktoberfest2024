#include <iostream>
#include <stack>

using namespace std;

// Function to check if the input string of brackets is valid
bool isValid(string s) {
    // Stack to store open brackets
    stack<char> stk;
    
    // Loop through each character in the string
    for (char ch : s) {
        // If it's an opening bracket, push it onto the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            stk.push(ch);
        } 
        // If it's a closing bracket, check for matching opening bracket
        else {
            // If stack is empty, there is no opening bracket to match
            if (stk.empty()) return false;

            char top = stk.top();
            // Check if the top of the stack matches the corresponding open bracket
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;  // Bracket mismatch
            }
            // If valid, pop the opening bracket from the stack
            stk.pop();
        }
    }

    // In the end, the stack should be empty if all brackets were matched
    return stk.empty();
}

int main() {
    string s;
    cout << "Enter a string of brackets: ";
    cin >> s;

    // Calling the function to check if the string is valid
    if (isValid(s)) {
        cout << "The string is valid." << endl;
    } else {
        cout << "The string is invalid." << endl;
    }

    return 0;
}
