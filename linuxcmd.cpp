//知止而后有定，静而后能安。
//192.168.17.86

//可以以树形显示目录结构
install apt install tree


//查看opence版本
pkg-config opencv --modversion

//创建文件,并打开编辑
gedit 文件名

//显示目录文件
ls [选项] [文件或目录]
-a 显示所有文件，包括隐藏文件
-l 详细信息显示
-d 查看目录属性 //加上-d则显示目录
-h 文件大小以Kb,Mb来显示

//创建目录
mkdir -p 目录名
-p 递归创建

//切换目录
cd [目录]
可以是相对目录和绝对目录
cd .. //返回上一级目录

//赋值文件或目录
cp -rp [原文件或目录] [目标目录]
-r 复制时递归目录中文件
-p 保留文件属性

//剪切，改名
//全称move
mv [原文件或目录] [目标目录]

//删除文件或目录
//全称 remove 
rm -rf [文件或目录]
-r 递归删除目录
-f 强制执行
-d 对目录进行操作

//创建空文件
touch [文件名]
如果文件已存在则摸一下
更新访问时间

//显示文件内容
cat -n [文件名]
-n 显示行号

//分页显示文件内容,不可修改文件
more [文件名]
空格或f翻页
Enter 换行
q或Q退出

//分页显示文件内容，不可修改文件
less [文件名]
具有more的所有功能
且可上下翻页
/内容 进行搜索

//显示文件后面几行
tail [文件名]
-n 指定行数
-f 动态显示文件末尾内容

//改变文件或目录权限
//全称：change the permissions mode of a file
chmod [{ugoa}{+-=}{rwx}][文件或目录]
      [mode=42] [文件或目录]
chmod u+x Japan.cpp
chmod g+w,0-r Japan.cpp
chomd g=rwx Japn.cpp
r---4
w---2
x---1
rwxrw-r--
 7  6  4
chomd 755 Japan.cpp
-R 递归修改

//rwx对目录的意义
对文件来说是读写执行
对文档：
r 可以列出目录中的文件
w 可以在目录中创建，删除文件。
x 可以进入目录


//改变文件或目录的所有者
全称：change file ownership
chown [用户] [文件或目录]
chown shenchao fengjie
改变文件fengjie所有者为shenchao

//改变文件或目录的所属组
全称：change file grop wonership
chgrp [用户组] [文件或目录]
chgrp lampbrother fengjie
改变fengjie的所属组为lampbrother

//显示，设置文件的缺省权限
//the user file-creation mask
umask [-S]
-S 以rwx形式显示新建文件缺省权限
 



//查看和设置网卡信息
全称：interface configure
ifconfig 网卡名称 IP地址
例: ifconfig eth0 192.168.2.122
修改eth0的IP

//测试网络连通性
ping 选项 IP地址
-c 指定发送次数
例：ping 192.168.2.112

//目录处理命令
ls [选项] [文件或文档]
-a 显示所有文件，包括隐藏文件
-l 显示详细信息
-d 查看目录本身
-h 文件大小以Kb为单位

//创建目录
mkdir [选项] [目录名]

//生成链接文件
ln -s [原文件][目标文件]
-s 创建软链接


//安装deb包
sudo dpkg -i sunloginclient-10.1.1.28779-amd64.deb

//文件搜索find
find 路径 [选项] 文件名
-name 按文件名查找
-iname 不区分大小写
find 路径 -size +204800
+n 大于 -n 小于 n 等于
单位为数据块，一个数据块512字节（0.5kb）
在路径下查找大小大于204800的文件
find 路径 -user yqw
在路径下查找所有者为yqw的文件
-group 根据所属组查找
find 路径 [选项] -5
在路径下查找5分钟内被修改过的文件和文档
-amin 修改访问时间
-emin 修改文件属性
-mmin 修改文件内容
-a 两个条件同时满足
-o 两个条件满足一个即可

//文件搜索命令
locate 文件名
在文件资料库中查找资料
需要用updatedb定期更新资料库


