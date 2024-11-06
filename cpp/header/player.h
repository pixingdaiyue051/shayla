#ifndef SHAYLA_PLAYER_H
#define SHAYLA_PLAYER_H

#include <iostream>

using std::string;

class Player {
private:
    string _firstName;
    string _lastName;
    bool _hasTable;
public:
    explicit Player(const string &firstName = "", const string &lastName = "", bool hasTable = false);

    string getName() const { return _firstName + " " + _lastName; };

    bool hasTable() const { return _hasTable; };

    void resetTable(bool hasTable = false) { _hasTable = hasTable; };

    string getInfo() const;
};

class RatePlayer : public Player {
private:
    unsigned int _rate;
public:
    explicit RatePlayer(unsigned int rate = 0, const string &firstName = "", const string &lastName = "",
                        bool hasTable = false);

    RatePlayer(unsigned int rate, const Player &player);

    unsigned int getRate() const { return _rate; };

    void resetRate(unsigned int rate = 0) { _rate = rate; };

    string getInfo() const;
};

#endif
