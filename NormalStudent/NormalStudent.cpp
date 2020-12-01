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
string NormalStudent::getParkingCode()
{
  return this->parkingCode;
}

void NormalStudent::setParkingCode(string& parkingCode)
{ 
  this->parkingCode = parkingCode;
}

ostream& operator << (ostream& o, const NormalStudent& student)
{
  student.show();
  return o;
}

ostream& operator << (ostream& o, const NormalStudent* student)
{
  student->show();
  return o;
}