#include "vec2.h"

namespace core {
namespace math {

	vec2::vec2(const float& x, const float& y)
	{
		this->x = x;
		this->y = y;
	}

	vec2::~vec2()
	{

	}
	//Foo(1,1)
	//Bar(2,2)
	
	vec2& vec2::add(const vec2& other)
	{
		x += other.x;
		y += other.y;

		return *this;
	}

	vec2& vec2::sub(const vec2& other)
	{
		x -= other.x;
		y -= other.y;

		return *this;
	}

	vec2& vec2::mult(const vec2& other)
	{
		x *= other.x;
		y *= other.y;

		return *this;
	}

	vec2& vec2::div(const vec2& other)
	{
		x /= other.x;
		y /= other.y;

		return *this;
	}

	vec2 operator+(vec2 left, const vec2& right)
	{
		return left.add(right);
	}

	vec2 operator-(vec2 left, const vec2& right)
	{
		return left.sub(right);
	}

	vec2 operator*(vec2 left, const vec2& right)
	{
		return left.mult(right);
	}

	vec2 operator/(vec2 left, const vec2& right)
	{
		return left.div(right);
	}

	//Foo(1,1)
	//Bar(2,2)

	vec2& vec2::operator+=(const vec2& other)
	{
		return add(other);
	}
	
	vec2& vec2::operator-=(const vec2& other)
	{
		return sub(other);
	}

	vec2& vec2::operator*=(const vec2& other)
	{
		return mult(other);
	}

	vec2& vec2::operator/=(const vec2& other)
	{
		return div(other);
	}

	std::ostream& operator<<(std::ostream& stream, const vec2& vector)
	{
		stream << "Vector: (" << vector.x << ", " << vector.y << ")";
		return stream;
	}


}}

