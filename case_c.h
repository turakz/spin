#ifndef _CASE_C
#define _CASE_C
#include <vector>
#include <unordered_map>
#include <iterator>
#include <algorithm>
//begin namespace spin
namespace spin { 
    //begin spin::case_c
    struct case_c {
        //for titlecase()
        //can be adapted to whatever is needed
        std::unordered_map<std::string, bool> reserved_lower{
            {"a", true},
            {"an", true},
            {"the", true},
            {"at", true},
            {"by", true},
            {"for", true},
            {"in", true},
            {"of", true},
            {"is", true},
            {"on", true},
            {"to", true},
            {"as", true},
            {"or", true},
            {"with", true},
        };
        //for titlecase()
        //this is also extendable
        std::unordered_map<std::string, bool> reserved_upper{
            {"stl", true},
            {"c++", true},
        };
        //internals
        std::string case_type;
        const char delim_type;
        case_c() : case_type(std::string()), delim_type(' '){}
        case_c(std::string& x) : case_type(x), delim_type(' '){}
        case_c(std::string& x, const char& c) : case_type(x), delim_type(c){}
        case_c(const char* x) : case_type(&x[0]), delim_type(' '){}
        case_c(const char* x, const char& c) : case_type(&x[0]), delim_type(c){}
        ~case_c(){};

        //I models RandomAcessIterator
        template<class I>
        void titlecase(I first, I last){
            if (first == last) return;
            I next = first;
            while (first != last && next != last){
                I front = first;
                std::string word = "";
                //find delimited sequence
                next = std::find(first, last, delim_type);
                //lowercase is default case for reserved words
                while (first != next){
                    *first = std::tolower(*first);
                    word += *first;
                    ++first;
                }
                //apply uppercase reserved_uppers
                if (reserved_upper[word]){
                    while (front != next){
                        *front = std::toupper(*front);
                        ++front;
                    }
                }
                //if not a reserved_lower, apply titlecase to first character
                else if (!reserved_lower[word]){
                    *front = std::toupper(*front);
                }
                //everything else reserved_lower and already lowercase, move to start of next sequence.
                first = next + 1;
            }
        }
        //I models RandomAcessIterator
        template<class I>
        void lowercase(I first, I last){
            if (first == last) return;
            while (first != last){
                *first = std::tolower(*first);
                ++first;
            }
        }
        //I models RandomAcessIterator
        template<class I>
        void uppercase(I first, I last){
            if (first == last) return;
            while (first != last){
                *first = std::toupper(*first);
                ++first;
            }
        }
        //I models RandomAcessIterator
        template<class I>
        void snakecase(I first, I last){
            if (first == last) return;
            while (first != last){
                if (*first == delim_type) *first = '_';
                ++first;
            }
        }
        //I models RandomAcessIterator
        template<class I>
        void operator()(I first, I last){
            if (case_type == "titlecase"){
                titlecase(first, last);
            }
            else if (case_type == "lowercase"){
                lowercase(first, last);
            }
            else if (case_type == "uppercase"){
                uppercase(first, last);
            }
            else if (case_type == "snakecase"){
                snakecase(first, last); //preserves original pattern, but now delimited with _
            }
        }
   
    }; 
    //end of struct case_c
    
}//end namespace spin
#endif


