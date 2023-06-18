#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include "/Users/ehast/Documents/GitHub/CS303/Assignment_2/header.h"
using namespace std;

int main() {
    employee e; //Declaring instances of each class
    professional p;
    nonprofessional n;

    char ans;
    int time_with_comp =0;
    double pay = 4000;
    double hourly_rate = 15.00;
    double hours = 0;
    int tot_hours = 0;
    cout << "Is employee part time or full time? (f or p)\n"; // choose which class type to run
    cin >> ans;
    tolower(ans);
    if (ans == 'f') { // full time processes
        p.salary(pay); // runs the salary calculation from header.cpp
        cout << "How long has employee worked for this company? (In years) ";
        cin >> time_with_comp;
        if (time_with_comp == 0) { // The longer an employee works for the company, the more vac time they qualify for each YTD
            cout << "Vacation time: 40 hours.\n";
        }
        else if (time_with_comp >= 1 && time_with_comp <= 5) {
            cout << "Vacation time: 60 hours.\n";
        }
        else if (time_with_comp > 5 && time_with_comp <= 10) {
            cout << "Vacation time: 80 hours.\n";
        }
        else if (time_with_comp > 10) {
            cout << "Vacation time: 100 hours.\n";
        }
        else { // If something is not entered properly, return an error
            cout << "Error: Not a proper value.\n";
        }
    cout << "Health insurance cost: $100 per month\n"; // Health insurance cost is the same every month
    }
    else if (ans == 'p') { //Run through part time processes
        cout << "How many hours has employee worked this week? ";
        cin >> hours;
        n.weekly_salary(hourly_rate, hours); //Calculates weekly pay from header.cpp
        cout << "How many hours has employee worked YTD? ";
        cin >> tot_hours;
        double vac_time = tot_hours * .0515; //Vac time = a fraction of the hours worked. 30 hours a week for a full year nets 80 hours vacation time
        cout << "Vacation time: " << vac_time << endl;
        cout << "Health insurance cost: $250 per month\n";

    }
    return 0;
}