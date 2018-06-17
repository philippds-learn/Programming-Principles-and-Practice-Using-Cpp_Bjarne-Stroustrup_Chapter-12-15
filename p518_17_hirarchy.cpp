//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 14 Exercise 17

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

using namespace Graph_lib;

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


int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 720, 400, "Simple Window");
	Point center(win.x_max() / 2, win.y_max() / 2);

	Fl_Color boxColor = Color::black;
	Fl_Color textColor = Color::black;
	Fl_Color arrowColor = Color::black;

	boxRoundCorners exc(boxColor, Point(20, win.y_max() / 2), 150, 30, 5, textColor, "exception <exception>");

	boxRoundCorners bad_cast(boxColor, Point(250, 20), 150, 30, 5, textColor, "bad_cast <typeinfo>");
	boxRoundCorners bad_typeid(boxColor, Point(250, 70), 150, 30, 5, textColor, "bad_typeid <typeinfo>");
	boxRoundCorners logic_error(boxColor, Point(250, 120), 150, 30, 5, textColor, "logic_eror <stdexcept>");
	boxRoundCorners bad_alloc(boxColor, Point(250, 170), 150, 30, 5, textColor, "bad_alloc <new>");
	boxRoundCorners Ios_base(boxColor, Point(250, 220), 150, 30, 5, textColor, "Ios_base::failure <ios>");
	boxRoundCorners runtime_error(boxColor, Point(250, 270), 200, 30, 5, textColor, "runtime_error <stdexcept>");
	boxRoundCorners bad_exception(boxColor, Point(250, 320), 200, 30, 5, textColor, "bad_exception <exception>");

	boxRoundCorners domain_error(boxColor, Point(500, 20), 200, 30, 5, textColor, "domain_error <stdexception>");
	boxRoundCorners invalid_argument(boxColor, Point(500, 70), 200, 30, 5, textColor, "invalid_argument <stdexcept>");
	boxRoundCorners length_error(boxColor, Point(500, 120), 200, 30, 5, textColor, "length_error <stdexcept>");
	boxRoundCorners out_of_range(boxColor, Point(500, 170), 200, 30, 5, textColor, "out_of_range <stdexcept>");
	boxRoundCorners range_error(boxColor, Point(500, 220), 200, 30, 5, textColor, "range_error <stdexcept>");
	boxRoundCorners overflow_error(boxColor, Point(500, 270), 200, 30, 5, textColor, "overflow_error <stdexcept>");
	boxRoundCorners underflow_error(boxColor, Point(500, 320), 200, 30, 5, textColor, "underflow_error <stdexcept>");

	Line l1(exc.get_east(), Point(exc.get_east().x + 30, exc.get_east().y));
	l1.set_color(Color::black);

	Line l2(Point(exc.get_east().x + 30, 35), Point(exc.get_east().x + 30, 335));
	l2.set_color(Color::black);

	Line l3(Point(exc.get_east().x + 30, 35), bad_cast.get_west());
	l3.set_color(Color::black);

	Line l4(Point(bad_typeid.get_west().x - 50, 85), bad_typeid.get_west());
	l4.set_color(Color::black);

	Line l5(Point(logic_error.get_west().x - 50, 135), logic_error.get_west());
	l5.set_color(Color::black);

	Line l6(Point(bad_alloc.get_west().x - 50, 185), bad_alloc.get_west());
	l6.set_color(Color::black);

	Line l7(Point(Ios_base.get_west().x - 50, 235), Ios_base.get_west());
	l7.set_color(Color::black);

	Line l8(Point(runtime_error.get_west().x - 50, 285), runtime_error.get_west());
	l8.set_color(Color::black);

	Line l9(Point(bad_exception.get_west().x - 50, 335), bad_exception.get_west());
	l9.set_color(Color::black);


	Line l10(Point(logic_error.get_east()), length_error.get_west());
	l10.set_color(Color::black);

	Line l11(Point(runtime_error.get_east()), overflow_error.get_west());
	l11.set_color(Color::black);

	Line l12(Point(domain_error.get_west().x - 30, domain_error.get_west().y), Point(out_of_range.get_west().x - 30, out_of_range.get_west().y));
	l12.set_color(Color::black);

	Line l13(Point(range_error.get_west().x - 30, range_error.get_west().y), Point(underflow_error.get_west().x - 30, underflow_error.get_west().y));
	l13.set_color(Color::black);

	Line l14(Point(domain_error.get_west().x - 30, domain_error.get_west().y), domain_error.get_west());
	l14.set_color(Color::black);

	Line l15(Point(invalid_argument.get_west().x - 30, invalid_argument.get_west().y), invalid_argument.get_west());
	l15.set_color(Color::black);

	Line l16(Point(length_error.get_west().x - 30, length_error.get_west().y), length_error.get_west());
	l16.set_color(Color::black);

	Line l17(Point(out_of_range.get_west().x - 30, out_of_range.get_west().y), out_of_range.get_west());
	l17.set_color(Color::black);

	Line l18(Point(range_error.get_west().x - 30, range_error.get_west().y), range_error.get_west());
	l18.set_color(Color::black);
	
	Line l19(Point(overflow_error.get_west().x - 30, overflow_error.get_west().y), overflow_error.get_west());
	l19.set_color(Color::black);

	Line l20(Point(underflow_error.get_west().x - 30, underflow_error.get_west().y), underflow_error.get_west());
	l20.set_color(Color::black);

	win.attach(exc);

	win.attach(bad_cast);
	win.attach(bad_typeid);
	win.attach(logic_error);
	win.attach(bad_alloc);
	win.attach(Ios_base);
	win.attach(runtime_error);
	win.attach(bad_exception);

	win.attach(domain_error);
	win.attach(invalid_argument);
	win.attach(length_error);
	win.attach(out_of_range);
	win.attach(range_error);
	win.attach(overflow_error);
	win.attach(underflow_error);

	win.attach(l1);
	win.attach(l2);
	win.attach(l3);
	win.attach(l4);
	win.attach(l5);
	win.attach(l6);
	win.attach(l7);
	win.attach(l8);
	win.attach(l9);

	win.attach(l10);
	win.attach(l11);
	win.attach(l12);
	win.attach(l13);
	win.attach(l14);
	win.attach(l15);
	win.attach(l16);
	win.attach(l17);
	win.attach(l18);
	win.attach(l19);
	win.attach(l20);

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

/*
*/