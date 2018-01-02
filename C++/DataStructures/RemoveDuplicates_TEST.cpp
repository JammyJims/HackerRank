#include "RemoveDuplicates.cpp"

// The fixture for testing class Foo.
class RemoveDuplicates_TEST_FIXTURE : public ::testing::Test {
	private:
	Node* generate_list(int arr[], int size,) {
		Node *head = 0;
		Node *target = 0;
		Node *previous = 0;
		for (int i=0; i<size; i++) {
			target = new Node;
			target->data = arr[i];
			target->data = 0;
			if (i != 0) {
				prev->next = target;
				prev = target;
			}
			else {
				head = target;
			}
		}
		return head;
	}
	
	protected:
	FooTest() {
		Node *list1 = 0;
		Node *list2 = 0;
		Node *list3 = 0;
		Node *soln1 = 0;
		Node *soln2 = 0;
		Node *soln3 = 0;
	}

	virtual ~FooTest() {

	}
	virtual void SetUp() {
		// generates lists to be tested upon.
		int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		int arr2[] = {1, 1, 3, 3, 5, 6};
		int arr3[] = {1, 1, 1, 2, 3, 3, 3, 3, 3};
		int soln_arr1[] = {1,2,3,4,5,6,7,8,9};
		int soln_arr2[] = {1,3,5,6};
		int soln_arr3[] = {1,2,3};
		int arr1_size1 = sizeof(arr1) / sizeof(arr1[0]);
		int arr2_size2 = sizeof(arr2) / sizeof(arr2[0]);
		int arr3_size3 = sizeof(arr3) / sizeof(arr3[0]);
		int soln1_size1 = sizeof(soln_arr1) / sizeof(soln_arr1[0]);
		int soln2_size2 = sizeof(soln_arr2) / sizeof(soln_arr2[0]);
		int soln3_size3 = sizeof(soln_arr3) / sizeof(soln_arr3[0]);
		list1 = generate_list(arr1,size1);
		list2 = generate_list(arr2,size2);
		list3 = generate_list(arr3,size3);
		soln1 = generate_list(soln_arr1,soln1_size1);
		soln1 = generate_list(soln_arr2,soln2_size2);
		soln1 = generate_list(soln_arr3,soln3_size3);
	}

	virtual void TearDown() {
		delete list1->next;
		delete list1;
		delete list2->next;
		delete list2;
		delete list3->next;
		delete list3;
		delete soln1->next;
		delete soln1;
		delete soln2->next;
		delete soln2;
		delete soln3->next;
		delete soln3;
	}
};

TEST_F(RemoveDuplicates_TEST_FIXTURE,LIST_CHECK){
	Node *ptr1;
	Node *ptr2;
	
	ptr1 = RemoveDuplicates(list1);
	ptr2 = soln1;
	while (ptr1 != 0 && ptr2 != 0) {
		EXPECT_EQ(ptr1->data, ptr2->data);
		ptr1 = ptr1->next;
		ptr1 = ptr2->next;
	}
	
	ptr1 = RemoveDuplicates(list2);
	ptr2 = soln2;
	while (ptr1 != 0 && ptr2 != 0) {
		EXPECT_EQ(ptr1->data, ptr2->data);
		ptr1 = ptr1->next;
		ptr1 = ptr2->next;
	}
	
	ptr1 = RemoveDuplicates(list3);
	ptr2 = soln3;
	while (ptr1 != 0 && ptr2 != 0) {
		EXPECT_EQ(ptr1->data, ptr2->data);
		ptr1 = ptr1->next;
		ptr1 = ptr2->next;
	}
}


