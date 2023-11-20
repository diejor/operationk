
#include <string>
#include<iostream>
#include<vector>

// utils
#include "output.hpp"

// implementation
#include "cat.hpp"

using namespace std;

int Cat::cat_count = 0;

void default_init() {
}

Cat::Cat(vector<string> const& atributes) : Animal(atributes) {
    cat_count++;
    cat_id = cat_count;
    debug::cat_created(this);
}

Cat::~Cat() {
    cat_count--;
    cout << "Cat destructor called" << endl;
    debug::cat_destroyed(this);
}

int Cat::get_cat_count() {
    return cat_count;
}

int Cat::get_cat_id() const {
    return cat_id;
}

void Cat::introduce(ostream& out) const {
    out << speak() << endl;
    out << "  Miau, Miau! " << get_breed() << " " << get_color() << " " << get_type() << endl;
    out << "  My name is " << get_name() << ", I am a " << get_sex() << " and " << get_age() << " years old" << endl;
    out << "  I weight " << get_weight() << ". I think my health is " << get_health() << endl;
    out << " My cat id is " << get_cat_id() << endl;
    out << endl;
}


namespace debug {
    void cat_created(Cat const* cat) {
        if (global::debug_flags::CAT_CREATED) {
            string msg = "+ Cat, count is now: " + to_string(Cat::get_cat_count());
            output::debug(msg);
        }
    }

    void cat_destroyed(Cat const* cat) {
        if (global::debug_flags::CAT_DELETED) {
            string msg = "- Cat, count is now: " + to_string(Cat::get_cat_count());
            output::debug(msg);
        }
    }
}
