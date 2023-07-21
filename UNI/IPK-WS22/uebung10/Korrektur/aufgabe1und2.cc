#include <vector>
#include <iostream>

/*
passt
*/


class BigInteger
{
    std::vector<char> digits;
    
public:
    BigInteger();
    BigInteger(int n);
    BigInteger(std::string);
    
    friend std::ostream& operator<<(std::ostream& os, const BigInteger& b);

    //Aufgabe2:
    BigInteger operator+(const BigInteger& other) const;
    BigInteger& operator+=(const BigInteger& other);
};

BigInteger::BigInteger()
    : digits(){};

BigInteger::BigInteger(int n){
    std::string x = std::to_string(n);
    for(int i = x.length(); i >= 0; i--){
        char deinemum = x[i];
        digits.push_back(deinemum);
    }
    
}

BigInteger::BigInteger(std::string muchogusto){
    for(int i = muchogusto.length(); i >= 0; i--){
        char x = muchogusto[i];
        digits.push_back(x);
    }
}


std::ostream& operator<<(std::ostream& out, const BigInteger& b){
        for(int i = b.digits.size() - 1; i >= 0; i--)
            std::cout << b.digits[i];
        return std::cout<<std::endl;
        }

BigInteger BigInteger::operator+(const BigInteger& other) const {
    BigInteger result;
    int n = digits.size(), m = other.digits.size(), tester = 0;
    if (n < m){
        int t = n;
        n = m;
        m = t;
    }
    if (n >= m){
        for (int i = 1; i < m; i++){
            if (tester != 0){
                char x = digits[i]-48 + other.digits[i] + 1;
                // x = x+1;
                if (x-48 >= 10){
                    result.digits.push_back(x-10);
                } else {
                    tester = 0;
                    result.digits.push_back(x);
                }
            } else {
                char x = digits[i]-48 + other.digits[i];
                if (x-48 >= 10){
                    tester = 1;
                    result.digits.push_back(x-10);
                } else{
                    result.digits.push_back(x);
                }
            }
        }
        if (n > m){
            for (int i = m; i < n; i++){
                if (tester != 0){
                    char x;
                    if (digits.size() > other.digits.size()){
                        x = digits[i] + 1;
                    } else {
                        x = other.digits[i] + 1;
                    }
                    if (x-48 >= 10){
                        result.digits.push_back(x-10);
                    } else {
                        result.digits.push_back(x);
                        tester = 0;
                    }
                } else {
                    if (digits.size() > other.digits.size()){
                        result.digits.push_back(digits[i]);
                    } else {
                        result.digits.push_back(other.digits[i]);
                    }
                }
            }    
        }
    }
    if (tester != 0){
        result.digits.push_back(49);
    }
return result;
};

BigInteger& BigInteger::operator+=(const BigInteger& other){
    *this = *this + other;
    return *this;
    
}

BigInteger operator+(int x, const BigInteger& other){
    BigInteger result;
    result = other + x;
    return result;
}
