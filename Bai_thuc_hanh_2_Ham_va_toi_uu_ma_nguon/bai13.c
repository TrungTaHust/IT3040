#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

struct bigNum {
    char sign;
    char num[101];
};

bigNum add(const bigNum& a, const bigNum& b) {
    bigNum result;
    int carry = 0;
    int lenA = strlen(a.num);
    int lenB = strlen(b.num);
    int maxLength = max(lenA, lenB);

    for (int i = 0; i < maxLength; ++i) {
        int digitA = i < lenA ? a.num[lenA - i - 1] - '0' : 0;
        int digitB = i < lenB ? b.num[lenB - i - 1] - '0' : 0;

        int sum = digitA + digitB + carry;
        result.num[i] = sum % 10 + '0';
        carry = sum / 10;
    }

    if (carry > 0) {
        result.num[maxLength] = carry + '0';
        result.num[maxLength + 1] = '\0';
    }
    else {
        result.num[maxLength] = '\0';
    }

    return result;
}

bigNum multiply(const bigNum& a, const bigNum& b) {
    bigNum result;
    bigNum temp;
    result.sign = '1';
    temp.sign = '1';

    int lenA = strlen(a.num);
    int lenB = strlen(b.num);

    for (int i = 0; i < lenB; ++i) {
        int digitB = b.num[lenB - i - 1] - '0';
        int carry = 0;

        for (int j = 0; j < lenA; ++j) {
            int digitA = a.num[lenA - j - 1] - '0';
            int product = digitA * digitB + carry;
            temp.num[j] = product % 10 + '0';
            carry = product / 10;
        }

        if (carry > 0) {
            temp.num[lenA] = carry + '0';
            temp.num[lenA + 1] = '\0';
        }
        else {
            temp.num[lenA] = '\0';
        }

        for (int k = 0; k < i; ++k) {
            strcat(temp.num, "0");
        }

        result = add(result, temp);
    }

    return result;
}

bigNum subtract(const bigNum& a, const bigNum& b) {
    bigNum result;
    int borrow = 0;
    int lenA = strlen(a.num);
    int lenB = strlen(b.num);
    int maxLength = max(lenA, lenB);

    for (int i = 0; i < maxLength; ++i) {
        int digitA = i < lenA ? a.num[lenA - i - 1] - '0' : 0;
        int digitB = i < lenB ? b.num[lenB - i - 1] - '0' : 0;

        int diff = digitA - digitB - borrow;

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        }
        else {
            borrow = 0;
        }

        result.num[i] = diff + '0';
    }

    while (result.num[maxLength - 1] == '0' && maxLength > 1) {
        maxLength--;
    }

    result.num[maxLength] = '\0';

    return result;
}

int main() {
    bigNum a, b;
    cin >> a.sign >> a.num;
    cin >> b.sign >> b.num;

    bigNum ab_minus_3a_plus_4b = subtract(multiply(a, b), add(multiply(a, b), add(a, add(b, add(b, b)))));

    if (ab_minus_3a_plus_4b.sign == '0') {
        cout << "-";
    }

    cout << ab_minus_3a_plus_4b.num << endl;

    return 0;
}

