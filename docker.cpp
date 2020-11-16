高山仰止，止于至善。
service docker restart//重启docker服务

//在ubuntu:15.10容器里运行应用
//Docker 首先从本地主机上查找镜像是否存在，如果不存在，Docker 就会从镜像仓库Docker Hub下载公共镜像。(已改aliyun)
docker run ubuntu:15.10 /bin/echo "Hello world" 
ctrl + D //退出容器,并不会停止容器，容器以后台运行
docker exec //退出容器，不会停止容器
docker attach //进入容器
docker ps //显示正在运行的容器信息，不是镜像
docker ps -a //显示本机所有存在的容器，不是镜像
docker logs 容器ID(/容器name）//显示容器日志
docker stop 容器ID(/容器name）//停止正在运行的容器
docker start 容器ID(/容器name）//运行一个已经停止的容器
docker //客户端执行一览

docker run -it ubuntu /bin/bash //-i，交互式操作，-t终端。
-itd //-d以后台模式运行
docker export 容器ID(/容器name） > ubuntu.tar //把指定容器导出为一个.tar格式
docker load < media_server.rar //将.rar加载为一个镜像


cat ubuntu.tar | docker import - myubuntu //将名叫myubuntu的镜像添加进来，若有"/"，不表路径，表示名字
//通过URL导入镜像
docker import http://example.com/exampleimage.tgz example/imagerepo
docker rm -f 1e560fca3906 //删除容器，不删除镜像
docker container prune //删除掉所有处于终止状态的容器
docker top 容器ID(/容器name） //查看容器运行所在的进程
docker ps -l //查询最后一次创建的容器

//镜像
//本地主机上的镜像，每个repository可以有不同的版本，引用不同版本时：repository:tag
//若不指定则默认使用repository:latest
docker images 
docker search //搜索镜像，也可在hub.docker.com中获取。
docker pull //下载镜像
docker rmi //删除镜像，不指定版本则默认删除最新版本

//数据卷
docker run -itd --name nginx -v /docker/nginx/:/usr/share/nginx/html/ -p 80:80 nginx
docker run -it -v  /宿主机绝对路径目录:/容器内目录  镜像名
//一个容器打开两个终端
docker exec -it cd3b79a85d7e /bin/bash





