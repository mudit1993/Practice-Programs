#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort

int main () {
  int myints[] = {1,2,3,4,5};
int cnt=1;
  std::sort (myints,myints+5);

  std::cout << "The 3! possible permutations with 3 elements:\n";
  do {std::cout<<cnt++<<'\t';
    std::cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << ' ' << myints[3]<< ' '  << myints[4]<< ' '<<'\n';
  } while ( std::next_permutation(myints,myints+5) );

  //std::cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';

  return 0;
}
