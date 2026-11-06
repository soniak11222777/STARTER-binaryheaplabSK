// heap.cpp
// Diba Mirza

#include "heap.h"
#include <iostream>
using std::cout;

// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end) : vdata(start, end){
int n = vdata.size();
for (int i = n/2 -1 ; i>=0; i--){
int smaller;
int ind = i;
while (((2*ind)+1) < vdata.size()){
if (((2*ind)+2) < vdata.size()){
if(vdata.at(2*(ind)+2) > vdata.at(2*(ind)+1)){
    smaller = (2*ind)+1;
  }else{
    smaller = (2*ind)+2;
  }
} else {
  smaller = (2*ind)+1;
}

if(vdata.at(ind) > vdata.at(smaller)){
  int temp = vdata.at(smaller);
  vdata.at(smaller) = vdata.at(ind);
  vdata.at(ind) = temp;
  ind = smaller;
} else{
  break;
}
}
}
}

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
vdata.push_back(value);
int i = vdata.size()-1;
while( i > 0 && vdata.at((i-1)/2) >= vdata.at(i))  {
  int temp = vdata.at((i-1)/2);
  vdata.at((i-1)/2) = vdata.at(i);
  vdata.at(i) = temp;
  i = (i-1)/2;
}
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
if(vdata.empty()){
  return;
} else if (vdata.size() == 1){
  vdata.pop_back();
  return;
}
vdata.front() = vdata.back();
vdata.pop_back();
int i = 0;
int smaller;
while(i != vdata.size() && (2*(i)+1) < vdata.size()) {
if ((2*(i)+2) < vdata.size()){
  if (vdata.at(2*(i)+2) > vdata.at(2*(i)+1)){
    smaller = 2*(i)+1;
  }else{
    smaller = 2*(i)+2;
  }
} else {
  smaller = 2*(i)+1;
}
if (vdata.at(i)>vdata.at(smaller)){
  int temp = vdata.at(smaller);
  vdata.at(smaller) = vdata.at(i);
  vdata.at(i) = temp;
  i = smaller;
}else{
  return;
}
}
}

// Returns the minimum element in the heap
int Heap::top(){
  if (!vdata.empty()){
  return vdata.front(); 
  }
  return 0;
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  if (vdata.size()==0){
    return true;
  }
  return false;
}
    