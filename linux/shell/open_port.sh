#!/bin/bash  
  
# 检查参数数量  
if [ "$#" -ne 1 ]; then  
    echo "Usage: $0 <port_number>"  
    exit 1  
fi  
  
# 获取端口号  
PORT=$1  
  
# 检查端口号是否为数字  
if ! [[ "$PORT" =~ ^[0-9]+$ ]]; then  
    echo "Error: Port number must be a positive integer."  
    exit 1  
fi  
  
# 开放端口  
sudo firewall-cmd --zone=public --add-port=$PORT/tcp --permanent  
  
# 重新加载防火墙配置  
sudo firewall-cmd --reload  
  
# 检查端口是否已开放  
if sudo firewall-cmd --zone=public --query-port=$PORT/tcp; then  
    echo "Port $PORT has been opened successfully."  
else  
    echo "Failed to open port $PORT."  
    exit 1  
fi