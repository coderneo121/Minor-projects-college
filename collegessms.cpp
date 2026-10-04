#include <iostream>
#include <string>
using namespace std;

/*
===========================================================
        STUDENT SCHOLARSHIP MANAGEMENT SYSTEM
===========================================================

SCHOLARSHIP ELIGIBILITY CONDITIONS:

1. Student must score 75 marks or above.
2. Family annual income must be Rs. 3,00,000 or below.
3. Both conditions must be satisfied.
4. If both conditions are true, the student is eligible.
5. Otherwise, the student is not eligible.

DSA CONCEPTS USED:

- Structure
- Singly Linked List
- Array
- Insertion
- Deletion
- Traversal
- Linear Search
- Binary Search
- Bubble Sort
- Counting
- Functions
===========================================================
*/


// Structure for storing student information
struct Student
{
    int rollNo;
    string name;
    float marks;
    int familyIncome;
    bool eligible;
};


// Node for Linked List
struct Node
{
    Student data;
    Node* next;
};


// Head pointer of Linked List
Node* head = NULL;


// ---------------------------------------------------------
// SCHOLARSHIP ELIGIBILITY FUNCTION
// ---------------------------------------------------------

bool checkEligibility(Student s)
{
    /*
    Eligibility Conditions:

    Marks >= 75
    AND
    Family Income <= Rs. 3,00,000

    If both conditions are satisfied,
    student will be eligible.
    */

    if (s.marks >= 75 && s.familyIncome <= 300000)
    {
        return true;
    }
    else
    {
        return false;
    }
}


// ---------------------------------------------------------
// ADD STUDENT
// Linked List Insertion
// ---------------------------------------------------------

void addStudent()
{
    Student s;

    cout << "\n========== ADD STUDENT ==========\n";

    cout << "Enter Roll Number: ";
    cin >> s.rollNo;

    cout << "Enter Name: ";
    cin >> s.name;

    cout << "Enter Marks: ";
    cin >> s.marks;

    cout << "Enter Family Annual Income: ";
    cin >> s.familyIncome;

    // Check scholarship eligibility
    s.eligible = checkEligibility(s);

    // Create a new Linked List node
    Node* newNode = new Node;

    newNode->data = s;
    newNode->next = NULL;


    // If Linked List is empty
    if (head == NULL)
    {
        head = newNode;
    }

    // Otherwise add at the end
    else
    {
        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }


    cout << "\nStudent added successfully!\n";

    if (s.eligible)
    {
        cout << "Scholarship Status: ELIGIBLE\n";
    }
    else
    {
        cout << "Scholarship Status: NOT ELIGIBLE\n";
    }
}


// ---------------------------------------------------------
// DISPLAY ALL STUDENTS
// Linked List Traversal
// ---------------------------------------------------------

void displayStudents()
{
    if (head == NULL)
    {
        cout << "\nNo student records available.\n";
        return;
    }

    Node* temp = head;

    cout << "\n============== STUDENT RECORDS ==============\n";

    while (temp != NULL)
    {
        cout << "\nRoll Number   : "
             << temp->data.rollNo;

        cout << "\nName          : "
             << temp->data.name;

        cout << "\nMarks         : "
             << temp->data.marks;

        cout << "\nFamily Income : Rs. "
             << temp->data.familyIncome;


        if (temp->data.eligible)
        {
            cout << "\nScholarship   : ELIGIBLE";
        }
        else
        {
            cout << "\nScholarship   : NOT ELIGIBLE";
        }

        cout << "\n----------------------------------------------";

        // Move to next node
        temp = temp->next;
    }

    cout << endl;
}


// ---------------------------------------------------------
// LINEAR SEARCH
// ---------------------------------------------------------

