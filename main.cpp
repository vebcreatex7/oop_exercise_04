#include "rectangle.h"
#include "point.h"
#include "trapezoid.h"
#include "rhombus.h"
#include "template.h"
#include <string>


int main()
{

	std::string cmd;
	std::cout << "enter:\nrectangle - to add rectangle and calculate square and center of rectangle;\n" 
			  << "rhombus - to add rhombus and calculate square and center of rhombus;\n"
			  << "trapezoid - to add trapezoid and calculate square and center of trapezoid;\n"
			  << "help - to show this manual;\n"
			  << "exit - to finish execution of program.\n";
	while (true) {
		std::cin >> cmd;
		if (cmd == "rectangle") {
			TRectangle<double> real_rectangle(std::cin);
			std::tuple<TPoint<double>, TPoint<double>, TPoint<double>, TPoint<double>>
			tuple_rectangle{real_rectangle.a, real_rectangle.b, real_rectangle.c, real_rectangle.d};
			std::cout << "\nreal_rectangle\n";
			std::cout << "coordinates: ";
			print(real_rectangle);
			std::cout << "\nsquare: " << Square(real_rectangle);
			std::cout << "\ncenter: " << center(real_rectangle);
			std::cout << "\ntuple_rectangle\n";
			std::cout << "coordinates: ";
			print(tuple_rectangle);
			std::cout << "\nsquare: " << Square(tuple_rectangle);
			std::cout << "\ncenter: " << center(tuple_rectangle) << "\n";


		} else if (cmd == "rhombus") {
			TRhombus<double> real_rhombus(std::cin);
			std::tuple<TPoint<double>, TPoint<double>, TPoint<double>, TPoint<double>>
			tuple_rhombus{real_rhombus.a, real_rhombus.b, real_rhombus.c, real_rhombus.d};
			std::cout << "\nreal_rhombus\n";
			std::cout << "coordinates: ";
			print(real_rhombus);
			std::cout << "\nsquare: " << Square(real_rhombus);
			std::cout << "\ncenter: " << center(real_rhombus);
			std::cout << "\ntuple_rhombus\n";
			std::cout << "coordinates: ";
			print(tuple_rhombus);
			std::cout << "\nsquare: " << Square(tuple_rhombus);
			std::cout << "\ncenter: " << center(tuple_rhombus) << "\n";


			
		} else if (cmd == "trapezoid") {
			TTrapezoid<double> real_trapezoid(std::cin);
			std::tuple<TPoint<double>, TPoint<double>, TPoint<double>, TPoint<double>>
			tuple_trapezoid{real_trapezoid.a, real_trapezoid.b, real_trapezoid.c, real_trapezoid.d};
			std::cout << "\nreal_trapezoid\n";
			std::cout << "coordinates: ";
			print(real_trapezoid);
			std::cout << "\nsquare: " << Square(real_trapezoid);
			std::cout << "\ncenter: " << center(real_trapezoid);
			std::cout << "\ntuple_trapezoid\n";
			std::cout << "coordinates: ";
			print(tuple_trapezoid);
			std::cout << "\nsquare: " << Square(tuple_trapezoid);
			std::cout << "\ncenter: " << center(tuple_trapezoid) << "\n";
		} else if (cmd == "help") {
			std::cout << "\nenter:\nrectangle - to add rectangle and calculate square and center of rectangle;\n" 
			  << "rhombus - to add rhombus and calculate square and center of rhombus;\n"
			  << "trapezoid - to add trapezoid and calculate square and center of trapezoid;\n"
			  << "help - to show this manual;\n"
			  << "exit - to finish execution of program.\n";
			} else if (cmd == "exit"){
				break;
			} else {
				std::cout << "wrong comand, try again\n";
				continue;
			}


	}
	
}