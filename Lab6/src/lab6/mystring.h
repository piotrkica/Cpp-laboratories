#ifndef MYSTRING_H
#define MYSTRING_H

#include <cstdlib>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <iterator>
#include <set>
#include <map>

class MyString{
private:
    std::string _string;
    size_t _size;
    size_t _capacity;

public:
    static const int initialBufferSize = 20;
    static char genRandomChar() { return rand() % 26 + 65 + rand() % 2 * 32; }
    static MyString generateRandomWord(size_t word_length){
        std::string word(word_length,' ');
        std::generate_n(word.begin(), word_length, genRandomChar);
        return MyString(word);
    }

    MyString(): _string(std::string()), _size(_string.size()), _capacity(initialBufferSize + _string.capacity()) { _string.reserve(initialBufferSize); }
    MyString(const char chars[]): _string(chars), _size(_string.size()), _capacity(initialBufferSize + _string.capacity()) { _string.reserve(initialBufferSize); }
    MyString(const std::string str_): _string(str_),  _size(str_.length()), _capacity(str_.capacity()){}

    size_t size() const { return _size; }
    size_t capacity() const { return _capacity; }

    char operator[](size_t index) const;
    MyString& operator+=(const char c);

    std::string::const_iterator begin() const { return _string.begin(); }
    std::string::const_iterator end() const { return _string.end(); }

    bool operator<(const MyString &str) const { return _string.compare(str._string) < 0; }
    bool operator==(const MyString &str) const { return _string.compare(str._string) == 0; }
    bool operator!=(const MyString &str) const;

    std::set<MyString> getUniqueWords() const;
    std::map<MyString, size_t> countWordsUsage() const;

    bool empty() const { return _size == 0; }
    void clear();
    void toLower();
    bool startsWith(std::string str) const;
    bool endsWith(std::string str) const;
    bool all_of(int predicate(int)) const;
    void trim();

    MyString join(const std::vector<MyString> str) const;

    friend std::ostream &operator<<(std::ostream & stream, const MyString &str);
    friend std::istream &operator>>(std::istream & stream, MyString &str);
};

#endif // MYSTRING_H



