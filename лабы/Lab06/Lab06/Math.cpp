#include "Math.h"


template <typename T>
T modpow(T base, T exp, T modulus) {
    base %= modulus;
    T result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

int mul(int a, int b, int n) {// a*b mod n 
    int sum = 0;

    for (int i = 0; i < b; i++) {
        sum += a;

        if (sum >= n) {
            sum -= n;
        }
    }

    return sum;
}

int power(int a, int b, int n) {// a^b mod n
    int tmp = a;
    int sum = tmp;
    for (int i = 1; i < b; i++) {
        for (int j = 1; j < a; j++) {
            sum += tmp;
            if (sum >= n) {
                sum -= n;
            }
        }
        tmp = sum;
    }
    return tmp;
}


int bitNum(int a)
{
    for (int i = 0; i <= a; i++)
    {
        if (pow(2, i) >= a)
        {
            if (i == 0)  return i + 1;
            else return i;
        }
    }
}