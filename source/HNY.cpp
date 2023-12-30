#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <windows.h>
using namespace std;
int bl_ind, clr_ind;
char bls[2] = { 'O', 'o' };
int clrs[6] = { 31, 33, 34, 35, 36, 37 };
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void print_tree() {

    srand(time(NULL));
    int width = 5;
    int height = 5;
    int space = width * 3;
    
    int x = 1;


    // Pyramids
    //cout << endl << endl << endl << endl;
    for (int a = 1; a <= height; a++) {
        for (int i = x; i <= width; i++) {
            for (int j = space; j >= i; j--)
                cout << " ";
            for (int k = 1; k <= i; k++) {
                if ((i == 1) || ((k - 3) % 4 == 0 && (i - 2) % 2 == 0)) {
                    bl_ind = rand() % (1 - 0 + 1) + 0;
                    clr_ind = rand() % (6 - 0 + 1) + 0;
                    cout << "\x1b[32;"<< clrs[clr_ind] << "m" << bls[bl_ind] << " " << "\x1b[0m";
                }
                else cout << "\x1b[32m" << "* " << "\x1b[0m";
            }
            cout << endl;
        }
        //cout << endl;
        x = x + 2;
        width = width + 2;
    }

    // Print Branch
    for (int i = 1; i <= 2; i++) {

        for (int j = space - 1; j >= 1; j--)
            cout << " ";

        for (int k = 1; k <= 2; k++)
            cout << "\x1b[0;2;33m# \x1b[0m";

        cout << endl;
    }

    for (int i = 1; i <= 2; i++) {

        for (int j = space - 3; j >= 1; j--)
            cout << " ";

        for (int k = 1; k <= 4; k++)
            cout << "\x1b[0;2;33m# \x1b[0m";

        cout << endl;
    }
}

int main()
{
    ShowConsoleCursor(false);
    while (1) {
        print_tree();
        this_thread::sleep_for(std::chrono::milliseconds(750));
        system("cls");
    }
    return 0;
}
