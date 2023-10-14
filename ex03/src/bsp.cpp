#include "Point.hpp"

// REF: https://huse360.home.blog/2019/12/14/como-saber-si-un-punto-esta-dentro-de-un-triangulo/ 

static std::pair<Fixed, Fixed>	getW(Point const a, Point const d, Point const e, Point const p);

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Point const	d(b - a);
	Point const	e(c - a);

	std::pair<Fixed, Fixed> w = getW(a, d, e, point);
	if ( (w.first > Fixed()) && (w.second > Fixed()) && ((w.first + w.second) < Fixed(1.0f)) )
		return true;
	else
		return false;
}

static std::pair<Fixed, Fixed>	getW(Point const a, Point const d, Point const e, Point const p)
{
	Fixed w1;
	Fixed w2;

	std::pair<Fixed, Fixed> aV = a.getValue();
	std::pair<Fixed, Fixed> dV = d.getValue();
	std::pair<Fixed, Fixed> eV = e.getValue();
	std::pair<Fixed, Fixed> pV = p.getValue();

	w1 = (eV.first * (aV.second - pV.second) + eV.second * (pV.first - aV.first)) / (dV.first * eV.second - dV.second * eV.first);
	w2 = (pV.second - aV.second - w1 * dV.second) / eV.second;

	return std::make_pair(w1, w2);
}
