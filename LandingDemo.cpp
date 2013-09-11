#include <iostream>
#include "LandingList.h"
#include <cstdlib>

using namespace assign1;
using namespace std;

int main() {
  LandingList *landingList1, *landingList2;
  landingList1 = new LandingList("List10Aug2013FromBrisbane.txt");
  landingList2 = new LandingList("List10Aug2013FromMelbourne.txt");

  cout << "Landing List 1 | Flights - " << landingList1->Size() << endl << *landingList1 << endl;
  cout << "Landing List 2 | Flights - " << landingList2->Size() << endl << *landingList2 << endl;

  (*landingList1) += *landingList2;
  cout << "New Landing List 1 | Flights - " << landingList1->Size() << endl << *landingList1 << endl;

  delete landingList2;
  cout << "Landing List 1 After Landing List 2 Deletion | Flights - " << landingList1->Size() << endl << *landingList1 << endl;

  delete landingList1;

  return EXIT_SUCCESS;
}
