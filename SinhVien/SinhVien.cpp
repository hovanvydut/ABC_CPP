#include "SinhVien.h"

SinhVien::SinhVien()
{
}

SinhVien::SinhVien(string ten, int tuoi, string dia_chi, bool gioi_tinh, string msv, double diemTB) : Person(ten, tuoi, dia_chi, gioi_tinh)
{
  this->setMSV(msv);
  this->setDiemTB(diemTB);
}

SinhVien::~SinhVien()
{
}

string SinhVien::getMSV()
{
  return this->msv;
}

void SinhVien::setMSV(const string &msv)
{
  // gom 10 ki tu [0...9], ky tu dau tien khong duoc bat dau bang ky tu 0
  this->msv = msv;
}

double SinhVien::getDiemTB()
{
  return this->diemTB;
}

void SinhVien::setDiemTB(const double &diemTB)
{
  // kiem tra diem TB
  if (diemTB < 0 || diemTB > 4)
  {
    throw "Over rangge [0, 4]";
  }
  this->diemTB = diemTB;
}

void SinhVien::show()
{
  Person::show();
  std::cout << "	msv: " << this->getMSV() << "\n";
  std::cout << "	DTB: " << this->getDiemTB() << "\n";
}