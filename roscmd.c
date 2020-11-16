//装ros时设置的环境变量
source /opt/ros/melotic/setup.bash       kinetic

sudo apt install catkin
 //创建工作空间
$ mkdir -p ~/catkin_ws/src
$ cd ~/catkin_ws/src
$ catkin_init_workspace
//编译工作空间
$ cd ~/catkin_ws/
$ catkin_make
//设置环境变量
$ source /home/yqw/catkin_ws/devel/setup.bash
//检查环境变量
$ echo $ROS_PACKAGE_PATH
//创建功能包
$ cd ~/catkin_ws/src
$ catkin_create_pkg test_pkg std_msgs rospy roscpp
//编译功能包
$ cd ~/catkin_ws
$ catkin_make

                              
//功能包中定义一个节点的名称
ros::init(argc, argv, "talker")


//话题通信方式
//编译话题通信节点之前需要在CMakeLists.txt中
• 设置需要编译的代码和生成的可执行文件.
• 设置链接库;

//自定义消息结构体案例：
//发布者不断发送乌龟定位信息，接受者不断接受显示定位信息
//自定义一个消息结构体，需要
➢ 在CMakeLists.txt添加编译选项
• find_package( ...... message_generation)
• add_message_files(FILES Person.msg)
  generate_messages(DEPENDENCIES std_msgs)
• catkin_package(...... message_runtime)

➢ 在package.xml中添加功能包依赖
<build_depend>message_generation</build_depend>
<exec_depend>message_runtime</exec_depend>


//编译的的话题通信节点中有自定义的消息结构需要在CMakeLists.txt中
• 设置需要编译的代码和生成的可执行文件
• 设置链接库;
• 添加依赖项；
（需要在.cpp文件中添加自定义消息结构体的节点）




//编译好功能包中的节点后，运行此功能包中编译好的节点
rosrun learning_topic velocity_publisher
//新建文本编辑器，给名字和格式可以是文本，cpp
nano file.txt

//小乌龟的三个操作
roscore
//小乌龟这个节点既支持话题通信，又支持服务通信
rosrun turtlesim turtlesim_node
rosrun turtlesim turtle_teleop_key
//编译好功能包中的节点，运行此功能包中编译好的节点
rosrun learning_topic velocity_publisher
//新建文本编辑器，给名字和格式可以是文本，cpp
nano file.txt


//在一个文件里打开终端直接创建msg文件
touch Person.msg

//话题发布
（1）初始化节点
（2）注册节点
（3）（组消息包）发布话题

//话题订阅
（0）定义回调函数
（1）初始化节点
（2）注册节点
（3）订阅话题




//服务通信模式

//在src中创建功能包
//要用到的消息结构体是turtlesim功能包中的，所以添加进来
$ cd ~/catkin_ws/src
$ catkin_create_pkg learning_service roscpp rospy std_msgs geometry_msgs
turtlesim

//创建一个客户端
//此客户端请求产生一个新的小海龟，并初始化它的位置
（1）初始化ros节点
（2）检测到要检测的服务名后，创建一个client实例
（3）发布服务请求数据
（4）等待server处理后的应答结果

//如何配置CMakeLists.txt中的编译规则
• 设置需要编译的代码和生成的可执行文件;
• 设置链接库;
add_executable(turtle_spawn src/turtle_spawn.cpp)
target_link_libraries(turtle_spawn ${catkin_LIBRARIES})

//编译，在工作空间根目录执行
catkin_make
//运行功能包
//第三个参数是节点编译出来的可执行文件
rosrun learning_service turtle_spawn

//创建一个服务器
//该程序是server，当有名ID为turtle_command的请求时(服务），则调用回调函数
//对请求进行返回，并发布话题，指导小乌龟进行线性和角度的运动
（1）初始化ros节点
（2）创建server实例，并注册
（3）循环等待服务请求，进入回调函数
（4）在回调函数中完成服务功能的处理，并反馈数据。
（5）发布话题指导小乌龟运行
//运行编译好的功能包
rosrun learning_service turtle_command_server

