/*
*	Author:	CS
*	Date:	2022_03_19	YYYY_MM_DD
* 
*	Program writes to file, with junk if fields where name is defined, but others are empty.
* 
*	Binaries for GUI are added, the GUI is designed front-to-back, templated on MS Powerpoint
*	Support is only added for writing orders as in the question statement, these are written when
*	next is pressed. Only one of the add purchase buttons need be pressed to update all of the list
*	purchases of the current order.
*	Purchases are stored in an array, which may vary until it is submitted with the add order button.

* Lesson:
* [Context: Order_window contains 1 Order_box and an array of 4 Purchase_box]
* 	The set_order_member_args and callback function is held within the Order_box class
	whereas the callback_functions of the four purchases are defined in the main window.
	This is because the GUI callback returns control to the Window (inherited) type, and
	does not differentiate objects, each callback must be independently linked to class functions.

*	Improvements:
*	Input filtering is not used for 'valid' purchases and orders,
*	empty fields add junk contents.
*/

#include <iostream>
#include "Order_Purchase.h"
#include <iterator>	// for std::istream_iterator
#include "CS_Shapes.h"
#include "fltk.h"
#include "Gui.h"
#include "Simple_window.h"
#include "Window.h"
#include "Order_pad.h"

int main() {
	try {
		
		Point tl{ 50,50 };
		constexpr int width = 1200;
		constexpr int height = 400;
		Order_window win{ tl, width, height, "Order pad" };
		win.wait_for_button();
		win.write_orders("Output.txt");
		return 0;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}