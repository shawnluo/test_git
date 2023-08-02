#include "test.hpp"

class Book {
public:
    string Title;
    string Author;
    float* Rates;
    int RatesCounter;

    Book(string title, string author) {
        Title = title;
        Author = author;

        RatesCounter = 2;
        Rates = new float[RatesCounter];
        Rates[0] = 5;
        Rates[1] = 4;
    }

    ~Book() {
        delete[] Rates;
        Rates = nullptr;
    }

    // deep copy constructor
    Book(const Book& original) {    // 1. using const
                                    // 2. using reference "&"
        Title = original.Title;
        Author = original.Author;
        RatesCounter = original.RatesCounter;

        Rates = new float[RatesCounter];            // 3. make a new object.
        for(int i = 0; i < RatesCounter; i++) {     // 4. copy the origin data to the new obj
            Rates[i] = original.Rates[i];
        }
    }
};

int main(void) {
    Book book1("Show me", "the monry");
    Book book2("show must", "go on");

    // Book book3 = book1; // involking copy constructor - Book(const Book& original)
    Book book3(book1);   // involking copy constructor - same as the upper
    for(auto i = 0; i < book3.RatesCounter; i++)
        cout << book3.Rates[i] << endl;

    return 0;
}