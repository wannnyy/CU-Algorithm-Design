#include <iostream>
#include <vector>

using namespace std;


vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int n = matrix[0].size(), m = matrix.size();
        int i=0,j=0,cnt = 0;
        int left_bound = 0, right_bound = n-1;
        int up_bound = 0, low_bound = m - 1;
        int state = 0;
        if(n==1)state=1;
        // if(m==)
        while(v.size()< m*n)
        {
            if(state%4 == 0) // go right
            {
                // cout << i << " " << j << endl;
                cout << matrix[i][j] << endl;
                v.push_back(matrix[i][j]);
                j += 1;
                if(j >= right_bound)
                {
                    up_bound += 1;
                    j = right_bound;
                    // v.push_back(matrix[i][j]);
                    // i += 1;
                    state += 1;
                }
            }
            else if(state%4 == 1) // go down
            {
                // cout << i << " " << j << endl;
                cout << matrix[i][j] << endl;
                v.push_back(matrix[i][j]);
                i += 1;
                if(i >= low_bound)
                {
                    right_bound -= 1;
                    i = low_bound;
                    state += 1;
                    // v.push_back(matrix[i][j]);
                    // j -=1;
                }
            }
            else if(state%4 == 2) // go left
            {
                // cout << i << " " << j << endl;
                cout << matrix[i][j] << endl;
                v.push_back(matrix[i][j]);
                j -= 1;
                if(j <= left_bound)
                {
                    low_bound -= 1;
                    j = left_bound;
                    state += 1;
                    // v.push_back(matrix[i][j]);
                    // i -=1;
                }
            }
            else if(state%4 == 3) // go up
            {
                // cout << i << " " << j << endl;
                cout << matrix[i][j] << endl;
                v.push_back(matrix[i][j]);
                i -= 1;
                if(i <= up_bound)
                {
                    left_bound += 1;
                    i = up_bound;
                    state += 1;
                    // v.push_back(matrix[i][j]);
                    // j+=1;
                }
            }
        }
        return v;
    }

int main()
{
    vector<vector<int>> matrix  = {{1,2,3,4},
                                   {5,6,7,8},
                                   {9,10,11,12},
                                   {13,14,15,16},
                                   {17,18,19,20},
                                   {21,22,23,24}};
    vector<int> v = spiralOrder(matrix);
    for(int i=0;i<v.size();i++)
    {
        cout << v[i] << " ";
    }
}