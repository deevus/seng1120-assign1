/**************************/
/* Simon Hartcher         */
/* C3185790               */
/* Software Engineering 2 */
/**************************/

#include "LandingList.h"
#include <iostream>
#include <fstream>
#include "Flight.h"
#include <cassert>

namespace assign1 {
  LandingList::LandingList() {
    flight_list = new LinkedList();
  }

  LandingList::LandingList(const string file_name) {
    this->flight_list = new LinkedList();
    this->LoadFromFile(file_name);
  }

  LandingList::~LandingList() {
    delete flight_list;
  }

  void LandingList::LoadFromFile(const string file_name) {
    ifstream file;
    string line;
    unsigned int pos;

    file.open(file_name.c_str());
    if (!file.good()) {
      cout << "Invalid file. No flights loaded." << endl;
      return;
    }

    while (file.good()) {
      getline(file, line);
      if (line.length() == 0) continue;

      pos = line.find(' ');
      string flight_number = line.substr(0, pos);

      line = line.substr(pos);
      pos = line.find(':');
      unsigned int hours = atoi(line.substr(0, pos).c_str());
      unsigned int minutes = atoi(line.substr(pos + 1).c_str());

      value_type flight = value_type(flight_number, hours, minutes);
      AddFlight(flight);
    }

    if (Size() == 0) {
      cout << "Given file was empty, or no valid flights found." << endl;
    }
  }

  size_t LandingList::Size() const {
    return flight_list->Size();
  }

  ostream& operator<< (ostream& os, const LandingList& list) {
    os << *list.flight_list;
    return os;
  }

  LandingList& LandingList::operator+= (const LandingList& rhs) {
    Node* r_head = rhs.flight_list->get_head();
    Node* current = r_head;
    if (current != NULL) do {
      value_type flight = current->Data();
      this->AddFlight(flight);

      current = current->Next();
    } while (current != NULL);

    return *this;
  }
}

void LandingList::AddFlight(const value_type& flight) {
  int size = flight_list->Size();
  if (size == 0) {
    //empty list - add as head
    flight_list->InsertAfterTail(new Node(flight));
  } 
  else if (size == 1) {
    //1 item.. work out which one should be head
    Node* head = flight_list->get_head();
    value_type data = head->Data();
    if (flight.CompareTo(data) >= 0) {
      flight_list->InsertAfterTail(new Node(flight));
    } 
    else {
      flight_list->InsertBeforeHead(new Node(flight));
    }
  } 
  else {
    //work out the rest
    Node* current = flight_list->get_tail();
    for (size_t i = 0; i < flight_list->Size(); ++i) {
      value_type data = current->Data();
      if (data.CompareTo(flight) <= 0) {
        break;
      } else {
        current = current->Prev();
      }
    }

    if (current == NULL) {
      flight_list->InsertBeforeHead(new Node(flight));
    }
    else {
      flight_list->InsertAfterNode(new Node(flight), current);
    }

    #if DEBUG
    //make sure same number of elements both ways
    int next_count, prev_count;
    next_count = prev_count = 0;
    Node* _next = flight_list->get_head();
    Node* _prev = flight_list->get_tail();
    do {
      if (_next != NULL) {
        next_count++;
        _next = _next->Next();
      }

      if (_prev != NULL) {
        prev_count++;
        _prev = _prev->Prev();
      }
    } while (_next != NULL || _prev != NULL);
    assert(next_count == prev_count);

    //ensure that list is sorted
    try {
      cout << "Starting sort test" << endl;
      current = flight_list->get_head();
      for (size_t i = 0; i < flight_list->Size() - 1; ++i) {
        value_type current_data = current->Data();
        value_type next_data = current->Next()->Data();
        cout << "Flight: " << current_data << endl;
        if (current_data.CompareTo(next_data) == 1) throw next_data.ArrivalTimeInMinutes();

        current = current->Next();
      }
    }
    catch (int e) {
      int hours = e / 60;
      int minutes = e % 60;
      cout << "Invalid time: " << hours << ":" << minutes << endl;
      throw;
    }
    #endif
  }
}
