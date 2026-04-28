#include "Bureaucrat.hpp"

// constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : _name(name)
{
    // burada sınır kontrolü yapmak kritik
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();

    _grade = grade;
}

// copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : _name(other._name), _grade(other._grade)
{
}

// assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    // name const olduğu için kopyalanamaz
    if (this != &other)
        _grade = other._grade;
    return *this;
}

// destructor
Bureaucrat::~Bureaucrat()
{
    // şu an özel bir iş yok ama canonical form için yazıldı
}

// getterlar
std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

// grade yükseltme
void Bureaucrat::incrementGrade()
{
    // 1 zaten en yüksek → daha yukarı çıkamaz
    if (_grade <= 1)
        throw GradeTooHighException();

    _grade--;
}

// grade düşürme
void Bureaucrat::decrementGrade()
{
    // 150 zaten en düşük
    if (_grade >= 150)
        throw GradeTooLowException();

    _grade++;
}

// exception mesajları
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

// output format
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}