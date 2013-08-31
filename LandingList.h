#include <string>
#include "datastructures/LinkedList.h"

namespace assign1 {
  class LandingList {

  public:
    LandingList();
    LandingList(string file_name[]);
    int get_size();

  private:
    LinkedList* linked_list;
  };
}
