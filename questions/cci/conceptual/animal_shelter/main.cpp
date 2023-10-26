// **Animal Shelter:** An animal shelter, which holds only dogs and cats, operates on a strictly "first in, first out" basis. People must adopt either the "oldest" (based on arrival time) of all animals at the shelter, or they can select whether they would prefer a dog or a cat (and will receive the oldest animal of that type). They cannot select which specific animal they would like. Create the data structures to maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog, and dequeueCat. You may use the build-in LinkedList data structure.
#include <iostream>
#include <string>
using namespace std;
class Animal
{
public:
    string name;
    char type;
};
class Node
{
public:
    Animal data;
    Node *next;
    Node(Animal val) : data(val), next(nullptr) {}
};
class Queue
{
private:
    Node *front, *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}
    void enQueue(Animal data)
    {
        Node *newNode = new Node(data);
        if (!front)
            front = rear = newNode;
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }
    void displayAllQueue()
    {
        if (!front)
            return;
        Node *tempPtr = front;
        while (tempPtr)
        {
            cout << tempPtr->data.name << " : " << tempPtr->data.type << " << ";
            tempPtr = tempPtr->next;
        }
        cout << endl;
    }
    void deQueueAny()
    {
        if (!front)
            return;
        Node *tempPtr = front;
        front = front->next;
        delete tempPtr;
    }
    void deQueueDog()
    {
        if (!front)
            return;
        else if (front->data.type == 'd')
        {
            Node *tempPtr = front;
            front = front->next;
            delete tempPtr;
            return;
        }
        Node *current = front;
        Node *previous = nullptr;
        while (current->data.type != 'd')
        {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        delete current;
    }
    void deQueueCat()
    {
        if (!front)
            return;
        else if (front->data.type == 'c')
        {
            Node *tempPtr = front;
            front = front->next;
            delete tempPtr;
            return;
        }
        Node *current = front;
        Node *previous = nullptr;
        while (current->data.type != 'c')
        {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        delete current;
    }
};
int main()
{
    Animal a1;
    a1.name = "J";
    a1.type = 'c';
    Animal a2;
    a2.name = "Q";
    a2.type = 'd';
    Animal a3;
    a3.name = "G";
    a3.type = 'c';
    Animal a4;
    a4.name = "H";
    a4.type = 'c';
    Animal a5;
    a5.name = "K";
    a5.type = 'd';
    Animal a6;
    a6.name = "L";
    a6.type = 'd';

    Queue animalQueue;

    animalQueue.enQueue(a1);
    animalQueue.enQueue(a2);
    animalQueue.enQueue(a3);
    animalQueue.enQueue(a4);
    animalQueue.enQueue(a5);
    animalQueue.enQueue(a6);

    animalQueue.displayAllQueue();

    animalQueue.deQueueAny();
    animalQueue.displayAllQueue();

    animalQueue.deQueueDog();
    animalQueue.displayAllQueue();

    animalQueue.deQueueCat();
    animalQueue.displayAllQueue();

    return 0;
}