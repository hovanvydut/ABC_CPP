#include "SectionClass.h"
#include "../Student/Student.h"

SectionClass::SectionClass()
{
  this->listStudents = nullptr;
}

SectionClass::SectionClass(const string &name, Lecturer *lecturer)
{
  this->setName(name);
  this->setLecturer(lecturer);
  this->setNumberOfStudents(0);
  this->listStudents = nullptr;
}

SectionClass::SectionClass(SectionClass &anotherSectionClass)
{
  this->setName(anotherSectionClass.getName());
  this->setLecturer(anotherSectionClass.getLecturer());
  this->setNumberOfStudents(anotherSectionClass.getNumberOfStudents());
}

SectionClass::~SectionClass()
{
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
  return this->numberOfStudents;
}

void SectionClass::setNumberOfStudents(const int &size)
{
  if (size < 0)
  {
    throw "Error: numberOfStudents must be larger or equal 0";
  }

  this->numberOfStudents = size;
}

bool SectionClass::addStudent(Student *student)
{
  // backup old data
  int size = this->numberOfStudents;
  Student **temp = new Student *[size];
  for (int i = 0; i < size; i++)
  {
    *(temp + i) = *(this->listStudents + i);
  }

  // allocate new pointer
  size = ++this->numberOfStudents;
  this->listStudents = new Student *[size];
  for (int i = 0; i < size - 1; i++)
  {
    *(this->listStudents + i) = *(temp + i);
  }
  *(this->listStudents + size - 1) = student;

  // add SectionClass into Student
  student->setSectionClass(this);

  return true;
}

bool SectionClass::removeStudent(const string &studentId)
{
  int i = 0;
  int size = this->numberOfStudents;

  // list of students is empty
  if (size <= 0)
  {
    return true;
  }

  Student **list = this->listStudents;

  for (; i < size; i++)
  {
    if (list[i]->getStudentId() == studentId)
      break;
  }

  // not found studentId
  if (i == size)
  {
    return false;
  }

  for (int j = i + 1; j < size; j++)
  {
    *(list + j - 1) = *(list + j);
  }

  // NOTE: 
  // delete list[size-1];
  this->setNumberOfStudents(--size);
  return true;
}

void SectionClass::show()
{
  for (int i = 0; i < this->numberOfStudents; i++)
  {
    (*(this->listStudents + i))->show();
  }
}