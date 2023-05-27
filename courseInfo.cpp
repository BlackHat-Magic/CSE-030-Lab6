# include <iostream>
# include <fstream>
# include <string>

using namespace std;

struct Time {
    int hour;
    int mins;
    int secs;
};

struct Course {
    string name;
    int credits;
    bool majorRequirement;
    double avgGrade;
    string days;
    Time startTime;
    Time endTime;
};

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

void print24Hour(Time input) {
    cout << input.hour << ":" << input.mins << ":";
    if (input.secs < 10) {
        cout << "0" << input.secs;
    } else {
        cout << input.secs;
    }
}

int main () {
    ifstream infile("in.txt");

    string courseNumStr;
    infile >> courseNumStr;
    int courseNum = stoi(courseNumStr);
    if (courseNum < 1) {
        cout << "Invalid number of courses." << endl;
        return(1);
    }

    Course courses[courseNum];

    for (int i = 0; i < courseNum; i++) {
        string credits;
        string majorRequirement;
        string avgGrade;
        string dummy;
        string days;
        string start;
        string end;
        infile >> courses[i].name;
        infile >> credits;
        courses[i].credits = stoi(credits);
        infile >> majorRequirement;
        courses[i].majorRequirement = stoi(majorRequirement);
        infile >> avgGrade;
        courses[i].avgGrade = atof(avgGrade.c_str());
        infile.ignore();
        getline(infile, courses[i].days);
        infile >> start;
        if (!getTimeFromUser(courses[i].startTime, start)) {
            cout << "Invalid Time Encountered." << endl;
            return(1);
        }
        infile >> end;
        if (!getTimeFromUser(courses[i].endTime, end)) {
            cout << "Invalid Time Encountered." << endl;
            return(1);
        }
    }

    cout << "-------------------" << endl;
    cout << "SCHEDULE OF STUDENT" << endl;
    for (int i = 0; i < courseNum; i++) {
        cout << "-------------------" << endl;
        cout << "COURSE " << i + 1 << ": " << courses[i].name << endl;
        if (courses[i].majorRequirement) {
            cout << "Note: this course is a major requirement!" << endl;
        } else {
            cout << "Note: this course is not a major requirement..." << endl;
        }
        cout << "Number of Credits: " << courses[i].credits << endl;
        cout << "Days of Lectures: " << courses[i].days << endl;

        cout << "Lecture Time: ";
        print24Hour(courses[i].startTime);
        if (courses[i].startTime.hour >= 12) {
            cout << "pm";
        } else {
            cout << "am";
        }
        cout << " - ";
        print24Hour(courses[i].endTime);
        if (courses[i].endTime.hour >= 12) {
            cout << "pm";
        } else {
            cout << "am";
        }
        cout << endl;

        cout << "Stat: on average students get " << courses[i].avgGrade << "\% in this course." << endl;
    }

    return(0);
}