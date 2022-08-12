#include "Books.hpp"

void Books::AddBook(std::string name, std::string author, std::string genre, std::string publisher, int year, int numofpages)
{
    Book book;
    book.title = name;
    book.author = author;
    book.genre = genre;
    book.publisher = publisher;
    book.year = year;
    book.numofpages = numofpages;
    AllBooks.push_back(book);
}

void Books::DeleteBook(std::string name)
{
    for(unsigned int i = 0; i < AllBooks.size(); i++)
    {
        if(AllBooks[i].title == name)
        {
            AllBooks.erase(AllBooks.begin() + i);
            AllBooks.shrink_to_fit();
        }
    }
}

void Books::Report(std::string author, std::string genre, std::string publisher)
{
    ShowAllBooksByAuthor(author);
    ShowAllBooksByGenreAndPublisher(genre, publisher);
    ShowBestPublisher();
    ShowBestGenre();
}

void Books::ShowAllBooksByAuthor(std::string author)
{
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

