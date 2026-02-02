#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;

// Print scores (not modified)
void printScores(const int arr[], int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        cout << arr[i] << (i < size -1 ? " " : ""); 
    }
    cout << endl;
}

// Pointer/array ( not modified)
int calculateSum(const int arr[], int size)
{
    int sum =0;
    for (int i =0; i < size; ++i)
        sum += arr[i];
    return sum;
}

//Pass by value
double getAverage(int sum, int size)
{
    if (size == 0) return 0.0;
    return static_cast<double>(sum) / size;
}

// Pass by pointer and array (modified)
void addBonus(int arr[], int size, int bonus = 5)
{
    for (int i = 0; i < size; ++i)
         arr[i] += bonus;
}

//Pass by pointer (read only)
int findHighest(const int* arr, int size)
{
    if (size <= 0) return -1; // safe
    int highest = arr[0];
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] > highest)
            highest = arr[i];
    }
    return highest;   
}

//Pass by array count scores >= 70
int countPassed(const int arr[], int size)
{
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] >= 70)
            ++count;
    }
    return count;
}
int main()
{
    const int SIZE = 5;
    int scores[SIZE] = {65, 82, 90, 45, 78};

    // Show original scores
    cout << "Original scores: ";
    printScores(scores, SIZE);

    // Show sum and average
    int sum = calculateSum(scores, SIZE);
    double average = getAverage(sum, SIZE);

    cout << "Sum: " << sum << endl;
    cout << "Average: " << std::fixed << std::setprecision(2) << average << endl;

    // Add bonus points
    addBonus(scores, SIZE);
    cout << "Scores after adding bonus (+5): ";
    printScores(scores, SIZE);

    // Show highest and number passed
    cout << "Highest score: " << findHighest(scores, SIZE) << endl;
    cout << "Number passed (>=70): " << countPassed(scores, SIZE) << endl;

    return 0;
}