#include "NormalStudent.h"

NormalStudent::NormalStudent()
{

}

NormalStudent::NormalStudent(string name, int age, string address, bool gender, string studentId, double GPA, string parkingCode)
  : Student(name, age, address, gender, studentId, GPA)
{
  this->setParkingCode(parkingCode);
}

NormalStudent::NormalStudent(string name, int age, string address, bool gender, string studentId, double GPA, SectionClass* sectionClass, string roomCode)
  : Student(name, age, address, gender, studentId, GPA, sectionClass)
{
  this->setParkingCode(parkingCode);
}

NormalStudent::~NormalStudent()
{

}

// getter, setter
string NormalStudent::getParkingCode() const
{
  return this->parkingCode;
}

void NormalStudent::setParkingCode(string& parkingCode)
{ 
  this->parkingCode = parkingCode;
}

ostream& operator << (ostream& o, const NormalStudent& student)
{
  o << student.getClassName() << "\n";
  student.show();
  return o;
}

ostream& operator << (ostream& o, const NormalStudent* student)
{
  o << student->getClassName() << "\n";
  student->show();
  return o;
}

void NormalStudent::show() const
{
  Student::show();
  std::cout << "	parkingCode: " << this->getParkingCode() << "\n";
}

string NormalStudent::getClassName() const
{
  return "NormalStudent";
}