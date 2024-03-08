#pragma warning(disable: 6001)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <regex>

//#include <bits/stdc++.h>

using namespace std;

typedef struct bigNum {
    char sign;
    char num[101];
};

bigNum add(bigNum& a, bigNum& b) {
    bigNum result = { '1', "0" };
    int carry = 0;
    int lenA = strlen(a.num);
    int lenB = strlen(b.num);
    if (lenA + lenB >= 101) {
        cout << "Overflow when add!" << endl;
        exit(0);
    }
    int maxLength = max(lenA, lenB);
    result.sign = a.sign;

    for (int i = 0; i < maxLength; i++) {
        int digitA = i < lenA ? a.num[lenA - i - 1] - '0' : 0;
        int digitB = i < lenB ? b.num[lenB - i - 1] - '0' : 0;

        int sum = digitA + digitB + carry;
        result.num[maxLength - i - 1] = sum % 10 + '0';
        carry = sum / 10;
    }
    result.num[maxLength] = '\0';

    if (carry > 0) {
        if (maxLength == 101) {
            cout << "Overflow when add!" << endl;
            exit(0);
        }
        else {
            for (int i = 1; i <= maxLength; i++) {
                result.num[maxLength + 1 - i] = result.num[maxLength - i];
            }
            result.num[0] = '1';
            result.num[maxLength + 1] = '\0';

        }
    }

    return result;
}

bigNum subtract(bigNum& a, bigNum& b) {
    bigNum result;
    int borrow = 0;
    char tempA[101];
    char tempB[101];

    int lenA = strlen(a.num);
    int lenB = strlen(b.num);
    int maxLength = max(lenA, lenB);

    if (lenA > lenB || (lenA == lenB && strcmp(a.num, b.num) > 0)) {
        result.sign = a.sign;
        strcpy(tempA, a.num);
        strcpy(tempB, b.num);
    }
    else {
        result.sign = '0' + '1' - a.sign;
        strcpy(tempA, b.num);
        strcpy(tempB, a.num);
    }

    lenA = strlen(tempA);
    lenB = strlen(tempB);

    for (int i = 0; i < maxLength; ++i) {
        int digitA = i < lenA ? tempA[lenA - i - 1] - '0' : 0;
        int digitB = i < lenB ? tempB[lenB - i - 1] - '0' : 0;

        int diff = digitA - digitB - borrow;

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        }
        else {
            borrow = 0;
        }

        result.num[maxLength - i - 1] = diff + '0';
    }
    result.num[maxLength] = '\0';

    int zeroIndex = 0;
    while (result.num[zeroIndex] == '0')
        zeroIndex++;
    for (int i = 0; i < maxLength - zeroIndex; i++) {
        result.num[i] = result.num[zeroIndex + i];
    }
    result.num[maxLength - zeroIndex] = '\0';

    return result;
}

//////////////////////////////////////////////////////////
/* KARATSUBA ALGORITHM ON GEEKSFORGEEKS*/

