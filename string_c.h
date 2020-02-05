#ifndef _STRING_C
#define _STRING_C
#include <iostream>
#include <cstring>
#include <string>
//begin namespace spin
namespace spin {

    //begin spin::string_c
    struct string_c{
        
        using value_type         = char;
        using size_type          = std::ptrdiff_t;
        using reference          = char&;
        using const_reference    = const char&;
        using pointer            = char*;
        using const_pointer      = const char*;
        using iterator           = pointer;
        using const_iterator     = const_pointer;

        pointer buffer;
        size_type sz;
        //move
        string_c(string_c&& x)
            : buffer(x.buffer), sz(x.size()){
                x.~string_c();
            }
        //default
        string_c()
            : buffer(nullptr), sz(0){/**/}
        //copy
        string_c(const string_c& x)
             //add one to size because sequence is null-terminated
            : buffer(nullptr), sz(x.size() + 1)
        {
            buffer = new value_type[sz];
            for (size_type i = 0; i != sz; ++i){
                buffer[i] = x[i];
            }
            buffer[sz - 1] = '\0';
        }
        //destructor
        ~string_c() {
            if (buffer) {
                delete[] buffer;
            }
        }
        //constructor from literal
        string_c(const_pointer x)
            : buffer(nullptr), sz(std::strlen(x) + 1)
        {
            buffer = new value_type[sz];
            for (size_type i = 0; i != sz; ++i){
                buffer[i] = x[i];
            }
            buffer[sz-1] = '\0';
        }
        //constructor from std::string
        string_c(const std::string& x)
            : buffer(nullptr), sz(x.size() + 1)
        {
            buffer = new value_type[sz];
            for (size_type i = 0; i != sz; ++i){
                buffer[i] = x[i];
            }
            buffer[sz-1] = '\0';
        }
        //SemiRegular
        string_c& operator=(const string_c& x){
            if (this == &x) return *this;
            if (buffer) {
                delete[] buffer;
            }
            //size() returns length of sequence + 1 (for null-termination)
            sz = x.size();
            buffer = new value_type[sz];
            for (size_type i = 0; i != sz; ++i){
                buffer[i] = x[i];
            }
            buffer[sz-1] = '\0';
            return *this;
        }
        //Regular
        friend
        bool operator==(const string_c& x, const string_c& y){
            if (x.size() != y.size()) return false;
            for (size_type i = 0; i != x.size(); ++i){
                if (x[i] != y[i]) return false;
            }
            return true;
        }
        friend
        bool operator==(const string_c& x, const_pointer y){
            if (x.size() != std::strlen(y)) return false;
            for (size_type i = 0; i != x.size(); ++i){
                if (x[i] != y[i]) return false;
            }
            return true;
        }
        friend
        bool operator==(const string_c& x, const std::string& y){
            if (x.size() != y.size()) return false;
            for (size_type i = 0; i != x.size(); ++i){
                if (x[i] != y[i]) return false;
            }
            return true;
        }
        friend
        bool operator==(const std::string& x, const string_c& y){
            if (x.size() != y.size()) return false;
            for (size_type i = 0; i != x.size(); ++i){
                if (x[i] != y[i]) return false;
            }
            return true;
        }
        friend
        bool operator<(const string_c& x, const string_c& y){
            size_type i = 0, j = 0;
            while (i < x.size() && j < y.size()){
                if (!(x[i] < y[i])) return false;
                ++i;
                ++j;
            }
            return true;
        }
        friend
        bool operator>(const string_c& x, const string_c& y){
            return (y < x);
        }
        friend
        bool operator<=(const string_c& x, const string_c& y){
            return !(y < x);
        }
        friend
        bool operator>=(const string_c& x, const string_c& y){
            return !(x < y);
        }
        inline
        reference operator[](size_type i){
            return buffer[i];
        }
        inline
        const_reference operator[](size_type i) const {
            return buffer[i];
        }
        inline
        size_type size() const { return sz; }
        inline
        bool empty() { return size() == 0; }
        void clear(){
            if (buffer) {
                std::fill(buffer, buffer+sz, '\0');
            }
        }
        inline
        iterator begin() { return buffer; }
        inline
        iterator end() { return begin() + size(); }
        inline
        const_iterator cbegin() const { return buffer; }
        inline
        const_iterator cend() const { return cbegin() + size(); }

        //aux
        inline
        friend
        std::ostream& operator<<(std::ostream& output, const string_c& x){
            output << x.buffer;
            return output;
        }
        inline
        friend
        std::istream& operator>>(std::istream& input, const string_c& x){
            input >> x.buffer;
            return input;
        }

    };
    //end spin::string_c
}
//end namespace spin
#endif
