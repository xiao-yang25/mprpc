#include<iostream>
#include"test.pb.h"
#include<string>
using namespace fixbug;


int main()
{
    // LoginRespose rsp;
    // ResultCode *rc = rsp.mutable_result();
    // rc->set_errcode(1);
    // rc->set_errmsg("失败");

    GetFriendListsResponse rsp;
    ResultCode *rc = rsp.mutable_result();
    rc->set_errcode(0);
    
    User *user1 = rsp.add_friend_list();
    user1->set_name("zhang san");
    user1->set_age(20);
    user1->set_sex(User::MAN);

    User *user2 = rsp.add_friend_list();
    user2->set_name("li si");
    user2->set_age(20);
    user2->set_sex(User::MAN);

    std::cout << rsp.friend_list_size() << std::endl;

    
}
int main1()
{

    //封装了login请求对象的数据
    LoginRequest req;
    req.set_name("zhangsan");
    req.set_pwd("123456");

    //对象数据序列化
    std::string send_str;
    if(req.SerializeToString(&send_str)){
        std::cout << send_str.c_str() << std::endl;
    }

    //从send_str反序列化
    LoginRequest reqb;
    if( reqb.ParseFromString(send_str)){
        std::cout << reqb.name() << std::endl;
        std::cout << reqb.pwd() << std::endl;
    }

    return 0;

    
}
