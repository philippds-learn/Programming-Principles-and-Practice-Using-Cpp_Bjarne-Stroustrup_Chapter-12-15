//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 14 Exercise 11

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

using namespace Graph_lib;

ostream& operator<<(ostream& out, Point& a) {
	out << "(" << a.x << "," << a.y << ")";
	return out;
}

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
	void draw_lines() const;

	

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

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 720, 400, "Simple Window");
	Point center(win.x_max() / 2, win.y_max() / 2);

	Binary_tree tree(Point(center.x, 20), 7);
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