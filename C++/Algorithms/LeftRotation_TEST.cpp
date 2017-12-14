#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include <vector>
#include <iostream>
using namespace std;

// trivial swap function
void swap(int *a, int *b){
	int *temp = a;
	*a = *b;
	*b = *temp;
	return;
}

// prints the vector to standard out
// to be used for testing purposes
void print(vector<int> vec){
	for (int i=0; i<vec.size(); i++){
		cout << vec.at(i) << " ";
	}
	cout << endl;
	return;
}

// circular shift all elements in the vector to the left
vector <int> shift(vector <int> a){
	int n = a.size();
	// edge cases do nothing.
	if (n == 0 || n == 1) return a;
	
	// swap elements until all elements 
	for (int i=n-1; i>0; i--){
		swap(a.at(i), a.at(0));
	}
	return a;
}

// perform a left rotation to all elements in the vector d times
vector <int> leftRotation(vector <int> a, int d) {
	if (d > 0){
		for (int i=0; i<d; i++){
			a = shift(a);
		}
    }
    else if (d == 0){
    	return a;
    }
    else {
    	for (int i=0; i<a.size()+d; i++){
    		a = shift(a);
    	}
    }
    return a;
}

TEST(LEFTROTATION, BASE){
	vector <int> argA = {1, 2, 3, 4, 5};
	int argD = 4;
	vector <int> expected = {5, 1, 2, 3, 4};
	vector <int> received = leftRotation(argA, argD);
	int n = expected.size();
	for (int i=0; i<n; i++){
		int val1 = expected.at(i);
		int val2 = received.at(i);
		ASSERT_EQ(val1,val2);
	}
}

TEST(LEFTROTATION, SHIFT_BY_ZERO){
	vector <int> argA = {1, 2, 3, 4, 5};
	int argD = 0;
	vector <int> expected = argA;
	vector <int> received = leftRotation(argA, argD);
	int n = expected.size();
	for (int i=0; i<n; i++){
		int val1 = expected.at(i);
		int val2 = received.at(i);
		ASSERT_EQ(val1,val2);
	}
}

TEST(LEFTROTATION, SHIFT_BY_ONE){
	vector <int> argA = {1, 2, 3, 4, 5};
	int argD = 1;
	vector <int> expected = {2, 3, 4, 5, 1};
	vector <int> received = leftRotation(argA, argD);
	int n = expected.size();
	for (int i=0; i<n; i++){
		int val1 = expected.at(i);
		int val2 = received.at(i);
		ASSERT_EQ(val1,val2);
	}
}

TEST(LEFTROTATION, SHIFT_BY_N){
	vector <int> argA = {1, 2, 3, 4, 5};
	int argD = 5;
	vector <int> expected = argA;
	vector <int> received = leftRotation(argA, argD);
	int n = expected.size();
	for (int i=0; i<n; i++){
		int val1 = expected.at(i);
		int val2 = received.at(i);
		ASSERT_EQ(val1,val2);
	}
}

TEST(LEFTROTATION, SHIFT_BY_TWO_N){
	vector <int> argA = {1, 2, 3, 4, 5};
	int argD = 10;
	vector <int> expected = argA;
	vector <int> received = leftRotation(argA, argD);
	int n = expected.size();
	for (int i=0; i<n; i++){
		int val1 = expected.at(i);
		int val2 = received.at(i);
		ASSERT_EQ(val1,val2);
	}
}

TEST(LEFTROTATION, SHIFT_BY_N_TAKE_ONE){
	vector <int> argA = {1, 2, 3, 4, 5};
	int argD = 4;
	vector <int> expected = {5, 1, 2, 3, 4};
	vector <int> received = leftRotation(argA, argD);
	int n = expected.size();
	for (int i=0; i<n; i++){
		int val1 = expected.at(i);
		int val2 = received.at(i);
		ASSERT_EQ(val1,val2);
	}
}

TEST(LEFTROTATION, VECTOR_SIZE_ONE){
	vector <int> argA = {1};
	int argD = 3;
	vector <int> expected = argA;
	vector <int> received = leftRotation(argA, argD);
	int n = expected.size();
	for (int i=0; i<n; i++){
		int val1 = expected.at(i);
		int val2 = received.at(i);
		ASSERT_EQ(val1,val2);
	}
}

TEST(LEFTROTATION, VECTOR_SIZE_TWO){
	vector <int> argA = {1, 2};
	int argD = 6;
	vector <int> expected = argA;
	vector <int> received = leftRotation(argA, argD);
	int n = expected.size();
	for (int i=0; i<n; i++){
		int val1 = expected.at(i);
		int val2 = received.at(i);
		ASSERT_EQ(val1,val2);
	}
}

TEST(LEFTROTATION, NEGATIVE_SHIFT_BY_ONE){
	vector <int> argA = {1, 2, 3, 4, 5};
	int argD = -1;
	vector <int> expected = {5,1,2,3,4};
	vector <int> received = leftRotation(argA, argD);
	int n = expected.size();
	for (int i=0; i<n; i++){
		int val1 = expected.at(i);
		int val2 = received.at(i);
		ASSERT_EQ(val1,val2);
	}
}

TEST(LEFTROTATION, NEGATIVE_SHIFT_BY_TWO){
	vector <int> argA = {1, 2, 3, 4, 5};
	int argD = -2;
	vector <int> expected = {4,5,1,2,3};
	vector <int> received = leftRotation(argA, argD);
	int n = expected.size();
	for (int i=0; i<n; i++){
		int val1 = expected.at(i);
		int val2 = received.at(i);
		ASSERT_EQ(val1,val2);
	}
}

TEST(LEFTROTATION, HIGHEST_INTEGERS){
	vector <int> argA = {1000000, 2000, 30000, 40000, 50000};
	int argD = 2;
	vector <int> expected = {30000, 40000, 50000, 1000000, 2000};
	vector <int> received = leftRotation(argA, argD);
	int n = expected.size();
	for (int i=0; i<n; i++){
		int val1 = expected.at(i);
		int val2 = received.at(i);
		ASSERT_EQ(val1,val2);
	}
}


TEST(LEFTROTATION, SWAP_FX){
	int a = 4;
	int b = 20;
	swap(a,b);
	ASSERT_EQ(a,20);
	ASSERT_EQ(b,4);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}
