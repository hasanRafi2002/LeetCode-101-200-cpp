#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(string s){
    int left = 0;
    int right = s.size() - 1;

    while (left<right){
        while (left<right && !isalnum(s[left])) left++;
        while (left<right && !isalnum(s[right])) right--;

        if((tolower(s[left])) != tolower(s[right]))
        return false;

        left++;
        right--;
    }
    return true;
}

int main(){
    string s;
    cout<<"Enter a string: ";
    getline(cin, s);

    if(isPalindrome(s))
        cout<<"true\n";
        else
        cout<<"false\n";

        return 0;
}