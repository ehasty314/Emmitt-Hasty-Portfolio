#ifndef HEADER_H_
#define HEADER_H_

class employee {
    public: int hours_worked(int hours);
            int vacation_hours(int hours_worked);
            int health_contrib();
};

class professional : public employee {
    public: double salary(double pay);
};

class nonprofessional : public employee {
    public: double weekly_salary(double hourly_rate, int hours_worked);
};

#endif