#include <iostream>
#include <vector>
#include <utility>
#include <string>
#define cutOff 80

using namespace std;

vector <string>& Merge(vector<string>& Array, int left, int middle, int right);
vector<string>& QuickSort(vector<string> &Array, int Begin, int End);
vector<string>& TimSort(vector<string>& Array);
vector<string>& MergeSort(vector<string>& Array, int left, int right);
int Partition(vector<string>& Array, int Begin, int End);

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
// MergeSort learned from Professor AmanPreet Kapoor Sorting Module
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

// QuickSort learned from Professor Amanpreet Kapoor sorting module
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

// Learned from Geeks for Geeks
// cutOff is 80 because tim sort works better when array size is divisible by this value
vector<string>& TimSort(vector<string>& Array)
{
    // Insertion sort small pieces of array
    for (int j = 0; j < Array.size(); j+= cutOff)
    {
        int x;

        if (Array.size() > j + cutOff)
            x = j + cutOff;
        else
            x = Array.size();

        for (int i = j + 1; i < x; i++)
        {
            int key = i;
            string value = Array.at(i);
            while (key > j && Array.at(key - 1).compare(value) > 0)
            {
                Array.at(key) = Array.at(key - 1);
                key--;
            }

            Array.at(key) = value;
        }
    }

    int right;

    // merge small portions of array
    int CutOff = cutOff;
    while (CutOff < Array.size())
    {
        // merges each portion with portion 2*f values away
        for (int left = 0; left < Array.size(); left += 2 * CutOff)
        {

            // comp is value of right half of array
            int comp = left + 2 * CutOff;

            if (Array.size() - 1 > comp - 1)
                right = comp - 1;

            else
                right = Array.size() - 1;

            // ensures this array needs to be merged
            if((left + CutOff - 1) < right)
                Array = Merge(Array, left, left + CutOff - 1, right);
        }
        CutOff = 2 * CutOff;
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
