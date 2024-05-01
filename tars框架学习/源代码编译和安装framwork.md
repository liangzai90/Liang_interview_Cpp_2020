

## framework框架里面 

```shell
sh build.sh all # 编译框架
sudo sh build.sh install # 安装框架
```


##  框架的基础目录
/usr/local/tars/cpp/deploy


### 框架的工具 安装目录
/usr/local/tars/cpp/tools

## 框架自带的若干程序 目录 
/usr/local/tars/cpp/deploy/framework/servers

## sql语句目录 
/usr/local/tars/cpp/deploy/framework/sql


# 框架自带的若干程序 启动的脚本
/usr/local/tars/cpp/deploy/framework/util-linux

# 若干 配置文件路径
/usr/local/tars/cpp/deploy/framework/conf/


# 框架需要的第三方库
/usr/local/tars/cpp/thirdparty/lib64

/usr/local/tars/cpp/thirdparty/lib

/usr/local/tars/cpp/thirdparty/include

/usr/local/tars/cpp/lib/

/usr/local/tars/cpp/lib64


## 框架基础类的 头文件 目录
/usr/local/tars/cpp/include/util

/usr/local/tars/cpp/include/

# 框架自带的程序的 协议文件
/home/tarsproto/protocol/

/usr/local/tars/cpp/include/framework/



```shell
/usr/local/tars/cpp/script/cmake_tars_server.sh  APP  Server  Servant 
```

eg: 生成一个工程
```shell
/usr/local/tars/cpp/script/cmake_tars_server.sh  Test  HenryS1Server  henryS1Interface 
```

修改了协议文件之后，重新生成协议文件对应的 .h 文件
```shell
/usr/local/tars/cpp/tools/tars2cpp  henryS1Interface.tars  

```
