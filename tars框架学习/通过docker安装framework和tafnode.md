


##  框架容器化安装

https://doc.tarsyun.com/#/installation/docker.md


参考这个地址说明，手动启动 和安装确实是可以的。



## 1.拉取镜像文件
```shell
docker pull mysql:5.6
docker pull tarscloud/framework:v3.0.20
docker pull tarscloud/tars-node:latest
```

# 2.创建docker虚拟网络
为了方便虚拟机、Mac、Linux 主机等各种环境下的 docker 部署，在本示例中先创建虚拟网络，模拟现实中的局域网内网环境(注意 docker 都还是在同一台机器, 只是 docker 的虚拟 ip 不同, 模拟多机)

### 创建一个名为tars的桥接(bridge)虚拟网络，网关172.25.0.1，网段为172.25.0.0
```shell
docker network create -d bridge --subnet=172.25.0.0/16 --gateway=172.25.0.1 tars
```

### 启动 mysql:5.6 容器
```shell
docker run -d -p 3306:3306 \
    --net=tars \
    -e MYSQL_ROOT_PASSWORD="123456" \
    --ip="172.25.0.2" \
    -v /data/framework-mysql:/var/lib/mysql \
    -v /etc/localtime:/etc/localtime \
    --name=tars-mysql \
    mysql:5.6
```

为了验证 MySQL 是否正常启动且能正常连接，可通过 host 中的 mysql 客户端进行登录验证
```shell
mysql -h 172.25.0.2 -u root -p
```

### 启动框架  tarscloud/framework:v3.0.20  容器
```shell
# 挂载的/etc/localtime是用来设置容器时区的，若没有可以去掉
# 3000端口为web程序端口
# 3001端口为web授权相关服务端口(docker>=v2.4.7可以不暴露该端口)
docker run -d \
    --name=tars-framework \
    --net=tars \
    -e MYSQL_HOST="172.25.0.2" \
    -e MYSQL_ROOT_PASSWORD="123456" \
    -e MYSQL_USER=root \
    -e MYSQL_PORT=3306 \
    -e REBUILD=false \
    -e INET=eth0 \
    -e SLAVE=false \
    --ip="172.25.0.3" \
    -v /data/framework:/data/tars \
    -v /etc/localtime:/etc/localtime \
    -p 3000:3000 \
    -p 3001:3001 \
    tarscloud/framework:v3.0.20
```


### 启动 tars-node 容器
```shell
docker run -d \
    --name=tars-node \
    --net=tars \
    -e INET=eth0 \
    -e WEB_HOST="http://172.25.0.3:3000" \
    --ip="172.25.0.5" \
    -v /data/tars:/data/tars \
    -v /etc/localtime:/etc/localtime \
    -p 9000-9010:9000-9010 \
    tarscloud/tars-node:latest
```

安装完毕后, 访问 http://${your_machine_ip}:3000 打开 web 管理平台

浏览器最好是chrome ，打开的时候，要先配置密码；
用户名 默认是 admin 
然后用这个账号登录，登录之后，在web页面，要给这个用户 授予一些权限（web页面里面可以找到），然后就ok了。






