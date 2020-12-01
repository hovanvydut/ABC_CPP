#include "SectionClass.h"
#include "../Student/Student.h"

SectionClass::SectionClass()
{
  this->listStudents = nullptr;
}

SectionClass::SectionClass(const string& name, const Lecturer& lecturer)
{
  this->setName(name);
  this->setLecturer(lecturer);
  this->setNumberOfStudents(0);
  this->listStudents = nullptr;
}

SectionClass::SectionClass(SectionClass& anotherSectionClass)
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
void SectionClass::setName(const string& name)
{
  if (name.length() <= 0)
  {
    throw "Error: name must be longer than 0";
  }

  this->name = name;
}

Lecturer SectionClass::getLecturer()
{
  return this->lecturer;
}

void SectionClass::setLecturer(const Lecturer& lecturer)
{
  this->lecturer = lecturer;
}

int SectionClass::getNumberOfStudents()
{
  return this->numberOfStudents;
}

void SectionClass::setNumberOfStudents(const int& size)
{
  if (size < 0)
  {
    throw "Error: numberOfStudents must be larger or equal 0";
  }

  this->numberOfStudents = size;
}

void SectionClass::addStudent(Student* student)
{
  // backup old data
  int size = this->numberOfStudents;
  Student** temp = new Student*[size];
  for (int i = 0; i < size; i++) {
    *(temp + i) = *(this->listStudents + i);
  }

  // allocate new pointer
  size = ++this->numberOfStudents;
  this->listStudents = new Student*[size];
  for (int i = 0; i < size - 1; i++)
  {
    *(this->listStudents + i) = *(temp + i);
  }
  *(this->listStudents + size - 1) = student; 
}

void SectionClass::show()
{
  for (int i = 0; i < this->numberOfStudents; i++) 
  { 
    (*(this->listStudents + i))->show();
  }
}