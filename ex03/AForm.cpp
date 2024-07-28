#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("AForm"), _signed(false), _signGradeRequired(150), _execGradeRequired(150) {}

AForm::AForm(std::string const name, unsigned int signGradeRequired, unsigned int execGradeRequired)
	: _name(name), _signed(false), _signGradeRequired(signGradeRequired), _execGradeRequired(execGradeRequired) {
	if (signGradeRequired < 1 || execGradeRequired < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (signGradeRequired > 150 || execGradeRequired > 150)
		throw Bureaucrat::GradeTooLowException();
}

AForm::AForm(AForm const &obj) : _name(obj._name), _signed(obj._signed), _signGradeRequired(obj._signGradeRequired), _execGradeRequired(obj._execGradeRequired) {}

AForm::~AForm() {}

AForm &AForm::operator=(AForm const &obj) {
	if (this != &obj)
		_signed = obj._signed;
	return *this;
}

std::string const AForm::getName() const {
	return _name;
}

bool AForm::getSigned() const {
	return _signed;
}

unsigned int AForm::getSignGradeRequired() const {
	return _signGradeRequired;
}

unsigned int AForm::getExecGradeRequired() const {
	return _execGradeRequired;
}

void AForm::setSignatureStatus(bool status) {
	_signed = status;
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
	std::cout << "grade: " << bureaucrat.getGrade() << std::endl;
	if (bureaucrat.getGrade() > _signGradeRequired)
		throw Bureaucrat::GradeTooLowException();
	_signed = true;
}

std::ostream &operator<<(std::ostream &out, AForm const &obj) {
	return out << obj.getName() << " form is " << (obj.getSigned() ? "" : "not ") << "signed and requires grade " << obj.getSignGradeRequired() << " to sign and grade " << obj.getExecGradeRequired() << " to execute";
}