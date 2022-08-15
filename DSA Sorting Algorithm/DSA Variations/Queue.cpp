/*  LINEAR ARRAY QUEUE*/
#define MAX_QUEUE 12
class Queue
{ private:
 int front; // index at front
 int back; // index at rear queue
 char items[MAX_QUEUE]; //store item in Q
 public:
 Queue(); // Constructor - create Q
 ~Queue(); // Destructor - destroy Q
 bool isEmpty(); // check Q empty
 bool isFull(); // check Q full
 void enQueue(char); // insert into Q
 void deQueue(); // remove item from Q
 char getFront(); // get item at Front
 char getRear(); // get item at back Q
}; 

/************
 * Con/De constractors
************/
Queue::Queue()
{ front = 0;
 back = -1;
 /* in Circular
 int count = 0, front = 0,
 back = MAX_QUEUE – 1;
 */
}
Queue::~queue()
{ delete [ ] items; } 

/************
 * Checkers
************/
bool Queue::isEmpty()
{ return bool(back < front); } 
bool Queue::isFull()
{ return bool(back == size – 1); }

/************
 * Insertion & delation
************/
void Queue::enQueue(char insertItem)
{ if (isFull())
 cout<< "\nCannot Insert. Queue is full!";
 else
 { //insert at back
 back++;
 //back = ( back + 1 ) % MAX_QUEUE;
 //++count;

 items[back] = insertItem;
 } // end else if
}

void Queue::deQueue()
{ if (isEmpty())
 cout<< "\nCannot remove item. Empty Queue!";
 else
 { //retrieve item at front
 deletedItem = items[front];
 front++;
//  front = ( front + 1 ) % MAX_QUEUE;
// --count;
 } // end else if
} 


/************
 * Retrieve
************/

char Queue::getFront() // get item at Front
{ return items[front] ; }
char Queue::getRear() // get item at Back
{ return items[back] ; } 
