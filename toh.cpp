#include "Bridges.h"
#include <vector>
#include <iostream>
#include <math.h>
#include "Hanoi.hpp"

using namespace std;
using namespace bridges;


void moveStack(Hanoi& nt, int from, int to, int howmany) {
  //TODO
  
}

int main() {
  //create Bridges object
  Bridges bridges (126, "YOUR_USER_ID", "YOUR_API_KEY");
  // title, description
  bridges.setTitle("Towers of Hanoi");
  bridges.setDescription("Moving only one disk at a time, how to move the first stack to the second stack without ever having a large disk sittign ontop of a small disk?");
  
  Hanoi nt (5, bridges);
  
  // set visualizer type
  SymbolCollection sc = nt.getVisual();
  bridges.setDataStructure(&sc);
  // visualize the JSON and Collection
  bridges.visualize();
  

  moveStack(nt, 1, 2, 5);
		
  // nt.move(1,2);
  // // set visualizer type
  // bridges.setDataStructure(nt.getVisual());
  // // visualize the JSON and Collection
  // bridges.visualize();

  return 0;
}
