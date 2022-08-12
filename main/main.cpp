#include "../lib/Books.hpp"

int main(int argc, char **argv)
{
  Books books;
  books.AddBook("tytul", "autor", "genre", "publisher", 1000, 358);
  books.AddBook("tytul4", "autor", "genre", "publisher", 1000, 358);
  books.AddBook("tytul1", "autor2", "genre2", "publisher2", 1000, 358);
  books.AddBook("tytul3", "autor2", "genre2", "publisher2", 1000, 358);
  books.AddBook("tytul2", "autor2", "genre2", "publisher2", 1000, 358);
  books.Report("autor", "genre2", "publisher");
  return 0;
}
