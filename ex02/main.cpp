#include "Bureaucrat.hpp"
#include "Form.hpp"

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

	Form form("Form", 1, 1);
	try {
		bob.signForm(form);
	} catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	bob.setGrade(1);
	Form form2("Form2", 2, 1);
	try {
		std::cout << bob.getGrade() << std::endl;
		bob.signForm(form2);
	} catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}