/*
 * Main application
 *  * file: main.cpp
 *   * author: Diego R.R.
 *    * started: 11/15/2023
 *     * course: CS2337.501
 *      *
 *       * Purpose: The entry point of the application which handles the execution 
 *        * flow including parsing animal data, creating reports, and cleaning up.
 *         *
 *          * Changelog:
 *           *  - 11/15/2023 - Main application structure created
 *            *  - 11/16/2023 - Added report functions
 *            *  - 11/17/2023 - Added report functions to cfile 
 *            *  - 11/18/2023 - improved edge cases
 *            *  - 11/19/2023 - added comments
 *             *
 *              * Notes:
 *              *  - the tree of the project is as follows:
 *              ├── HW 6 - Operation Kindness.csv
 *              ├── output.txt
 *              ├── src
 *              │   ├── animals
 *              │   │   ├── animal.cpp
 *              │   │   ├── animal.hpp
 *              │   │   ├── cat.cpp
 *              │   │   ├── cat.hpp
 *              │   │   ├── dog.cpp
 *              │   │   └── dog.hpp
 *              │   ├── app
 *              │   │   └── main.cpp
 *              │   └── utils
 *              │       ├── global.hpp
 *              │       ├── input.hpp
 *              │       ├── output.hpp
 *              │       └── parser.hpp
 *              */

#include <string>
#include <vector>
#include <iostream>

// utils
#include "input.hpp"
#include "output.hpp"
#include "parser.hpp"

// animals
#include "animal.hpp"
#include "cat.hpp"
#include "dog.hpp"

using namespace std;

namespace debug {
    void print_vector(vector<Animal*> animals) {
        if (global::debug_flags::PRINT_VECTOR) {
            output::debug("Printing vector of animals ...");
            for (Animal* animal : animals) {
                output::debug(animal->to_csv());
            }
        }
    }
}

/*
 * Parses the tokens from the csv file and creates the Animals
 * * @param tokens: the tokens from the csv out_file
 * * @param animals: the vector of animals to be populated
 * * @param dogs: the vector of dogs to be populated 
 * * @param cats: the vector of cats to be populated 
 * */
void parse_animals(
        vector<string> tokens, 
        vector<Animal*>& animals,
        vector<Dog*>& dogs,
        vector<Cat*>& cats)
{
    output::inform("Getting animals from file ...");
    // first csv is just formatting info
    tokens.erase(tokens.begin());

    for (string csv_line : tokens) {
        vector<string> animal_data = Animal::get_atributes(csv_line);
        string animal_type = animal_data[0];

        if (global::fncs::contains(animal_type, "cat")) {
            Cat* cat = new Cat(animal_data);
            animals.push_back(cat);
            cats.push_back(cat);
        } else if (global::fncs::contains(animal_type, "dog")) {
            Dog* dog = new Dog(animal_data);
            animals.push_back(dog);
            dogs.push_back(dog);
        } else {
            Animal* animal = new Animal(animal_data);
            animals.push_back(animal);
        }
    }

    output::inform("Animals gotten.");
    debug::print_vector(animals);
    output::separate();
}

void delete_animals(
        vector<Animal*> animals,
        vector<Dog*> dogs,
        vector<Cat*> cats)
{
    output::inform("Deleting animals ...");
    for (Animal* animal : animals) {
        delete animal;
    }

    for (Dog* dog : dogs) {
        delete dog;
    }

    for (Cat* cat : cats) {
        delete cat;
    }

    output::inform("Animals deleted.");
}

void report1(ostream& out) {
    out << "### REPORT 1: Number of Animals" << endl;
    out << "  - Total number of animals: " << Animal::get_animal_count() << endl;
    out << "  - Total number of dogs: " << Dog::get_dog_count() << endl;
    out << "  - Total number of cats: " << Cat::get_cat_count() << endl;
    out << endl;
}

void report2(ostream& out, vector<Animal*> const& animals) {
    out << "### REPORT 2: Animals" << endl;
    for (Animal* animal : animals) {
        animal->introduce(out);
    }
    out << endl;
}

void report3(ostream& out, vector<Dog*> const& animals) {
    out << "### REPORT 3: Dogs" << endl;
    for (Dog* dog : animals) {
        dog->introduce(out);
    }
    out << endl;
}

void report4(ostream& out, vector<Cat*> const& animals) {
    out << "# REPORT 4: Cats" << endl;
    for (Cat* cat : animals) {
        cat->introduce(out);
    }
    out << endl;
}

int main() {

    // animals found
    vector<Animal*> animals;   
    vector<Dog*> dogs;
    vector<Cat*> cats;

    // read animals from file 
    ifstream file = input::get_input();
    vector<string> tokens = parser::consume_file(file);   
    parse_animals(tokens, animals, dogs, cats);

    // reports to console
    report1(cout);
    report2(cout, animals);
    report3(cout, dogs);
    report4(cout, cats);

    // reports to file
    ofstream out_file("output.txt");
    report1(out_file);
    report2(out_file, animals);
    report3(out_file, dogs);
    report4(out_file, cats);

    // delete Animals
    delete_animals(animals, dogs, cats);
    return 0;
}
