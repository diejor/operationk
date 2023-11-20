#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>

#include "animal.hpp"

class Dog : public Animal {
   private:
    static int dog_count;  // Static variable to keep track of the number of Dog objects created
    int dog_id;            // Identification number of the dog
                                   
   public:
    Dog();
    Dog(vector<string> const& atributes);
    ~Dog();
                                   
    // Static method to get the count of Dog objects
    static int get_dog_count();
    int get_dog_id() const;

    // Method to introduce the dog
    void introduce(ostream& out) const;
};

namespace debug {
    void dog_created(Dog const* dog);
    void dog_destroyed(Dog const* dog);
}
                                   
#endif // DOG_HPP
