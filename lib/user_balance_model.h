//
// Created by 黄湘 on 2020/8/17.
//

#ifndef CPP_WX_USER_BALANCE_MODEL_H
#define CPP_WX_USER_BALANCE_MODEL_H
#include <cstring>

/**
 * 用户余额对象
 */
class UserBalance{
public:
    string getUserId();
    double getBalance();
    int getVersion();
    string getUpdateTime();
    void setUserId(string userId);
    void setBalance(double balance);
    void setVersion(int version);
    void setUpdateTime(string updateTime);

private:
    string userId;
    double balance;
    int version;
    string updateTime;
};
#endif //CPP_WX_USER_BALANCE_MODEL_H
