

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>

// import Animal class
#include "animal.hpp"

class Cat : public Animal {
   private:
    static int cat_count; // Static variable to keep track of the number of Cat objects created
    int cat_id;           // Identification number of the cat
   public:
    Cat();
    Cat(vector<string> const& atributes);
    ~Cat();

    // Static method to get the count of Cat objects
    static int get_cat_count();
    int get_cat_id() const;

    // Method to introduce the cat
    void introduce(ostream& out) const;
};

namespace debug {
    void cat_created(Cat const* cat);
    void cat_destroyed(Cat const* cat);
}

#endif // CAT_HPP
                                   