//向server发生一个请求命令
rosservice call /turtle_command "{}"

//服务通信，自定义结构体
//在功能包内，src同级定义文件夹，在文件夹内
touch Person.srv

//自定义一个.srv消息结构体需要配置
➢ 在package.xml中添加功能包依赖
<build_depend>message_generation</build_depend>
<exec_depend>message_runtime</exec_depend>

➢ 在CMakeLists.txt添加编译选项
• find_package( ...... message_generation)
• add_service_files(FILES Person.srv)
generate_messages(DEPENDENCIES std_msgs)

• catkin_package(...... message_runtime)
//编译会生成三个文件，两外两个是第一个的分开，用的时候包含第一个就行

//编译含有自定义结构体的client和server之前配置CMakeLists.txt
• 设置需要编译的代码和生成的可执行文件;
• 设置链接库;
• 添加依赖项；
add_executable(person_server src/person_server.cpp)
target_link_libraries(person_server ${catn_LIBRARIES})
add_dependencies(person_server ${PROJECT_NAME}_genckipp)
add_executable(person_client src/person_client.cpp)
target_link_libraries(person_client ${catkin_LIBRARIES})
add_dependencies(person_client ${PROJECT_NAME}_gencpp)



//参数的使用与编程方法
//创建参数功能包 第三个参数及以后是依赖包
catkin_create_pkg learning_parameter roscpp rospy std_srvs

//发一个服务命令
rosservice call /clear "{}"

//rosparam基本命令
//列出当前所有参数
rosparam list
//显示某个参数值
rosparam get param_key
//设置某个参数的值
rosparam set param_key param_value
//保存当前所有的全局参数到一个新建的文件(在hoem下)
rosparam dump file_name
//从文件读取参数
rosparam load file_name
//删除参数
rosparam delete param_key

//在编译功能包之前做的
//要编译的文件，和编译后生成的文件
//设置链接库
add_executable(parameter_config src/parameter_config.cpp)
target_link_libraries(parameter_config ${catkin_LIBRARIES})

Apollo平台对ROS的改进,分为三方面:
1.通信性能优化,通过共享内存机制.
2.去中心话网络拓扑
3.数据兼容性扩展


1.ros传输数据是一帧一帧传输,前一帧传完,才会传下一帧,若某一帧,传的太久
就会丢弃这帧.
ros系统把一个传输,到接受方拿到,需要copy四次数据,百度apollo改造后,基于
共享内存,只需要copy两次.
原声的ros系统,基于socket通信方式,传5M需要4ms,百度apollo改造后的基于
共享内存机制的传输方式需要2ms.整机每秒达5.5G.

2.节点之间建立通信过程分为五部:
1)发布节点向master注册.
2)接收节点向master注册.
3)master向接收节点发送已经发送节点的拓扑信息.
4)接收节点向发送节点请求tcp链接.
5)二者建立了p2p的链接后,进行通信.


//安装ros所缺少的依赖包
rosdep install --from-paths src --ignore-src --rosdistro=melotic -y
//更新ros源
rosdep update


//CMakeLists.txt
cmake_minimum_required()  //指定catkin最低版本
project()  //指定软件包的名称
find_package()  //指定编译时所需要的依赖项
//添加消息文件，服务文件，动作文件
add_message_files()
add_service_files()
add_action_files() 

generate_messages() //生成消息，服务，动作
catkin_package()  //指定编译信息给编译系统生成Cmake文件
add_library() / add_executable()  //指定生成库，可执行文件
target_link_libraries()  //指定可执行文件去链接哪些库
catkin_add_gtest()  //添加测试单元
install()  //生成可安装目标

//添加静态库test.lib
add_library(test STATIC test.c)
//添加动态库test.dll
add_library(test SHARED test.c)

