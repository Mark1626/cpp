// Sort array based on number of factors
#include <iostream>
#include <cmath>

using namespace std;

class data{
  public:
    int val;
    int factors;
    void swp(data &a) {
      data temp;
      temp.val = a.val;
      temp.factors = a.factors;
      a.val = val;
      a.factors = factors;
      val = temp.val;
      factors = temp.factors;
    }
    int cmp(data a) {
       if(factors > a.factors)
        return 1;
       else if(factors == a.factors) {
          if(val > a.val)
            return 1;
       }
      return 0;
    }
};

int factors[100];
void sieve(int limit) {

  int cnt, i, j, temp;
  factors[0] = factors[1] = 1;
  for(i=2;i<=limit;++i)
    factors[i] = 1;

  // Sieve of erathosthenes
  for(i=2 ;i <= sqrt(limit); ++i) {
    if(factors[i] == 1) {
      for(j=i+i; j <= limit; j+=i) {
        temp = j;
        cnt = 0;
        while(temp%i == 0) {
          temp/=i;
          ++cnt;
        }
        factors[j] *= (1+cnt);
      }
    }
  }
}

int main() {
  int n, i, j;
  cin >> n;
  int a[n];
  data Val[n];

  int m = 0;
  for(i=0; i < n; ++i) {
    cin>>a[i];
    if(m < a[i])
      m = a[i];
  }

  sieve(m);
  for(i=0; i < n; ++i) {
    Val[i].val = a[i];
    Val[i].factors = factors[a[i]];
  }

  //Sort the new structure
  for(i=0; i < n; ++i) {
    for(j=i+1; j < n; ++j) {
      if(Val[i].cmp(Val[j])) {
        Val[i].swp(Val[j]);
      }
    }
  } 

  cout << endl;
  for(i=0; i < n; ++i)  {
    cout << Val[i].val << " ";
  }
  cout << endl;

  return 0;
}
