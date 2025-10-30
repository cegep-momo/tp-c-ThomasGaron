#include <string>
#include <sstream>
#include "book.h"

using namespace std;

Book::Book()
    :title(""), author(""), isbn(""), isAvailable(true), borrowerName(""){}

Book::Book(const string& t, const string& a, const string& i)
    :title(t), author(a), isbn(i), isAvailable(true), borrowerName(""){}

string Book::getTitle() const {return title;}
string Book::getAuthor() const {return author;}
string Book::getISBN() const {return isbn;}
bool Book::getAvailability() const {return isAvailable;}
string Book::getBorrowerName() const {return borrowerName;}

void Book::setTitle(const string& t) {title=t;}
void Book::setAuthor(const string& a) {author = a;}
void Book::setISBN(const string& i) {isbn = i;}
void Book::setAvailability(bool b) {isAvailable=b;}
void Book::setBorrowerName(const string& n) {borrowerName = n;}

void Book::checkOut(const string& borrower){
    if(isAvailable) {
        isAvailable = false;
        borrowerName = borrower;
    }
}

void Book::returnBook() {
    isAvailable = true;
    borrowerName = "";
}

string Book::toString() const {
    ostringstream os;
    os  << "Titre: " << title
        << "\nAuteur: " << author
        << "\nISBN: " << isbn
        << "\nStatut: " << (isAvailable ? "Dispo" : "Enprunte");
    if (!isAvailable && !borrowerName.empty()){
        os << "\nEmprunteur: " << borrowerName;
    }
    return os.str();
}

string Book::toFileFormat() const {
    ostringstream os;
    os  << title << '|'
        << author << '|'
        << isbn << '|'
        << (isAvailable ? '1' : '0') << '|';

    if(!isAvailable && !borrowerName.empty()){
        os << borrowerName;
    }
    return os.str();
}

void Book::fromFileFormat(const string& line){
    string::size_type start=0, pos=0;

    auto next = [&](string& out){
        pos = line.find('|', start);
        if (pos == string::npos){
            out = line.substr(start);
            start = string::npos;
        } else {
            out = line.substr(start, pos - start);
            start = pos + 1;
        }
    };

    string t,a,i,flag,borrower;

    next(t);
    next(a);
    next(i);
    next(flag);

    title=t;
    author=a;
    isbn=i;

    if(start != string::npos) borrower = line.substr(start);

    isAvailable=(flag=="1");
    borrowerName=isAvailable ? "":borrower;
}