// Function to find the sum of larger numbers represented as a string
string findSum(string str1, string str2)
{
    // Before proceeding further, make
    // sure length of str2 is larger
    if (str1.length() > str2.length())
        swap(str1, str2);

    // Stores the result
    string str = "";

    // Calculate length of both string
    int n1 = str1.length();
    int n2 = str2.length();

    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i = 0; i < n1; i++) {

        // Find the sum of the current
        // digits and carry
        int sum
            = ((str1[i] - '0')
                + (str2[i] - '0')
                + carry);
        str.push_back(sum % 10 + '0');

        // Calculate carry for next step
        carry = sum / 10;
    }

    // Add remaining digits of larger number
    for (int i = n1; i < n2; i++) {
        int sum = ((str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    // Add remaining carry
    if (carry)
        str.push_back(carry + '0');

    // Reverse resultant string
    reverse(str.begin(), str.end());

    return str;
}

// Function to find difference of larger numbers represented as strings
string findDiff(string str1, string str2)
{
    // Stores the result of difference
    string str = "";

    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();

    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;

    // Run loop till small string length
    // and subtract digit of str1 to str2
    for (int i = 0; i < n2; i++) {

        // Compute difference of the
        // current digits
        int sub
            = ((str1[i] - '0')
                - (str2[i] - '0')
                - carry);

        // If subtraction < 0 then add 10
        // into sub and take carry as 1
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    // Subtract the remaining digits of
    // larger number
    for (int i = n2; i < n1; i++) {
        int sub = ((str1[i] - '0') - carry);

        // If the sub value is -ve,
        // then make it positive
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    // Reverse resultant string
    reverse(str.begin(), str.end());

    // Return answer
    return str;
}

// Function to remove all leading 0s from a given string
string removeLeadingZeros(string str)
{
    // Regex to remove leading 0s
    // from a string
    const regex pattern("^0+(?!$)");

    // Replaces the matched value
    // with given string
    str = regex_replace(str, pattern, "");
    return str;
}

// Function to multiply two numbers using Karatsuba algorithm
string multiply(string A, string B)
{
    if (A.length() > B.length())
        swap(A, B);

    // Make both numbers to have
    // same digits
    int n1 = A.length(), n2 = B.length();
    while (n2 > n1) {
        A = "0" + A;
        n1++;
    }

    // Base case
    if (n1 == 1) {

        // If the length of strings is 1,
        // then return their product
        int ans = stoi(A) * stoi(B);
        return to_string(ans);
    }

    // Add zeros in the beginning of
    // the strings when length is odd
    if (n1 % 2 == 1) {
        n1++;
        A = "0" + A;
        B = "0" + B;
    }

    string Al, Ar, Bl, Br;

    // Find the values of Al, Ar,
    // Bl, and Br.
    for (int i = 0; i < n1 / 2; ++i) {
        Al += A[i];
        Bl += B[i];
        Ar += A[n1 / 2 + i];
        Br += B[n1 / 2 + i];
    }

    // Recursively call the function
    // to compute smaller product

    // Stores the value of Al * Bl
    string p = multiply(Al, Bl);

    // Stores the value of Ar * Br
    string q = multiply(Ar, Br);

    // Stores value of ((Al + Ar)*(Bl + Br)
    // - Al*Bl - Ar*Br)
    string r = findDiff(
        multiply(findSum(Al, Ar),
            findSum(Bl, Br)),
        findSum(p, q));

    // Multiply p by 10^n
    for (int i = 0; i < n1; ++i)
        p = p + "0";

    // Multiply s by 10^(n/2)
    for (int i = 0; i < n1 / 2; ++i)
        r = r + "0";

    // Calculate final answer p + r + s
    string ans = findSum(p, findSum(q, r));

    // Remove leading zeroes from ans
    ans = removeLeadingZeros(ans);

    // Return Answer
    return ans;
}


//////////////////////////////////////////////////////////////


bigNum multiply(bigNum& a, bigNum& b) {
    bigNum result;
    int lenA = strlen(a.num);
    int lenB = strlen(b.num);
    if (lenA + lenB >= 101) {
        printf("Overflow when multiply!\n");
        exit(0);
    }

    result.sign = (a.sign == b.sign) ? '1' : '0';

    string numberA(a.num);
    string numberB(b.num);

    string ans = multiply(numberA, numberB);
    strcpy(result.num, ans.c_str());

    return result;
}

// Toán tử cộng
bigNum operator +(bigNum& a, bigNum& b) {
    if (a.sign == b.sign)
        return add(a, b);
    else
        return subtract(a, b);
}

// Toán tử trừ
bigNum operator -(bigNum& a, bigNum& b) {
    if (a.sign != b.sign) {
        bigNum tempB = b;
        b.sign = '0' + '1' - b.sign;
        return add(a, b);
    }
    else
        return subtract(a, b);
}

// Toán tử nhân
bigNum operator *(bigNum& a, bigNum& b) {
    return multiply(a, b);
}

int main() {
    bigNum a, b;
    cin >> a.sign >> a.num;
    cin >> b.sign >> b.num;

    //result = ab
    bigNum ans = a * b;
    
    ans = ans - a;
    ans = ans - a;
    ans = ans - a;

    ans = ans + b;
    ans = ans + b;
    ans = ans + b;
    ans = ans + b;

    cout << ans.sign << ans.num << endl;

    return 0;
}