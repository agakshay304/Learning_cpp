
//Not applicable for negative number

#include<iostream>
#include <climits>
#include <vector>
using namespace std;
int solve(vector<int> &A, const int &k) {
	int n = A.size();
	int i = 0, j = 0, sum = 0;
	int mx = INT_MIN;
	while (j < n) {
		sum += A[j];
		if (sum < k) {
			j++;
		} 
        else if (sum == k) {
			mx = max(mx, j - i + 1);
			j++;
		} 
        else if (sum > k) {
			while (sum > k) {
				sum = sum - A[i];
				i++;
			}
			j++;
		}
	}
	return mx;
}
int main()
{
	vector<int> A;
    A.push_back(4);
    A.push_back(1);
    A.push_back(1);
    A.push_back(1);
    A.push_back(2);
    A.push_back(5);
	int k = 5;
	cout << solve(A, k);
	return 0;
}