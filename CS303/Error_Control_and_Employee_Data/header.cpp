#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include "/Users/ehast/Documents/GitHub/CS303/Assignment_2/header.h"
using namespace std;

int hours_worked(int hours) {
    int full_time = 40;
    int part_time = 30;
    return 0;
}

int vacation_hours(int hours_worked) {
    int full_time0 = 40;
    int full_time1thru5 = 60;
    int full_time6thru10 = 80;
    int full_time10 = 100;
    return 0;
}

int health_contrib(){
    int full_time = 100;
    int part_time = 250;
    return 0;
}

double professional::salary(double pay) {
    double pay_period = pay/4; // Monthly pay split into 4 for each week
    cout << "For the current pay period, full time employee has been paid: " << pay_period << endl;
    return 0;
}

double nonprofessional::weekly_salary(double hourly_rate, int hours_worked) {
    double pay_period;
    if (hours_worked <=40) {
    pay_period = hourly_rate * hours_worked; // Calculates pay for hours worked
    }
    else if (hours_worked > 40){
        double OT_pay = hourly_rate *1.5; // If worked mored than 40 hours in one week, calculate overtime pay
        int OT_hours = hours_worked - 40;
        pay_period = (OT_pay * OT_hours) + (40 * hourly_rate);
    }
    cout << "For the current pay period, part time employee has been paid: " << pay_period << endl;
    return 0;
}
