#include "player.h"

using std::cout;
using std::endl;

Player::Player(const string &firstName, const string &lastName, bool hasTable) : _firstName(firstName),
                                                                                 _lastName(lastName),
                                                                                 _hasTable(hasTable) {
    cout << "player constructor" << endl;
}

Player::~Player() {
    cout << "player destructor" << endl;
}

string Player::getInfo() const {
    return getName() + (_hasTable ? "1" : "0");
}

RatePlayer::RatePlayer(unsigned int rate, const string &firstName, const string &lastName, bool hasTable) : _rate(rate),
                                                                                                            Player(firstName,
                                                                                                                   lastName,
                                                                                                                   hasTable) {

    cout << "RatePlayer constructor" << endl;
}

RatePlayer::RatePlayer(unsigned int rate, const Player &player) : _rate(rate), Player(player) {
    cout << "RatePlayer constructor player" << endl;

}

RatePlayer::~RatePlayer() {
    cout << "RatePlayer destructor" << endl;
}

string RatePlayer::getInfo() const {
    return getName() + (_rate > 1 ? "9" : "8");
}

BaseBrass::Formatter BaseBrass::getFormatter() const {
    Formatter f{};
    f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
    f.size = cout.precision(2);
    return f;
}

void BaseBrass::resetFormatter(BaseBrass::Formatter &f) const {
    cout.setf(f.flag, ios_base::floatfield);
    cout.precision(f.size);
}

BaseBrass::BaseBrass(const string &fullName, long account, double balance) {
    _fullName = fullName;
    _account = account;
    _balance = balance;
}

void BaseBrass::withdraw(double balance) {
    _balance -= balance;
}

void Brass::withdraw(double balance) {
    if (balance > getBalance()) {
        cout << "over the max balance" << endl;
        return;
    }
    BaseBrass::withdraw(balance);
}

void Brass::viewAccount() const {
    Formatter f = getFormatter();
    cout << "client fullName:" << getFullName() << endl;
    cout << "client account:" << getAccount() << endl;
    cout << "client balance:" << getBalance() << endl;
    resetFormatter(f);
}

void BrassPlus::withdraw(double balance) {
    Formatter f = getFormatter();
    double ownBalance = getBalance();
    double tmp = ownBalance + _maxLoan - _owesBank;
    if (balance <= ownBalance) {
        BaseBrass::withdraw(balance);
    } else if (balance <= tmp) {
        tmp = balance - ownBalance;
        _owesBank += tmp * (1.0 + _rate);
        deposit(tmp);
        BaseBrass::withdraw(balance);
    } else {
        cout << "over the max balance" << endl;
    }
    resetFormatter(f);
}

void BrassPlus::viewAccount() const {
    Formatter f = getFormatter();
    cout << "client fullName:" << getFullName() << endl;
    cout << "client account:" << getAccount() << endl;
    cout << "client balance:" << getBalance() << endl;
    cout << "client maxLoan:" << _maxLoan << endl;
    cout << "client owesBank:" << _owesBank << endl;
    cout.precision(3);
    cout << "client rate:" << 100 * _rate << endl;
    resetFormatter(f);
}