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
			fake_rectangle{{0, 0}, {0, 1}, {1, 1}, {1, 0}};
			std::cout << "\nreal_rectangle\n";
			std::cout << "coordinates: ";
			print(real_rectangle);
			std::cout << "\nsquare: " << Square(real_rectangle);
			std::cout << "\ncenter: " << center(real_rectangle);
			std::cout << "\nfake_rectangle\n";
			std::cout << "coordinates: ";
			print(fake_rectangle);
			std::cout << "\nsquare: " << Square(fake_rectangle);
			std::cout << "\ncenter: " << center(fake_rectangle) << "\n";


		} else if (cmd == "rhombus") {
			TRhombus<double> real_rhombus(std::cin);
			std::tuple<TPoint<double>, TPoint<double>, TPoint<double>, TPoint<double>>
			fake_rhombus{{1, 0}, {0, 1}, {1, 2}, {2, 1}};
			std::cout << "\nreal_rhombus\n";
			std::cout << "coordinates: ";
			print(real_rhombus);
			std::cout << "\nsquare: " << Square(real_rhombus);
			std::cout << "\ncenter: " << center(real_rhombus);
			std::cout << "\nfake_rhombus\n";
			std::cout << "coordinates: ";
			print(fake_rhombus);
			std::cout << "\nsquare: " << Square(fake_rhombus);
			std::cout << "\ncenter: " << center(fake_rhombus) << "\n";


			
		} else if (cmd == "trapezoid") {
			TTrapezoid<double> real_trapezoid(std::cin);
			std::tuple<TPoint<double>, TPoint<double>, TPoint<double>, TPoint<double>>
			fake_trapezoid{{0, 0}, {1, 1}, {2, 1}, {3, 0}};
			std::cout << "\nreal_trapezoid\n";
			std::cout << "coordinates: ";
			print(real_trapezoid);
			std::cout << "\nsquare: " << Square(real_trapezoid);
			std::cout << "\ncenter: " << center(real_trapezoid);
			std::cout << "\nfake_trapezoid\n";
			std::cout << "coordinates: ";
			print(fake_trapezoid);
			std::cout << "\nsquare: " << Square(fake_trapezoid);
			std::cout << "\ncenter: " << center(fake_trapezoid) << "\n";
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