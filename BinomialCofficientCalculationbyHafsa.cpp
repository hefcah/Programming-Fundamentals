
#include <iostream>
using namespace std;
int main()
 {
    int n, k, j, binom_coff,num;
    int fact=1;
    int fact_n;
    int fact_k;
    cout<<"enter number"<<endl;
    cin>>num;
    cout<<"enter value for n"<<endl;
    cin>>n;
    cout<<"enter value for k"<<endl;
    cin>>k;
    for (int i = 1; i <= n; i++) {
        fact_n *= i;
        if (i <= k) {
            fact_k *= i;
        }
    binom_coff=n*fact/(k*fact*(n-k)*fact;
    cout<<"binomial coefficient = "<<binom_coff<<endl;
    return 0;
}
