#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include <vector>
using namespace std;

// trivial swap function
void swap(int a, int b){
	int temp = a;
	a = b;
	b = temp;
	return;
}

// circular shift all elements in the vector to the left
vector <int> shift(vector <int> a){
	int n = a.size();
	// edge cases do nothing.
	if (n == 0 || n == 1) return a;
	
	// swap elements until all elements 
	for (int i=0; i<n-1; i++){
		int it = n-i;
		swap(it, a.at(0));
	}
	return a;
}

// perform a left rotation to all elements in the vector d times
vector <int> leftRotation(vector <int> a, int d) {
    for (int i=0; i<d; i++){
    	a = shift(a);
    }
    return a;
}

TEST(LEFTROTATION, BASE){
	vector <int> argA = {1, 2, 3, 4, 5};
	int argD = 4;
	vector <int> expected = {5, 1, 2, 3, 4};
	vector <int> received = leftRotation(argA, argD);
	EXPECT_THAT(expected, ::testing::ContainerEq(received));
	/*
	int n = expected.size();
	for (int i=0; i<n; i++){
		int val1 = expected.at(i);
		int val2 = received.at(i);
		ASSERT_EQ(val1,val2);
	}
	*/
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}
