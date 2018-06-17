//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 12 Exercise 10

#include "Simple_window.h"
#include "Graph.h"
using namespace Graph_lib;

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, 800, 800, "File Diagram");

	//Point.h
	Text pointh(Point(50, 40), "Point.h:");
	pointh.set_color(Color::black);

	Text structPoint(Point(55, 70), "struct Point {...};");
	structPoint.set_color(Color::black);

	Graph_lib::Rectangle rect0(Point(50, 50), 150, 30);
	rect0.set_color(Color::black);
	rect0.set_fill_color(Color::yellow);

	win.attach(rect0);
	win.attach(pointh);
	win.attach(structPoint);

	//Graph.h
	Text graphh(Point(50, 140), "Graph.h:");
	graphh.set_color(Color::black);

	Text graphing(Point(55, 170), "//graphing interface:");
	Text graphing1(Point(55, 190), "struct Shape { ... };");
	Text graphing2(Point(55, 210), "...");

	graphing.set_color(Color::black);
	graphing1.set_color(Color::black);
	graphing2.set_color(Color::black);

	Graph_lib::Rectangle rect1(Point(50, 150), 150, 70);
	rect1.set_color(Color::black);
	rect1.set_fill_color(Color::yellow);

	win.attach(rect1);
	win.attach(graphh);
	win.attach(graphing);
	win.attach(graphing1);
	win.attach(graphing2);


	//Graph.cpp
	Text graphcpp(Point(20, 320), "Graph.cpp:");
	graphcpp.set_color(Color::black);

	Text graphcode(Point(25, 345), "Graph code");
	graphcode.set_color(Color::black);
	
	Graph_lib::Rectangle rect2(Point(20, 325), 100, 30);
	rect2.set_color(Color::black);
	rect2.set_fill_color(Color::yellow);

	win.attach(rect2);
	win.attach(graphcpp);
	win.attach(graphcode);

	//chapter12.cpp
	Text chapter12cpp(Point(50, 450), "chapter12.cpp:");
	chapter12cpp.set_color(Color::black);

	Text includeGraphh(Point(55, 475), "#include \"Graph.h\"");
	includeGraphh.set_color(Color::black);

	Text includeSimpleWindow(Point(55, 490), "#include \"Simple_window.h\"");
	includeSimpleWindow.set_color(Color::black);

	Text intMain(Point(55, 505), "int Main() {...}");
	intMain.set_color(Color::black);

	Graph_lib::Rectangle rect3(Point(50, 455), 200, 60);
	rect3.set_color(Color::black);
	rect3.set_fill_color(Color::yellow);

	win.attach(rect3);
	win.attach(chapter12cpp);
	win.attach(includeGraphh);
	win.attach(includeSimpleWindow);
	win.attach(intMain);


	//FLTK headers
	Text FLTKheaders(Point(355, 60), "FLTK headers");
	FLTKheaders.set_color(Color::black);

	Graph_lib::Rectangle rect4(Point(350, 40), 100, 50);
	rect4.set_color(Color::black);
	rect4.set_fill_color(Color::yellow);

	Graph_lib::Rectangle rect5(Point(345, 35), 100, 50);
	rect5.set_color(Color::black);
	rect5.set_fill_color(Color::yellow);

	Graph_lib::Rectangle rect6(Point(340, 30), 100, 50);
	rect6.set_color(Color::black);
	rect6.set_fill_color(Color::yellow);

	win.attach(rect6);
	win.attach(rect5);
	win.attach(rect4);
	win.attach(FLTKheaders);

	//Arrows
	Graph_lib::Line line0(Point(120, 80), Point(120, 150));
	line0.set_color(Color::black);

	Graph_lib::Line line1(Point(120, 220), Point(110, 325));
	line1.set_color(Color::black);

	Graph_lib::Line line2(Point(140, 220), Point(150, 455));
	line2.set_color(Color::black);

	Graph_lib::Line line3(Point(170, 455), Point(270, 415));
	line3.set_color(Color::black);

	Graph_lib::Line line4(Point(450, 70), Point(540, 70));
	line4.set_color(Color::black);

	Graph_lib::Line line5(Point(420, 90), Point(420, 180));
	line5.set_color(Color::black);

	Graph_lib::Line line6(Point(440, 90), Point(600, 300));
	line6.set_color(Color::black);

	Graph_lib::Line line7(Point(600, 300), Point(450, 200));
	line7.set_color(Color::black);

	Graph_lib::Line line8(Point(370, 90), Point(150, 150));
	line8.set_color(Color::black);

	Graph_lib::Line line9(Point(420, 200), Point(420, 400));
	line9.set_color(Color::black);

	Graph_lib::Line line10(Point(400, 200), Point(300, 285));
	line10.set_color(Color::black);

	Graph_lib::Line line11(Point(420, 400), Point(480, 280));
	line11.set_color(Color::black);

	Graph_lib::Line line12(Point(550, 280), Point(600, 355));
	line12.set_color(Color::black);

	win.attach(line0);
	win.attach(line1);
	win.attach(line2);
	win.attach(line3);
	win.attach(line4);
	win.attach(line5);
	win.attach(line6);
	win.attach(line7);
	win.attach(line8);
	win.attach(line9);
	win.attach(line10);
	win.attach(line11);
	win.attach(line12);

	//FLTK code
	Text FLTKcode(Point(555, 80), "FLTK code");
	FLTKcode.set_color(Color::black);

	Graph_lib::Rectangle rect7(Point(550, 60), 100, 50);
	rect7.set_color(Color::black);
	rect7.set_fill_color(Color::yellow);

	Graph_lib::Rectangle rect8(Point(545, 55), 100, 50);
	rect8.set_color(Color::black);
	rect8.set_fill_color(Color::yellow);

	Graph_lib::Rectangle rect9(Point(540, 50), 100, 50);
	rect9.set_color(Color::black);
	rect9.set_fill_color(Color::yellow);

	win.attach(rect9);
	win.attach(rect8);
	win.attach(rect7);
	win.attach(FLTKcode);

	//Window.h
	Text windowh(Point(345, 140), "Window.h:");
	windowh.set_color(Color::black);

	Text windowInterface(Point(340, 160), "// window interface:");
	windowInterface.set_color(Color::black);

	Text classWindow(Point(340, 175), "class Window {...};");
	classWindow.set_color(Color::black);

	Text ddd(Point(340, 190), "...");
	ddd.set_color(Color::black);
		
	Graph_lib::Rectangle rect10(Point(330, 145), 150, 60);
	rect10.set_color(Color::black);
	rect10.set_fill_color(Color::yellow);

	win.attach(rect10);
	win.attach(windowh);
	win.attach(windowInterface);
	win.attach(classWindow);
	win.attach(ddd);

	//window.cpp
	Text windowcpp(Point(200, 280), "Window.cpp:");
	windowcpp.set_color(Color::black);

	Text windowcode(Point(205, 300), "Window code:");
	windowcode.set_color(Color::black);

	Graph_lib::Rectangle rect11(Point(200, 285), 150, 30);
	rect11.set_color(Color::black);
	rect11.set_fill_color(Color::yellow);

	win.attach(rect11);
	win.attach(windowcpp);
	win.attach(windowcode);

	//Simpe_window.h
	Text simpleWindowh(Point(250, 350), "Simple_Window.h:");
	simpleWindowh.set_color(Color::black);

	Text windowInterface1(Point(255, 370), "// window interface:");
	windowInterface1.set_color(Color::black);

	Text classSimpleWindow(Point(255, 385), "class Simple_window {...};");
	classSimpleWindow.set_color(Color::black);

	Text ddd1(Point(255, 400), "...");
	ddd1.set_color(Color::black);

	Graph_lib::Rectangle rect12(Point(250, 355), 200, 60);
	rect12.set_color(Color::black);
	rect12.set_fill_color(Color::yellow);

	win.attach(rect12);
	win.attach(simpleWindowh);
	win.attach(windowInterface1);
	win.attach(classSimpleWindow);
	win.attach(ddd1);

	//GUI.h:
	Text guih(Point(450, 250), "GUI.h:");
	guih.set_color(Color::black);

	Text guiInterface(Point(455, 270), "// GUI interface:");
	guiInterface.set_color(Color::black);

	Text structInbox(Point(455, 285), "struct In_box {...};");
	structInbox.set_color(Color::black);

	Text ddd2(Point(455, 300), "...");
	ddd2.set_color(Color::black);

	Graph_lib::Rectangle rect13(Point(450, 255), 200, 60);
	rect13.set_color(Color::black);
	rect13.set_fill_color(Color::yellow);

	win.attach(rect13);
	win.attach(guih);
	win.attach(guiInterface);
	win.attach(structInbox);
	win.attach(ddd2);

	//GUI.cpp
	Text guicpp(Point(470, 350), "GUI.cpp:");
	guicpp.set_color(Color::black);

	Text guicode(Point(475, 370), "GUI code");
	guicode.set_color(Color::black);

	Graph_lib::Rectangle rect14(Point(470, 355), 150, 30);
	rect14.set_color(Color::black);
	rect14.set_fill_color(Color::yellow);




	win.attach(rect14);
	win.attach(guicpp);
	win.attach(guicode);
		

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