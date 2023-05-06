// In some cases the exception handler in catch block may decide to rethrow the exception without processing it.
// A throw statement without an exception explicitly mention causes the current exception to be thrown to the next enclosing try catch block which catches it and handles it in the specific manner.

#include <iostream>

void divide(double x, double y)
{
  try
  {
    std::cout << "Inside function" << std::endl;

    if (y == 0.0)
      throw y; // throw exception;
    else
      std::cout << "Division = " << x / y << std::endl;
  }
  catch (double)
  {
    std::cout << "caught double inside function" << std::endl;
    throw; // rethrow
  }

  std::cout << "End of function" << std::endl;
}

int main()
{
  std::cout << "Inside main" << std::endl;
  try
  {
    divide(10.5, 2.0);
    divide(20.0, 0.0);
  }
  catch (double)
  {
    std::cout << "caught double inside main" << std::endl;
  }

  std::cout << "End of main" << std::endl;

  return 0;
}
