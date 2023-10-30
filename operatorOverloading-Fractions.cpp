#include <bits/stdc++.h>
using namespace std;

int lcm(int num1, int num2){
    int multiplier = 1;
    while((num1*multiplier)%num2){
        multiplier++;
    }
    return num1*multiplier;
}

class Fraction{
    public:
        int numerator;
        int denominator;
        Fraction(int numerator, int denominator){
            this->numerator = numerator;
            this->denominator = denominator;
        }
        Fraction operator+(Fraction f1){
            int common_denominator = lcm(this->denominator, f1.denominator);
            int common_numerator = (this->numerator*(common_denominator/this->denominator)) + (f1.numerator*(common_denominator/f1.denominator));
            Fraction result(common_numerator, common_denominator);
            return result;
        }
        Fraction operator-(Fraction f1){
            int common_denominator = lcm(this->denominator, f1.denominator);
            int common_numerator = (this->numerator*(common_denominator/this->denominator)) - (f1.numerator*(common_denominator/f1.denominator));
            Fraction result(common_numerator, common_denominator);
            return result;
        }
        Fraction operator*(Fraction f1){
            int common_denominator = this->denominator*f1.denominator;
            int common_numerator = (this->numerator* f1.numerator);
            Fraction result(common_numerator, common_denominator);
            return result;
        }
        Fraction operator/(Fraction f1){
            int common_denominator = this->denominator*f1.numerator;
            int common_numerator = (this->numerator* f1.denominator);
            Fraction result(common_numerator, common_denominator);
            return result;
        }
        void print(){
            cout<<this->numerator<<"/"<<this->denominator;
        }
};

int main(){
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3 = f1+f2;
    Fraction f4 = f1-f2;
    Fraction f5 = f1*f2;
    Fraction f6 = f1/f2;
    f1.print();
    cout<<" + ";
    f2.print();
    cout<<" = ";
    f3.print();
    cout<<endl;
    f1.print();
    cout<<" - ";
    f2.print();
    cout<<" = ";
    f4.print();
    cout<<endl;
    f1.print();
    cout<<" * ";
    f2.print();
    cout<<" = ";
    f5.print();
    cout<<endl;
    f1.print();
    cout<<" / ";
    f2.print();
    cout<<" = ";
    f6.print();
    cout<<endl;
    return 0;
}