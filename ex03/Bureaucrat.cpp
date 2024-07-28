#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Bob"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string const name, unsigned int grade) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &obj) : _name(obj._name), _grade(obj._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &obj) {
	if (this != &obj)
		_grade = obj._grade;
	return *this;
}

std::string const Bureaucrat::getName() const {
	return _name;
}

unsigned int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::setGrade(unsigned int grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

void Bureaucrat::incrementGrade() {
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(AForm &src) {
	try {
		if (src.getSigned() == true)
			std::cout << this->_name << " couldn't sign " << src.getName() << ", it's already signed." << std::endl;
		else
		{
			src.beSigned(*this);
			std::cout << this->_name << " signed " << src.getName() << std::endl;
		}
	} catch (std::exception &e) {
        throw GradeTooLowException();
	}
}

void Bureaucrat::executeForm(AForm const &form) {
	try {
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << this->_name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &src)
{
    return stream << "Bureaucrat : "<< src.getName() << ", Grade : " << src.getGrade(); 
}