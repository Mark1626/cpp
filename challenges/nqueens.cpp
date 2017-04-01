//Implementation of nqueens from http://www.cl.cam.ac.uk/~mr10/backtrk.pdf
//Seriously awesome link
#include <iostream>
#include <ctime>

using namespace std;

int count;
int all;

void trySolve(int ld, int col, int rd) {

  if(col == all) {
    count++;
  return; 
  }

  int poss = ~(ld | col | rd) & all;

  while(poss) {
    int bit = poss & -poss;
    poss -= bit;
    trySolve( (ld|bit)<<1, col|bit, (rd|bit)>>1);
  }
}

int main() {

  int n;
  cout<<"Enter size of board"<<endl;
  cin>>n;
  
  clock_t tStart = clock();
  count = 0;
  all = (1<<n) - 1;

  trySolve(0, 0, 0);

  cout<<"Total solutions : "<<count<<endl;
  cout<<"Time taken: " <<(double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;

  return 0;
}
