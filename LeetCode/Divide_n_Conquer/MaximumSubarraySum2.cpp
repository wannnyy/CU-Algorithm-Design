// time: O(nlogn)
// Divide & Conquer Approach.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/**/
int maxCrossingSum(vector<int> &v, int start, int mid, int stop) {
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = mid; i >= start; i--) {
        sum += v[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    sum = 0;
    int right_sum = INT_MIN;
    for (int i = mid + 1; i < stop; i++) {
        sum += v[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    return left_sum + right_sum;
}

int solve(vector<int> &v, int start, int stop) {
    if (start == stop - 1)
        return v[start];

    int mid = (start + stop) / 2;
    int left_sum = solve(v, start, mid);
    int right_sum = solve(v, mid, stop);
    int cross_sum = maxCrossingSum(v, start, mid, stop);

    return max({left_sum, right_sum, cross_sum});
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int max_sum = solve(v, 0, n);
    cout << "Maximum Subarray Sum is " << max_sum << endl;

    return 0;
}