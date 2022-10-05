#include<iostream>
#include<string>
#include "friend.pb.h"
#include "mprpcapplication.h"
#include "rpcprovider.h"
#include<vector>
#include "logger.h"

class FriendService : public fixbug::FriendServiceRpc
{
public:
    std::vector<std::string> GetFriendsList(uint32_t userid)
    {
        std::cout << "do GetFriendsList service! userid: " << userid << std::endl ;
        std::vector<std::string> vec;
        vec.push_back("li si");
        vec.push_back("wang wu");
        vec.push_back("zhao liu");
        return vec;

    }
    //重写基类方法
    void GetFriendsList(::google::protobuf::RpcController* controller,
                       const ::fixbug::GetFriendsListRequest* request,
                       ::fixbug::GetFriendsListResponse* response,
                       ::google::protobuf::Closure* done)
    {
        uint32_t userid = request->userid();
        std::vector<std::string> friendsList = GetFriendsList(userid);
        response->mutable_result()->set_errcode(0);
        response->mutable_result()->set_errmsg("");
        for(std::string &name : friendsList)
        {
            std::string *p = response->add_friends();
            *p = name;
        }

        done->Run();
        

    }

};

int main(int argc,char **argv)
{
    
    //调用框架的初始化操作  provider -i config.conf
    MprpcApplication::Init(argc, argv);

    //provider是一个rpc网络服务对象，把Userservice服务发布到rpc节点上

    RpcProvider provider;
    provider.NotifyService(new FriendService());//发布服务

    //启动一个rpc服务发布节点， run以后，进程进入阻塞状态，等待远程的rpc调用请求
    provider.Run();

    return 0;
}