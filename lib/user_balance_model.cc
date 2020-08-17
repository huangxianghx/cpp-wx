//
// Created by 黄湘 on 2020/8/17.
//
#include <cstring>
#include "user_balance_model.h"

string UserBalance::getUserId() {
    return userId;
}

double UserBalance::getBalance() {
    return balance;
}

int UserBalance::getVersion() {
    return version;
}

string UserBalance::getUpdateTime() {
    return updateTime;
}

void UserBalance::setUserId(string user_id) {
    userId = user_id;
}

void UserBalance::setBalance(double user_balance) {
    balance = user_balance;
}

void UserBalance::setVersion(int balance_version) {
    version = balance_version;
}
void UserBalance::setUpdateTime(string update_time) {
    updateTime = update_time;
}

