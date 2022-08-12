#include "../lib/Books.hpp"

int main(int argc, char **argv)
{
  char choice{};
  Books books;

  while(choice != 'q')
  {
    std::cout << "BOOKS!\n";
    std::cout << "What would You like to do?\n";
    std::cout << "'a' - add a book\n";
    std::cout << "'d' - delete a book\n";
    std::cout << "'r' - Print a report\n";
    std::cout << "'q' - Quit\n";
    std::cin >> choice;
    switch(choice)
    {
      case 'a':
        books.AddBook();
        break;
      case 'd':
        books.DeleteBook();
        break;
      case 'r':
        books.Report();
        break;
      case 'q':
        std::cout << "Thank You!\n";
        break;
    }
  };

  return 0;
}
