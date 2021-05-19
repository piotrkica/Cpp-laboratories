#include "mystring.h"

void MyString::clear(){
    _string.clear();
    _size = 0;
    _capacity = 0;
}

char MyString::operator[](size_t index) const{
    if (index >= _size){
         throw std::out_of_range("Index out of range");
    }
    return _string[index];
}

MyString& MyString::operator+=(const char c){
    _string += c;
    _size = _string.size();
    _capacity = _string.capacity();
    return *this;
}

bool MyString::operator!=(const MyString &str) const { // just for the purpose of using mismatch i dont use .compare() != 0
    std::pair result = std::mismatch(_string.begin(), _string.end(), str.begin());
    if (result.first == _string.begin() && _string[0] == str[0]){
        return false;
    }
    return true;
}

std::set<MyString> MyString::getUniqueWords() const{
    std::set<MyString> unique_words;
    std::string str_cpy = _string;
    auto mytolower = [](char c) { return std::tolower(c); };
    auto myisspace = [](char c) { return std::isspace(c); };
    std::transform(str_cpy.begin(), str_cpy.end(), str_cpy.begin(), mytolower);
    auto i = str_cpy.begin();
    auto j = str_cpy.begin();
    while (i != str_cpy.end()){
        i = std::find_if_not(i, str_cpy.end(), myisspace);
        j = std::find_if(i, str_cpy.end(), myisspace );

        auto d1 = i - str_cpy.begin();
        auto d2 = j - str_cpy.begin();
        std::string word = str_cpy.substr(d1, d2 - d1);
        unique_words.insert(MyString(word));
        i = j;
    }
    return unique_words;
}


void MyString::toLower() {
    auto mytolower = [](char c) { return std::tolower(c); };
    std::transform(_string.begin(), _string.end(), _string.begin(), mytolower);
}

bool MyString::startsWith(std::string str) const {
    auto start = std::search(_string.begin(), _string.end(), str.begin(), str.end());
    return start == _string.begin();
}

bool MyString::endsWith(std::string str) const {
    auto start = std::search(_string.begin(), _string.end(), str.begin(), str.end());
    return start == _string.end() - str.size();
}

bool MyString::all_of(int predicate(int)) const {
    return std::all_of(_string.begin(), _string.end(), predicate);
}

void MyString::trim(){
    auto left = std::find_if_not(_string.begin(),_string.end(),[](unsigned char c) {return std::isspace(c); });
    auto right = std::find_if_not(_string.rbegin(),_string.rend(),[](unsigned char c) {return std::isspace(c); }).base();
    _string = std::string(left,right);
    _size = _string.size();
    _capacity = _string.capacity();
}

std::map<MyString, size_t> MyString::countWordsUsage() const {
    std::map<MyString, size_t> word_usage_map;

    auto myisspace = [](char c) { return std::isspace(c); };
    auto i = _string.begin(), j = _string.begin();

        while (i != _string.end()) {
        i = std::find_if_not(i,_string.end(), myisspace);
        j = std::find_if(i,_string.end(), myisspace);
        auto d1 = i - _string.begin();
        auto d2 = j - _string.begin();

        std::string word = _string.substr(d1, d2 - d1);
        word.erase(std::remove_if(word.begin(),word.end(), [](char c) { return !isalpha(c); } ),word.end());
        MyString ms_word(word);

        if (word_usage_map.find(ms_word) == word_usage_map.end()){
            word_usage_map.insert(std::pair<MyString,size_t>(ms_word, 1));
        }
        else{
            word_usage_map.find(ms_word)->second++;
        }
        i = j;
   }
   return word_usage_map;
}

MyString MyString::join(const std::vector<MyString> str) const {
    MyString joined_text;
    for (auto&& elem : str){
        for (char c : elem._string){
            joined_text += c;

        }
        for (char sep: _string){
            joined_text += sep;
        }
    }
    for (size_t i = 0; i < _string.size(); i++){
        joined_text._string.pop_back();
    }

    return joined_text;
}

std::ostream &operator<<(std::ostream & stream, const MyString &str){
    return stream << str._string;
}

std::istream &operator>>(std::istream & stream, MyString &str){
    std::string buffer_str;
    while (stream >> buffer_str){
        str._string.append(buffer_str);
        str._string.append(" ");
    }
    str._capacity = str._string.capacity();
    str._size = str._string.size();
    return stream;

}
