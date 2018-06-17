//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 14 Exercise 9

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

using namespace Graph_lib;

ostream& operator<<(ostream& out, Point& a) {
	out << "(" << a.x << "," << a.y << ")";
	return out;
}

struct Group : Shape
{
	void add_board_shape(Shape& shape) { b.push_back(shape); }
	void add_piece_shape(Shape& shape) { p.push_back(shape); }

	void draw_lines() const;
	void move_piece(int index, int dx, int dy);
		
	Vector_ref<Shape> shapes() { return b; }

private:
	Vector_ref<Shape> b;
	Vector_ref<Shape> p;
};


void Group::draw_lines() const
{
	for (int i = 0; i < b.size(); ++i) {
		b[i].draw();		
	}
	for (int i = 0; i < p.size(); ++i) {
		p[i].draw();
	}

}

void Group::move_piece(int index, int fieldx, int fieldy)
{
	int dx = fieldx * 100;
	int dy = fieldy * 100;
	p[index].move(dx, dy);
}

void initialize_checkers_board(Group& group, Vector_ref<Graph_lib::Rectangle>& board)
{

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			// pushback to vector_ref
			board.push_back(new Graph_lib::Rectangle(Point(j * 100, i * 100), Point(j * 100 + 100, i * 100 + 100)));

			// setup color of checkers_board
			if (i % 2 == 0) {
				if (((i * 8) + j) % 2 == 0) {
					board[i * 8 + j].set_fill_color(Color::black);
				}
				else {
					board[i * 8 + j].set_fill_color(Color::white);
				}
			}
			else {
				if (((i * 8) + j) % 2 == 0) {
					board[i * 8 + j].set_fill_color(Color::white);
				}
				else {
					board[i * 8 + j].set_fill_color(Color::black);
				}
			}

			// add rectangle to checkers_board Group
			group.add_board_shape(board[i * 8 + j]);
		}
	}
}

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 800, 800, "Simple Window");
	Point center(win.x_max() / 2, win.y_max() / 2);

	Group checkers_board;
	Vector_ref<Graph_lib::Rectangle> board;
	Vector_ref<Graph_lib::Circle> pieces;
	initialize_checkers_board(checkers_board, board);

	pieces.push_back(new Graph_lib::Circle(Point(50, 50), 40));
	pieces[0].set_color(Color::black);
	pieces[0].set_fill_color(Color::white);
	checkers_board.add_piece_shape(pieces[0]);

	win.attach(checkers_board);
	win.wait_for_button();

	checkers_board.move_piece(0, 3, 4);
	win.attach(checkers_board);
	
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