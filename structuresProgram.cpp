// Name: Aaron Pelto
// Week: 12
// Program: CST 180 C++ Programming Structures Program Assignment

/*
***********************************************************************************************************
LoadArray

Primary responsibility: Loads periodic table array with records.

HOW: Pass the address of your structures array to the function. Use a loop to read in
the data records from the data file for each atom.
***********************************************************************************************************

***********************************************************************************************************
DisplayMenu

Primary responsibility: Displays the program menu.

HOW: Display a menu that allows the user to search the periodic table using either the
element code or the atomic number. Return the menu selection to the calling
function.
***********************************************************************************************************

***********************************************************************************************************
CodeSearch

Primary responsibility: Searches the structure array by element symbol(code).

How: Pass the address of your structures array and the symbol for the desired
element. Set up a loop to process the array, searching for the symbol. If found, return
the array index where the element was found. If not found, return -1.
***********************************************************************************************************

***********************************************************************************************************
NumberSearch

Primary responsibility: Searches the structure array by atomic number (element
number).

HOW: Pass the address of your structures array and the atomic number for the desired
element. Set up a loop to process the array, searching for the atomic number. If
found, return the array index where the element was found. If not found, return -1.
***********************************************************************************************************

***********************************************************************************************************
In addition to the above functions, you should display the result of the search (e.g. whether the element
was found or not) and the associated information.
***********************************************************************************************************
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int SIZE = 103;
const size_t MAXIMUM_CHARACTERS = 25;

struct periodicElements
{

    // Element Code such as H
    string elementCode;

    // Element Name
    string elementName;

    // Element #
    int elementNumber;

    // Element Weight
    double elementWeight;

} e[SIZE];

void loadArray(periodicElements, int);
int displayMenu(int);
int codeSearch(periodicElements, string, int);
int numberSearch(periodicElements, int, int);

int main()
{

    int i;
    double menuValue;
    menuValue = 0;
    string codeInput;
    int numberInput;
    int x, z;
    x = 0;
    z = 0;

    periodicElements elements;
    cout << "Welcome to the Element Structures Program.\n";
    // Load the array from Periodic.txt
    loadArray(elements, SIZE);

    // display the menu to enter the Atomic Number or Weight
    menuValue = displayMenu(menuValue);

    if (menuValue == 1)
    {
        cout << "Enter your Element Code" << endl;
        cin >> codeInput;

        i = codeSearch(elements, codeInput, SIZE);
    }
    else if (menuValue == 2)
    {
        do
        {
            cout << "Enter your Element Atomic Number" << endl;
            cin >> numberInput;

            i = numberSearch(elements, numberInput, SIZE);
        } while (numberInput < 1 || numberInput > 103);
    }
    else if (menuValue == -1)
    {
        exit(0);
    }

    if (i == -1)
    {
        cout << "\nElement not found\n";
    }
    else
    {
        cout << "\nThe element requested is\n";
        cout << e[i].elementCode << " " << e[i].elementName << " " << e[i].elementNumber << " " << e[i].elementWeight;
    }
}

void loadArray(periodicElements, int SIZE)
{
    int i;

    ifstream periodic("periodic.txt");

    if (!periodic)
    {
        cout << "Error reading file." << endl;
        exit(1);
    }
    for (i = 0; i < SIZE; i++)
    {
        periodic >> e[i].elementCode >> e[i].elementName >> e[i].elementNumber >> e[i].elementWeight;
    }
}

int displayMenu(int)
{
    int menuInput;

    do
    {
        cout << "[0] Quit" << endl;
        cout << "[1] Search for Element Code" << endl;
        cout << "[2] Search for Element Atomic Number" << endl;
        cin >> menuInput;

        switch (menuInput)
        {
        case 0:
            break;
        case 1:
            return menuInput;
        case 2:
            return menuInput;
        }
    } while (menuInput != 0);
    menuInput = -1;
    return menuInput;
}

int codeSearch(periodicElements, string codeInput, int SIZE)
{
    int i;
    int x;
    x = 0;

    for (i = 0; i < SIZE; i++)
    {
        if (e[i].elementCode != codeInput)
        {
            x = -1;
        }
        else if (e[i].elementCode == codeInput)
        {
            x = i;
            return x;
        }
    }
    return x;
}

int numberSearch(periodicElements, int numberInput, int SIZE)
{
    int i;
    int x;
    x = 0;

    for (i = 0; i < SIZE; i++)
    {
        if (e[i].elementNumber != numberInput)
        {
            x = -1;
        }
        else if (e[i].elementNumber == numberInput)
        {
            x = i;
            return x;
        }
    }
    return x;
}
