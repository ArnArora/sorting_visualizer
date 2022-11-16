#include <SFML/Graphics.hpp>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int n;

int bin_search(int query, int arr[], int end)
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
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    visualizer vis = new visualizer();

    for (int i = 0; i < n; i++)
    {
        int insert = bin_search(arr[i], arr, i);

        visualizer.
    }
}

