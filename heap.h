#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> heap_;
  int m_; //m-ary tree
  PComparator pcomp_; //Type of comparator?

};

// Add implementation of member functions here
//Constructor
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m_(m), pcomp_(c){

}

//Destructor
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {

}

//Push
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
  heap_.push_back(item);
  //Need a heapify of sorts

  size_t i = heap_.size() - 1; //Index of item
  while (i != 0) {
    size_t parent = (i - 1) / m_; //Parent node of item (divide by amount of children possible)
    if (pcomp_(heap_[i], heap_[parent])) { //If the comparison is true (index better than parent)
      std::swap(heap_[i], heap_[parent]); //Swap item and parent
      i = parent;
    } else {
      break;
    }
  }

}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty Stack");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  //Return top of heap (1st element)
  return heap_[0];


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty Stack");

  }
  //Swap first and last item then remove back
  std::swap(heap_[0], heap_.back());
  heap_.pop_back();

  //Trickle down
  size_t i = 0; //Index of item
  size_t leftChild = 1; //Left child index
  bool breakLoop = false;
  while (leftChild < heap_.size()) { //While still possible children

    size_t betterChildI = leftChild; //The current better child index
    for (size_t c = 1; c <= m_; c++) { //For each child
      size_t currentChildI = leftChild + c; //Current Child index
      if (currentChildI < heap_.size()) { //If it exists in heap (not out of range)
        if (pcomp_(heap_[currentChildI], heap_[betterChildI])) { //If the current child is better than the "betterChild"
          betterChildI = currentChildI; //Set "betterChild" to the better child
        }
      } else {
        breakLoop = true; //If any further changes will be out of scope, break from for loop
        break;
      }
    }

    if (pcomp_(heap_[betterChildI], heap_[i])) { //If the better child is better than the parent node/original item
      std::swap(heap_[i], heap_[betterChildI]); //Swap the node with its "better" child
      i = betterChildI; //Change index to better Child index
      leftChild = (i*m_) + 1; //Update left child
      if (breakLoop == true) { //If out of bounds, end function
        return;
      }
    } else {
      break;
    }
    
    
    
  }

}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
  return heap_.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
  return heap_.size();
}


#endif

