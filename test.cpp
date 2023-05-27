# include <iostream>
# include <fstream>
# include <string>

using namespace std;

int main () {
    ifstream infile("test.txt");
    string firstline;

    infile >> firstline;
    cout << firstline << endl;

    infile.ignore();

    string secondline;
    getline(infile, secondline);
    cout << secondline << endl;

    return(0);
}