// Palindrome.cpp
// By: Sophia Moore
// Created on: 12/07/20

#include <iostream>
#include <string>

using namespace std;

void cleanUp(string& a_string);
// Pre-condition: takes a string
// Post-condition: takes out all non-alphabetical characters and makes everything lowercase

bool isPalindrome(string a_string);
// Pre-condition: takes a string
// Post-condition: returns a boolean value -- true if it's a palindrome, false if it's not

int main() {
    string p;
    cout << "Enter sentence:\n";
    getline(cin, p);
    
    cleanUp(p);
    bool answer = isPalindrome(p);
   
    if (answer) {
        cout << "It is a palindrome.\n";
    } else {
        cout << "It is not a palindrome.\n";
    }

    return 0;
}

void cleanUp(string& a_string)
{
    string new_string;

    for (int i = 0; i < a_string.size(); i++)
    {
        if (isalpha(a_string[i]) != 0) // if it's not a number,
        {
            if ( (a_string[i] >= 97) && (a_string[i] <= 122) ) // if it's lowercase,
            {
                new_string += a_string[i];
            }

            else if ( (a_string[i] >= 65) && (a_string[i] <= 90) ) // else if it's uppercase,
            {
                a_string[i] += 32; // lowercase are 32 away from corresponding uppercase in ascii
                new_string += a_string[i]; // adds all letters to a new string
            }
        }
    }

    a_string = new_string; // setting StringValue equal to new_string
}

bool isPalindrome(string a_string)
{
    if ( (a_string.length() == 1) || (a_string.length() == 0) )
    // if we've reached the middle of the string (or if the string is a single character / nothing)
    {
        return true;
    }

    else if (a_string[0] != a_string[a_string.length()-1])
    // else if corresponding characters in the string aren't the same
    {
        return false;
    }

    // recreating a_string with no first or last characters
    a_string = a_string.substr(1,a_string.length()-2);
    // starting over isPalindrome. #recursion 
    return isPalindrome(a_string);
}

