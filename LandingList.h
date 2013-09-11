#ifndef LANDINGLIST_H_DEFINED
#define LANDINGLIST_H_DEFINED

#include <string>
#include "datastructures/LinkedList.h"
#include "Flight.h"

using namespace std;

namespace assign1 {
  class LandingList {

  public:
    LandingList();
    LandingList(string file_name);

    ~LandingList();
    
    //Pre-condition:
    //Given flight is not already in the list
    //The list is already sorted
    //Post-condition:
    //Flight is inserted into place so that the list stays sorted
    void AddFlight(value_type& flight);

    int Size();
    LandingList& operator+= (const LandingList& rhs);

  private:
    LinkedList * flight_list;
    void LoadFromFile(string file_name);

    friend ostream& operator<< (ostream& os, const LandingList& list);
  };
}

#endif