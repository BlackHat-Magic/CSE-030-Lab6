# include <iostream>
# include <string>
# include <ctype.h>

using namespace std;

struct Time {
    int hour;
    int mins;
    int secs;
};

// define function which checks user input
bool getTimeFromUser (Time &startend, string input) {
    if(input.size() != 8) {
        return(false);
    }
    if(input.substr(2, 1) != ":" || input.substr(5, 1) != ":") {
        return(false);
    }

    if (!(isdigit(input[0]) && isdigit(input[1]) && isdigit(input[3]) && isdigit(input[4]) && isdigit(input[6]) && isdigit(input[7]))) {
        return(false);
    }
    int hour = stoi(input.substr(0, 2));
    int mins = stoi(input.substr(3, 2));
    int secs = stoi(input.substr(6, 2));

    if (hour > 24 || mins > 59 || secs > 59) {
        return(false);
    }

    startend.hour = hour;
    startend.mins = mins;
    startend.secs = secs;

    return(true);
}

// define function which prints time structure as HH:MM:SS
void print24Hour(Time input) {
    cout << input.hour << ":" << input.mins << ":";
    if (input.secs < 10) {
        cout << "0" << input.secs << endl;
    } else {
        cout << input.secs << endl;
    }
}

int main () {
    // define time structure

    // get & check start time
    cout << "Enter the start time for the lecture (format is HH:MM:SS): ";
    string start;
    getline(cin, start);

    Time startst;
    if (!getTimeFromUser(startst, start)) {
        cout << "Invalid time entered." << endl;
        return(1);
    }

    // get & check end time
    cout << "Enter the end time for the lecture (format is HH:MM:SS): ";
    string end;
    getline(cin, end);

    Time endstrc;
    if (!getTimeFromUser(endstrc, end)) {
        cout << "Invalid time entered." << endl;
        return(1);
    }

    cout << "Start: "; 
    print24Hour(startst);
    
    cout << "End: ";
    print24Hour(endstrc);

    return(0);
}