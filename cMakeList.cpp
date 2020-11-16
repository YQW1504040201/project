//静而后能安，安而后能虑

//节点名和节点所包含的cpp文件
add_executable(${PROJECT_NAME}_node 
src/main.cpp
src/XMediaEncode.cpp
src/XRtmp.cpp
)

//添加链接库
target_link_libraries(${PROJECT_NAME}
    ${catkin_LIBRARIES}
    # ${PROJECT_NAME}_lib
    pthread
    boost_system
    boost_thread
    jsoncpp
    curl
    yaml-cpp
    ${protobuf3.7.1_LIB}
    glog
)

//CMakeList常用变量
PROJECT_NAME //工程名变量
<PKG_INCLUDE_DIR> //导入包头文件全路径
<PKG>_LIBRARIES //导入库文件全路径
CMAKE_VERSION  //Cmake的版本号
RPOJECT_SOURCE_DIR  //构建工程的全路径
CMAKE_INSTALL_PREFIX  //构建install的路径
$ENV{HOME}  //home环境下的目录路径


cmake_minimum_required(VERSION 2.8.3) //设置版本号
project(hello_cv_1)  //设置工程名
add_compile_options(-std=c++11) //设置支持c++11
include_directories(include)  //查询头文件的路径为CMakeList.txt同级路径的“include”目录
add_executable(hello_cv_1 src/main.cpp) //添加源文件

//生成库，此时需要屏蔽add_executable()
//STATIC 静态 SHARED 动态
//静态库为.a 动态库为.so
add_library(hello_cv_2_add_static_lib STATIC src/hello_cv_1.cpp)

//当程序被编译成一个库时，设置库文件的输出目录，默认输出到执行目录下
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)  //工程的根目录下

//编译后同时生成静态和动态库的方法
add_library(hello_cv_3_add_static_lib STATIC src/hello_cv_1.cpp)
//hello_cv_3_lib为动态库的名字
set_target_properties(hello_cv_3_add_static_lib PROPERTIES_OUTPUT_NAME "hello_cv_3_lib")

//生成工程的四个过程
预处理->编译->汇编->链接
其中动态和静态库是在链接时产生不同的
动态库：占用空间小，运行耗时 .a/.lib
静态库：占用空间大，运行快 .so/.dll

//如何给工程导入一个库
//1.导入头文件
//2.导入库文件
//3.三种方式
//绝对路径方式，install方式，find_package方式
方法一：
include_directories(/usr/include)
target_link_libraries(${PROJECT_NAME} /usr/lib/libhello_cv_2_add_static_lib.a)

//用find_package方式找头文件和库
find_path(<NAME_INCLUDES>) //库的头文件路径 常用变量<NAME>_INCLUDE_DIR <NAME_INCLUDES>
find_library(<NAME>_LIBS) //库文件路径，常用变量<NAME>_LIBRARY <NAME>_LIBS

方法二：
//找头文件
find_path
	(
	hello_lib_INCLUDE_DIR
	NAMES hello_lib.h
	PATHS "头文件绝对路径"
	)
//找库文件
find_library
	(	
	hello_lib_LIBRARY
	NAMES hello_lib
	PATHS "库文件全路径"
	)


































