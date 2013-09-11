/**************************/
/* Simon Hartcher         */
/* C3185790               */
/* Software Engineering 2 */
/**************************/

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
    //Pre-condition: None
    //Post-condition: Returns empty LandingList

    LandingList(const string file_name);
    //Pre-condition: None
    //Post-condition: Returns new LandingList with any flights it was able to
    //load from the given file. If the file fails to load, an error message will
    //be displayed

    ~LandingList();
    //Pre-condition: None
    //Post-condition: The LandingList and its associated data will be freed.
    
    void AddFlight(const value_type& flight);
    //Pre-condition: Given flight is not already in the list
    //The list is already sorted
    //Post-condition: Flight is inserted into place so that the list stays 
    //sorted

    size_t Size() const;
    //Pre-condition: None
    //Post-condition: Returns the number of flights

    LandingList& operator+= (const LandingList& rhs);
    //Pre-condition: lhs, rhs are not null.
    //Post-condition: The contents of rhs are deep copied into lhs. It is also 
    //ensured that the list of flights are sorted by arrival time.

  private:
    LinkedList* flight_list;
    void LoadFromFile(const string file_name);

    friend ostream& operator<< (ostream& os, const LandingList& list);
  };
}

#endif