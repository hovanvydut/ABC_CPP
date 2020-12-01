#include <iostream>
#include "Person/Person.h"
#include "Lecturer/Lecturer.h"
using namespace std;

int main()
{

  Person person("Ho Van      Vy", 19, "TT.Hue", true);
  person.show();

  Lecturer lecturer("Culi Vy", 19, "Qzuang Nom", true, "cleaner");
  lecturer.show();

  // try {
  //   Student sinhvien("Em la SV", 20, "Quang Ngai", false, "0987654321", 1.8);
  //   sinhvien.show();
  // } catch (const char* msg) {
  //   cout << msg << endl;
  // }

  return 0;
}