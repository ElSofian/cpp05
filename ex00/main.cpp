#include "Bureaucrat.hpp"

int	main() {
	Bureaucrat	bob("Bob", 150);
	Bureaucrat	jim("Jim", 1);

	std::cout << bob.getName() << " " << bob.getGrade() << std::endl;
	std::cout << jim.getName() << " " << jim.getGrade() << std::endl;

	bob.incrementGrade();
	jim.decrementGrade();

	std::cout << bob.getName() << " " << bob.getGrade() << std::endl;
	std::cout << jim.getName() << " " << jim.getGrade() << std::endl;

	try {
		Bureaucrat	alice("Alice", 0);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat	alice("Alice", 151);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		jim.incrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		bob.decrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}