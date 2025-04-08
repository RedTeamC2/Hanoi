#include "Bridges.h"
#include <vector>
#include <iostream>
#include <math.h>
#include "Hanoi.hpp"

using namespace std;
using namespace bridges;

// Recursive function to solve Towers of Hanoi
void moveStack(Hanoi& nt, int from, int to, int howmany) {
  // Base case: if there's only one disk to move
  if (howmany == 1) {
    nt.move(from, to); // Move the single disk
    // Visualize the move
    SymbolCollection sc = nt.getVisual();
    nt.br.setDataStructure(&sc); // Use the Bridges object directly
    nt.br.visualize();
    return;
  }

  // Recursive case:
  int aux = 6 - from - to; // Calculate the auxiliary peg (1 + 2 + 3 = 6)

  // Step 1: Move the top (howmany - 1) disks from "from" to "aux"
  moveStack(nt, from, aux, howmany - 1);

  // Step 2: Move the bottom disk from "from" to "to"
  nt.move(from, to);
  // Visualize the move
  SymbolCollection sc = nt.getVisual();
  nt.br.setDataStructure(&sc); // Use the Bridges object directly
  nt.br.visualize();

  // Step 3: Move the (howmany - 1) disks from "aux" to "to"
  moveStack(nt, aux, to, howmany - 1);
}

int main() {
  // Create Bridges object
  Bridges bridges(126, "homelab192", "1567609189770");
  // Title and description
  bridges.setTitle("Towers of Hanoi");
  bridges.setDescription("Moving only one disk at a time, how to move the first stack to the second stack without ever having a large disk sitting on top of a small disk?");
  
  // Initialize Hanoi with 5 disks
  Hanoi nt(5, bridges);
  
  // Set visualizer type
  SymbolCollection sc = nt.getVisual();
  bridges.setDataStructure(&sc);
  // Visualize the initial state
  bridges.visualize();
  
  // Solve the Towers of Hanoi problem
  moveStack(nt, 1, 2, 5);

  return 0;
}
