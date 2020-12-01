#include <iostream>
#include "Person/Person.h"
#include "Lecturer/Lecturer.h"
#include "SectionClass/SectionClass.h"
#include "Student/Student.h"
#include "Lecturer/Lecturer.h"
#include "BoardingStudent/BoardingStudent.h"
#include "ListtPackage/ArrayListt/ArrayListt.h"
using namespace std;

int main()
{
  Student *student1 = new Student("Ho Van      Vy", 19, "TT.Hue", true, "1234567890", 2.3);
  Student *student2 = new Student(" Nguyen Huy   Tuong", 30, "Quang Nom", true, "5432167890", 4.0);
  Student *student3 = new Student("Nguyen  Duy Thinh", 22, "TT.Hue", false,"7654321890", 3.0);

  BoardingStudent *bstudent1 = new BoardingStudent("Tran Viet Truong", 33, "Da Neng", false, "8765432190", 3.9, "B304");

  Lecturer lecturerOOP("Dang Hoai Phuong", 40, "Unknown", false, "Expert");

  SectionClass toangCLC("19TCLC_DT4", &lecturerOOP);
  
  toangCLC.getLecturer() -> show();
  cout << "List of students 19TCLC_DT4" << endl;
  toangCLC.addStudent(student1);
  toangCLC.addStudent(student2);
  toangCLC.addStudent(student3);
  toangCLC.addStudent(bstudent1);

  toangCLC.show();

  cout << "----------" << endl;
  toangCLC.removeStudent("5432167890");

  toangCLC.show();

  Listt<Student*> *arrayList = new ArrayListt<Student*>();
  arrayList->add(student1);
  arrayList->add(student2);
  arrayList->add(student3);
  arrayList->add(bstudent1);

  cout << "-----------daf----------" << endl;
  for (int i = 0; i < arrayList->getSize(); i++)
  {
    (arrayList->get(i))->show();
  }
  return 0;
}