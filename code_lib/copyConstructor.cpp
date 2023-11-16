
#include "test.hpp"

#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;


#include <iostream>
#include <string>



class Book {
public:
    string Title;
    string Author;
    float* Rates;
    int RatesCounter;

    Book(string titles, string author) : Title(titles), Author(author) {
        cout << " - constructor - " << endl;
        RatesCounter = 2;
        Rates = new float[RatesCounter];
        Rates[0] = 5;
        Rates[1] = 4;
    }

    ~Book() {
        cout << " - destructor - " << endl;
        delete[] Rates;
        Rates = nullptr;
    }

    Book(const Book& original) {
        cout << " - copy constructor - " << endl;
        Title = original.Title;
        Author = original.Author;
        // Rates = original.Rates;
        RatesCounter = original.RatesCounter;

        Rates = new float[RatesCounter];
        for(int i = 0; i < RatesCounter; i++) {
            Rates[i] = original.Rates[i];
        }
    }
};

void printBook(Book book) {
    cout << "Title: " << book.Title << endl;
    cout << "Author: " << book.Author << endl;

    float sum = 0;
    for(int i = 0; i < book.RatesCounter; i++) {
        sum += book.Rates[i];
    }
    cout << "Avg rate: " << sum / book.RatesCounter << endl;
}

int main(void) {
    Book book1("A's book", "A");
    
    // Book book2("B's book", "B");
    Book book2(book1);
    // cout << book3.Rates[0] << ", " << book3.Rates[1] << endl;

    // Book book4 = book1;
    // cout << book4.Rates[0] << ", " << book4.Rates[1] << endl;

    printBook(book1);
    printBook(book2);

    return 0;
}