//grep在文件中搜索字符串匹配的行，并输出
grep -iv [指定字符串] [文件]
-i 不区分大小写
-v 排除指定字符串
grep -v ^# /etc/inittab

//搜索命令所在目录及别名信息
which 命令

//man页面
1表示命令的帮助
2表示配置文件的帮助

//添加新的用户
useradd 用户名

//设置用户密码
passwd 用户名

//查看用户登录信息
who
tty本地终端 pts远程

//维护时间
uptime


//压缩文件
//原意GUN zip
gzip [文件]
压缩以后的格式.gz

//解压.gz压缩包命令
//原意GUN unzip
gunzip [文件]

//打包目录
tar [选项] [压缩后文件名] [目录]
-c 打包
-v 显示详细信息
-f 指定文件名
-z 打包同时压缩
例：tar -zcf Japan.tar.gz Japan
压缩后的文件格式 .tar.gz

//解压命令
tar [选项] [压缩后文件名] [目录]
-x 解包
-v 显示详细信息
-f 指定解压文件
-z 解压缩
例：tar -zxvf Japan.tar.gz

//解压命令
zip [选项] [压缩后文件名] [文件或文档]
-r 压缩目录
压缩后文件格式 .zip

//解压命令
unzip [压缩文件]
例： unzip test.zip

//压缩文件
bzip2 [选项] [文件]
-k 产生压缩文件后保留原来文件
压缩后文件格式 .bz2
例：bzip2 -k boduo
tar -cjf Japan.tar.bz2 Japan

//解压命令
bunzip2 [选项] [压缩文件]
-k 解压后保留原文件
例：
bunzip2 -k boduo.bz2
tar -xjf Japan.tar.bz2

//测试网络连通性
ping [选项] ip地址
-c 指定发送次数
例：ping 192.168.1.156

//查看和设置网卡信息
ifconfig [网卡名称] [ip地址]
ifconfig eth0 192.168.8.250

//列出目前与过去登录系统的用户信息
last



//定时任务，编辑crontab文件
crontab [选项]
-e:编辑crontab定时任务
-l:查询crontab任务
-r:删除当前用户的所有crontab任务

//重启服务
service 服务名 restart


//查看系统与内核使用情况
uname [选项]
-a:查看系统所有相关信息
-r:查看内核版本
-s:查看内核名称

//查看内存使用情况
free [选项]
-b:以字节为单位显示
-k:以kb显示
-m:以MB显示
-g:以GB显示

//命令监控系统资源
vmstat

//把进程放入后台
//+表示最后一个放入后台的工作
//-表示倒数第二个放入后台的工作
//此方法放入后台后，依然在运行
1.命令 &
//放入后台后，会停止运行
2.在命令的执行过程中，按下ctrl+z快捷键

//把后台暂停的工作恢复到后台执行
bg %工作号

//显示放入后台的工作
jobs [选项]
-l:显示工作的PID

//杀死进程
killal [选项] [信号] 进程名
-i:交互式
-I:忽略进程名的大小写

//查看进程信号
kill -l
//重启进程
kill -1 22354
//强制杀死进程
kill -9 22368



//进程树
pstree [选项]
-p:显示进程的PID
-u:显示进程的所属用户




//执行指令后q键退出
top [ 选项 ]
id: CPU空闲率

//查看系统中所有进程
ps aux

//用于监控TCP/IP网络链接状况
netstat -tlun

//设置一个服务开机自启动命令
//也可以配置开机自启动文件列表
sudo systemctl start mysqld.service

//服务的启动脚本位置
/etc/init.d

//查看服务的启动状态
//+表示运行中，-表示未运行
service --status-all 


until循环，与while相反，当关系不成立时执行，一旦成立则不执行
unitl [ 条件判断式 ]
	do
		程序
	done
until [ $i -gt 100 ]
gt 大于
 
while [ 条件判断式 ]
	do
		程序
	done
例子：
while [ $i -le 100 ] // <= 100
while [ $i -lt 100 ] // < 100

//for循环 语法1
for 变量 in 值1 值2 值3 ...
	do
		程序
	done

