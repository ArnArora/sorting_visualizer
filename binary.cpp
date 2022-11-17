#include <algorithm>
#include <bits/std_thread.h>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

#include "./visualizer.cpp"

using namespace std;

int n;

/** Lowerbound binary search

@param    query    
@param    arr      
@param    end      

@return index to insert element
*/
int bin_search(int query, vector<double> arr, int end)
{
    int low = 0;
    int high = end;
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] < query) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}

int main()
{
    cout << "Number of elements: " << endl;
    cin >> n;
    cout << "Elements: " << endl;
    vector<double> arr;
    double max_val = 0;
    for (int i = 0; i < n; i++) {
        double temp;
        cin >> temp;
        arr.push_back(temp);
        max_val = max(max_val, temp);
    }

    double time_per_animation;
    cout << "Time taken to animate sorting each element:" << endl;
    cin >> time_per_animation;

    visualizer vis(n, max_val, 640, 480, 60, time_per_animation);

    // Animate binary insertion sort
    for (int i = 0; i < n; i++) {
        // For non-animation implementation
        // vis.draw_all(arr);
        cout << i << endl; // for debugging purposes

        // Find index to insert current element
        int insert = bin_search(arr[i], arr, i);

        // Call visualizer function to move element
        vector<int> new_positions;
        for (int j = 0; j < n; j++) {
            new_positions.push_back(j);
        }
        new_positions[i] = insert;
        for (int j = insert; j < i; j++) {
            new_positions[j] = j + 1;
        }
        vis.move(arr, new_positions);

        // Insert element in list vector
        double temp = arr[i];
        arr.erase(arr.begin() + i);
        arr.insert(arr.begin() + insert, temp);
    }

    // For non-animation implementation
    // vis.draw_all(arr);
    vis.quit();
}

