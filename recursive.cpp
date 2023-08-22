#include<iostream>
using namespace std;

int count = 0;

void number_of_zeroes(int num){
    int temp = num%10;
    if(temp == 0){
        count++;
    }
    if(num/10 >= 1){
        number_of_zeroes((num/10));
    }
}

int main()
{
    int a;
    scanf("%d", &a);
    number_of_zeroes(a);
    printf("%d", count);
    return 0;
}