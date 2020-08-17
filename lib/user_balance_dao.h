//
// Created by 黄湘 on 2020/8/2.
//

#ifndef CPP_STUDY_USER_DAO_H
#define CPP_STUDY_USER_DAO_H

#include <cstring>
#include "user_balance_model.h"

using namespace std;

/**
 * 数据库操作
 */
class UserBalanceDao {
public:
    /**
     * 创建用户余额
     * @param userId
     * @return
     */
    bool createUserBalance(string userId);
    /**
     * 更新用户余额
     * @param userId
     * @param amount
     * @return
     */
    bool updateUserBalance(String userId,double amount);
    /**
     * 查询用户余额
     * @param userId
     * @return
     */
    UserBalance queryUserBalance(string userId);
};
#endif //CPP_STUDY_USER_DAO_H
