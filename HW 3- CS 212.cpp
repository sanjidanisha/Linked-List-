//SANJIDA NISHA 

#include<iostream>
using namespace std;

struct mylist{ //structure to contrain linked list 
  int data;
  mylist *next;
};

int main (){
  int count = 7; // to count the number of elements 
  int i = 1, x; 
  cout<< "Enter list :";

  mylist *head = NULL; //head of the linked list 
  mylist *iter = head; //variable for iteration over linked list 

  while ((i < count) && (x< 50)){
    cin >> x; // taking values from user for list 
    mylist *new_node = new mylist; //creating new node in linked list 
    new_node->data = x;
    new_node->next = NULL;

    if(head == NULL) // for special case when head is null 
    {
      head = new_node;
      iter= head;
    }
    else 
    {
      iter->next = new_node;
      iter = iter-> next; 
    }
    i++; 
  }
  cout << "Entered List: ";
  iter=head;
  while (iter-> next!= NULL){
    cout << iter->data << "->";
    iter = iter->next; 
  }

  cout<< iter-> data<<endl;

  cout<< "Modified List: ";
  i= 1;

  while (i < count){   // loop to sort the linked list 
    mylist *ptr1 = head;
    mylist *ptr2 = head->next;

    while (ptr2!= NULL)
    {
      if(ptr1 -> data > ptr2-> data) //if elements is bigger than the 2nd swap the values 
      {
        int t = ptr1-> data;
        ptr1 -> data = ptr2 -> data;
        ptr2-> data = t;

        ptr1 = ptr2;
        ptr2 = ptr2 -> next;
      }
      else if (ptr1->data == ptr2-> data){   //if the values are the same then delete the node 
        mylist *temp = ptr2; 
        ptr2 = ptr2->next;
        ptr1 -> next = ptr2;

        delete temp;
      }
      else{     //if the first value is bigger, dont swap, just increment the iterators 
        ptr1= ptr2;
        ptr2=ptr2->next;
      }
    }
    i++;
  }
  iter = head;
  while (iter-> next!= NULL){
    cout << iter->data<<"->";
    iter = iter-> next;

  }
  cout << iter-> data<<endl;


  return 0;
}

