#include "Books.hpp"
#include <map>
#include <fstream>

void Books::AddBook()
{
    std::string name;
    std::string author;
    std::string genre;
    std::string publisher;
    int year;
    int numofpages;

    std::cout << "Name: ";
    std::cin >> name;
    std::cout << std::endl;
    
    std::cout << "Author: ";
    std::cin >> author;
    std::cout << std::endl;
    
    std::cout << "Genre: ";
    std::cin >> genre;
    std::cout << std::endl;
    
    std::cout << "Publisher: ";
    std::cin >> publisher;
    std::cout << std::endl;

    std::cout << "Year: ";
    std::cin >> year;
    std::cout << std::endl;
    
    std::cout << "Num of pages: ";
    std::cin >> numofpages;
    std::cout << std::endl;
    std::cout << std::endl;

    Book book;
    book.title = name;
    book.author = author;
    book.genre = genre;
    book.publisher = publisher;
    book.year = year;
    book.numofpages = numofpages;
    AllBooks.push_back(book);
}

void Books::DeleteBook()
{
    std::string name;
    std::cout << "Enter the name of book to delete: ";
    std::cin >> name;
    std::cout << std::endl;

    for(unsigned int i = 0; i < AllBooks.size(); i++)
    {
        if(AllBooks[i].title == name)
        {
            AllBooks.erase(AllBooks.begin() + i);
            AllBooks.shrink_to_fit();
        }
    }
}

void Books::Report()
{
    std::string author;
    std::string genre;
    std::string publisher;
    
    std::cout << "Author: ";
    std::cin >> author;
    std::cout << std::endl;
    
    std::cout << "Genre: ";
    std::cin >> genre;
    std::cout << std::endl;
    
    std::cout << "Publisher: ";
    std::cin >> publisher;
    std::cout << std::endl;

    ShowAllBooksByAuthor(author);
    ShowAllBooksByGenreAndPublisher(genre, publisher);
    ShowBestPublisher();
    ShowBestGenre();
}

void Books::ShowAllBooksByAuthor(std::string author)
{
    std::cout << "Books of author: " << author << std::endl;
    for(unsigned int i = 0; i < AllBooks.size(); i++)
    {
        if(AllBooks[i].author == author)
        {
            std::cout << AllBooks[i].title << "\t";
        }
    }
    std::cout << std::endl;
}

void Books::ShowAllBooksByGenreAndPublisher(std::string genre, std::string publisher)
{
    std::cout << "Books of Genre: " << genre << " published by: " << publisher << std::endl;

    for(unsigned int i = 0; i < AllBooks.size(); i++)
    {
        if(AllBooks[i].genre == genre && AllBooks[i].publisher == publisher)
        {
            std::cout << AllBooks[i].title << "\t";
        }
    }
    std::cout << std::endl;
}

void Books::ShowBestPublisher()
{
    std::cout << "Best publisher: ";

    std::map<std::string, int> publishers;
    for(unsigned int i = 0; i < AllBooks.size(); i++)
    {
        publishers[AllBooks[i].publisher]++;
    }
    std::string bestpublisher{};
    int maxnumofbooks{};

    for(const auto& pub : publishers)
    {
        if(pub.second > maxnumofbooks)
        {
            maxnumofbooks = pub.second;
            bestpublisher = pub.first;
        }
    }
    std::cout << bestpublisher << std::endl;
}

void Books::ShowBestGenre()
{
    std::cout << "Best Genre: ";

    std::map<std::string, int> genres;
    for(unsigned int i = 0; i < AllBooks.size(); i++)
    {
        genres[AllBooks[i].genre]++;
    }
    std::string bestgenre{};
    int maxnumofgenre{};

    for(const auto& gen : genres)
    {
        if(gen.second > maxnumofgenre)
        {
            maxnumofgenre = gen.second;
            bestgenre = gen.first;
        }
    }
    std::cout << bestgenre << std::endl;
}

void Books::SaveToFile()
{
    std::string path{};
    std::cout << "Provide a path: ";
    std::cin >> path;
    std::cout << std::endl;

    std::ofstream file;
    file.open(path);
    for(unsigned int i = 0; i < AllBooks.size(); i++)
    {
        file << std::endl;
        file << AllBooks[i].title << "\t";
        file << AllBooks[i].author << "\t";
        file << AllBooks[i].publisher << "\t";
        file << AllBooks[i].genre << "\t";
        file << AllBooks[i].year << "\t";
        file << AllBooks[i].numofpages << "\t";
    }
    file.close();
}