void linearSearch()
{
    if (head == NULL)
    {
        cout << "\nNo student records available.\n";
        return;
    }

    int roll;

    cout << "\nEnter Roll Number to search: ";
    cin >> roll;

    Node* temp = head;


    // Traverse the Linked List
    while (temp != NULL)
    {
        if (temp->data.rollNo == roll)
        {
            cout << "\nStudent Found!\n";

            cout << "Name          : "
                 << temp->data.name << endl;

            cout << "Marks         : "
                 << temp->data.marks << endl;

            cout << "Family Income : Rs. "
                 << temp->data.familyIncome << endl;


            if (temp->data.eligible)
            {
                cout << "Scholarship   : ELIGIBLE\n";
            }
            else
            {
                cout << "Scholarship   : NOT ELIGIBLE\n";
            }

            return;
        }

        temp = temp->next;
    }

    cout << "\nStudent not found.\n";
}


// ---------------------------------------------------------
// COUNT TOTAL STUDENTS
// ---------------------------------------------------------

int countStudents()
{
    int count = 0;

    Node* temp = head;

    while (temp != NULL)
    {
        count++;

        temp = temp->next;
    }

    return count;
}


// ---------------------------------------------------------
// COPY LINKED LIST DATA INTO ARRAY
// ---------------------------------------------------------

void copyToArray(Student arr[])
{
    Node* temp = head;

    int i = 0;

    while (temp != NULL)
    {
        arr[i] = temp->data;

        i++;

        temp = temp->next;
    }
}


// ---------------------------------------------------------
// BUBBLE SORT
// Sort students according to marks
// ---------------------------------------------------------

void sortByMarks()
{
    int n = countStudents();

    if (n == 0)
    {
        cout << "\nNo students available.\n";
        return;
    }

    Student arr[100];

    copyToArray(arr);


    /*
    Bubble Sort:

    Students with higher marks
    will appear first.
    */

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].marks < arr[j + 1].marks)
            {
                Student temp = arr[j];

                arr[j] = arr[j + 1];

                arr[j + 1] = temp;
            }
        }
    }


    cout << "\n========== STUDENTS SORTED BY MARKS ==========\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Roll: "
             << arr[i].rollNo;

        cout << "   Name: "
             << arr[i].name;

        cout << "   Marks: "
             << arr[i].marks << endl;
    }
}


// ---------------------------------------------------------
// BINARY SEARCH
// Search student using Roll Number
// ---------------------------------------------------------

void binarySearch()
{
    int n = countStudents();

    if (n == 0)
    {
        cout << "\nNo students available.\n";
        return;
    }

    Student arr[100];

    copyToArray(arr);


    /*
    Binary Search works on sorted data.

    First we sort students according to
    Roll Number and then perform Binary Search.
    */

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].rollNo > arr[j + 1].rollNo)
            {
                Student temp = arr[j];

                arr[j] = arr[j + 1];

                arr[j + 1] = temp;
            }
        }
    }


    int roll;

    cout << "\nEnter Roll Number to search: ";
    cin >> roll;


    int low = 0;
    int high = n - 1;


    // Binary Search Algorithm
    while (low <= high)
    {
        int mid = (low + high) / 2;


        if (arr[mid].rollNo == roll)
        {
            cout << "\nStudent Found!\n";

            cout << "Name          : "
                 << arr[mid].name << endl;

            cout << "Marks         : "
                 << arr[mid].marks << endl;

            cout << "Family Income : Rs. "
                 << arr[mid].familyIncome << endl;


            if (arr[mid].eligible)
            {
                cout << "Scholarship   : ELIGIBLE\n";
            }
            else
            {
                cout << "Scholarship   : NOT ELIGIBLE\n";
            }

            return;
        }


        else if (arr[mid].rollNo < roll)
        {
            low = mid + 1;
        }


        else
        {
            high = mid - 1;
        }
    }


    cout << "\nStudent not found.\n";
}


// ---------------------------------------------------------
// DELETE STUDENT
// Linked List Deletion
// ---------------------------------------------------------

void deleteStudent()
{
    if (head == NULL)
    {
        cout << "\nNo student records available.\n";
        return;
    }


    int roll;

    cout << "\nEnter Roll Number to delete: ";
    cin >> roll;


    Node* temp = head;
    Node* previous = NULL;


    // Find the student
    while (temp != NULL &&
           temp->data.rollNo != roll)
    {
        previous = temp;

        temp = temp->next;
    }


    // Student not found
    if (temp == NULL)
    {
        cout << "\nStudent not found.\n";
        return;
    }


    // Delete first node
    if (previous == NULL)
    {
        head = head->next;
    }


    // Delete middle or last node
    else
    {
        previous->next = temp->next;
    }


    delete temp;

    cout << "\nStudent record deleted successfully.\n";
}


