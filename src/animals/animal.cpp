#include "animal.hpp"
#include <iostream>
#include <sstream>
#include "global.hpp"
#include "output.hpp"

using namespace std;

int Animal::animal_count = 0;

Animal::Animal() {
    animal_count++;
    animal_id = animal_count;

    type = default_atributes[0];
    name = default_atributes[1];
    sex = default_atributes[2];
    age = stoi(default_atributes[3]);
    weight = stoi(default_atributes[4]);
    breed = default_atributes[5];
    color = default_atributes[6];
    health = default_atributes[7];
    sound = default_atributes[8];

    debug::animal_created(this);
}

void assign_if_not_empty(string& field, string value) {
    if (global::fncs::trim_whitespace(value) != "" && value.length() != 1) {
        field = value;
    }
}

void assign_if_not_empty(int& field, string value) {
    if (global::fncs::trim_whitespace(value)!= "") {
        field = stoi(value);
    }
}

// Constructor that takes a CSV string and initializes the object
Animal::Animal(vector<string> const& atributes) : Animal() {
    assign_if_not_empty(type, atributes[0]);
    assign_if_not_empty(name, atributes[1]);
    assign_if_not_empty(sex, atributes[2]);
    assign_if_not_empty(age, atributes[3]);
    assign_if_not_empty(weight, atributes[4]);
    assign_if_not_empty(breed, atributes[5]);
    assign_if_not_empty(color, atributes[6]);
    assign_if_not_empty(health, atributes[7]);
    assign_if_not_empty(sound, atributes[8]);
}

// Destructor
Animal::~Animal() {
    animal_count--;
    debug::animal_destroyed(this);
}

// Getter methods
string Animal::get_type() const { return type; }
string Animal::get_name() const { return name; }
string Animal::get_sex() const { return sex; }
int Animal::get_age() const { return age; }
int Animal::get_weight() const { return weight; }
string Animal::get_breed() const { return breed; }
string Animal::get_color() const { return color; }
string Animal::get_health() const { return health; }
string Animal::speak() const { return sound; }

// Static method to get the count of Animal objects
int Animal::get_animal_count() {
    return animal_count;
}

int Animal::get_animal_id() const {
    return animal_id;
}

void Animal::introduce(ostream& out) const {
    out << sound << endl;
    out << "  I am a " << breed << " " << color << " " << type << endl;
    out << "  My name is " << name << ", I am a " << sex << " and " << age << " years old" << endl;
    out << "  I weight " << weight <<  "lbs. I think my health is " << health << endl;
    out << " My animal id is " << animal_id << endl;
    out << endl;
}

/*
 *  Values surrounded by quotes are treated as a single value. Note that
 *  commas could be in within the quotes.
 */
vector<string> Animal::get_atributes(string csv) {
    vector<string> atributes;

    string token = "";
    for (int index = 0; index < csv.length(); index++) {
        char character = csv[index];
        if (character == '"') {
            index++;
            while (csv[index] != '"') {
                token += csv[index];
                index++;
            }
        } else if (character == ',') {
            atributes.push_back(token);
            token = "";
        } else {
            token += character;
        }
    }
    atributes.push_back(token);

    return atributes;
}

string Animal::to_csv() const {
    stringstream ss;
    ss << type << "," << name << "," << sex << "," << age << "," << weight << "," << breed << "," << color << "," << health << "," << sound;
    return ss.str();
}

namespace debug {
    void animal_created(Animal const* animal) {
        if (global::debug_flags::ANIMAL_CREATED) {
            string msg = "+ Animal, count is now: " + to_string(Animal::get_animal_count());
            output::debug(msg);
        }
    }

    void animal_destroyed(Animal const* animal) {
        if (global::debug_flags::ANIMAL_DELETED) {
            string msg = "- Animal, count is now: " + to_string(Animal::get_animal_count());
            output::debug(msg);
        }
    }
}

