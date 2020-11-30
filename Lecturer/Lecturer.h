#ifndef LECTURER_H
#define LECTURER_H

#include "../Person/Person.h"

class Lecturer : public Person
{

private:
  string ma_lecture;
  string cap_bac;

public:
  Lecturer();
  Lecturer(string, int, string, bool, string);
  Lecturer(const Lecturer &);
  ~Lecturer();

  // setter, getter
  // override setTen()
  void setTen(const string &);

  string getMaLecture() const;

  string getCapBac() const;
  void setCapBac(const string &);

  void show();

private:
  void setMaLecture();
  string createIdLecturerFromName(string str);
};

#endif