#ifndef MY_VEC_H
#define MY_VEC_H

#include <iostream>

class Vec3 {
  public:
  Vec3();
  Vec3(double x,double y, double z);
  Vec3(const Vec3& v);
    /* GETTERS */
  double getX() const;
  double getY() const;
  double getZ() const;

  /* SETTERS */
  void setX(double x);
  void setY(double y);
  void setZ(double z);
 
  // Operators overloading
  friend std::ostream& operator<<(std::ostream& out,const Vec3& v);
  friend Vec3 operator*(double scalar, const Vec3& v); 

  Vec3 operator+(const Vec3& v) const;
  Vec3 operator-(const Vec3& v) const;
  Vec3 operator*(double scalar) const;
  double operator*(const Vec3& v) const;
  private:
  double x,y,z;  
};


#endif
