#include "Flight.h"

namespace assign1 {
  Flight::Flight() { 
    flight_number = "";
    arrival_time_hours = 0;
    arrival_time_minutes = 0;
  }
  Flight::Flight(string flight_number, unsigned int arrival_time_hours, unsigned int arrival_time_minutes) {}

  string Flight::get_flight_number() {
    return flight_number;
  }

  unsigned int Flight::get_arrival_time_hours() {
    return arrival_time_hours;
  }

  unsigned int Flight::get_arrival_time_minutes() {
    return arrival_time_minutes;
  }
}