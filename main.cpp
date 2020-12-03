#include <iostream>
#include "Person/Person.h"
#include "Lecturer/Lecturer.h"
#include "SectionClass/SectionClass.h"
#include "Student/Student.h"
#include "Lecturer/Lecturer.h"
#include "BoardingStudent/BoardingStudent.h"
#include "NormalStudent/NormalStudent.h"
using namespace std;

int main()
{
  Student *fakeStudent = new Student("afasfds", 123, "Tdafd", true, "1234567890", 3.0);
  Student *student1 = new Student("Ho Van      Vy", 19, "TT.Hue", true, "1234567890", 2.3);
  Student *student2 = new Student(" Nguyen Huy   Tuong", 30, "Quang Nom", true, "5432167890", 4.0);
  Student *student3 = new Student("Nguyen  Duy Thinh", 22, "TT.Hue", false,"7654321890", 3.0);
  BoardingStudent *bstudent1 = new BoardingStudent("Tran Viet Truong", 33, "Da Neng", false, "8765432190", 3.9, "B304");
  NormalStudent *nstudent1 = new NormalStudent("Nguyen Van Thanh", 22, "Quang Nom", false,"7654321890", 3.0, "P12121212");
  Lecturer lecturerOOP("Dang Hoai Phuong", 40, "Unknown", false, "Expert");

  SectionClass *toangCLC = SectionClass::getInstance();
  toangCLC->setLecturer(&lecturerOOP);
  toangCLC->setName("19TCLC_DT4");

  toangCLC->getLecturer() -> show();
  cout << "List students of " + toangCLC->getName() << endl;
  toangCLC->addStudent(student1);
  toangCLC->addStudent(student2);
  toangCLC->addStudent(student3);
  toangCLC->addStudent(bstudent1);
  toangCLC->addStudent(nstudent1);
  toangCLC->show();

  cout << "----------" << endl;
  
  if (toangCLC->removeStudent("5432167890"))
  {
    cout << "Removed" << endl;
  }
  toangCLC->sortGPAStudentDESC();
  cout << toangCLC << endl;

  cout << "------------------\n";
  cout << (*toangCLC)[0] << endl;

  cout << "------------------\n";
  cout << (toangCLC->findStudentById("8765432190")) << endl;

  return 0;
}