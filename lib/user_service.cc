//
// Created by 黄湘 on 2020/7/24.
//
#include <iostream>
#include "user_dao.h"
#include "user_service.h"

using namespace std;

/**
 * 注册用户
 * @param user
 * @return
 */
int UserService::registerUser(User user) {
    cout << "register user" <<endl;
    cout << "userName:" << user.getUserName() << endl;
    cout << "loginNo:" << user.getLoginNo() << endl;
    cout << "password:" << user.getPassword() << endl;
    UserDao userDao;
    // 判断用户是否存在
    if(userDao.isUserExit(user)){
        return 0;
    }
    userDao.insertUser(user);
    return 1;
}

int UserService::login(User user) {
    cout << "login" << endl;
    return 0;
}

