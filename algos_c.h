#ifndef _ALGOS_C
#define _ALGOS_C
#include "string_c.h"
#include <vector>
//begin namespace spin
namespace spin { 
    //begin general algos
    //I models RandomAcessIterator
    template<class I, class case_cFunctor>
    void transform(I first, I last, case_cFunctor C){
        if (first == last) return;
        C(first, last);
    }
    //I models RandomAcessIterator
    template<class I>
    std::vector<spin::string_c> split_into_words(I first, I last){//whitespace is default delim
        std::vector<spin::string_c> v;
        if (first == last) return v;
        I next = first;
        while (first != last && next != last){
            next = std::find(first, last, ' ');
            std::string word(first, next);
            if (!word.empty()) v.push_back(spin::string_c(word));
            first = next + 1;
        }
        return std::move(v);
    }
    //I models RandomAcessIterator
    //T models Regular (expecting std::string, or char)
    template<class I, typename T>
    std::vector<spin::string_c> split_into_words(I first, I last, T delim){
        std::vector<spin::string_c> v;
        if (first == last) return v;
        I next = first;
        while (first != last && next != last){
            next = std::find(first, last, delim);
            std::string word(first, next);
            if (!word.empty()) v.push_back(spin::string_c(word));
            first = next + 1;
        }
        return std::move(v);
    }
    //end general algos
}//end namespace spin
#endif


