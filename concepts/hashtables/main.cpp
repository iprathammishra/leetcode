#include <iostream>
using namespace std;
const int TABLE_SIZE = 100;
int SimpleHash(const string &key, int tableSize) // & is for efficiency
{
    int hash = 0;
    for (char c : key)
    {
        hash += c;
    }
    return hash % tableSize;
}
struct HashTableItem
{
    string key;
    int value;
    HashTableItem *next;
    HashTableItem(const string &k, int v, HashTableItem *n) : key(k), value(v), next(n) // New way other than `this`.
    {
    }
};
class HashTable
{
private:
    HashTableItem *table[TABLE_SIZE];

public:
    HashTable()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            table[i] = nullptr;
        }
    }
    void Insert(const string &key, int value)
    {
        int index = SimpleHash(key, TABLE_SIZE);
        HashTableItem *newItem = new HashTableItem(key, value, nullptr);
        if (table[index] == nullptr)
        {
            table[index] = newItem;
        }
        else
        {
            HashTableItem *current = table[index];
            while (current->next)
            {
                current = current->next;
            }
            current->next = newItem;
        }

        cout << "Item Inserted at index: " << index << endl;
    }
    int Search(const string &key)
    {
        int index = SimpleHash(key, TABLE_SIZE);
        HashTableItem *current = table[index];
        while (current)
        {
            if (current->key == key)
                return current->value;
            current = current->next;
        }
        return -1;
    }
    void Delete(const string &key)
    {
        int index = SimpleHash(key, TABLE_SIZE);
        HashTableItem *current = table[index];
        HashTableItem *prev = nullptr;
        while (current)
        {
            if (current->key == key)
            {
                if (prev)
                    prev->next = current->next;
                else
                    table[index] = current->next;
                delete current;
                cout << "Item deleted." << endl;
                return;
            }
            prev = current;
            current = current->next;
        }

        cout << "Item could not be found." << endl;
    }
};
int main()
{
    HashTable hashtable;
    hashtable.Insert("John", 25);
    hashtable.Insert("Alice", 30);

    int age = hashtable.Search("John");
    cout << "Value: " << age << endl;

    hashtable.Delete("Alince");
    hashtable.Delete("Alice");
    age = hashtable.Search("Alice");

    cout << "Error: " << age;
    return 0;
}