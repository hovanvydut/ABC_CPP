#include "SectionClass.h"
#include "../Student/Student.h"

SectionClass* SectionClass::_instance = nullptr;

SectionClass::SectionClass()
{
  this->listStudents = new ArrayListt<Student*>();
}

SectionClass::SectionClass(const string &name, Lecturer *lecturer)
{
  this->setName(name);
  this->setLecturer(lecturer);
  // this->setNumberOfStudents(0);
  this->listStudents = new ArrayListt<Student*>();
}

// SectionClass::SectionClass(SectionClass &anotherSectionClass)
// {
//   this->setName(anotherSectionClass.getName());
//   this->setLecturer(anotherSectionClass.getLecturer());
//   this->setNumberOfStudents(anotherSectionClass.getNumberOfStudents());
// }

SectionClass::~SectionClass()
{
}

SectionClass* SectionClass::getInstance()
{
  if (_instance == nullptr)
  {
    _instance = new SectionClass();
  }

  return _instance;
}

string SectionClass::getName() const
{
  return this->name;
}

// NOTE: validate, remove space name
void SectionClass::setName(const string &name)
{
  if (name.length() <= 0)
  {
    throw "Error: name must be longer than 0";
  }

  this->name = name;
}

Lecturer *SectionClass::getLecturer() const
{
  return this->lecturer;
}

void SectionClass::setLecturer(Lecturer *lecturer)
{
  this->lecturer = lecturer;
}

int SectionClass::getNumberOfStudents() const
{
  return this->listStudents->getSize();
}

bool SectionClass::addStudent(Student *student)
{
  return this->listStudents->add(student);
}

bool SectionClass::removeStudent(const string &studentId)
{
  for (int i = 0; i < this->listStudents->getSize(); i++)
  {
    Student* student = this->listStudents->get(i);
    if (student->getStudentId() == studentId)
    {
      return this->listStudents->remove(student);
    }
  }
  return false;
}

Student* SectionClass::findStudentById(const string& studentId)
{
  for (int i = 0; i < this->listStudents->getSize(); i++)
  {
    Student* student = this->listStudents->get(i);
    if (student->getStudentId() == studentId)
    {
      return student;
    }
  }

  return nullptr;
}

void SectionClass::sortGPAStudentDESC()
{
  this->listStudents->sort(ArrayListt<Student*>::compareDESC);
}

void SectionClass::sortGPAStudentASC()
{
  this->listStudents->sort(ArrayListt<Student*>::compareASC);
}

void SectionClass::show() const
{
  for (int i = 0; i < this->listStudents->getSize(); i++)
  {
    cout << this->listStudents->get(i) << endl;
  }
}

Student* SectionClass::operator [] (int index)
{
  return this->listStudents->get(index);
}

ostream& operator << (ostream& o, const SectionClass& sectionClass)
{
  cout << "Lop: " << sectionClass.getName() << endl;
  cout << sectionClass.getLecturer() << endl;
  cout << "Bao gom " << sectionClass.getNumberOfStudents() << " hoc sinh" << endl;
  sectionClass.show();
  return o;
}

ostream& operator << (ostream& o, const SectionClass* sectionClass)
{
  cout << "Lop: " << sectionClass->getName() << endl;
  cout << sectionClass->getLecturer() << endl;
  cout << "Bao gom " << sectionClass->getNumberOfStudents() << " hoc sinh" << endl;
  sectionClass->show();
  return o;
}