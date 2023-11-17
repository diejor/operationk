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

using namespace std;

class Animal {
   private:
    int type;
    int age;
    int weight;
    string breed;
    string color;
    string health;
    string sound;

    static int animal_count;

   public:
    Animal();
    Animal(int, int, int, string, string, string, string);
    ~Animal();

    int getType();
    int getAge();
    int getWeight();
    string getBreed();
    string getColor();
    string getHealth();
    string getSound();

    static int getAnimalCount();
};

#endif
