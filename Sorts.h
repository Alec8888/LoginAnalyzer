#include <iostream>
#include <vector>
#include <utility>
#include <string>


using namespace std;

vector <string>& Merge(vector<string>& Array, int left, int middle, int right);
vector<string>& QuickSort(vector<string> &Array, int Begin, int End);
vector<string>& TimSort(vector<string>& Array);
vector<string>& MergeSort(vector<string>& Array, int left, int right);

int Partition(vector<string>& Array, int Begin, int End);

//int main()

//{
//    vector<string> fruits = {"banana", "orange", "lemon", "coconut", "mango", "apple", "pear", "grape", "cherry"};
//    vector<string> colors = {"pink", "black", "orange", "green", "yellow", "white", "purple", "red", "blue"};
//    cout << "\n----------------------------\nUnsorted Fruits: ";
//    for (int i = 0; i < fruits.size(); i++)
//    {
//        cout << fruits.at(i) << " ";
//    }

//    fruits = MergeSort(fruits, 0, fruits.size() - 1);
//    cout << "\n\n----------------------------\nMerge Sorted Fruits: ";
//    for (int i = 0; i < fruits.size(); i++)
//    {
//        cout << fruits.at(i) << " ";
//    }

//    cout << "\n\n\n----------------------------\nUnsorted Colors: ";
//    for (int i = 0; i < colors.size(); i++)
//    {
//        cout << colors.at(i) << " ";
//    }

//    colors = QuickSort(colors, 0, colors.size() - 1);
//    cout << "\n\n----------------------------\nQuick Sorted Colors: ";
//    for (int i = 0; i < colors.size(); i++)
//    {
//        cout << colors.at(i) << " ";
//    }
//    cout << endl << endl;
//    return 0;
//}

vector<string>& MergeSort(vector<string>& Array, int left, int right)
{
    //cout << "merge sort was called..." << endl;
    // while left index is smaller than right, keep dividing array
    if (left < right)
    {
        int middle = (left / 2) + (right / 2);

        // Merge Sort left and right halves of array recursively
        Array = MergeSort(Array, left, middle);
        Array = MergeSort(Array, middle + 1, right);

        // Once array is completely divided, merge its elements back together
        Array = Merge(Array, left, middle, right);
    }

    return Array;
}
vector<string>& Merge(vector<string>& Array, int left, int middle, int right)
{
    int counter = left, lHalf = middle - left + 1, rHalf = right - middle, x = 0, y = 0;
    vector<string> leftHalf, rightHalf;

    // Push left and right halves of array into ther respective containers
    for (int i = 0; i < lHalf; i++)
        leftHalf.push_back(Array.at(i + left));

    for (int j = 0; j < rHalf; j++)
        rightHalf.push_back(Array.at(middle + 1 + j));

    // Push elements into array in a sorted order, pushing smaller elements first, and larger ones last
    // x keeps track of how many left half elements have been pushed, y keeps track of the right
    while (x != lHalf && y != rHalf)
    {
        if (leftHalf.at(x).compare(rightHalf.at(y)) < 0)
        {
            Array.at(counter) = leftHalf.at(x);
            x++;
            counter++;
        }

        else
        {
            Array.at(counter) = rightHalf.at(y);
            y++;
            counter++;
        }
    }

    // If all left elements have been sorted, add right elements to array
    if (x == lHalf)
    {
        while (y != rHalf)
        {
            Array.at(counter) = rightHalf.at(y);
            y++;
            counter++;
        }
    }

    // If all right elements have been sorted, add left elements to array
    if (y == rHalf)
    {
        while (x != lHalf)
        {
            Array.at(counter) = leftHalf.at(x);
            x++;
            counter++;
        }
    }
    return Array;
}

vector<string>& QuickSort(vector<string>& Array, int Begin, int End)
{
    //cout << "quicksort was called..." << endl;
    // If left less than right, partition array, then quicksort recursively

    if (Begin < End)
    {
        int Pivot = Partition(Array, Begin, End);
        Array = QuickSort(Array, Begin, Pivot - 1);
        Array = QuickSort(Array, Pivot + 1, End);
    }

    return Array;
}

vector<string>& Sorts::TimSort(vector<string>& Array)
{
    int mycount = 0;
    for (int j = 0; j < Array.size(); j++)
    {
        if (mycount < cutOff)
        {
            for (int i = j - mycount; i <= j; i++)
            {
                int key = i;
                string value = Array.at(i);
                while (key > 0 && Array.at(key - 1).compare(value) > 0)
                {
                    Array.at(key) = Array.at(key - 1);
                    key--;
                }
                Array.at(key) = value;
            }
            mycount = 0;
        }

        else
        {
            int left = j - cutOff;
            int mid = (j - cutOff) / 2 + (j /2);
            int right = j;
            Array = Merge(Array, left, mid, right);
        }
        mycount++;
    }
    return Array;
}

int Partition(vector<string>& Array, int Begin, int End)
{

    string PivotEle = Array.at(Begin);

    int top = Begin, bottom = End;

    // Sort divided array placing smaller elements to left of pivot and greater ones to the right
    while (top < bottom)
    {
        for (int j = top; j < End; j++)
        {
            if (Array.at(top).compare(PivotEle) > 0)
                break;
            top++;
        }


        for (int i = bottom; i > Begin; i--)
        {
            if (Array.at(bottom).compare(PivotEle) < 0)
                break;

            bottom--;
        }
        if (top < bottom)
            swap(Array.at(top), Array.at(bottom));

    }

    swap(Array.at(Begin), Array.at(bottom));

    return bottom;
}