// ---------------------------------------------------------
// DISPLAY ELIGIBLE STUDENTS
// ---------------------------------------------------------

void displayEligibleStudents()
{
    if (head == NULL)
    {
        cout << "\nNo student records available.\n";
        return;
    }


    Node* temp = head;

    bool found = false;


    cout << "\n========== ELIGIBLE STUDENTS ==========\n";


    while (temp != NULL)
    {
        if (temp->data.eligible)
        {
            cout << "\nRoll Number : "
                 << temp->data.rollNo;

            cout << "\nName        : "
                 << temp->data.name;

            cout << "\nMarks       : "
                 << temp->data.marks;

            cout << "\nIncome      : Rs. "
                 << temp->data.familyIncome;

            cout << "\n---------------------------------------";

            found = true;
        }

        temp = temp->next;
    }


    if (!found)
    {
        cout << "\nNo eligible students found.\n";
    }

    cout << endl;
}


// ---------------------------------------------------------
// COUNT ELIGIBLE STUDENTS
// ---------------------------------------------------------

void countEligibleStudents()
{
    if (head == NULL)
    {
        cout << "\nNo student records available.\n";
        return;
    }


    int count = 0;

    Node* temp = head;


    while (temp != NULL)
    {
        if (temp->data.eligible)
        {
            count++;
        }

        temp = temp->next;
    }


    cout << "\nTotal Eligible Students: "
         << count << endl;
}


// ---------------------------------------------------------
// FIND TOP SCORING STUDENT
// ---------------------------------------------------------

void highestMarks()
{
    if (head == NULL)
    {
        cout << "\nNo student records available.\n";
        return;
    }


    Node* temp = head;

    Student highest = temp->data;

    temp = temp->next;


    while (temp != NULL)
    {
        if (temp->data.marks > highest.marks)
        {
            highest = temp->data;
        }

        temp = temp->next;
    }


    cout << "\n========== TOP SCORING STUDENT ==========\n";

    cout << "Roll Number : "
         << highest.rollNo << endl;

    cout << "Name        : "
         << highest.name << endl;

    cout << "Marks       : "
         << highest.marks << endl;
}


// ---------------------------------------------------------
// MAIN FUNCTION
// ---------------------------------------------------------

int main()
{
    int choice;


    do
    {
        cout << "\n\n==============================================";
        cout << "\n       STUDENT SCHOLARSHIP PROGRAM";
        cout << "\n==============================================";


        cout << "\n\nScholarship Eligibility:";
        cout << "\nMarks >= 75";
        cout << "\nFamily Income <= Rs. 3,00,000";


        cout << "\n\n--------------- MENU ----------------";

        cout << "\n1. Add Student";
        cout << "\n2. Display All Students";
        cout << "\n3. Linear Search";
        cout << "\n4. Binary Search";
        cout << "\n5. Sort Students by Marks";
        cout << "\n6. Display Eligible Students";
        cout << "\n7. Count Eligible Students";
        cout << "\n8. Find Top Scoring Student";
        cout << "\n9. Delete Student";
        cout << "\n10. Count Total Students";
        cout << "\n11. Exit";


        cout << "\n\nEnter your choice: ";
        cin >> choice;


        switch (choice)
        {
        case 1:
            addStudent();
            break;


        case 2:
            displayStudents();
            break;


        case 3:
            linearSearch();
            break;


        case 4:
            binarySearch();
            break;


        case 5:
            sortByMarks();
            break;


        case 6:
            displayEligibleStudents();
            break;


        case 7:
            countEligibleStudents();
            break;


        case 8:
            highestMarks();
            break;


        case 9:
            deleteStudent();
            break;


        case 10:
            cout << "\nTotal Students: "
                 << countStudents() << endl;
            break;


        case 11:
            cout << "\nThank you for using the program!\n";
            break;


        default:
            cout << "\nInvalid choice!\n";
        }


    } while (choice != 11);


    return 0;
}