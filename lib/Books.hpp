#pragma once
#include "Book.hpp"
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

class Books
{
    public:
    void AddBook(std::string name, std::string author, std::string genre, std::string publisher, int year, int numofpages);
    void DeleteBook(std::string name);
    void Report(std::string author, std::string genre, std::string publisher);

    private:
    void ShowAllBooksByAuthor(std::string author);
    void ShowAllBooksByGenreAndPublisher(std::string genre, std::string publisher);
    void ShowBestPublisher();
    void ShowBestGenre();
    std::vector<Book> AllBooks;
};