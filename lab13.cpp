#include<iostream>
using namespace std;
const int MAX = 3;

template <class type>
class Queue
{
private:
    type qu[MAX];//array of any type
    int head; //index of the front queue (remove old item)
    int tail;//index of the back queure (insert new item)
    int count;//number of items in queue
public:
    Queue();
    void put(type t);
    type get();
    class full {};
    class empty {};

};

template<class type>
Queue<type>::Queue()
{
    head = -1;
    tail = -1;
    count = 0;
}

template<class type>
void Queue< type>::put(type var)
{
    if (count >= MAX)
        throw Queue<type>::full();
    qu[++tail] = var;//store the item
    ++count;
    if (tail >= MAX - 1) //wrap around if the past array end
        tail = -1;
}


template <class type>
type Queue< type>::get()
{
    if (count <= 0)
        throw Queue<type>::empty();
        type  temp = qu[++head]; //get item
    --count;
    if (head >= MAX - 1)//wrap around if past array end
        head = -1;
    return temp;
}

int main()
{
    Queue<float> q1;
    float data;
    char choice = 'p';
    do
    {
        try
        {
         cout << "\nEnter 'x' to exit, 'p' for put, and 'g' for get " << endl;
          cin >> choice;
          if (choice == 'p')
          {
                cout << "Enter data value: ";
                cin >> data;
                q1.put(data);
          }
          if (choice == 'g')
              cout << "Data = " << q1.get() << endl;
        }//end try
            catch (Queue<float>::full)
        {
            cout << "Error: queue is full." << endl;
        }
        catch(Queue<float>::empty)
        {
            cout << "Error: queue is empty." << endl;
        }
    } while (choice != 'x');
    return 0;
}