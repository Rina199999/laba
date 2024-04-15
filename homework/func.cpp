#include <iostream>
#include <fstream>
#include <string>
#include "func.h"
using namespace std;
int func::ch(int* m) {
    if (cin >> *m)
        return 0;
    else {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
}

void func::save(SportMatches* arr, const int& n) {
    ofstream file("file.txt");
    if (!file.is_open()) {
        cout << "save: file error" << endl;
        return;
    }
    file << n << endl;
    for (int i = 0; i < n; i++)
        file << arr[i].teamname() << " " << arr[i].country() << " " << arr[i].numberofplayers() << endl;
    file.close();
}
void func::read(SportMatches** arr, int* n) {
    ifstream file("file.txt");
    if (!file.is_open()) {
        cout << "Error: could not open file.txt" << endl;
        return;
    }

    file >> *n;
    if (*n <= 0) {
        cout << "Error: invalid number of records" << endl;
        file.close();
        return;
    }

    *arr = new SportMatches[*n];
    for (int i = 0; i < *n; i++) {
        string teamname, country;
        int numberofplayers;
        file >> teamname >> country >> numberofplayers;
        (*arr)[i].setName(teamname);
        (*arr)[i].setCountry(country);
        (*arr)[i].setNumber(numberofplayers);
    }

    file.close();
}
SportMatches* func::load(int& n) {
    ifstream file("t.txt");
    if (!file.is_open()) {
        cout << "load: file error" << endl;
        return nullptr;
    }
    file >> n;
    if (n <= 0) {
        cout << "load: n error" << endl;
        return nullptr;
    }

    SportMatches* arr = new SportMatches[n];
    for (int i = 0; i < n; i++) {
        string teamname;
        string country;
        int numberofplayers;
        file >> teamname >> country >> numberofplayers;
        arr[i].setName(teamname);
        arr[i].setCountry(country);
        arr[i].setNumber(numberofplayers);
    }
    file.close();
    return arr;
}

void func::create(SportMatches** arr, int* n) {
    cout << "n = ";
    if (ch(n))
        return;
    if (*n <= 0)
        return;
    *arr = new SportMatches[*n];
    for (int i = 0; i < *n; i++) {
        cout << "Team name = ";
        string teamName;
        cin >> teamName;
        (*arr)[i].setName(teamName);

        cout << "Country = ";
        string country;
        cin >> country;
        (*arr)[i].setCountry(country);

        cout << "Number of players = ";
        int numOfPlayers;
        if (ch(&numOfPlayers))
            return;
        (*arr)[i].setNumber(numOfPlayers);
    }
}
void func::find(SportMatches* arr, int* n, int nn) {
    switch (nn) {
    case 1: {
        cout << "Name team - " << endl;
        string teamName;
        cin >> teamName;
        for (int i = 0; i < *n; i++) {
            if (arr[i].teamname() == teamName) {
                cout << arr[i].teamname() << " " << arr[i].country() << " " << arr[i].numberofplayers() << endl;
            }
        }
        break;
    }
    case 2: {
        cout << "Country - " << endl;
        string country;
        cin >> country;
        for (int i = 0; i < *n; i++) {
            if (arr[i].country() == country) {
                cout << arr[i].teamname() << " " << arr[i].country() << " " << arr[i].numberofplayers() << endl;
            }
        }
        break;
    }
    case 3: {
        cout << "Numbers of players - " << endl;
        int numOfPlayers;
        if (func::ch(&numOfPlayers))
            return;
        for (int i = 0; i < *n; i++) {
            if (numOfPlayers == arr[i].numberofplayers()) {
                cout << arr[i].teamname() << " " << arr[i].country() << " " << arr[i].numberofplayers() << endl;
            }
        }
        break;
    }
    default:
        cout << "Have not this team" << endl;
        break;
    }
}
void func::removeElement(SportMatches*& arr, int& n, int index) {
    if (index < 0 || index >= n) {
        cout << "Index out of range." << endl;
        return;
    }

    for (int i = index; i < n - 1; ++i) {
        arr[i] = arr[i + 1];
    }

    --n;
    SportMatches* newArr = new SportMatches[n];
    for (int i = 0; i < n; ++i)
        newArr[i] = arr[i];
    delete[] arr;
    arr = newArr;
}
void func::edit(SportMatches* match) {
    string newName;

    cout << "Enter new team name: ";
    cin >> newName;
    match->setName(newName);

    cout << "Match information updated successfully." << endl;
}
void func::addElemement(SportMatches*& arr, int& n, const SportMatches& newMatch) {
    SportMatches* newArr = new SportMatches[n + 1];
    for (int i = 0; i < n; ++i)
        newArr[i] = arr[i];
    newArr[n] = newMatch;
    ++n;
    delete[] arr;
    arr = newArr;
}

