#include "Flight.h"
#include <iostream>
#include <sstream>

namespace assign1 {
  Flight::Flight() { 
    flight_number = "";
    arrival_time_hours = 0;
    arrival_time_minutes = 0;
  }
  Flight::Flight(string flight_number, unsigned int arrival_time_hours, unsigned int arrival_time_minutes) {
    this->flight_number = flight_number;
    this->arrival_time_hours = arrival_time_hours;
    this->arrival_time_minutes = arrival_time_minutes;
  }

  string Flight::get_flight_number() {
    return flight_number;
  }

  const string Flight::get_flight_number() const {
    return flight_number;
  }

  unsigned int Flight::get_arrival_time_hours() {
    return arrival_time_hours;
  }

  const unsigned int Flight::get_arrival_time_hours() const {
    return arrival_time_hours;
  }

  unsigned int Flight::get_arrival_time_minutes() {
    return arrival_time_minutes;
  }

  const unsigned int Flight::get_arrival_time_minutes() const {
    return arrival_time_minutes;
  }

  void Flight::set_flight_number(string flight_number) {
    this->flight_number = flight_number;
  }

  void Flight::set_arrival_time_hours(unsigned int arrival_time_hours) {
    this->arrival_time_hours = arrival_time_hours;
  }

  void Flight::set_arrival_time_minutes(unsigned int arrival_time_minutes) {
    this->arrival_time_minutes = arrival_time_minutes;
  }

  int Flight::ArrivalTimeInMinutes() {
    return arrival_time_hours * 60 + arrival_time_minutes;
  }

  ostream& operator<< (ostream& os, const Flight& fl) {
    stringstream ss;
    if (fl.get_arrival_time_hours() < 10) ss << "0";
    ss << fl.get_arrival_time_hours();

    ss << ":";

    if (fl.get_arrival_time_minutes() < 10) ss << "0";
    ss << fl.get_arrival_time_minutes();

    string timeString;
    ss >> timeString;

    os << fl.get_flight_number() << " " << timeString;
    return os;
  };

  int Flight::CompareTo(Flight& b) {
    if (this->ArrivalTimeInMinutes() == b.ArrivalTimeInMinutes()) return 0;
    if (this->ArrivalTimeInMinutes() < b.ArrivalTimeInMinutes()) return -1;
    return 1;
  }

}

