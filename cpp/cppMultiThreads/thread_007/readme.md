## 项目案例线程通信：使用互斥锁和list实现线程通信

### 使用互斥锁+list模拟线程通信
 * 封装线程基类 XThread 控制线程启动和停止
 * 模拟消息服务器线程 接收字符串消息，并模拟处理
 * 通过 unique_lock 和 mutex 互斥访问 list<string> 消息队列
 * 主线程定时发送消息给子线程





