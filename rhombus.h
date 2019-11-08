#ifndef RHOMBUS_H
#define RHOMBUS_H 1
#include "point.h"


template <class T>
struct TRhombus {
	TPoint<T> a, b, c, d;
	TRhombus(std::istream&);
	double Square() const;
	TPoint<T> Center() const;
	void Print() const;
};

template <class T>
TRhombus<T>::TRhombus(std::istream& is) {
	is >> a >> b >> c >> d;
	TPoint<T> ab, bc, cd, da;
	ab.x = b.x - a.x;
	ab.y = b.y - a.y;
	bc.x = c.x - b.x;
	bc.y = c.y - b.y;
	cd.x = d.x - c.x;
	cd.y = d.y - c.y;
	da.x = a.x - d.x;
	da.y = a.y - d.y;
	assert(sqrt(ab.x * ab.x + ab.y * ab.y) ==  sqrt(bc.x * bc.x + bc.y * bc.y) && sqrt(bc.x * bc.x + bc.y * bc.y) == sqrt(cd.x * cd.x + cd.y * cd.y) && sqrt(cd.x * cd.x + cd.y * cd.y) == sqrt(da.x * da.x + da.y * da.y));

}

template <class T>
double TRhombus<T>::Square() const{
	double ans = 0.5 * sqrt(pow(a.x - c.x, 2) + pow(a.y - c.y, 2)) * sqrt(pow(b.x - d.x, 2) + pow(b.y - d.y, 2));
	return fabs(ans);
}

template <class T>
TPoint<T> TRhombus<T>::Center() const{
	TPoint<T> p;
	T x = (a.x + b.x + c.x + d.x) / 4;
	T y = (a.y + b.y + c.y + d.y) / 4;
	p.x = x;
	p.y = y;
	return p;
}

template <class T>
void TRhombus<T>::Print() const{
	std::cout << a << " " << b << " " << c << " " << d;
}

#endif