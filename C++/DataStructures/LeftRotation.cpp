#include <bits/stdc++.h>
#include <vector>
using namespace std;

// trivial swap function
void swap(int *&a, int *&b){
	int *temp = a;
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
    for (int i=1; i<d; i++){
    	a = shift(a);
    }
    return a;
}

int main() {
    int n;
    int d;
    cin >> n >> d;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    vector <int> result = leftRotation(a, d);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;


    return 0;
}

