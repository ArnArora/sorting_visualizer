#include <algorithm>
#include <iostream>
#include <vector>

#include "./visualizer.cpp"

using namespace std;

int n;

visualizer vis(n, 0, 640, 480, 60, 5);

void update_chart(vector<double>& arr, int cur_spot, int left, int done)
{
    vector<int> new_positions;
    for (int j = 0; j < n; j++) {
        new_positions.push_back(j);
    }
    new_positions[cur_spot] = done+1;
    for (int j = done+1; j < cur_spot; j++) {
        new_positions[j] = j + 1;
    }
    vector<int> highlighted;
    highlighted.push_back(cur_spot);
    vis.move(arr, new_positions, highlighted);

    double temp = arr[cur_spot];
    arr.erase(arr.begin() + cur_spot);
    arr.insert(arr.begin() + done + 1, temp);
}

void merge(vector<double>& arr, int left, int mid, int right)
{
    int size1 = mid-left+1;
    int size2 = right-mid;

    int arr1[size1], arr2[size2];

    for (int i = 0; i < size1; i++)
      arr1[i] = arr[left + i];
    for (int j = 0; j < size2; j++)
      arr2[j] = arr[mid + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = left;

    while (i < size1 && j < size2) {
      if (arr1[i] <= arr2[j]) {
        arr[k] = arr1[i];
        i++;
      } else {
        arr[k] = arr2[j];
        update_chart(arr, mid+j+1, l, k+left);
        j++;
      }
      k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < size1) {
      arr[k] = arr1[i];
      i++;
      k++;
    }

    while (j < size2) {
      arr[k] = arr2[j];
      j++;
      k++;
    }
}

void merge_sort(vector<double>& arr, int begin, int end)
{
    if (begin<end)
    {
        int mid = begin+((end-begin)/2);
        merge_sort(arr, begin, mid);
        merge_sort(arr, mid+1, end);
        merge(arr, begin, mid, end);
    }
}

int main()
{
    cout << "Number of elements: " << endl;
    cin >> n;
    cout << "Elements: " << endl;
    vector<double> arr;
    double max_val = 0;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". ";
        double temp;
        cin >> temp;
        arr[i] = temp;
        max_val = max(max_val, temp);
    }

    double time_per_animation;
        cout << "Time taken to animate sorting each element:" << endl;
        cin >> time_per_animation;
    
    vis.max = max_val;
    vis.animation_duration = time_per_animation;
    
    merge_sort(arr, 0, n-1);
    
    vis.quit();
    
}
