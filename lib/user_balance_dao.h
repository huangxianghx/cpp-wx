//
// Created by 黄湘 on 2020/8/2.
//

#ifndef CPP_STUDY_USER_DAO_H
#define CPP_STUDY_USER_DAO_H

#include <cstring>
#include <user_balance_model.h>

using namespace std;

/**
 * 数据库操作
 */
class UserBalanceDao {
public:
    /**
     * 创建用户余额
     * @param userBalance
     * @return
     */
    bool createUserBalance(UserBalance userBalance);
    /**
     * 更新用户余额
     * @param userBalance
     * @return
     */
    int updateUserBalance(UserBalance userBalance);
    /**
     * 查询用户余额
     * @param userBalance
     * @return
     */
    int queryUserBalance(UserBalance userBalance);
};
#endif //CPP_STUDY_USER_DAO_H
