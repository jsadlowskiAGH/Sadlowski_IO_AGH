#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Date {
public:
    int day;
    int month;
    string hour;
};

class Secretary {
public:
    Date checkAvailableDates() {
        Date date;
        cout << "Enter the day: ";
        cin >> date.day;
        cout << "Enter the month: ";
        cin >> date.month;
        cout << "Enter the hour (format 00:00): ";
        cin >> date.hour;
        return date;
    }

    bool wantToBook() {
        char response;
        cout << "Do you want to book an appointment for this date? (y/n): ";
        cin >> response;
        return (response == 'y' || response == 'Y');
    }

    void bookAnAppointment(string dateToBook) {
        ifstream file("C:/Users/jakub/Programming/C++/C++ Projects/Exercises/data.csv");
        string line;
        vector<string> lines;

        if (!file.is_open()) {
            cout << "Unable to open file" << endl;
            return;
        }

        while (getline(file, line)) {
            vector<string> tokens = split(line, ',');

            if (tokens.size() > 0 && tokens[0] == dateToBook) {
                line = tokens[0] + ",Zajęty";
            }

            lines.push_back(line);
        }

        file.close();

        ofstream outfile("data.csv", ofstream::out | ofstream::trunc);
        for (const auto &line : lines) {
            outfile << line << endl;
        }
        outfile.close();
    }

    vector<string> split(const string &str, char delimiter) {
        vector<string> internal;
        stringstream ss(str);
        string temp;

        while (getline(ss, temp, delimiter)) {
            internal.push_back(temp);
        }

        return internal;
    }
};

class DataBase {
private:
    string filename;

public:
    DataBase(string fname) : filename(fname) {}

    bool searchDateInFile(string dateToSearch, const Date &inputDate) {
        ifstream file(filename);
        string line;

        if (!file.is_open()) {
            cout << "Unable to open file" << endl;
            return false;
        }

        bool found = false;
        bool status = false;

        while (getline(file, line)) {
            vector<string> tokens = split(line, ',');
            if(tokens.size() > 0){
                vector<string> dateAndTime;
                dateAndTime.push_back(tokens[0]);
                dateAndTime.push_back(tokens[1]);
                if(dateAndTime.size() > 1){
                    if (dateAndTime[0] == dateToSearch || dateAndTime[1] == inputDate.hour) {
                        if (tokens[2] == "Dostępny") {
                            found = true;
                            status = true;
                        } else if (tokens[2] == "Zajęty") {
                            found = true;
                            status = false;
                        }
                        break;
                    }
                }
            }
        }

        file.close();
        return found ? status : false;
    }

    vector<string> split(const string &str, char delimiter) {
        vector<string> internal;
        stringstream ss(str);
        string temp;

        while (getline(ss, temp, delimiter)) {
            internal.push_back(temp);
        }

        return internal;
    }
};

int main() {
    Secretary secretary;
    Date inputDate = secretary.checkAvailableDates();

    string dateToSearch = to_string(inputDate.day) + "-" + to_string(inputDate.month);

    // Modify this path to match the actual location of your data.csv file
    DataBase database("C:/Users/jakub/Programming/C++/C++ Projects/Exercises/data.csv");
    bool found = database.searchDateInFile(dateToSearch, inputDate);

    if (found) {
        cout << "Matching record found." << endl;
        if (secretary.wantToBook()) {
            secretary.bookAnAppointment(dateToSearch + " " + inputDate.hour);
            cout << "Appointment booked for the specified date." << endl;
        } else {
            cout << "Appointment not booked. Exiting program." << endl;
        }
    } else {
        cout << "No record found for the specified date." << endl;
    }

    return 0;
}
