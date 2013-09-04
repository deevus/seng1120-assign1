#ifndef FLIGHT_H_DEFINED
#define FLIGHT_H_DEFINED

#include <string>

using namespace std;

namespace assign1 {
  class Flight {

  public:
    Flight();
    Flight(string flight_number, unsigned int arrival_time_hours, unsigned int arrival_time_minutes);

    string get_flight_number();
    const string get_flight_number() const;
    unsigned int get_arrival_time_hours();
    const unsigned int get_arrival_time_hours() const;
    unsigned int get_arrival_time_minutes();
    const unsigned int get_arrival_time_minutes() const;

    void set_flight_number(string flight_number);
    void set_arrival_time_hours(unsigned int arrival_time_hours);
    void set_arrival_time_minutes(unsigned int arrival_time_minutes);

    int ArrivalTimeInMinutes();

  private:
    string flight_number;
    unsigned int arrival_time_hours;
    unsigned int arrival_time_minutes;
  };

  ostream& operator<< (ostream& os, const Flight& fl);
}

#endif