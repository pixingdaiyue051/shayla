#ifndef SHAYLA_PLAYER_H
#define SHAYLA_PLAYER_H

#include <iostream>

using std::ios_base;
using std::string;
const double DEFAULT_RATE = 0.1125;

class Player {
private:
    string _firstName;
    string _lastName;
    bool _hasTable;
public:
    explicit Player(const string &firstName = "", const string &lastName = "", bool hasTable = false);

    virtual ~Player();

    string getName() const { return _firstName + _lastName; }

    bool hasTable() const { return _hasTable; }

    void resetTable(bool hasTable = false) { _hasTable = hasTable; }

    virtual string getInfo() const;
};

class RatePlayer : public Player {
private:
    unsigned int _rate;
public:
    explicit RatePlayer(unsigned int rate = 0, const string &firstName = "", const string &lastName = "",
                        bool hasTable = false);

    RatePlayer(unsigned int rate, const Player &player);

    ~RatePlayer() override;

    unsigned int getRate() const { return _rate; }

    void resetRate(unsigned int rate = 0) { _rate = rate; }

    string getInfo() const override;
};

class BaseBrass {
private:
    string _fullName; // 账号名
    long _account; // 账户号
    double _balance; // 余额
protected:
    struct Formatter {
        ios_base::fmtflags flag;
        std::streamsize size;
    };

    const string &getFullName() const { return _fullName; }

    long getAccount() const { return _account; }

    double getBalance() const { return _balance; }

    Formatter getFormatter() const;

    void resetFormatter(Formatter &f) const;

public:
    explicit BaseBrass(const string &fullName = "", long account = 0, double balance = 0.0);

    virtual ~BaseBrass() = default;

    void deposit(double balance) { _balance += balance; } // 存款
    virtual void withdraw(double balance) = 0; // 取款
    virtual void viewAccount() const = 0; // 查看账户详情
};

/**
 * 普通账户
 */
class Brass : public BaseBrass {
public:
    explicit Brass(const string &fullName = "", long account = 0, double balance = 0.0) : BaseBrass(fullName, account,
                                                                                                    balance) {}

    ~Brass() override = default;

    void withdraw(double balance) override; // 取款
    void viewAccount() const override; // 查看账户详情
};

/**
 * 会员
 */
class BrassPlus : public BaseBrass {
private:
    double _maxLoan;
    double _rate;
    double _owesBank;
public:
    explicit BrassPlus(const string &fullName = "", long account = 0, double balance = 0.0, double maxLoan = 0.0,
                       double rate = DEFAULT_RATE, double owesBank = 0.0) : BaseBrass(fullName, account, balance),
                                                                            _maxLoan(maxLoan), _rate(rate),
                                                                            _owesBank(owesBank) {}

    ~BrassPlus() override = default;

    void withdraw(double balance) override; // 取款
    void viewAccount() const override; // 查看账户详情
    void resetMaxLoan(double maxLoan) { _maxLoan = maxLoan; }

    void resetRate(double rate) { _rate = rate; }

    void resetOwesBank(double owesBank) { _owesBank = owesBank; }
};

#endif