//for循环 语法2
for((初始值; 循环控制条件; 变量变化))
	do
		程序
	done

//case分支语句
case $变量 in
"值1")
	值为此，则执行此语句
	;;
"值2")
	值为此，则执行此语句
	;;
*)
	如果值都不是则执行此语句
	;;
esac


ping 119.27.162.114

downgraded

//shell脚本文件
#!/bin/bash

//单分支if条件语句
if [ 条件判断式 ];then
	程序段
fi
或者
if [ 条件判断式 ]
	then
		程序段
	else
		条件不成立执行这个程序
fi

//if多分支语句
if [ 条件判断式1 ]
	then
		语句1
elif [ 条件判断式2 ]
	then
		语句2
	else
		语句3
fi


//sort排序，对一个文件每行排序
sort [选项] 文件名
-f: 忽略大小写
-n: 以数值型进行排序，默认使用字符排序
-r: 反向排序
-t: 指定分隔符
-k n[,m]: 指定行范围排序，从n行开始到m行结束

//wc [选项] 文件名 
-l: 只统计行数
-w: 只统计单词数
-m: 只统计字符数

//test判断
-d: 判断目录文件是否存在，存在为真
-e: 判断文件（包含文本和文档）是否存在，存在为真
-f: 判断文本文件是否存在，存在为真
test -e /root/install.log 
等同于
[-e /root/install.log ]  ([]留有空格)
test也可判断文件是否有读写权限
-z: 判断字符串是否为空(为空返回真)
-n: 判断字符串是否为非空(非空返回真)
字符串1 == 字符串2：判断字符串1和字符串2是否相等
字符串1 != 字符串2：判断字符串1和字符串2是否不等
论断1 -a 论断2：逻辑与，判断1和2都成立则返回真
论断1 -o 论断2：逻辑或，判断1和2有一个成立则为真
!论断：取反

//etc/apt/sources.list 修改源的地址



//sed命令是一个轻量文档编辑器
sed [选项] '[动作]' 文件名
-n: 一般sed会把所有数据输出到屏幕，加入此行只有处理过的行才会显示
-e: 允许对sed命令用多条命令编程
-i: sed的修改保存到文件中去
a\:追加
c\:打印
i\:插入
d: 删除
p: 打印

//一般用在awk中
printf '输出类型输出格式' 输出内容
输出类型：
%ns: 输出字符串，n代表输出几个字符
%ni: 输出整数，n代表输出几个整数
%m.nf输出浮点数，m指代总共有几位，n指小数有几位
输出格式：
\n:换行
\r:回车
\t:制表符，tab键

//awk竖匹配
awk '条件1{动作1} 条件2{动作2}' 文件名
条件：一般使用关系表达式作为条件,条件也可省略，默认执行动作
x > 10
awk默认以制表符和空格为分割符，也可指定分割符号使用内置
变量FS
awk 'BEGIN{FS=":"}{printf $1 "\t" $3 "\n"}'

//grep命令，行匹配
grep [选项] "搜索内容" 文件名
-i: 忽略大小写
-n: 输出行号
-v: 反向查找
--color=auto 搜索出的关键字用颜色显示

//cut命令 竖匹配
cut [选项] 文件名
-f 列好：提取第几列的内容
-d 分隔符：按照指定分隔符分割列
cut默认以制表符为分割符


//正则匹配(用来匹配文件中内容分)
*:前一个字符匹配0次或任意多次
.:匹配除了换行符外任意一个字符
^:匹配行首, ^hello会匹配以hello开头的行
$:匹配行尾
[]:匹配中括号中指定的任意一个字符
[^]:^表示取反
\:转移符
\{n\}:表示其前面的字符恰好出现n次
\{n,m\}:表示至少出现n次，最多出现m次

[a-zA-Z]:表示以字母开头的任一个字符

~/bash_history //记录已执行的shell命令
~/.bash_logout //注销时生效的环境变量配置文件


//修改配置文件立即生效（否则需要重新登录才会生效）
source 配置文件 / .配置文件

