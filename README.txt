spin: a basic wrapper/API for manipulating strings and character sequences (prototype)

-provides the user a type spin::string_c (the c stands for case) and
some operations for manipulating its contents[0].

-[0] buffer is a null-terminated character array

objective: to provide an STL compatible interface that can take any character
sequence S and manipulate it, but also transform it into some sequence S'
which is identical to S, but 'case-a-fied'


certain cases will follow specific rules

available cases:

    titlecase 
        input:  "eVERYTHING iS nOTHING, wITH A tWIST!"
        output: "Everything is Nothing, with a Twist!"

        -there exist certain reserved keywords whose original state is preserved
        and these keywords will either remain all UPPERCASE or all lowercase:

        ie: "STL" vs "at"
    
    lowercase
        input:  "EVERYTHING IS NOTHING, WITH A TWIST!"
        output: "everything is nothing, with a twist!"

        -totally applied

    uppercase
        input:  "everything is nothing, with a twist!"
        output: "EVERYTHING IS NOTHING, WITH A TWIST!"

        -totally applied

    snakecase
        input:  "eVERYTHING iS nOTHING, wITH A tWIST!"
        output: "eVERYTHING_iS_nOTHING,_wITH_A_tWIST!"

        -totally applied
        -creates a '_' delimited sequence, where delimeter can be user specified (defaults is whitespace)
        -preserves state of remaining characters in sequence

development so far (7/26/2018):

notes:

    -no longer a wrapper around an std::string but around a raw resource
     (c-style character array)

spin:

    specification

        -must provide auxilliary operations or general algos that are compatible with
          RandomAcessIterators

    interface
        
        -spin::string_c: a Regular string type
        -spin::case_c: function class for totally applying cases to spin::string_c objects
        -spin::algos_c: interface for general algos that can be applied to
          spin::string_c objects (or c-style/std::string sequences)


spin::string_c:

    specification

        -must mimic std::string behavior
        -must be compatible with c-style strings or std::strings
        -must be compatible with the STL

    interface

        -Regular (default, copy, destructor, asignment, equality)
        -type conversions for the following:
            from spin::string_c,
            from std::string,
            from char,
            from const char*
        -[] operator: function that defines random access operations
        -iterators/const iterators: pointers to begining and end of sequence
          output (<<) and input (>>) operators: functions that extract and put
          to std::iostreams
        -size: function that defines size of spin::string_c
        -empty: function that determines if spin::string_c is empty
        -clear: function that clears the contents of a spin::string_c's
          underlying buffer (can think of as delete)

spin::case_c:

    specification
        
        -must apply a user specified case to contents of underlying buffer
        -must be able to use RandomAccessIterators
        -must be STL/std::string compatible


    interface
        
        -hashmaps for word flagged to be reserved
        -Default, Conversions, Destructor
        -titlecase: function that applies the idea of "titlecase" to
        a given sequence
        -lowercase: function that applies the idea of "lowercase" to
        a given sequence
        -uppercase: function that applies the idea of "uppercase" to
        a given sequence
        -snakecase: function that applies the idea of "snakecase" to
        a given sequence


spin::algos_c:

    specification

    interface

TODO:
        
    spin::string_c
       
        readline/getline
        remove whitespace
        remove leading whitespace
        remove trailing whitespace
        find (implement KMP)
        rfind
        find_first_of
        find_first_not_of
        find_last_of
        find_last_not_of
        substr
        tokenize
        concactenation
        at, with bounds checking
        

