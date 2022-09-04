/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <iostream>

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
  //if(odds = nullptr){
  //}
  if(in == nullptr){
    return;
  }
  else {
    if(in->value % 2 == 0){
      //evens->value = in->value;
      //in = nullptr;
      //evens->value = in->value;
      evens = in;
      in = in->next;
      evens->next = nullptr;
      split(in, odds, evens->next);
      //cout << evens->value << endl;
      //in = nullptr;
      //cout << in->value << endl;
    }
    else{
      //in = nullptr;
      //odds->value = in->value;
      odds = in;
      in = in->next;
      odds->next = nullptr;
      split(in, odds->next, evens);
      //cout << odds->value << endl;
      //in = nullptr;
      //cout << in->value << endl;
      
    }
      //split(in->next, odds, evens);
  }
  

}

/* If you needed a helper function, write it here */

// WRITE YOUR CODE HERE