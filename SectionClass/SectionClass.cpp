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

string SectionClass::getName()
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

Lecturer *SectionClass::getLecturer()
{
  return this->lecturer;
}

void SectionClass::setLecturer(Lecturer *lecturer)
{
  this->lecturer = lecturer;
}

int SectionClass::getNumberOfStudents()
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

void SectionClass::show()
{
  for (int i = 0; i < this->listStudents->getSize(); i++)
  {
    cout << this->listStudents->get(i) << endl;
  }
}