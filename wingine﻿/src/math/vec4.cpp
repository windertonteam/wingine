#include "vec4.h"

namespace core {
namespace math {

	vec4::vec4(const float& x, const float& y, const float& z, const float& w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	vec4::~vec4()
	{

	}
	//Foo(1,1)
	//Bar(2,2)
	
	vec4& vec4::add(const vec4& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;

		return *this;
	}

	vec4& vec4::sub(const vec4& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;

		return *this;
	}

	vec4& vec4::mult(const vec4& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		w *= other.w;

		return *this;
	}

	vec4& vec4::div(const vec4& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		w /= other.w;

		return *this;
	}

	vec4 operator+(vec4 left, const vec4& right)
	{
		return left.add(right);
	}

	vec4 operator-(vec4 left, const vec4& right)
	{
		return left.sub(right);
	}

	vec4 operator*(vec4 left, const vec4& right)
	{
		return left.mult(right);
	}

	vec4 operator/(vec4 left, const vec4& right)
	{
		return left.div(right);
	}

	//Foo(1,1)
	//Bar(2,2)

	vec4& vec4::operator+=(const vec4& other)
	{
		return add(other);
	}
	
	vec4& vec4::operator-=(const vec4& other)
	{
		return sub(other);
	}

	vec4& vec4::operator*=(const vec4& other)
	{
		return mult(other);
	}

	vec4& vec4::operator/=(const vec4& other)
	{
		return div(other);
	}

	std::ostream& operator<<(std::ostream& stream, const vec4& vec4tor)
	{
		stream << "vec4tor: (" << vec4tor.x << ", " << vec4tor.y << ", " << vec4tor.z << ", " << vec4tor.w <<  ")";
		return stream;
	}


}}

