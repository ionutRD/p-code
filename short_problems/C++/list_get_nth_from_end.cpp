/**
 * Get the nth element from the end of a
 * singly linked list.
 */
#include <iostream>
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
T get_nth_from_end(Node<T> *head, size_t n)
{
    if (head == nullptr) {
        throw invalid_argument("List cannot be null");
    }

    size_t k = 0;
    auto first_it = head;
    auto second_it = head;
    while (second_it && k < n) {
        second_it = second_it->next;
        ++k;
    }
    if (!second_it || k != n) {
        throw logic_error("Index out of bounds");
    }

    while(second_it->next) {
        second_it = second_it->next;
        first_it = first_it->next;
    }
    return first_it->item;
}

int main()
{
    auto head = new Node<int>(1, new Node<int>(2, new Node<int>(3)));
    cout << get_nth_from_end<int>(head, 0) << endl;
    cout << get_nth_from_end<int>(head, 1) << endl;
    cout << get_nth_from_end<int>(head, 2) << endl;
    return 0;
}
