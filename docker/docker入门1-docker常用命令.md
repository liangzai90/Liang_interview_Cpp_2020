
# 记录一些docker 常用命令


### docker常用命令
s
```shell

# 列出所有容器（包括未启动的容器）
docker ps -a 

# 列出正在运行的容器
docker ps 

# 启动容器
docker start 容器id

# 停止容器
docker stop 容器id

# 删除容器
docker rm 容器id

# 列出所有镜像
docker images

### 特别注意 镜像 和容器的关系，删除镜像和删除容器是不同的意思。
# 删除镜像 
docker rmi 镜像id

# 查看容器详细信息
docker inspect 容器id

# 查看容器端口映射
docker inspect 容器id | grep Exposed

# 查看容器stats 包括cpu,内存，存储，网络等信息
docker stats 容器id

# 查看容器日志
docker logs 容器id

# 启动容器并进入容器
docker run -it 镜像id /bin/bash

# 进入已启动的容器
docker exec -it 容器id /bin/bash

# 从宿主机拷贝文件到 容器
docker cp 宿主机文件路径+文件名  容器id:容器内文件路径
# 从容器拷贝文件到宿主机
docker cp 容器id:容器内文件路径+文件名 宿主机文件路径



```



### /etc/docker/daemon.json 配置 docker的镜像地址
```json
{
  "debug":true,
  "registry-mirrors": [
    "https://hub-mirror.c.163.com",
    "https://dockerproxy.com",
    "https://mirror.baidubce.com",
    "https://ccr.ccs.tencentyun.com",
    "https://docker.m.daocloud.io"
     ]

}
```





