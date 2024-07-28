# include "Bureaucrat.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

int main()
{
    Bureaucrat test = Bureaucrat("patrick", 2);
    std::cout << "==PARDON TEST==" << std::endl;
    AForm *a1 = new PresidentialPardonForm("Thanos");
    try
    {
        test.signForm(*a1);
        a1->execute(test);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "==ROBOT TEST==" << std::endl;
    AForm *a2 = new RobotomyRequestForm("Sub-Zero");
    try
    {
        test.signForm(*a2);
        a2->execute(test);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "==TREE TEST==" << std::endl;
    AForm *a3 = new ShrubberyCreationForm("Garden-Permit-2-A");
    try
    {
        test.signForm(*a3);
        a3->execute(test);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    delete a1;
    delete a2;
    delete a3;
    return 0;
}