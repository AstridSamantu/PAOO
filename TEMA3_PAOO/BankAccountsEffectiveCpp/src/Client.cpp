#include "../inc/Client.hpp"
#include <utility>

Client::Client(std::string name, int id) : name_(std::move(name)), id_(id) {}
Client::Client(const Client& other) : name_(other.name_), id_(other.id_) {}
Client& Client::operator=(const Client& other) {
    if (this != &other) {
        name_ = other.name_;
        id_ = other.id_;
    }
    return *this;
}
const std::string& Client::name() const { return name_; }
int Client::id() const { return id_; }

PremiumClient::PremiumClient(std::string name, int id, int creditLimit, std::string tier)
    : Client(std::move(name), id), creditLimit_(creditLimit), tier_(std::move(tier)) {}
PremiumClient::PremiumClient(const PremiumClient& other)
    : Client(other), creditLimit_(other.creditLimit_), tier_(other.tier_) {}
PremiumClient& PremiumClient::operator=(const PremiumClient& other) {
    if (this != &other) {
        Client::operator=(other); // copiem partea de baza
        creditLimit_ = other.creditLimit_;
        tier_ = other.tier_;
    }
    return *this;
}
int PremiumClient::creditLimit() const { return creditLimit_; }
const std::string& PremiumClient::tier() const { return tier_; }
