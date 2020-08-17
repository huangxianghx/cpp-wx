//
// Created by 黄湘 on 2020/8/17.
//

#ifndef CPP_WX_USER_BALANCE_MODEL_H
#define CPP_WX_USER_BALANCE_MODEL_H
/**
 * 用户余额对象
 */
class UserBalance{
public:
    std::string getUserId();
    double getBalance();
    int getVersion();
    std::string getUpdateTime();
    void setUserId(std::string userId);
    void setBalance(double balance);
    void setVersion(int version);
    void setUpdateTime(std::string updateTime);

private:
    std::string userId;
    double balance;
    int version;
    std::string updateTime;
};
#endif //CPP_WX_USER_BALANCE_MODEL_H
