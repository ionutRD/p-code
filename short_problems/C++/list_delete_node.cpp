/**
 * Given a pointer to a node in a singly linked list
 * delete that node.
 */
#include <iostream>
#include <utility>
#include <algorithm>
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
void delete_node(Node<T> *node)
{
    if (node == nullptr) {
        throw invalid_argument("Node cannot be null");
    }

    if (!node->next) {
        throw logic_error("Node cannot be last");
    }

    swap(node->item, node->next->item);
    auto old_node = node;
    node->next = node->next->next;
    delete old_node;
}

int main()
{
    auto head = new Node<int>(1, new Node<int>(2, new Node<int>(3)));
    auto node = head->next;
    delete_node<int>(node);
    delete_node<int>(head);
    for (auto it = head; it; it = it->next) {
        cout << it->item << endl;
    }
    return 0;
}
