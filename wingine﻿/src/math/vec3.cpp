#include "vec3.h"

namespace core {
namespace math {

	vec3::vec3(const float& x, const float& y, const float& z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	vec3::~vec3()
	{

	}
	//Foo(1,1)
	//Bar(2,2)
	
	vec3& vec3::add(const vec3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;

		return *this;
	}

	vec3& vec3::sub(const vec3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;

		return *this;
	}

	vec3& vec3::mult(const vec3& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;

		return *this;
	}

	vec3& vec3::div(const vec3& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;

		return *this;
	}

	vec3 operator+(vec3 left, const vec3& right)
	{
		return left.add(right);
	}

	vec3 operator-(vec3 left, const vec3& right)
	{
		return left.sub(right);
	}

	vec3 operator*(vec3 left, const vec3& right)
	{
		return left.mult(right);
	}

	vec3 operator/(vec3 left, const vec3& right)
	{
		return left.div(right);
	}

	//Foo(1,1)
	//Bar(2,2)

	vec3& vec3::operator+=(const vec3& other)
	{
		return add(other);
	}
	
	vec3& vec3::operator-=(const vec3& other)
	{
		return sub(other);
	}

	vec3& vec3::operator*=(const vec3& other)
	{
		return mult(other);
	}

	vec3& vec3::operator/=(const vec3& other)
	{
		return div(other);
	}

	std::ostream& operator<<(std::ostream& stream, const vec3& vector)
	{
		stream << "Vector: (" << vector.x << ", " << vector.y << ", " << vector.z << ")";
		return stream;
	}


}}

