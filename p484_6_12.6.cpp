//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 13 Exercise 6

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

using namespace Graph_lib;

Point operator+(Point& a, Point& b)
{
	return Point(a.x + b.x, a.y + b.y);
}

Point operator-(Point& a, Point& b)
{
	return Point(a.x - b.x, a.y - b.y);
}

//ARROW CLASS-----------------------------------------START

double pointVecMag(Point vec) {
	return sqrt(pow(vec.x, 2) + pow(vec.y, 2));;
}

struct MyArrow : public Shape
{
	MyArrow(Point start, Point end, bool s, bool e, int size, Fl_Color arrowColor)
		:start(start), end(end), s(s), e(e), size(size), aColor(arrowColor)
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
	Fl_Color aColor;
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

void MyArrow::draw_lines() const {

	if (color().visibility()) {
		fl_color(aColor);
		//Line
		fl_line(start.x, start.y, end.x, end.y);
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

//ARROW CLASS-----------------------------------------END

//BOX ROUNDED CORNERS CLASS---------------------------START

struct boxRoundCorners : public Shape
{
	boxRoundCorners(Fl_Color boxColor, Point origin, int width, int height, int radius, Fl_Color textColor, string s)
	:
		bc(boxColor),		// box color
		o(origin),			// box origin
		w(width),			// box width
		h(height),			// box height
		r(radius),			// box corner radius
		tc(textColor),		// text color
		label(s)			// text
	{
		// defining points for box
		a1 = Point(o.x + r, o.y);
		a2 = Point(o.x, o.y + r);
		a3 = Point(o.x + r, o.y + r);
		
		b1 = Point(o.x + w - r, o.y);
		b2 = Point(o.x + w, o.y + r);
		b3 = Point(o.x + w - r, o.y + r);

		c1 = Point(o.x + w, o.y + h - r);
		c2 = Point(o.x + w - r, o.y + h);
		c3 = Point(o.x + w - r, o.y + h - r);

		d1 = Point(o.x + r, o.y + h);
		d2 = Point(o.x, o.y + h - r);
		d3 = Point(o.x + r, o.y + h - r);

		set_fill_color(Color::red);

		textPt = Point(o.x + r, o.y + h / 2 + r); // text point
		add(textPt);		// adding text point to shape
	};
		
	Point get_textPt() { return textPt; }
	Point get_north() { return Point(o.x + w / 2, o.y); }
	Point get_east() { return Point(o.x + w, o.y + h / 2); }
	Point get_south() { return Point(o.x + w / 2, o.y + h); }
	Point get_west() { return Point(o.x, o.y + h / 2); }

	int get_width() { return w; }
	int get_height() { return h; }

	void draw_lines() const {
		if (color().visibility()) {
			// DRAWING TEXT
			fl_color(tc);	// setting text color
			fl_draw(label.c_str(), point(0).x, point(0).y); // drawing text

			// DRAWING BOX
			fl_color(bc);	// setting box color

			/*
			// defining box lines
			fl_line(a1.x, a1.y, b1.x, b1.y);
			fl_line(b2.x, b2.y, c1.x, c1.y);
			fl_line(c2.x, c2.y, d1.x, d1.y);
			fl_line(d2.x, d2.y, a2.x, a2.y);
			// defining box arcs
			fl_arc(o.x, o.y, r + r, r + r, 90, 180);
			fl_arc(o.x + w - (r + r), o.y, r + r, r + r, 360, 90);
			fl_arc(o.x + w - (r + r), o.y + h - (r + r), r + r, r + r, 270, 360);
			fl_arc(o.x, o.y + h - (r + r), r + r, r + r, 180, 270);
			*/

			fl_begin_complex_polygon();
			fl_arc(o.x, o.y, r + r, r + r, 90, 180);
			fl_gap();
			fl_line(a1.x, a1.y, b1.x, b1.y);
			fl_gap();
			fl_arc(o.x + w - (r + r), o.y, r + r, r + r, 360, 90);
			fl_gap();
			fl_line(b2.x, b2.y, c1.x, c1.y);
			fl_gap();
			fl_arc(o.x + w - (r + r), o.y + h - (r + r), r + r, r + r, 270, 360);
			fl_gap();
			fl_line(c2.x, c2.y, d1.x, d1.y);
			fl_gap();
			fl_arc(o.x, o.y + h - (r + r), r + r, r + r, 180, 270);
			fl_gap();
			fl_line(d2.x, d2.y, a2.x, a2.y);
			fl_end_complex_polygon();
		}		
	}
	
private:
	// BOX
	Point o;
	Point a1, a2, b1, b2, c1, c2, d1, d2;
	Point a3, b3, c3, d3;
	Point north, east, south, west;	
	Fl_Color bc;
	int w, h, r;

	// LABEL
	Point textPt;
	string label; // label
	Fl_Color tc;	
};

//BOX ROUNDED CORNERS CLASS---------------------------END

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 600, 400, "Simple Window");

	Fl_Color boxColor = Color::black;
	Fl_Color textColor = Color::black;
	Fl_Color arrowColor = Color::black;
	
	boxRoundCorners box_Window(boxColor, Point(200, 100), 60, 20, 5, textColor, "Window");
	boxRoundCorners box_Line_style(boxColor, Point(300, 100), 80, 20, 5, textColor, "Line_style");
	boxRoundCorners box_Color(boxColor, Point(400, 100), 60, 20, 5, textColor, "Color");

	boxRoundCorners box_Simple_window(boxColor, Point(175, 200), 105, 20, 5, textColor, "Simple_window");
	boxRoundCorners box_Shape(boxColor, Point(310, 200), 60, 20, 5, textColor, "Shape");
	boxRoundCorners box_Point(boxColor, Point(400, 200), 60, 20, 5, textColor, "Point");

	boxRoundCorners box_Line(boxColor, Point(150, 300), 40, 20, 5, textColor, "Line");
	boxRoundCorners box_Lines(boxColor, Point(200, 300), 40, 20, 5, textColor, "Lines");
	boxRoundCorners box_Polygon(boxColor, Point(250, 300), 60, 20, 5, textColor, "Polygon");
	boxRoundCorners box_Axis(boxColor, Point(325, 300), 40, 20, 5, textColor, "Axis");
	boxRoundCorners box_Rectangle(boxColor, Point(375, 300), 70, 20, 5, textColor, "Rectangle");
	boxRoundCorners box_Text(boxColor, Point(450, 300), 40, 20, 5, textColor, "Text");
	boxRoundCorners box_Image(boxColor, Point(500, 300), 45, 20, 5, textColor, "Image");

	MyArrow arrow_Sw_W(box_Simple_window.get_north(), box_Window.get_south(), false, true, 5, arrowColor);
	MyArrow arrow_L_S(box_Line.get_north(), Point(box_Shape.get_south().x - box_Shape.get_width() / 2, box_Shape.get_south().y), false, true, 5, arrowColor);
	MyArrow arrow_Ls_S(box_Lines.get_north(), Point(box_Shape.get_south().x - box_Shape.get_width() / 4, box_Shape.get_south().y), false, true, 5, arrowColor);
	MyArrow arrow_P_S(box_Polygon.get_north(), Point(box_Shape.get_south().x - box_Shape.get_width() / 6, box_Shape.get_south().y), false, true, 5, arrowColor);
	MyArrow arrow_A_S(box_Axis.get_north(), box_Shape.get_south(), false, true, 5, arrowColor);
	MyArrow arrow_R_S(box_Rectangle.get_north(), Point(box_Shape.get_south().x + box_Shape.get_width() / 6, box_Shape.get_south().y), false, true, 5, arrowColor);
	MyArrow arrow_T_S(box_Text.get_north(), Point(box_Shape.get_south().x + box_Shape.get_width() / 4, box_Shape.get_south().y), false, true, 5, arrowColor);
	MyArrow arrow_I_S(box_Image.get_north(), Point(box_Shape.get_south().x + box_Shape.get_width() / 2, box_Shape.get_south().y), false, true, 5, arrowColor);

	//ATTACH BOXES
	win.attach(box_Window);
	win.attach(box_Line_style);
	win.attach(box_Color);

	win.attach(box_Simple_window);
	win.attach(box_Shape);
	win.attach(box_Point);

	win.attach(box_Line);
	win.attach(box_Lines);
	win.attach(box_Polygon);
	win.attach(box_Axis);
	win.attach(box_Rectangle);
	win.attach(box_Text);
	win.attach(box_Image);

	//ATTACH ARROWS
	win.attach(arrow_Sw_W);
	win.attach(arrow_L_S);
	win.attach(arrow_Ls_S);
	win.attach(arrow_P_S);
	win.attach(arrow_A_S);
	win.attach(arrow_R_S);
	win.attach(arrow_T_S);
	win.attach(arrow_I_S);

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