//配置文件的分类
/etc/profile
/etc/profile.d/*.sh
~/.bashrc
/etc/bash.bashrc
//调用关系
profile -> ~/.bashrc -> /etc/bash.bashrc
    |
   \ /
/etc/profile.d/*.sh

//declare声明变量类型
declare[+/-][选项]变量名
-:给变量设定类型属性
+:取消变量的类型属性
-i:将变量声明为整数型
-x:将变量声明为环境变量
-p:显示指定变量的被声明类型

//预定义变量
$?:最后一个命令的执行返回状态，如果是0表示正确，非零表示错误
$$:当前进程的进程号
$!:后台运行的最后一个进程的进程号

//位置参数变量
$n: $0代表命令本身，$1-$9代表一个到第九个参数，10以上$(10)
$*:这个变量代表命令行中所有的参数，把所有的参数看成一个整体
$@:也代表命令行中所有参数，不过每个参数独立对待
$#:代表命令行中所有参数的个数

//定义系统提示符的变量
PS1

//执行一个shell脚本文件
bash shell.sh / sh shell.sh //当文件属性不是可执行时也可
./shell.sh //文件属性为可执行
//读入脚本并执行，与其他方式最大的区别：
//在当前shell中执行，而不是子shell
source shell.sh 
 
//1.系统常见环境变量
PATH:系统查找命令的路径
PATH="$PATH":/root/sh //叠加

//1.设置环境变量
export 变量名=变量值
//2.查询环境变量
env

//1.变量调用
$varname 例：echo $name
//2.变量查看
set
//3.变量删除
unset varname

//1.输出重定向 >>表示追加方式输入到文件
命令 &>文件 (命令正确出错信息到输入到文件）
命令 &>>文件 (追加方式到文件)
命令 >文件1 2>>文件2 （把命令正确输入文件1 错误输入文件2）

//2.输入重定向 将将文件输入到shell终端执行
wc [选项] [文件名]
-c 统计字节数
-w 同期单词数
-l 统计行数

//3.多命令顺序执行
; 例：命令1;命令2 命令之间不存在逻辑，不会互相影响
&& 例子：命令1&&命令2 逻辑与，命令1执行成功才会执行命令2
不成功则不执行
|| 例子：命令1||命令2 逻辑或 命令1执行不正确，命令2才会执行
执行正确则不执行

//4.管道符
| 例子：命令1 | 命令2 命令1的正确输出作为命令2的参数
如不正确输出则不会执行命令2



//5.通配符(用来匹配文件名字，通配符是完全匹配，非包含匹配)
? 匹配一个任意字符
* 匹配0和或多个任意字符
[] 匹配中括号中的任一个字符 如[abc] 含其中一个字符即匹配
[-] 匹配范围中的任一个字符，如[a-b]
[^] 逻辑非，如[^0-9] 表示匹配非数字字符                              

//6.Bash中其他字符
'' 单引号 在单引号中任何特殊字符都没有含义
"" 双引号 在双引号中除$ ` \外任何特殊字符都没有特殊含义
&()和``（反引号) 作用相同 包含的内容是shell命令，会得到执行
# 在shell中以#开头的表示注释
$ 放在变量前，用于调用变量的值
\ 转义符 跟在/之后的特殊符号将失去特殊含义，变为普通字符


lsblk   查看当前系统的分区情况和设备挂载情况

//https访问网页，-i显示返回头信息
curl -i https://www.baidu.com







http://linux.51yip.com/search//shell命令中文手册
chmod 777  文件或目录
scp [参数] [原路径] [目标路径] //-p读写属性不变
//有用户名需要输入密码，可复制文件/文件夹
scp local_file remote_username@remote_ip:remote_folder
scp local_file remote_ip:remote_folder

ps -ef | grep g++//查看进程状态
uname -r //查看linux内核版本
+++++
mkdir -p a/b/c //创建多层folder
dpkg -l > appList_1.txt
grep -w "unity-drive" appList_1.txt > appList_2.txt
awk '{print $2,$3}' appList_2.txt > appList_3.txt
+++++
mkdir params//创建文件夹
sudo -i//切换root权限
sudo passwd root//重置root密码
su//切换root权限
rostopic pub /auto_start std_msgs/Bool "data:true"//防止手动接管，ud_client运行后执行
sudo apt-get --purge remove sunloginclient//卸载并删除所有配置文件
192.168.17.28
grep -H //可用于查找文件
dpkg -l | grep gcc//查询已安装的gcc版本信息
apt list同上（略有区别）
apt-cache policy "^unity-drive"//列出包含unity-drive字段的软件信息
apt-cache pkgnames//列出所有软件包名字，无序
apt list --installed |& grep sysstat//已安装软件的信息
yum list installed | grep docker
sudo chmod 666 sources.list//改变文件为可写模式
gedit .profile//受用
apt install libjsoncpp-dev
apt-get install app
apt-get remove app
apt-get update//安装卸载更新
//"compilerPath": "/usr/bin/clang"

tar -xzf protobuf-all-3.13.0.tar.gz

https://postman-echo.com/get?d=d
408



精进至此~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
查看->调试（ctrl+shift+d)选择编译环境 
launch.json
ctrl+shift+p 搜索选择 “配置任务” 
task.json
ctrl+shift+p:输入C/C++
c_cpp_properties.json
//运维必用工具
tail -f curlposttest.log 

{"Data":{"UserName":"yanqingwei","PhoneNumber":"","Email":"","Token":"yanqingwei:52f99f60-8444-4d89-aae4-ff5c05d13f1e"},"Status":20001,"Message":"登录成功!","RequestID":"9d2bd445-773c-4aee-9999-40d26c3b20d0"}
{"Data":{"Longitude":0,"Latitude":0},"Status":1,"Message":"请求成功","RequestID":"51c132d1-62d7-4ad7-a088-8598ca4359d6"}
//运行ud_drive后, 订阅位置信息
rostopic pub -r 10 /current_odom nav_msgs/Odometry "{pose:{pose:{position: {x: 0.0, y: 0.0, z: 0.0}}}}"


host:ws://47.112.135.212:8084/ws


下面是一些响应code的说明：
成功
1. 200 ok请求成功
2. 201 OK 新的资源建立（post）
3. 202 请求被接受，但处理为完成
4. 204 OK但没有字段返回
重新定向用户代理执行更多动作

    301 所请求的支援已被指派为新的URL
    302 所请求的支援临时位于其他的URL

    304 文档没有被修改（get）
    客户端错误

    400 错误的请求
    401 未授权 该用户需要授权认证
    403 不明原因的禁止

    404 没有找到（参数错误）
    服务器错误

    500 服务器异常
    501 没有实现
    502 错误的网关
    503 服务器暂时失效
    补：tttp请求格式一般为

socket ready!
bind ready!
等待来自客户端的连接...
客户机:127.0.0.1连接本服务器成功!
Request information:
GET /get?dataRequest_1=/opt/b0&dataRequest_2=/opet/l0 HTTP/1.1
Content-Type: application/json
User-Agent: PostmanRuntime/7.26.2
Accept: */*
Postman-Token: c203098d-200b-43dd-b4fa-916805813e33
Host: 127.0.0.1:6666
Accept-Encoding: gzip, deflate, br
Connection: keep-alive


等待来自客户端的连接...
客户机:127.0.0.1连接本服务器成功!
Request information:
POST /post HTTP/1.1
Content-Type: application/json
User-Agent: PostmanRuntime/7.26.2
Accept: */*
Postman-Token: 65ccb9cd-c3f9-433d-9d04-917abe69056d
Host: 127.0.0.1:6666
Accept-Encoding: gzip, deflate, br
Connection: keep-alive
Content-Length: 130

{
	"Data": {
		"LoopSwitch": true,
		"Origin": {
			"Latitude": 0,
			"Longitude": 0
		},
		"Rotate": 0
	},
	"Message": "string"
}
389bytes

ws://120.78.66.145:8080/ws

