#pragma once
#include <string>

class Client {
protected:
    std::string name_;
    int id_;
public:
    Client(std::string name = "", int id = 0);
    Client(const Client& other);
    Client& operator=(const Client& other);
    virtual ~Client() = default;
    const std::string& name() const;
    int id() const;
};

class PremiumClient : public Client {
    int creditLimit_;
    std::string tier_;
public:
    PremiumClient(std::string name = "", int id = 0,
                  int creditLimit = 0, std::string tier = "Standard");
    PremiumClient(const PremiumClient& other);
    PremiumClient& operator=(const PremiumClient& other);
    int creditLimit() const;
    const std::string& tier() const;
};
