## 基于线程池实现音视频批量转码测试任务

========== windows 转码格式 ==========
```shell
ffmpeg -y -i test.mp4 -s 400x300 400.mp4 > log.txt 2>&1
```

 
========== centos7 转码格式 ==========
```shell
ffmpeg -i test.mp4 -vf "scale=400:300" 400.mp4
```


