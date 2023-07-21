#include <vector>
#include <iostream>
#include <string>


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

int main(){


    std::cout<<"Aufgabe1: "<<std::endl;
    BigInteger x2(12900441);
    BigInteger x3("6546546546546464646465131654984154654651981651981619851098419854189561985641985641795641985461985419856419856419865419856419865198519856198564198561985619+851874561789561985616519865198161123");
    std::cout << "x2 hat Wert: " << x2 << std::endl;
    std::cout << "x3 hat Wert: " << x3 << std::endl;

    std::cout<<"Aufgabe2: "<<std::endl;
    BigInteger int1(99);
    BigInteger int2(9);

    BigInteger string1("999");
    BigInteger string2("9999");

    BigInteger intadd;
    intadd = int1 + int2;
    std::cout<<"Wert von BigInteger intadd, wenn 2 integer addiert = "<<intadd<<std::endl;
    BigInteger stringadd;
    stringadd = string1 + string2;
    std::cout<<"Wert von BigInteger stringadd nachdem 2 strings miteinander addiert wurden = "<<stringadd<<std::endl;
    
    BigInteger plusgleich;
    plusgleich += int1;
    std::cout<<"Wert von BigInteger plusgleich nachdem operator += benutzt wurde = "<<plusgleich<<std::endl;

    std::cout<<"Aufgabe 2b: "<<std::endl;
    BigInteger a(1);
    int b = 1;
    std::cout<< "1 + 1 = " <<b + a<<std::endl;

    
    return 0;
}