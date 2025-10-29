#include <iostream>
#include <vector>
#define ll long long
using namespace std;

// O(2^n)
int recFib(int a) {
    if (a <= 1) return a;
    return recFib(a - 1) + recFib(a - 2);
}


// O(n) 
int DPFib(int a){
    vector<int>Fib(a + 1);
    Fib[0] = 0;
    Fib[1] = 1;
    for (int i = 2; i <= a; i++){
        Fib[i] = Fib[i - 1] + Fib[i - 2];
    }
    
    return Fib[a];
}

void multi(ll F[2][2], ll M[2][2]){
    ll x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    ll y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    ll z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    ll w = F[1][0] * M[0][1] + F[1][1] * M[1][1];
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power(ll F[2][2], int x){
    if (x == 0 || x == 1)
        return;
    ll M[2][2] = {{1, 1}, {1, 0}};

    power(F, x / 2);
    multi(F, F);

    if (x % 2 != 0)
        multi(F, M);
}

// O(log n)
ll matrixFib(int a){
    if ( a == 0) return 0;
    ll F[2][2] = {{1, 1}, {1, 0}};
    power(F, a - 1);
    return F[0][0];
}




int main(){
    int n = 15;
    cout << endl;
    cout << "Recursive: " <<recFib(n) << endl;
    cout << "Dynamic Programing: " <<DPFib(n) << endl;
    cout << "Matrix Exponentiation: " <<matrixFib(n) << endl;
    cout  << endl;
    return 0;
}