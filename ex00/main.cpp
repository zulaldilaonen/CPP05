#include "Bureaucrat.hpp"

// her senaryoyu ayrı fonksiyonda test etmek daha okunaklı
static void testValidFlow()
{
    std::cout << "[TEST] Valid flow" << std::endl;

    try
    {
        Bureaucrat b("Talha", 3);
        std::cout << b << std::endl;

        b.incrementGrade(); // 3 -> 2
        std::cout << "After increment: " << b << std::endl;

        b.decrementGrade(); // 2 -> 3
        std::cout << "After decrement: " << b << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }

    std::cout << std::endl;
}

static void testTooHigh()
{
    std::cout << "[TEST] Too high exception" << std::endl;

    try
    {
        Bureaucrat b("Zulal", 0); // invalid
    }
    catch (std::exception& e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << std::endl;
}

static void testTooLow()
{
    std::cout << "[TEST] Too low exception" << std::endl;

    try
    {
        Bureaucrat b("Ahmet", 151); // invalid
    }
    catch (std::exception& e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << std::endl;
}

static void testBoundary()
{
    std::cout << "[TEST] Boundary conditions" << std::endl;

    try
    {
        Bureaucrat high("HighRank", 1);
        std::cout << high << std::endl;

        // bu hata vermeli
        high.incrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << "Caught (high limit): " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat low("LowRank", 150);
        std::cout << low << std::endl;

        // bu hata vermeli
        low.decrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << "Caught (low limit): " << e.what() << std::endl;
    }

    std::cout << std::endl;
}

int main()
{
    std::cout << "===== Bureaucrat Tests =====" << std::endl << std::endl;

    testValidFlow();
    testTooHigh();
    testTooLow();
    testBoundary();

    std::cout << "===== End =====" << std::endl;

    return 0;
}