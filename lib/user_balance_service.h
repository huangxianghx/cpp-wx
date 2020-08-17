//
// Created by 黄湘 on 2020/8/2.
//

#ifndef CPP_STUDY_USER_SERVICE_H
#define CPP_STUDY_USER_SERVICE_H
#include "user_balance_dao.h"


class UserBalanceService {
public:
    /**
     * 充值
     * @param userId
     * @param orderId
     * @param amount
     * @return
     */
    int charge(string userId, string orderId, double amount);
    /**
     * 消费
     * @param userId
     * @param orderId
     * @param amount
     * @return
     */
    int consume(string userId, string orderId, double amount);
    /**
     * 查询余额
     * @param userId
     * @return
     */
    int queryBalance(string userId);
    /**
     * 查询订单
     * @param userId
     * @param orderId
     * @return
     */
    int queryOrder(string userId, string orderId);
};
#endif //CPP_STUDY_USER_SERVICE_H
