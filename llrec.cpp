#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
    //Initializing
    smaller = nullptr;
    larger = nullptr;

    //If head is empty
    if (head == nullptr) {
        return;
    }

    //If head is smaller than pivot
    if (head->val <= pivot) {
        smaller = head;
        head = head->next;
        llpivot(head, smaller->next, larger, pivot);
    } else if (head->val > pivot) { //If pivot greater
        larger = head;
        head = head->next;
        llpivot(head, smaller, larger->next, pivot);
    }

}
