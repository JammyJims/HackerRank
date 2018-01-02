
#include <iostream>
struct Node {
	int data;
	Node *next;
};

int main() {
	using namespace std;
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int size = sizeof (arr) / sizeof (arr[0]);
	cout << size << endl;
	Node *ptr = new Node;
	ptr->data = 4;
	ptr->next = 0;
	cout << "ptr = " << ptr << endl;
	cout << "ptr->data = " << ptr->data << endl;
	cout << "ptr->next = " << ptr->next << endl;
    return 0;
}
