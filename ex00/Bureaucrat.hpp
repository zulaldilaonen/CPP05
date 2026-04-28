#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat
{
private:
    const std::string _name;   // isim değişmemeli → const
    int _grade;                // 1 en yüksek, 150 en düşük

public:
    // constructor
    Bureaucrat(const std::string& name, int grade);

    // canonical form
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    // getterlar
    std::string getName() const;
    int getGrade() const;

    // grade işlemleri
    void incrementGrade(); // rank yükselir (1'e yaklaşır)
    void decrementGrade(); // rank düşer (150'ye yaklaşır)

    // exception classları
    class GradeTooHighException : public std::exception
    {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char* what() const throw();
    };
};

// çıktı formatı için operator overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
