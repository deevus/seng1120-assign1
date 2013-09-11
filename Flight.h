/**************************/
/* Simon Hartcher         */
/* C3185790               */
/* Software Engineering 2 */
/**************************/

#ifndef FLIGHT_H_DEFINED
#define FLIGHT_H_DEFINED

#include <string>

using namespace std;

namespace assign1 {
  class Flight {

  public:
    Flight();
    //Pre-condition: None
    //Post-condition: Returns empty Flight

    Flight(const string flight_number, const unsigned int arrival_time_hours, const unsigned int arrival_time_minutes);
    //Pre-condition: None
    //Post-condition: Returns new Flight with given values

    string get_flight_number();
    const string get_flight_number() const;
    //Pre-condition: None
    //Post-condition: Returns flight_number.

    unsigned int get_arrival_time_hours();
    const unsigned int get_arrival_time_hours() const;
    //Pre-condition: None
    //Post-condition: Returns arrival_time_hours.

    unsigned int get_arrival_time_minutes();
    const unsigned int get_arrival_time_minutes() const;
    //Pre-condition: None
    //Post-condition: Returns arrival_time_minutes.

    void set_flight_number(const string flight_number);
    //Pre-condition: None
    //Post-condition: Sets flight_number.

    void set_arrival_time_hours(unsigned int arrival_time_hours);
    //Pre-condition: None
    //Post-condition: Sets arrival_time_hours.

    void set_arrival_time_minutes(unsigned int arrival_time_minutes);
    //Pre-condition: None
    //Post-condition: Sets arrival_time_minutes.

    int ArrivalTimeInMinutes();
    const int ArrivalTimeInMinutes() const;
    //Pre-condition: None
    //Post-condition: Returns total integer value of arrival time in minutes.

    int CompareTo(const Flight& b); 
    const int CompareTo(const Flight& b) const; 
    //Pre-condition: None
    //Post-condition: Compares the arrival times of this with given argument.
    //If Flight is equal to the argument, returns 0;
    //If Flight is greater than the argument, returns 1;
    //If Flight is less than the argument, returns -1.

  private:
    string flight_number;
    unsigned int arrival_time_hours;
    unsigned int arrival_time_minutes;
  };

  ostream& operator<< (ostream& os, const Flight& fl);
}

#endif