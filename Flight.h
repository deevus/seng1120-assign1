#include <string>

using namespace std;

namespace assign1 {
  class Flight {

  public:
    Flight();
    Flight(string flight_number, unsigned int arrival_time_hours, unsigned int arrival_time_minutes);

    string get_flight_number();
    unsigned int get_arrival_time_hours();
    unsigned int get_arrival_time_minutes();

  private:
    string flight_number;
    unsigned int arrival_time_hours;
    unsigned int arrival_time_minutes;
  };
}