#include <iostream>
#include "func.h"
#include <fstream>

using namespace std;
using namespace func;

int main() {
    SportMatches* arr = nullptr;
    int n = 0;
    int stop = 0;
    while (stop != 1) {
        int key = 0;
        cout << "1-create, 2-read, 3-print, 4-find, 5-clear file, 6-edit, 7-exit" << endl;
        ch(&key);
        switch (key) {
        case 1:
            create(&arr, &n);
            if (arr)
                save(arr, n);
            break;
        case 2:
            read(&arr, &n);
            if (!arr)
                cout << "read error" << endl;
            else
                cout << "loaded " << n << endl;
            break;
        case 3:
            for (int i = 0; i < n; i++)
                cout << arr[i] << endl;
            break;
        case 4:
            cout << "1-team name, 2-country, 3-number of players" << endl;
            int x;
            cin >> x;
            find(arr, &n, x);
            break;
        case 5: {
            cout << "Enter the index for delete element: ";
            int index;
            cin >> index;
            removeElement(arr, n, index);
            break;
        }
        case 6: {
            cout << "Enter the index of the match you want to edit: ";
            int index;
            cin >> index;
            if (index >= 0 && index < n) {
                edit(&arr[index]);
                save(arr, n); 
            }
            else {
                cout << "Invalid index." << endl;
            }
            break;
        }
        case 7:
            stop = 1;
            break;
        default:
            cout << "Invalid option." << endl;
            break;
        }
    }
    delete[] arr;
    return 0;
}
