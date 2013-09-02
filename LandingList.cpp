#include "LandingList.h"
#include <iostream>
#include <fstream>
#include "Flight.h"

namespace assign1 {
  LandingList::LandingList() {
    flight_list = new LinkedList();
  }

  LandingList::LandingList(string file_name) {
    this->flight_list = new LinkedList();
    this->LoadFromFile(file_name);
  }

  LandingList::~LandingList() {
    delete flight_list;
  }

  void LandingList::LoadFromFile(string file_name) {
    ifstream file;
    string line;
    unsigned int pos;

    file.open(file_name.c_str());
    while (file.good()) {
      getline(file, line);

      pos = line.find(' ');
      string flight_number = line.substr(0, pos);

      line = line.substr(pos);
      pos = line.find(':');
      unsigned int hours = atoi(line.substr(0, pos).c_str());
      unsigned int minutes = atoi(line.substr(pos + 1).c_str());

      value_type flight = value_type(flight_number, hours, minutes);

      Node * node = new Node(flight, NULL);
      flight_list->AddAfterTail(node);
    }

  }

  int LandingList::Size() {
    return flight_list->Size();
  }

  ostream& operator<< (ostream& os, const LandingList& list) {
    os << *list.flight_list;
    return os;
  }

  LandingList& LandingList::operator+= (const LandingList& rhs) {
    Node * right = rhs.flight_list->get_head();
    Node * left = flight_list->get_head();
    LinkedList * new_list = new LinkedList();

    while (left != NULL || right != NULL) {
      bool moveLeft, moveRight;
      moveLeft = moveRight = false;
      Node * item = NULL;

      if (left == NULL) moveRight = true; 
      else if (right == NULL) moveLeft = true;
      else if (right->Data().ArrivalTimeInMinutes() < left->Data().ArrivalTimeInMinutes())
        moveRight = true;
      else moveLeft = true;

      if (moveLeft) {
        item = new Node(left);
        left = left->Link();
      }
      if (moveRight) {
        item = new Node(right);
        right = right->Link();
      }
      //remove the old link
      item->set_link(NULL);
      new_list->AddAfterTail(item);
    }

    this->flight_list = new_list;
    return *this;
  }
}

