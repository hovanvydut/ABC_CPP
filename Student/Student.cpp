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

string Student::getClassName() const
{
  return "Student";
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
  o << student.getClassName() << "\n";
  student.show();
  return o;
}

ostream& operator << (ostream& o, const Student* student)
{
  o << student->getClassName() << "\n";
  student->show();
  return o;
}

bool Student::operator == (const Student& student) const
{
  if (this->getStudentId() == student.getStudentId())
    return true;
  return false;
}

bool Student::operator > (const Student& anotherStudent) const
{
  return this->getGPA() > anotherStudent.getGPA();
}

bool Student::operator >= (const Student& anotherStudent) const
{
  return this->getGPA() >= anotherStudent.getGPA();
}

bool Student::operator < (const Student& anotherStudent) const
{
  return this->getGPA() < anotherStudent.getGPA();
}

bool Student::operator <= (const Student& anotherStudent) const
{
  return this->getGPA() <= anotherStudent.getGPA();
}

// string name, int age, string address, bool gender, string studentId, double GPA

istream& operator >> (istream& in, Student& student)
{
string name, address, studentId;
  int age, gender;
  double GPA;

  cout << "*** Vui long nhap: \n";

  in.ignore();
  cout << "* Ten: "; getline(in, name);
  student.setName(name);

  INPUT_AGE:
  cout << "* Tuoi: "; in >> age;
  try {
    student.setAge(age);
  } catch (const char* msg)
  {
    cout << msg << endl;
    goto INPUT_AGE;
  }

  in.ignore();
  cout << "* Dia chi: "; getline(in, address);
  student.setAddress(address);

  INPUT_GENDER:
  cout << "* Gioi tinh(0: nu, 1: nam): "; in >> gender;
  if (gender == 1)
    student.setGender(true);
  else if (gender == 0)
    student.setGender(false);
  else
  {
    cout << "Error: Nhap 0 hoac 1 \n";
    goto INPUT_GENDER;
  }

  INPUT_STUDENT_CODE:
  cout << "* Ma sinh vien (gom 10 ki tu, khong duoc bat dau bang ki tu 0): " << endl;
  try
  {
    in.ignore();
    getline(in, studentId);
    student.setStudentId(studentId);
  } catch (const char* msg)
  {
    cout << msg << endl;
    goto INPUT_STUDENT_CODE;
  }
  
  INPUT_GPA:
  try {
    in >> GPA;
    student.setGPA(GPA);
  } catch (const char* msg)
  {
    cout << msg << endl;
    goto INPUT_GPA;
  }

  return in;
}

istream& operator >> (istream& in, Student* student)
{
  string name, address, studentId;
  int age, gender;
  double GPA;

  cout << "*** Vui long nhap: \n";

  in.ignore();
  cout << "* Ten: "; getline(in, name);
  student->setName(name);

  INPUT_AGE:
  cout << "* Tuoi: "; in >> age;
  try {
    student->setAge(age);
  } catch (const char* msg)
  {
    cout << msg << endl;
    goto INPUT_AGE;
  }

  in.ignore();
  cout << "* Dia chi: "; getline(in, address);
  student->setAddress(address);

  INPUT_GENDER:
  cout << "* Gioi tinh(0: nu, 1: nam): "; in >> gender;
  if (gender == 1)
    student->setGender(true);
  else if (gender == 0)
    student->setGender(false);
  else
  {
    cout << "Error: Nhap 0 hoac 1 \n";
    goto INPUT_GENDER;
  }

  INPUT_STUDENT_CODE:
  cout << "* Ma sinh vien (gom 10 ki tu, khong duoc bat dau bang ki tu 0): ";
  try
  {
    in.ignore();
    getline(in, studentId);
    student->setStudentId(studentId);
  } catch (const char* msg)
  {
    cout << msg << endl;
    goto INPUT_STUDENT_CODE;
  }
  
  INPUT_GPA:
  try {
    cout << "* GPA: ";
    in >> GPA;
    student->setGPA(GPA);
  } catch (const char* msg)
  {
    cout << msg << endl;
    goto INPUT_GPA;
  }

  return in;
}