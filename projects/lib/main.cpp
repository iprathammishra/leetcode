#include <iostream>
#include <vector>
using namespace std;
class Library
{
public:
    vector<int> id_container;
    void add_book_id(int id);
    void remove_book(int id);
    void display_books();
};
void Library::add_book_id(int id)
{
    this->id_container.push_back(id);
    cout << "Book Id added." << endl;
}
void Library::remove_book(int id)
{
    for (int i = 0; i < this->id_container.size(); i++)
    {
        if (this->id_container[i] == id)
        {
            this->id_container.erase(this->id_container.begin() + i);
            cout << "Book ID deleted." << endl;
        }
    }
}
void Library::display_books()
{
    for (int id : this->id_container)
    {
        cout << "Book Id: " << id << endl;
        ;
    }
}
int main()
{
    Library lib;
    lib.add_book_id(1);
    lib.add_book_id(2);
    lib.add_book_id(4);
    lib.add_book_id(3);
    lib.display_books();
    lib.remove_book(4);
    lib.display_books();
    return 0;
}