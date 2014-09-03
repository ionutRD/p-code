/**
 * Get the nth element from a
 * singly linked list.
 */
#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

template<typename T>
class Node {
public:
    Node(const T& _item, Node<T> *_next = nullptr)
        : item(_item), next(_next) {}
    T item;
    Node<T> *next;
};

template<typename T>
T get_nth(Node<T> *head, size_t n)
{
    if (head == nullptr) {
        throw invalid_argument("List cannot be null");
    }

    size_t k = 0;
    auto it = head;
    while (it && k < n) {
        it = it->next;
        ++k;
    }
    if (it && k == n) {
        return it->item;
    }

    throw logic_error("Index out of bounds");
}

int main()
{
    auto head = new Node<int>(1, new Node<int>(2, new Node<int>(3)));
    cout << get_nth<int>(head, 0) << endl;
    cout << get_nth<int>(head, 1) << endl;
    cout << get_nth<int>(head, 2) << endl;
    cout << get_nth<int>(head, 5) << endl;
    return 0;
}
