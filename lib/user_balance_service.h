//
// Created by 黄湘 on 2020/8/2.
//

#ifndef CPP_STUDY_USER_SERVICE_H
#define CPP_STUDY_USER_SERVICE_H
#include "user_balance_dao.h"

/**
 * 充值请求
 */
class ChargeRequest{

};

/**
 * 消费请求
 */
class ConsumeRequest{

};

/**
 * 查询余额请求
 */
class QueryBalanceRequest{

};

/**
 * 查询订单请求
 */
class QueryOrderRequest{

};

class UserBalanceService {
public:
    /**
     * 充值
     * @param chargeRequest
     * @return
     */
    int charge(ChargeRequest chargeRequest);
    /**
     * 消费
     * @param consumeRequest
     * @return
     */
    int consume(ConsumeRequest consumeRequest);
    /**
     * 查询余额
     * @param queryBalanceRequest
     * @return
     */
    int queryBalance(QueryBalanceRequest queryBalanceRequest);
    /**
     * 查询订单
     * @param queryOrderRequest
     * @return
     */
    int queryOrder(QueryOrderRequest queryOrderRequest);
};
#endif //CPP_STUDY_USER_SERVICE_H