//启动多个node(若master没启动，自动启动)
roslaunch pkg_name file_name.launch


//package.xml
<package>	<!--根标签-->
	<name>    <!--包名-->
	<version< <!--版本号-->
	<description> <!--包描述-->
	<maintainer> <!--维护者-->
	<license> <!--软件许可证-->
	<buildtool_depend> <!--编译工具-->
	<build_depend> <!--编译时的依赖-->
	<run_depend> <!--运行时的依赖-->
</package>	<!--根标签-->



//ros基本msg包括
bool
int8, int16, int32, int64(及uint)
float32, float64
string
time, duration, header
可变长数组array[], 固定长度数组array[c]


//rostopic
rostopic list //列出当前所有topic
//显示某个topic的属性信息
rostopic info /topic_name 
//显示摸个topic的内容
rostipic echo /topic_name
//向某个topic发布内容
rostopic pub /topic_name ...

//显示系统上所有msg
//列出系统上所有msg
rosmsg list
//显示某个msg内容
rosmsg show /msg_name


//rospack
//查找某个pkg的地址
rospack  find package_name
//列出本地所有的pkg
rospack list

//roscd
//跳转到某个pkg路径下
roscd package_name

//列举某个pkg下的文件信息
rosls package_name

//rosed
//编辑pkg中的文件
rosed package_name file_name

//创建一个pkg
catkin_create_pkg pkg_name deps...

//rosdep
//安装某个pkg所需要的依赖
rosdep install pkg_name


//rosnode
//列出当前运行的node信息
rosnode list

//显示某个node的详细信息
rosnode info node_name

//结束某个node
rosnode kill node_name

//rosbag
//记录某些topic到bag中
rosbag record topic_name
//记录所有topic到bag中
rosbag recode -a
//回放bag
rosbag play bag_files

ros::NodeHandle Class类
常用成员函数
//创建话题的publisher
ros::Publisher advertise(const string &topic, uint32_t queue_size);
//创建话题的subscriber
ros::Subscriber subscirbe(const string &service, uint32_t queue_size, void(*)(M));
//创建服务的server
ros::ServiceServer advertiseService(const string &service, boo(*srv_func)(Mreq&, Mres&));
//创建服务的client
ros::ServiceClient serviceClient(const string &service_name, bool perisstent=false);
//查询某个参数的值
bool getParam(const string &key, void &val);
//给参数赋值
bool setparam(const string &key, void val);

//ros::master Namespace
//常用函数
bool check(); //检查master是否启动
const string& getHost(); //返回master所处的hostname
bool getNodes(V_string &nodes); //从master返回已知的node名称列表
bool getTopic(V_TopicInfo &topics); //返回所有正在被发布的topic列表
bool getURI(); //返回master的URI地址，如http://host:port/
uint32_t getPort(); //返回master运行在的端口

ros::this_node Namespace
//常用函数
void getAdvertisedTopics(V_string &topics); //返回本node发布的topic
const string &getName(); //返回当前node的名称
const string &getNamespace(); //返回当前node的命名空间
void getSubscribedTopics(V_string &topics); //返回当前node订阅的topic

//TF相关数据类型
tf::Vector3  //向量
tf::Point  //点
tf::Quaternion  //四元数
tf::Matrix3x3  //3X3矩阵
tf::Pose  //位姿
tf::Transform  //变换
tf::Stamped<T>  //带时间戳的以上类型
tf::StampedTransform  //带时间戳的变换

//tf::TransformBroadcaster 类
//成员函数
void sendTransform(const StampedTransform &transform)  //发送数据给tf的函数

//tf::TransformListener  类
//tf中接收其他发来的数据
void lookupTransform(const std::string &target_frame, const std::string &soruce_frame, const ros::Time &time, StampedTransform &transform)const

//urdf
Unified Robot Descirption Format //tf数据进行传输时的格式
//SLAM
Simutaneous Localization And Mapping  //同步定位与建图系统






































