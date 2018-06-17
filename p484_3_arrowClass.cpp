//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 13 Exercise 3

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>
using namespace Graph_lib;

double pointVecMag(Point vec) {
	return sqrt(pow(vec.x, 2) + pow(vec.y, 2));;
}

struct MyArrow : public Shape
{
	MyArrow(Point start, Point end, bool s, bool e, int size)
		:start(start), end(end), s(s), e(e), size(size)
	{
		if (s) {
			//end-start vector: c
			c = Point(end.x - start.x, end.y - start.y);
			cMag = pointVecMag(c);
			cUnit = Point(c.x / cMag * size, c.y / cMag * size);
			cTrans = Point(cUnit.x, cUnit.y);

			//Arrow Head Start
			cPerp = Point(-cTrans.y, cTrans.x);
			arrowhead01 = Point(start.x + cPerp.x + cTrans.x, start.y + cPerp.y + cTrans.y);
			arrowhead02 = Point(start.x - cPerp.x + cTrans.x, start.y - cPerp.y + cTrans.y);
		}
		if (e) {
			//start-end vector: d
			d = Point(start.x - end.x, start.y - end.y);
			dMag = pointVecMag(d);
			dUnit = Point(d.x / dMag * size, d.y / dMag * size);
			dTrans = Point(dUnit.x, dUnit.y);

			//Arrow Head End
			dPerp = Point(-dTrans.y, dTrans.x);
			arrowhead03 = Point(end.x + dPerp.x + dTrans.x, end.y + dPerp.y + dTrans.y);
			arrowhead04 = Point(end.x - dPerp.x + dTrans.x, end.y - dPerp.y + dTrans.y);
		}
	};

	void draw_lines() const;

private:
	//Line
	Point start;
	Point end;

	//Arrowhead at start
	Point c;
	Point cUnit;
	Point cTrans;
	Point cPerp;
	double cMag;

	Point arrowhead01;
	Point arrowhead02;

	//Arrowhead at end
	Point d;
	Point dUnit;
	Point dTrans;
	Point dPerp;
	double dMag;
	
	Point arrowhead03;
	Point arrowhead04;
		
	bool s;
	bool e;
	int size;
};

void MyArrow::draw_lines() const{

	if (color().visibility()) {
		//Line
		fl_line(start.x,start.y, end.x, end.y);
		//Arrowhead at start
		if (s) {
			fl_line(start.x, start.y, arrowhead01.x, arrowhead01.y);
			fl_line(start.x, start.y, arrowhead02.x, arrowhead02.y);
		}
		//Arrowhead at end
		if (e) {
			fl_line(end.x, end.y, arrowhead03.x, arrowhead03.y);
			fl_line(end.x, end.y, arrowhead04.x, arrowhead04.y);
		}
	}
}

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 600, 400, "Simple Window");
	
	MyArrow ma(Point(100, 150), Point(200, 250), true, true, 10);
	ma.set_color(Color::red);

	win.attach(ma);
	win.wait_for_button();
}
catch (exception& e) {
	cout << e.what() << endl;
	return 1;
}
catch (...) {
	cout << "Exiting" << endl;
	return 2;
}