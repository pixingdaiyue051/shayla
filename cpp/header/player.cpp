#include "player.h"

Player::Player(const string &firstName, const string &lastName, bool hasTable) : _firstName(firstName),
                                                                                 _lastName(lastName),
                                                                                 _hasTable(hasTable) {
    std::cout << "player constructor" << std::endl;
}

string Player::getInfo() const {
    return _firstName + _lastName + (_hasTable ? "1" : "0");
}

RatePlayer::RatePlayer(unsigned int rate, const string &firstName, const string &lastName, bool hasTable) : _rate(rate),
                                                                                                            Player(firstName,
                                                                                                                   lastName,
                                                                                                                   hasTable) {

    std::cout << "RatePlayer constructor" << std::endl;
}

RatePlayer::RatePlayer(unsigned int rate, const Player &player) : _rate(rate), Player(player) {
    std::cout << "RatePlayer constructor player" << std::endl;

}

string RatePlayer::getInfo() const {
    return getName() + (_rate > 1 ? "9" : "8");
}
