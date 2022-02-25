
#include <iostream>
using namespace std;

int mutex = 1;

int full = 0;

int empty, x = 0;

// Function to produce an item and add it to the buffer
void producer()
{
    --mutex; //mutex lock so that only one producer can enter the buffer at a time

    ++full;

    --empty;

    x++;
  cout<< "\nProducer produces item "<< x;
  
  ++mutex;
}
 
// Function to consume an item and
// remove it from buffer
void consumer()
{
    --mutex; //mutex lock so that only one consumer can enter the buffer at a time

    --full;
 
    ++empty;

  cout<< "\nConsumer consumes item "<< x;
  
    x--;
    ++mutex;
}
 
// Driver Code
int main()
{
    int n, i;
  
  cout << "\nEnter size of the buffer: ";
  cin >> empty;
  
   cout << "\n1. Press 1 for Producer\n2. Press 2 for Consumer\n3. Press 3 for Exit";

  do{
 
      cout << "\n\nEnter your choice: ";
      cin >> n;
 
        // Switch Cases
        switch (n) {
        case 1:
            //if condition to check the mutex lock and overflow condition
            if ((mutex == 1) && (empty != 0)) {
                producer();
            }
 
            else {
                cout <<"\nBuffer is full";
            }
            break;
 
        case 2:
            //if condition to check the mutex lock and underflow condition
            if ((mutex == 1) && (full != 0)) {
                consumer();
            }

            else {
                cout << "\nBuffer is empty";
            }
            break;
 
        // Exit Condition
        case 3:
            return 0;
            break;
        }
    } while(n != 3);
}
