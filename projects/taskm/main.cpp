#include <iostream>
using namespace std;
class Task
{
public:
    string name;
    string description;
    int id;
};
class ListNode
{
public:
    Task data;
    ListNode *next;
};
class LinkedList
{
private:
    ListNode *head, *tail;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    void addTask(Task data);
    void removeTask(int id);
    void display_T();
};
void LinkedList::addTask(Task data)
{
    ListNode *newNode = new ListNode;
    newNode->data.name = data.name;
    newNode->data.description = data.description;
    newNode->data.id = data.id;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}
void LinkedList::removeTask(int id)
{
    ListNode *current = head;
    ListNode *previous = head;
    bool flag = false;
    while (current != NULL)
    {
        if (current->data.id == id && current == head)
        {
            head = current->next;
            free(current);
            flag = true;
            break;
        }
        else if (current->data.id == id)
        {
            previous->next = current->next;
            if (current == tail)
            {
                tail = previous;
            }
            free(current);
            flag = true;
            break;
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }
    if (flag == true)
    {
        cout << endl
             << "Task deleted." << endl;
    }
    else
    {
        cout << endl
             << "Task not found." << endl;
    }
}
void LinkedList::display_T()
{
    ListNode *current = head;
    while (current != NULL)
    {
        cout << endl
             << current->data.name << endl
             << current->data.description << endl
             << current->data.id << endl;
        current = current->next;
    }
}
int main()
{
    LinkedList ll;
    Task t1;
    t1.name = "Homework";
    t1.description = "Complete maths homework.";
    t1.id = 1;

    Task t2;
    t2.name = "Homework";
    t2.description = "Complete science homework.";
    t2.id = 2;

    Task t3;
    t3.name = "Homework";
    t3.description = "Complete english homework.";
    t3.id = 3;

    ll.addTask(t1);
    ll.addTask(t2);
    ll.addTask(t3);

    ll.display_T();

    ll.removeTask(2);

    ll.display_T();

    return 0;
}