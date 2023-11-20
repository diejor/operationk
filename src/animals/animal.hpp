/*
 * Animal class
 * file: animal.hpp
 * author: Diego R.R.
 * started: 11/15/2023
 * course: CS2337.501
 *
 * Purpose: compilates the experiments that can be run with the chaos game.
 *
 * Changelog:
 *  - 11/15/2023 - header file created
 *  - 11/16/2023 - defined the Animal class
 *
 * Notes:
 *  
 */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <vector>

using namespace std;

const vector<string> default_atributes = 
    {"alien", "Paquito", "non-binary", "5", "8", "unknown", "green-explosion", 
        "biohazard", "We come in peace"};

class Cat;

class Animal {
   protected:
    string type;
    string name;
    string sex;
    int age;
    int weight;
    string breed;
    string color;
    string health;
    string sound;

    // identification
    static int animal_count;
    int animal_id;

   public:
    Animal();
    Animal(vector<string> const& atributes);
    ~Animal();

    string get_type() const;
    string get_name() const;
    string get_sex() const;
    int get_age() const;
    int get_weight() const;
    string get_breed() const;
    string get_color() const;
    string get_health() const;
    string speak() const;

    static int get_animal_count();
    int get_animal_id() const;

    void introduce(ostream& out) const;

    static vector<string> get_atributes(string csv);

    string to_csv() const;
};

namespace debug {
    void animal_created(Animal const* animal);
    void animal_destroyed(Animal const* animal);
}


#endif
