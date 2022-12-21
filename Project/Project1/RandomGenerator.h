#pragma once

#include <iostream>
#include <memory>
using namespace std;

class RandomGenerator {
private:
    inline static shared_ptr<RandomGenerator> _instance = NULL;
    RandomGenerator();

public:
    static shared_ptr<RandomGenerator> instance() {
        if (_instance == NULL) {
            RandomGenerator* temp = new RandomGenerator();
            _instance = shared_ptr<RandomGenerator>(temp);
        }

        return _instance;
    }
public:
    ~RandomGenerator();
public:
    int next();
    int next(int);
    int next(int, int);
};
