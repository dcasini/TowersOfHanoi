//  main.cpp    //  TowerOfHanoi_v3   //  Created by David Casini on 5/13/14.
#include <iostream>
#include <iomanip>
using namespace std;

char Grid[5][3];

string A = "54321";
string B;
string C;

void delay()
{
    char a = 'a';
    char b = 'b';
    
    for(long int i = 0; i < 97; ++i)
	{
        b = a;
        for(long int i = 0; i < 999999; ++i)   // add another '9' to make a longer delay, or remove a '9' to make a shorter delay
 		{ a = b; }
        b = a;
	}
}

void initializeGrid() {
    for (int i = 0; i < 5; ++i) {           //rows
        for (int c = 0; c < 3; ++c) {       //columns
            Grid[i][c] = '.';
        }
    }
}

void StringToGrid() {
    int i = 0;
    for (int g = 4; g >= 0; --g)
    {
        
        if ((A.size() > 0) && (i < A.size()))
            Grid[g][0] = A[i];
        
        if ((B.size() > 0) && (i < B.size()))
            Grid[g][1] = B[i];
        
        if ((C.size() > 0) && (i < C.size()))
            Grid[g][2] = C[i];
        
        ++i;
    }
}

void printGrid() {
    for (int i = 0; i < 5; ++i) {
        for (int c = 0; c < 3; ++c) {
            cout << setw(7)<< Grid[i][c];
        }
        cout << endl;
    }
    cout << "------A------B------C------" << endl;
    cout << endl << endl << endl;
}

void displayTowers() {
    initializeGrid();
    StringToGrid();
    printGrid();
}

void MoveDisk(char source, char destination){
    
    if ((source == 'A') && (destination == 'B'))
    { B.push_back(A[A.size() - 1]);
        A.pop_back();
    }
    
    if ((source == 'A') && (destination == 'C'))
    { C.push_back(A[A.size() - 1]);
        A.pop_back();
    }
    
    if ((source == 'B') && (destination == 'C'))
    { C.push_back(B[B.size() - 1]);
        B.pop_back();
    }
    
    if ((source == 'B') && (destination == 'A'))
    { A.push_back(B[B.size() - 1]);
        B.pop_back();
    }
    
    if ((source == 'C') && (destination == 'B'))
    { B.push_back(C[C.size() - 1]);
        C.pop_back();
    }
    
    if ((source == 'C') && (destination == 'A'))
    { A.push_back(C[C.size() - 1]);
        C.pop_back();
    }
}


void MoveTower(int disk, char source, char dest, char spare) {
    if (disk == 0) {
        MoveDisk(source, dest);
        displayTowers();
        delay();
    }
    else {
        MoveTower((disk -1 ), source, spare, dest);
        if ((B == "54321") || (C == "54321"))
            { return; }
        MoveDisk(source, dest);
        displayTowers();
        delay();
        MoveTower((disk - 1), spare, dest, source);
       }
}

int main()
{
    displayTowers();
    
    cout << "type 'b' to move tower from A to B (must be lowercase)" << endl;
    cout << "type 'c' to move tower from A to C (must be lowercase)" << endl;
    char selection;
    cin >> selection;
    if ((selection != 'b') && (selection != 'c')) {
        cout << "that is not a valid choice. Please run the program again." << endl;
        return 0;
    }
    cout << endl << endl;
    
    if (selection == 'b') {
        MoveTower(5, 'A', 'C', 'B');
    }
    if (selection == 'c') {
        MoveTower(5, 'A', 'B', 'C');
    }
    
    return 0;
}
