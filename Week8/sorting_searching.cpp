#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Data {
    string name;
    long long nisn;
    int value;
};

//Insertion Sort Function
void insertionSortNISN(Data studentData[], int n)
{
    for (int i=1; i<n; i++){
        Data temp = studentData[i];
        int j = i - 1;
        // Sort by descending order by NISN
        while(j>=0 && studentData[j].nisn < temp.nisn){
            studentData[j+1] = studentData[j];
            j--;
        }
        studentData[j+1] = temp;
    }
}

void insertionSortValue(Data studentData[], int n)
{
    for (int i=1; i<n; i++){
        Data temp = studentData[i];
        int j = i - 1;
        // Sort by descending order by value
        while(j>=0 && studentData[j].value < temp.value){
            studentData[j+1] = studentData[j];
            j--;
        }
        studentData[j+1] = temp;
    }
}

//Selection Sort Function
void selectionSortNISN(Data studentData[], int n){
    for (int i = 0; i < n; i++){
        int min = i;
        for (int j=1+i; j<n; j++){
            //Sort by the order of NISN
            if(studentData[j].nisn > studentData[min].nisn){
                min = j;
            }
        }
        Data temp = studentData[i];
        studentData[i] = studentData[min];
        studentData[min] = temp;
    }
}

void selectionSortValue(Data studentData[], int n){
    for (int i = 0; i < n; i++){
        int min = i;
        for (int j=1+i; j<n; j++){
            //Sort by the order of value
            if(studentData[j].value > studentData[min].value){
                min = j;
            }
        }
        Data temp = studentData[i];
        studentData[i] = studentData[min];
        studentData[min] = temp;
    }
}

//Bubble Sort Function
void bubbleSortNISN(Data studentData[], int n)
{
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1-i; j++){
            if(studentData[j].nisn < studentData[j+1].nisn){
                Data temp = studentData[j];
                studentData[j] = studentData[j+1];
                studentData[j+1] = temp;
            }
        }
    }
}

void bubbleSortValue(Data studentData[], int n)
{
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1-i; j++){
            if(studentData[j].value < studentData[j+1].value){
                Data temp = studentData[j];
                studentData[j] = studentData[j+1];
                studentData[j+1] = temp;
            }
        }
    }
}

// Binary Search Method
bool binarySearch(Data studentData[], int n, long long target)
{
    int left = 0;
    int right = n-1;
    int mid;

    while(left <= right){
        mid = (left + right)/2;
        if(studentData[mid].nisn == target){
            cout << "Target found with NISN " << studentData[mid].nisn
                 << "and with the value " << studentData[mid].value << endl;
            return true;
        }
        else if(studentData[mid].nisn < target){
            // found target, but return true instead of printing here
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    // Target not found
    return false;
}

// Sequential Search Method 
void changeName(Data studentData[], int n)
{
    bool found = false;
    for (int i=0; i<n; i++){
        if(studentData[i].value == 60){
            studentData[i].name = "Joko";
            found = true;
        }
    }

    if(!found){
        cout << "There are no values of 60" << endl;
    }
}

void printStudents(Data studentData[], int size){
    cout << left << setw(15) << "NISN" << setw(30) << "Name" << setw(10) << "Value" << endl;
    cout << "---------------------------------------------------\n";
    for (int i = 0; i < size; i++){
        cout << left << setw(15) << studentData[i].nisn
             << setw(30) << studentData[i].name
             << setw(10) << studentData[i].value << endl;
    }
        
}

int main(){
    Data students[] = {
        {"Handi Ramadhan", 9960312699, 90},
        {"Rio Alfandra", 9963959682, 55},
        {"Ronaldo Valentino Uneputty", 9950310962, 80},
        {"Achmad Yaumil Fadjri R.", 9970272750, 60},
        {"Alivia Rahma Pramesti", 9970293945, 70},
        {"Ari Lutfianto", 9952382180, 65},
        {"Arief Budiman", 9965653989, 60}
        };
    int n = sizeof(students) / sizeof(students[0]);

// Insertion sort of student's NISN
    insertionSortNISN(students, n);
    cout << "Insertion Sort by NISN: \n";
    printStudents(students, n);

// Insertion sort of student's value
    insertionSortValue(students, n);
    cout << "\nInsertion Sort by Value: \n";
    printStudents(students, n);

// Selection sort of student's NISN
    selectionSortNISN(students, n);
    cout << "\nSelection Sort by NISN: \n";
    printStudents(students, n);

// Selection sort of student's value
    selectionSortValue(students, n);
    cout << "\nSelection Sort by Value: \n";
    printStudents(students, n);

// Bubble sort of student's NISN
    bubbleSortNISN(students, n);
    cout << "\nBubble Sort by NISN: \n";
    printStudents(students, n);

// Bubble sort of student's value
    bubbleSortValue(students, n);
    cout << "\nBubble Sort by Value: \n";
    printStudents(students, n);

// Searching NISN with binary search
    cout << "\nBinary Search of a student's NISN: \n";
    binarySearch(students, n, 9950310962);

// Changing the name to Joko for those that have the value 60
    changeName(students, n);
    cout << "\nSequential Search After Name Change: \n";
    printStudents(students, n);
}