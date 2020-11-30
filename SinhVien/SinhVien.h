#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <iostream>
#include "../Person/Person.h"

class SinhVien : public Person
{

private:
  string msv;
  double diemTB;

public:
  SinhVien();
  SinhVien(string, int, string, bool, string, double);
  ~SinhVien();

  string getMSV();
  void setMSV(const string &);
  double getDiemTB();
  void setDiemTB(const double &);

  void show();
};

#endif