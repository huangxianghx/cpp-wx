//
// Created by 黄湘 on 2020/7/24.
//
#include <iostream>
#include "user_balance_dao.h"
#include "user_balance_service.h"

using namespace std;

// 创建dao服务
UserBalanceDao userBalanceDao;

/**
 * 充值
 * @param chargeRequest
 * @return
 */
int UserBalanceService::charge(ChargeRequest chargeRequest) {
    cout << "charge" <<endl;
    return 0;
}

/**
 * 消费
 * @param consumeRequest
 * @return
 */
int UserBalanceService::consume(ConsumeRequest consumeRequest) {
    cout << "consume" << endl;
    return 0;
}

/**
 * 查询余额
 * @param queryBalanceRequest
 * @return
 */
int UserBalanceService::queryBalance(QueryBalanceRequest queryBalanceRequest) {
    cout << "queryBalance" << endl;
    return 0;
}

/**
 * 查询订单
 * @param queryOrderRequest
 * @return
 */
int UserBalanceService::queryOrder(QueryOrderRequest queryOrderRequest) {
    cout << "queryOrder" << endl;
    return 0;
}

