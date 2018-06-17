//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 14 Exercise 14

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

using namespace Graph_lib;

ostream& operator<<(ostream& out, Point& a) {
	out << "(" << a.x << "," << a.y << ")";
	return out;
}

//-----------------------ARROW CLASS--------------------------------

struct MyArrow : public Shape
{
	MyArrow(Point start, Point end, bool s, bool e, int size, Color col);
	~MyArrow() {}

	void draw_lines() const;
	double pointVecMag(Point vec);

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

	Color flc;
};

MyArrow::MyArrow(Point start, Point end, bool s, bool e, int size, Color col)
	:start(start), end(end), s(s), e(e), size(size), flc(col)
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
}

double MyArrow::pointVecMag(Point vec) {
	return sqrt(pow(vec.x, 2) + pow(vec.y, 2));;
}

void MyArrow::draw_lines() const {

	fl_color(flc.as_int());
	if (color().visibility()) {
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

//-----------------------BINARY TREE CLASS--------------------------------

enum line_type { arrow_up = 0, arrow_down, arrow_both_ways, line };

class Binary_tree : public Shape
{
public:
	Binary_tree(Point root, int levels, line_type line_type, Color col)
		:r(root), l(levels), lt(line_type), col(col)
	{
		initialize_nodes();
	}
	~Binary_tree() {}

	void initialize_nodes();
	void draw_lines() const;

private:
	Point r;
	int l;
	vector<Point> node_points;
	line_type lt;

	Color col;
	vector<string> labels;
};

void Binary_tree::initialize_nodes()
{
	double nodes = 1.0;
	bool left = true;	
	double tree_w = l * 130;
	int y = 0;

	for (int i = 0; i < l; i++) {		
		for (double j = -(nodes / 2); j < (nodes / 2); j++) {
			cout << i << ", " << y << endl;
			if (i == 0) {
				node_points.push_back(Point(r.x + j, r.y + i * 50));
				labels.push_back("lr");
			}
			else {				
				node_points.push_back(Point(r.x + (double(tree_w / nodes) / 2) + (j * double(tree_w / nodes)), r.y + i * 50));

				if (left) {
					labels.push_back(labels[y] + "l");
					left = false;
				}
				else {
					labels.push_back(labels[y] + "r");
					left = true;
					y++;
				}				
			}			
		}
		nodes *= 2;
	}
}

void Binary_tree::draw_lines() const
{
	// draw nodes
	for (int i = 0; i < node_points.size(); i++) {
		Circle c(node_points[i], 2);		
		c.set_style(Line_style(Line_style::solid, 2));
		c.draw();

		Text t(Point(node_points[i].x + 5, node_points[i].y + 5), labels[i]);
		t.set_color(Color::blue);
		t.draw();
	}

	// draw connecting lines
	int node = 2;
	string l = labels[0];

	for (int i = 0; i < node_points.size() - ((node_points.size() + 1) / 2); i++) {
		for (int j = 1; j < 3; j++) {

			Point from(node_points[i].x, node_points[i].y + 5);
			Point to(node_points[i * node + j].x, node_points[i * node + j].y - 5);

			//enum line_type { arrow_up, arrow_down, arrow_both_ways, line };
			switch (lt)
			{
			case arrow_up:
				MyArrow(from, to, true, false, 5, col).draw_lines();
				break;
			case arrow_down:
				MyArrow(from, to, false, true, 5, col).draw_lines();
				break;
			case arrow_both_ways:
				MyArrow(from, to, true, true, 5, col).draw_lines();
				break;
			case line:
				Line l(from, to);
				l.set_color(col);
				l.draw();
				break;
			}
		}
	}
}

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 720, 400, "Simple Window");
	Point center(win.x_max() / 2, win.y_max() / 2);

	Binary_tree tree(Point(center.x, 20), 5, line_type::line, Color::blue);
	tree.set_color(Color::red);

	win.attach(tree);

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