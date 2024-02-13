#include "vec3.h"

Vec3::Vec3() {
  this->x = 0;
  this->y = 0;
  this->z = 0;
}


Vec3::Vec3(double x,double y, double z){
  this->x = x;
  this->y = y;
  this->z = z;
}

Vec3::Vec3(const Vec3& v){
  this->x = v.x;
  this->y = v.y;
  this->z = v.z;
}


double Vec3::getX() const{
  return this->x;
}

double Vec3::getY() const{
  return this->y;
}

double Vec3::getZ() const{
  return this->z;
}

void Vec3::setX(double x){
 this->x = x;
}

void Vec3::setY(double y){
 this->y = y; 
}

void Vec3::setZ(double z){
  this->z = z;
}


std::ostream& operator<<(std::ostream& out,const Vec3& v){
 out <<'(' << v.getX() << ", " << v.getY()<< ", " << v.getZ() << ')'; 
  return out;
}

Vec3  Vec3::operator+(const Vec3& v) const {
  return Vec3(x + v.getX(),
                y + v.getY(),
                z + v.getZ());
}

Vec3 Vec3::operator-(const Vec3& v) const {
  return Vec3(x - v.getX(),
                y - v.getY(),
                z - v.getZ());
}

Vec3 Vec3::operator*(double scalar) const {
  return Vec3(x * scalar ,
          y * scalar ,
          z * scalar);
}

double Vec3::operator*(const Vec3& v) const {
  return (x * v.getX() +
          y * v.getY() +
          z * v.getZ());

}
 
Vec3 operator*(double scalar,const Vec3& v) {
  return v * scalar;
}
