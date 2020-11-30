#include "Student.h"

Student::Student()
{
}

Student::Student(string name, int age, string address, bool gender, string studentId, double GPA) : Person(name, age, address, gender)
{
  this->setStudentId(studentId);
  this->setGPA(GPA);
}

Student::~Student()
{
}

string Student::getStudentId()
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

double Student::getGPA()
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

void Student::show()
{
  Person::show();
  std::cout << "	studentId: " << this->getStudentId() << "\n";
  std::cout << "	GPA: " << this->getGPA() << "\n";
}