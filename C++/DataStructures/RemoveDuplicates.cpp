#include "Node.cpp"

Node* RemoveDuplicates(Node *head) {
	Node *ptr = head;
    Node *lag = ptr;
    while (ptr != 0) {
        lag = ptr;
        if (ptr != 0) ptr = ptr->next;
        bool data_match = lag->data == ptr->data;
        if (data_match) Remove(lag, ptr, ptr->next);
        ptr = lag->next;
    }
    return head;
}
