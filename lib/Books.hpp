#pragma once
#include "Book.hpp"
#include <vector>
#include <iostream>

class Books
{
    public:
    void AddBook();
    void DeleteBook();
    void Report();
    void SaveToFile();

    private:
    void ShowAllBooksByAuthor(std::string author);
    void ShowAllBooksByGenreAndPublisher(std::string genre, std::string publisher);
    void ShowBestPublisher();
    void ShowBestGenre();
    std::vector<Book> AllBooks;
};