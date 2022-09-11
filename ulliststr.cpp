#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

/**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::push_back(const std::string& val){
		if(tail_ == NULL && head_ == NULL){ //if no items
			head_ = new Item();
			tail_ = head_;
			//head_ = newItem;
			//newItem->first = 0;
			head_->val[head_->last] = val;
			head_->last++;
			size_++;
		}
		else if (tail_->last == ARRSIZE){ //if full
			Item* temp = new Item();
			tail_->next = temp;
			temp->prev = tail_;
			tail_ = temp;
			tail_->val[tail_->last] = val;
			tail_->last++;
			size_++;
		}
		else{ //open space in item
			tail_->val[tail_->last] = val;
			tail_->last++;
		}
	}

  /**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_back(){
		if(head_ == NULL && tail_ == NULL){ //if no items
			return;
		}
		else if (tail_->last == 1 && size_ != 1){ //if empty
			tail_ = tail_->prev;
			tail_->next = NULL;
			size_--;
		}
		if (tail_->last == 1 && size_ == 1){
			clear();
			return;
		}
		else{
			tail_->last--;
		}

	}
  
  /**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
  void ULListStr::push_front(const std::string& val){
		if(tail_ == NULL && head_ == NULL){ //if no items
			head_ = new Item();
			tail_ = head_;
			//head_ = newItem;
			//newItem->first = 0;
			head_->val[head_->first] = val;
			head_->last++;
			size_++;
		}
		else if (head_->first == 0){ //if full
			Item* temp = new Item();
			temp->next = head_;
			head_->prev = temp;
			head_ = temp;
			head_->val[head_->first] = val;
			head_->last++;
			size_++;
		}
		else{ //open space in item
			head_->first--;
			head_->val[head_->first] = val;
		}
	}

  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_front(){
		if(head_ == NULL && tail_ == NULL){ //if no items
			return;
		}	
		else if (head_->first == ARRSIZE - 1 && size_ > 1){ //if empty
			head_ = head_->next;
			head_->prev = nullptr;
			size_--;
		}
		if (head_->first == ARRSIZE - 1 && size_ == 1){
			clear();
			return;
		}
		else{
			head_->first++;
		}

	}

	std::string* ULListStr::getValAtLoc(size_t loc) const{
		Item* temp = head_;
		int value = 0;
		unsigned int i = 0;
		if(loc > size_ * ARRSIZE || loc < 0){ //loc is not in list
			return NULL;
		}
		else if(loc < head_->first){ //for .get(0), if first != 0
			return &head_->val[head_->first];
		}
		else{ //go through each item until loc is reached
			while (i != loc){
				i++;
				value = i % 10;
				if(i % 10 == 0){
					temp = temp->next;
				}
			}
			return &temp->val[value];
		}
	}
	  /**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::back() const{
		return tail_->val[tail_->last-1];
	}

  /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::front() const{
		return head_->val[head_->first];
	}
