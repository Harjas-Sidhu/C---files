// #include<iostream>
// #include<math.h>
// using namespace std;

// int counter = 0;

// float geometric_sum(int num){
//     float g_sum = 0;
//     g_sum += 1/pow(2, counter);
//     counter++;
//     if(counter <= num){
//         g_sum += geometric_sum(num);
//     }
    
//     return g_sum;
// }

// int main()
// {
//     int a;
//     scanf("%d", &a);
//     printf("%f", geometric_sum(a));
//     return 0;
// }

#include <iostream>
#include <math.h>
using namespace std;

double geometricSum(int k) {
    if(k==0){
        return 1;
    }
    return (1/pow(2,k))+ geometricSum(k-1);
}

int main()
{
    int k; cin>>k;
    cout<<geometricSum(k);

}