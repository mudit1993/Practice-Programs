#include <bits/stdc++.h>
using namespace std;

void quickSort(vector <int> &arr) {
   // Complete this function

int size = arr.size();
if (size < 2) {
    return;
}

vector <int> leftArray;
vector <int> rightArray;

int pivot = arr[0];

for (int i = 1; i < size; ++i) {
    if (arr[i] <= pivot) {
        leftArray.push_back(arr[i]);
    }
    else {
        rightArray.push_back(arr[i]);
    }
}
quickSort(leftArray);
quickSort(rightArray);

int index = 0;

// Copy left array back into the original array
for (unsigned int l = 0; l < leftArray.size(); ++l) {
    arr[index++] = leftArray[l];
    cout << leftArray[l] << " ";
}

// Copy the pivot between left & right arrays
arr[index++] = pivot;
cout << pivot << " ";

// Copy right array back into the original array
for (unsigned int r = 0; r < rightArray.size(); ++r) {
    arr[index++] = rightArray[r];
    cout << rightArray[r] << " ";
}
cout << endl;
}


int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr);

    return 0;
}
