#include <iostream>
#include "split.h"
using namespace std;

int main(){
  //Node* start = new Node(1, nullptr);
  Node* start = new Node(1, nullptr);
  Node* odds = nullptr;
  Node* evens = nullptr;
  for(int i = 2; i < 21; i++){
    Node* nextnode = new Node(i, start);
    start = nextnode;
  }

  split(start, odds, evens);

  Node* iterator = evens;
  for(int i = 0; i < 10; i++){
    //cout << evens->value << endl;
    if(iterator != nullptr){
      cout << iterator->value << endl;
      if (iterator->next != nullptr){
        iterator = iterator->next;
      }
    }
  }
  Node* iterator2 = odds;
  for(int i = 0; i < 10; i++){
    if(iterator2 != nullptr){
      cout << iterator2->value << endl;
      if (iterator2->next != nullptr){
        iterator2 = iterator2->next;
      }
    }
  }
}