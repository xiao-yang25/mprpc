# mprpc分布式网络通信框架
mprpc可以实现不同进程间的函数调用需求，使得一个进程调用另一个进程的函数可以像调用同一个进程地址空间的函数一样方便。
## 技术栈
***
* 在通讯协议上，采用protobuf实现数据的序列化和反序列化。
* 网络通信层基于muduo网络库，负责监听客户端的连接以及与客户端的通讯处理。向下调用 Linux socket系统调用完成TCP数据通信，向上把接收到的数据反馈给Rpc应用层以及发送来自Rpc层的数据。
* 使用ZooKeeper作为服务配置中心，来实现服务注册/查询等功能。

## 项目代码工程目录
***
* bin：可执行文件
* build：项目编译文件
* lib：项目库文件
* src：源文件
* test：测试代码
* example：框架代码使用范例
* CMakeLists.txt：顶层的cmake文件
* README.md：项目自述文件
* autobuild.sh：一键编译脚本

## 需要配置的环境
***
* protobuf
* muduo
* ZooKeeper
