#include <string>
#include "datastructures/LinkedList.h"

using namespace std;

namespace assign1 {
  class LandingList {

  public:
    LandingList();
    LandingList(string file_name);

    ~LandingList();

    int Size();
    LandingList& operator+= (const LandingList& rhs);

  private:
    LinkedList * flight_list;
    void LoadFromFile(string file_name);

    friend ostream& operator<< (ostream& os, const LandingList& list);
  };
}
