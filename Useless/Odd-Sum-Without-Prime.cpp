// alg week13 odd_sum_without_prime
#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int n) {
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {

  int num = 1;
  cin >> num;

  int a = 3, b = 16;
  for (int i = 0; i < num; i++) {
    cin >> a >> b;
    int sum = 0;
    for (int i = a; i <= b; i++) {
      if (!isPrime(i) && i % 2 != 0) {
        sum += i;
      }
    }
    cout << sum << endl;
  }

  return 0;
}

// g++ odd_sum_without_prime.cpp -o /tmp/cpp.out && /tmp/cpp.out
