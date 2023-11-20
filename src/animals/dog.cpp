
#include <iostream>
#include <string>
#include <vector>

// utils
#include "global.hpp"
#include "output.hpp"

// implementation
#include "dog.hpp"

using namespace std;

int Dog::dog_count = 0;

Dog::Dog(vector<string> const& atributes) :  Animal(atributes) {
    dog_count++;
    dog_id = dog_count;
    debug::dog_created(this);
}

Dog::~Dog() {
    dog_count--;
    debug::dog_destroyed(this);
}

int Dog::get_dog_count() {
    return dog_count;
}

int Dog::get_dog_id() const {
    return dog_id;
}

void Dog::introduce(ostream& out) const {
    out << speak() << endl;
    out << "Wauf, Wauf! I am a " << get_breed() << " " << get_color() << " " << get_type() << endl;
    out << "  My name is " << get_name() << ", I am a " << get_sex() << " and " << get_age() << " years old" << endl;
    out << "  I weight " << get_weight() << ". I think my health is " << get_health() << " Wauf, Wauf!" << endl;
    out << " My dog id is " << get_dog_id() << endl;
    out << endl;
}

namespace debug {
    void dog_created(Dog const* dog) {
        if (global::debug_flags::DOG_CREATED) {
            string msg = "+ Dog, count is now: " + to_string(Dog::get_dog_count());
            output::debug(msg);
        }
    }

    void dog_destroyed(Dog const* dog) {
        if (global::debug_flags::DOG_DELETED) {
            string msg = "- Dog, count is now: " + to_string(Dog::get_dog_count());
            output::debug(msg);
        }
    }
}
