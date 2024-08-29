// ConsoleApplication1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include <iostream>
#include <fstream>
#include <string>
#include <random>
using namespace std;
//yest

int main()
{

    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(1, 26);

    ofstream file("random_text.log");
    if (!file.is_open()) {
        cout << "Failed to open file" << endl;
        return 1;
    }

    int bytes_written = 0;
    string line;

    int size = 10;//default
    cout << "please enter size"<<endl;
    cin >> size;

    char keyword[20];
    cout << "please enter keyword" << endl;
    cin >> keyword;

    while (bytes_written < 20 * 1024 * 1024) {
        int length = dist(mt);
        if (length > 50 - 6) { // make sure there's enough space for "Winter"
            length = 50 - 6;
        }

        line.clear();
        for (int i = 0; i < length; i++) {
            line += char(dist(mt) + 'a' - 1);
        }

        // Insert "Winter" randomly
        if (length < 50 - 6) {
            int pos = dist(mt) % (length + 1);
            line.insert(pos, "Winter");
        }

        // Write the line to file
        file << line << endl;
        bytes_written += line.size() + 1;
    }

    file.close();
    cout << "Done" << endl;

    return 0;
}


