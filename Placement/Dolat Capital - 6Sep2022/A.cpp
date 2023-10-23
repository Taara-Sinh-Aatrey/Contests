#include "bits/stdc++.h"
using namespace std;

struct Book {
    char Product[5];
    int Price;
    int SeqNum;
};

int no_of_books;

Book* Load() {
    cin >> no_of_books;
    Book* books = (Book*) malloc(no_of_books * sizeof(Book));
    
    for (int i = 0; i < no_of_books; i++) {
        
        // reading a line of input
        string s;
        while (s.empty()) {
            getline(cin, s);
        }
        
        // reading the product name, will stop when encounter a comma(,)
        int j = 0;
        while (j < s.size() && s[j] != ',') {
            books[i].Product[j] = s[j];
            j++;
        }
        j++;
        
        // ignoring space in between
        while (j < s.size() && s[j] == ' ') j++;
        
        // checking if input price is negative
        books[i].Price = 0;
        bool neg = false;
        if (j < s.size() && s[j] == '-') {
            neg = true;
            j++;
        }
        
        // reading the magnitude of price
        while (j < s.size() && s[j] != ',') {
            books[i].Price = books[i].Price * 10 + (s[j++] - '0');
        }
        
        // if negative, update the price accordingly
        if (neg)
            books[i].Price = -books[i].Price;
        j++;
        
        // ignoring the space in between
        while (j < s.size() && s[j] == ' ') j++;
        
        // reading the sequence number 
        books[i].SeqNum = 0;
        while (j < s.size() && s[j] != ',') {
            books[i].SeqNum = books[i].SeqNum * 10 + (s[j++] - '0');
        }
    }
    return books;
}

map<string, set<int>> top_prices;

void Process(const Book* newBook) {
    // insert the price of the product 
    top_prices[newBook->Product].insert(newBook->Price);
    
    // we only need top 5, so remove the last entry if no of entries exceeds 5
    if (top_prices[newBook->Product].size() > 5) {
        top_prices[newBook->Product].erase(prev(top_prices[newBook->Product].end()));
    }
    
    printf("%s || ", newBook->Product);
    
    // printing top distinct prices of this particular product
    int cnt = 0;
    for (auto it = top_prices[newBook->Product].begin(); it != top_prices[newBook->Product].end(); it++) {
        cout << *it << (cnt < 4 ? ", " : " ");
        cnt++;
    }
    
    // print 0 at the end if no of entries is less than 5
    while (cnt < 5) {
        cout << 0 << (cnt < 4 ? ", " : " ");
        cnt++;
    }
    cout << "||\n";
}


int main() {
    Book* books = Load();
    for (int i = 0; i < no_of_books; i++) {
        Process(&books[i]);
    }
    return 0;
}