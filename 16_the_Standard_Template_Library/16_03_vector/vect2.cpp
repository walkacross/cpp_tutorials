// vect2.cpp -- methods and attribute in container
#include <iostream>
#include <string>
#include <vector>

struct Review
{
    std::string title;
    int rating;
};

bool FillReview(Review & rr);
void ShowReview(const Review & rr);

int main()
{
    using std::cout;
    using std::vector;
    vector<Review> books;
    Review temp;

    while (FillReview(temp))
        books.push_back(temp);
    int num = books.size();
    if (num > 0)
    {
        cout << "thanks you. you enterd the following:\n"
             << "Rating\tBooks\n";
        for (int i = 0; i < num; i++)
            ShowReview(books[i]);
        
        cout << "reprising:\n"
             << "Rating\tBook\n";
        vector<Review>::iterator pr;
        for (pr = books.begin(); pr != books.end(); pr++)
            ShowReview(*pr);

        // copy constructor used
        vector<Review> oldlist(books);
        if (num > 3)
        {
            // remove two items
            books.erase(books.begin() +1, books.begin() + 3);
            cout << "after erasure:\n";
            for (pr = books.begin(); pr != books.end(); pr++)
                ShowReview(*pr);

            // insert 1 item
            books.insert(books.begin(), oldlist.begin()+1, oldlist.begin() +2);
            cout << "after insertion:\n";
            for (pr = books.begin(); pr != books.end(); pr++)
                ShowReview(*pr); 
        }
        books.swap(oldlist);
        cout << "swapping oldlist with books:\n";
        for (pr = books.begin(); pr != books.end(); pr++)
            ShowReview(*pr);
    }
    else
        cout << "Nothing entered, nothing gained.\n";
    return 0;
}

bool FillReview(Review & rr)
{
    std::cout << "enter book titme (quit to quit): ";
    std::getline(std::cin, rr.title);
    if (rr.title == "quit")
        return false;
    std::cout << "enter book rating: ";
    std::cin >> rr.rating;
    if (!std::cin)
        return false;
    // get rid of rest of input line
    while (std::cin.get() != '\n')
        continue;
    return true;
}

void ShowReview(const Review & rr)
{
    std::cout << rr.rating << "\t" << rr.title << std::endl;
}
