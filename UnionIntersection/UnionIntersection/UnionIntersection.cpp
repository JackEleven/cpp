
#include "stdafx.h"
#include <vector>
#include <unordered_set>

using namespace std;

void InsertSet(vector<int> v, unordered_set<int> &hset) {
	for (size_t i = 0; i < v.size(); ++i) {
		hset.insert(v[i]);
	}
}

vector<int> Union(vector<int> a1, vector<int> a2) {
	vector<int> result;
	unordered_set<int> hset;

	// O(m+n) algorithm
	// unordered_set is hash table based implementation in STL
	// also, unordered_set elements are unique
	InsertSet(a1, hset);
	InsertSet(a2, hset);

	for (auto e : hset) {
		result.push_back(e);
	}

	return result;
}

vector<int> GetCommonElements(const vector<int> &small, const vector<int> &big) {
	unordered_set<int> hset;
	vector<int> result;
	InsertSet(small, hset);
	for (size_t i = 0; i < big.size(); ++i) {
		if (hset.find(big[i]) != hset.end()) {
			result.push_back(big[i]);
		}
	}

	return result;
}

vector<int> Intersection(vector<int> v1, vector<int> v2) {
	vector<int> result;

	result = v1.size() < v2.size() ? GetCommonElements(v1, v2) : GetCommonElements(v2, v1);
	return result;
}

vector<int> GetVectorArray(int *arr, int size) {
	vector<int> v;
	for (int i = 0; i < size; ++i) {
		v.push_back(arr[i]);
	}
	return v;
}

int main()
{
	int arr1[] = { 7, 1, 5, 2, 3, 6 };
	int arr2[] = { 3, 8, 6, 20, 7 };
	
	vector<int> v1 = GetVectorArray(arr1, sizeof(arr1) / sizeof(arr1[0]));
	vector<int> v2 = GetVectorArray(arr2, sizeof(arr2) / sizeof(arr2[0]));

	vector<int> result1 = Union(v1, v2);
	vector<int> result2 = Intersection(v1, v2);
	
    return 0;
}

