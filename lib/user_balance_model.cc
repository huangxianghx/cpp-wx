//
// Created by 黄湘 on 2020/8/17.
//
#include "user_balance_model.h"

std::string UserBalance::getUserId() {
    return userId;
}

double UserBalance::getBalance() {
    return balance;
}

int UserBalance::getVersion() {
    return version;
}

std::string UserBalance::getUpdateTime() {
    return updateTime;
}

void UserBalance::setUserId(std::string user_id) {
    userId = user_id;
}

void UserBalance::setBalance(double user_balance) {
    balance = user_balance;
}

void UserBalance::setVersion(int balance_version) {
    version = balance_version;
}
void UserBalance::setUpdateTime(std::string update_time) {
    updateTime = update_time;
}

