#ifndef __HANOI_HPP__
#define __HANOI_HPP__

#include <vector>
#include "Bridges.h"
#include "SymbolCollection.h"
#include "Rectangle.h"

using namespace bridges;

class Hanoi {

private:
  std::vector<int> d1;
  std::vector<int> d2;
  std::vector<int> d3;
  int nbdisk;
	    
  Bridges& br;

public:
  Hanoi(int nbdisk, Bridges& b) :
    nbdisk(nbdisk), br (b)
  {
    for (int i=0; i<nbdisk; ++i) {
      d1.push_back(nbdisk-i);
    }
  }

  void move(int src, int dst) {
    int d = -1;
    std::vector<int>* srcal = nullptr;
    std::vector<int>* dstal = nullptr;
    if (src == 1) {
      srcal = &d1;
    }
    if (src == 2) {
      srcal = &d2;
    }
    if (src == 3) {
      srcal = &d3;
    }
    //
    if (dst == 1) {
      dstal = &d1;
    }	
    if (dst == 2) {
      dstal = &d2;
    }	
    if (dst == 3) {
      dstal = &d3;
    }
    
    //TODO: should throw exception if the move is invalid
    
    if (dstal->size()>0
	&& (*srcal)[srcal->size()-1] > (*dstal)[dstal->size()-1])
      throw new std::string("Illegal Move");
    
    //pop
    d = (*srcal)[srcal->size()-1];
    srcal->pop_back();
    //push
    dstal->push_back(d);
    
    // set visualizer type
    SymbolCollection sc = this->getVisual();
    br.setDataStructure(&sc);
    // visualize the JSON and Collection
    br.visualize();
    
  }
    

  SymbolCollection getVisual() {
    SymbolCollection sc;
    
    float diskheight = 10;
    float diskunitwidth = 20;
    float pegheight = (nbdisk+1) * diskheight;
    float pegspacing = (nbdisk+3)*diskunitwidth;
    
    sc.setViewport(-10.f-nbdisk*diskunitwidth, 10.f-nbdisk*diskunitwidth+3*pegspacing,
		   -10.f, pegheight+20.f);
    
    
    //peg
    Rectangle p1 (-1.0f, 0.0f, 2.0f, pegheight);
    p1.setFillColor("black");
    sc.addSymbol(p1);

    Rectangle p2 (-1.0f+pegspacing, 0.0f, 2.0f, pegheight);
    p2.setFillColor("black");
    sc.addSymbol(p2);

    Rectangle p3 (-1.0f+2*pegspacing, 0.0f, 2.0f, pegheight);
    p3.setFillColor("black");
    sc.addSymbol(p3);

    //disks
    //peg1
    for (int i=0; i<d1.size(); ++i) {
      int disksize = d1[i];
      Rectangle disk (-1.0f-disksize/2.f*diskunitwidth, 0.0f+diskheight*i, diskunitwidth*disksize, diskheight);
      disk.setFillColor("black");
      sc.addSymbol(disk);
    }
    
    //peg2
    for (int i=0; i<d2.size(); ++i) {
      int disksize = d2[i];
      Rectangle disk (-1.0f-disksize/2.f*diskunitwidth+pegspacing, 0.0f+diskheight*i, diskunitwidth*disksize, diskheight);
      disk.setFillColor("black");
      sc.addSymbol(disk);
    }

    //peg3
    for (int i=0; i<d3.size(); ++i) {
      int disksize = d3[i];
      Rectangle disk (-1.0f-disksize/2.f*diskunitwidth+2*pegspacing, 0.0f+diskheight*i, diskunitwidth*disksize, diskheight);
      disk.setFillColor("black");
      sc.addSymbol(disk);
    }

    return sc;
  }
};


#endif
