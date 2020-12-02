#include "Student.h"
#include "../SectionClass/SectionClass.h"

Student::Student() : Person()
{

}

Student::Student(string studentId, double GPA, SectionClass* sectionClass)
{
  this->setGPA(GPA);
  this->setSectionClass(sectionClass);
  this->setStudentId(studentId);
}

Student::Student(string name, int age, string address, bool gender, string studentId, double GPA) : Person(name, age, address, gender)
{
  this->setStudentId(studentId);
  this->setGPA(GPA);
  this->setSectionClass(sectionClass);
}

Student::Student(string name, int age, string address, bool gender, string studentId, double GPA, SectionClass* sectionClass) : Person(name, age, address, gender)
{
  this->setStudentId(studentId);
  this->setGPA(GPA);
  this->setSectionClass(sectionClass);
}

Student::~Student()
{
}

string Student::getStudentId() const
{
  return this->studentId;
}

void Student::setStudentId(const string &studentId)
{
  // gom 10 ki tu [0...9], ky tu dau tien khong duoc bat dau bang ky tu 0
  if (studentId.length() != 10)
  {
    throw "Error: studentId must be 10 characters";
  }
  
  if (studentId[0] == '0')
  {
    throw "Error: first character of studentId must not be '0'";
  }

  for (int i = 0; i < 10; i++) {
    if (studentId[i] < '0' && studentId[i] > '9')
    {
      throw "Error: characters of studentId must be [0-9]";
    }
  }
  this->studentId = studentId;
}

double Student::getGPA() const
{
  return this->GPA;
}

void Student::setGPA(const double &GPA)
{
  // kiem tra diem TB
  if (GPA < 0 || GPA > 4)
  {
    throw "Over rangge [0, 4]";
  }
  this->GPA = GPA;
}

void Student::show() const
{
  Person::show();
  std::cout << "	studentId: " << this->getStudentId() << "\n";
  std::cout << "	GPA: " << this->getGPA() << "\n";
}

SectionClass Student::getSectionClass() const
{
  return *(this->sectionClass);
}

void Student::setSectionClass(SectionClass* sectionClass)
{
  this->sectionClass = sectionClass;
}

ostream& operator << (ostream& o, const Student& student)
{
  student.show();
  return o;
}

ostream& operator << (ostream& o, const Student* student)
{
  student->show();
  return o;
}

bool Student::operator == (const Student& student) const
{
  if (this->getStudentId() == student.getStudentId())
    return true;
  return false;
}
