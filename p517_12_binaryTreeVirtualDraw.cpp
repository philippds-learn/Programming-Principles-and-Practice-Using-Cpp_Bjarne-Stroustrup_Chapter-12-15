//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 14 Exercise 12

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

using namespace Graph_lib;

ostream& operator<<(ostream& out, Point& a) {
	out << "(" << a.x << "," << a.y << ")";
	return out;
}

Point operator-(Point& p1, Point& p2) {
	Point p3 = Point(p1.x - p2.x, p1.y - p2.y);
	return p3;
}

Point operator+(Point& p1, Point& p2) {
	Point p3 = Point(p1.x + p2.x, p1.y + p2.y);
	return p3;
}

double pointVecMag(Point vec) {
	return sqrt(pow(vec.x, 2) + pow(vec.y, 2));;
}

struct Regular_triangle : Closed_polyline
{
	Regular_triangle(Point origin, int edge, int height, Fl_Color linecolor)
		: o(origin), e(edge), h(height), lc(linecolor)
	{
		generate_points();
	};

	void generate_points();
	void rotate_triangle(double rad);
	void draw_lines() const;

private:
	Point o;
	int e;
	int h;
	Fl_Color lc;
};

void Regular_triangle::generate_points()
{
	add(o);
	add(Point(o.x + e, o.y));
	add(Point(o.x + e / 2, o.y - h));
};

void Regular_triangle::draw_lines() const
{
	fl_color(lc);
	Closed_polyline::draw_lines();
};

void Regular_triangle::rotate_triangle(double rad)
{
	Point origin_Pt1 = Regular_triangle::point(0) - Regular_triangle::point(2);
	Point origin_Pt2 = Regular_triangle::point(1) - Regular_triangle::point(2);

	Point rotated_Pt1 = Point(cos(rad) * origin_Pt1.x - sin(rad) * origin_Pt1.y, sin(rad) * origin_Pt1.x + cos(rad) * origin_Pt1.y);
	Point rotated_Pt2 = Point(cos(rad) * origin_Pt2.x - sin(rad) * origin_Pt2.y, sin(rad) * origin_Pt2.x + cos(rad) * origin_Pt2.y);

	Regular_triangle::set_point(0, rotated_Pt1 + Regular_triangle::point(2));
	Regular_triangle::set_point(1, rotated_Pt2 + Regular_triangle::point(2));
};

class Binary_tree : public Shape
{
public:
	Binary_tree(Point root, int levels)
		:r(root), l(levels)
	{
		initialize_nodes();
	}
	~Binary_tree() {}

	void initialize_nodes();
	virtual void draw_lines() const;
	
	vector<Point> get_node_points() const { return node_points;  }


private:
	Point r;
	int l;
	vector<Point> node_points;

};

void Binary_tree::initialize_nodes()
{
	double nodes = 1.0;

	double tree_w = l * 100;

	for (int i = 0; i < l; i++) {
		for (double j = -(nodes / 2); j < (nodes / 2); j++) {
			if (i == 0) {
				node_points.push_back(Point(r.x + j, r.y + i * 30));
			}
			else {
				node_points.push_back(Point(r.x + (double(tree_w / nodes) / 2) + (j * double(tree_w / nodes)), r.y + i * 30));
			}
		}
		nodes *= 2;
	}
}

void Binary_tree::draw_lines() const
{
	// draw nodes
	for (int i = 0; i < node_points.size(); i++) {
		Circle c(node_points[i], 5);
		c.set_style(Line_style(Line_style::solid, 2));
		c.draw();
	}

	// draw connecting lines
	int node = 2;

	for (int i = 0; i < node_points.size() - ((node_points.size() + 1) / 2); i++) {
		for (int j = 1; j < 3; j++) {

			Point from(node_points[i].x, node_points[i].y + 5);
			Point to(node_points[i * node + j].x, node_points[i * node + j].y - 5);

			Line(from, to).draw();
		}
	}
}

class Binary_tree_triangle_nodes : public Binary_tree
{
public:
	Binary_tree_triangle_nodes(Point root, int levels)
		:Binary_tree(root, levels) {}
	~Binary_tree_triangle_nodes() {}

	void draw_lines() const override;
};

void Binary_tree_triangle_nodes::draw_lines() const
{
	vector<Point> node_points = Binary_tree::get_node_points();

	// draw nodes
	for (int i = 0; i < node_points.size(); i++) {

		Point origin(node_points[i].x - 5, node_points[i].y + 5);
		Regular_triangle t(origin, 10, 10, Fl_Color(0));
		t.set_style(Line_style(Line_style::solid, 2));
		t.draw();
	}

	// draw connecting lines
	int node = 2;

	for (int i = 0; i < node_points.size() - ((node_points.size() + 1) / 2); i++) {
		for (int j = 1; j < 3; j++) {

			Point from(node_points[i].x, node_points[i].y + 5);
			Point to(node_points[i * node + j].x, node_points[i * node + j].y - 5);

			Line(from, to).draw();
		}
	}
}

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 720, 400, "Simple Window");
	Point center(win.x_max() / 2, win.y_max() / 2);

	//Binary_tree tree(Point(center.x, 20), 7);

	Binary_tree_triangle_nodes tree(Point(center.x, 20), 7);
	
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