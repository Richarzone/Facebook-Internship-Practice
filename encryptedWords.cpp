#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

string findEncryptedWord(string s) {
  // Write your code here
  string ans = "";
  int mid;
  int sLenght = s.length();

  if(sLenght <= 2)
  {
    return s;
  }

  if(!(sLenght&1))
  {
    mid = (sLenght / 2) - 1;
  }
  else
  {
    mid = sLenght / 2; 
  }

  ans += s[mid];

  string left = s.substr(0, mid);
  string right = s.substr(mid+1, sLenght);
  
  ans += findEncryptedWord(left);
  ans += findEncryptedWord(right);

  return ans;
}

// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

void printString(string& str) {
  cout << "[\"" << str << "\"]";
}

int test_case_number = 1;

void check(string& expected, string& output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << " Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << " Test #" << test_case_number << ": Expected ";
    printString(expected); 
    cout << " Your output: ";
    printString(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {

  string s_1 = "abc";
  string expected_1 = "bac";
  string output_1 = findEncryptedWord(s_1);
  check(expected_1, output_1);

  string s_2 = "abcd";
  string expected_2 = "bacd";
  string output_2 = findEncryptedWord(s_2);
  check(expected_2, output_2);

  // Add your own test cases here
  string s_3 = "facebook";
  string expected_3 = "eafcobok";
  string output_3 = findEncryptedWord(s_3);
  check(expected_3, output_3);  
}