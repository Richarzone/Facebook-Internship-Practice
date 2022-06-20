#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


bool isBalanced(string s) {
  // Write your code here
  stack<char> stack;
  
  if(s.length() == 1)
  {
    return false;
  }

  for(int i = 0; i < s.length(); i++)
  {
    if(s[i] == '(' || s[i] == '[' || s[i] == '{')
    {
        stack.push(s[i]);
    }
    else if(s[i] == ')' && stack.top() == '(')
    {
        stack.pop();
    }
    else if(s[i] == ']' && stack.top() == '[')
    {
        stack.pop();
    }
    else if(s[i] == '}' && stack.top() == '{')
    {
        stack.pop();
    }
    else
    {
        return false;
    }
  }
  return stack.empty();
}  

// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

void printString(string& str) {
  cout << "[\"" << str << "\"]";
}

int test_case_number = 1;

void check(bool expected, bool output) {
  bool result = (expected == output);
  const char* rightTick = "u8\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printf("%s", expected ? "true" : "false");
    cout << " Your output: ";
    printf("%s", output ? "true" : "false");
    cout << endl; 
  }
  test_case_number++;
}

int main() {

  string s_1 = "{[(])}";
  bool expected_1 = false;
  bool output_1 = isBalanced(s_1);
  check(expected_1, output_1);

  string s_2 = "{{[[(())]]}}";
  bool expected_2 = true;
  bool output_2 = isBalanced(s_2);
  check(expected_2, output_2);

  string s_3 = "]";
  bool expected_3 = false;
  bool output_3 = isBalanced(s_3);
  check(expected_3, output_3);

  string s_4 = "[](){}";
  bool expected_4 = true;
  bool output_4 = isBalanced(s_4);
  check(expected_4, output_4);
  // Add your own test cases here
  
}