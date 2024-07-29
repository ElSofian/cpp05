#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Form"), _signed(false), _signGradeRequired(150), _execGradeRequired(150) {}

Form::Form(std::string const name, unsigned int signGradeRequired, unsigned int execGradeRequired)
	: _name(name), _signed(false), _signGradeRequired(signGradeRequired), _execGradeRequired(execGradeRequired) {
	if (signGradeRequired < 1 || execGradeRequired < 1)
		throw Form::GradeTooHighException();
	else if (signGradeRequired > 150 || execGradeRequired > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &obj) : _name(obj._name), _signed(obj._signed), _signGradeRequired(obj._signGradeRequired), _execGradeRequired(obj._execGradeRequired) {}

Form::~Form() {}

Form &Form::operator=(Form const &obj) {
	if (this != &obj)
		_signed = obj._signed;
	return *this;
}

std::string const Form::getName() const {
	return _name;
}

bool Form::getSigned() const {
	return _signed;
}

unsigned int Form::getSignGradeRequired() const {
	return _signGradeRequired;
}

unsigned int Form::getExecGradeRequired() const {
	return _execGradeRequired;
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _signGradeRequired)
		throw Form::GradeTooLowException();
	_signed = true;
}

std::ostream &operator<<(std::ostream &stream, const Form &src)
{
    return stream << src.getName() << ", Form signature grade: " << src.getSignGradeRequired() << ", Form exec grade: " << src.getExecGradeRequired() << ", Signature statuts: " << src.getSigned();
}