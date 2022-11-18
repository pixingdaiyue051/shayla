## 文件目录
1. /root						系统管理员用户目录
2. /sbin						系统管理员使用的程序
3. /etc						系统管理的配置文件及子目录
4. /home						用户主目录	每个用户都会有单独一个目录
5. /usr						共享资源文件,默认安装的应用程序文件目录
6. /opt						optinonal目录,默认为空,预留给系统安装其他软件目录
7. /tmp						临时文件目录
8. /var						variable目录,存放经常修改的文件日志等
9. /srv						存放服务启动后需要提取的数据
10. /mnt						系统挂载目录,挂载额外的服务，比如映射磁盘
11. /boot						系统启动引导分区
## linux系统启动顺序
1. 启动硬件即bios
	- 读取计算机时间
	- 选择引导分区(硬盘 U盘 光驱) linux下会从/boot文件夹下开启
2. 从引导分区开始启动
	- 读取配置的开启文件 /etc/inittab
	- linux runlevel
		- 0 系统停机(halt)状态，系统的默认运行级别不能设为 0，否则不能正常启动
		- 1 单用户工作(single user)状态，root 权限，用于系统维护，禁止远程登陆
		- 2 多用户(multiuser)状态 (没有 NFS)
		- 3 完全的多用户(multiuser)状态 (有 NFS)，登陆后进入控制台命令行模式
		- 4 系统未使用，保留
		- 5 X11 控制台 (xdm、gdm、kdm)，登陆后进入图形 GUI 模式
		- 6 系统正常关闭并重启(reboot)，默认运行级别不能设为 6，否则不能正常启动
	- 读取runlevel寻找对应的启动目录和脚本
		- /etc/rc.d 开启自启的配置目录
		- /etc/rc.d/init.d 自启脚本位置(需要执行权限)
		- /etc/rc.d/rc.local 自定义自启脚本(需要执行权限)
	- 创建或修改rc.local脚本 配置开机启动参数
	- 使用chkconfig命令加入启动脚本
		```shell
			#! /bin/bash
			#chkconfig: 35 66 88 
			#35表示加入到rc3.d和rc5.d中 
			#66指开启顺序号
			#88指关闭顺序号
			ntpdate cn.ntp.org.cn #同步系统时钟
			#再使用chkconfig --add 脚本目录 将脚本加入到init.d
		```
	- 启动服务 等待连接
## 自定义配置
1. root
	- 账号:root
	- 密码:root000root
	- alter user user() identified by 'root000root';
	- alter user root identfied by 'root000root';
2. mysql
	- root  root000root
	- admin  admin1889101
	- uread  read1987098
	- 查看用户			SELECT User, Host, Password FROM mysql.user;
	- 新增用户			create user '新用户名'@'localhost' identified by '密码';
	- 删除用户			DROP USER username@localhost;
	- 查看用户权限		show grants for ad@localhost;
	- 赋予权限			grant all privileges on *.* to '新用户名'@'指定ip' identified by '新用户密码'
		- 	权限 create  建表	alter	改表		DROP 	删表
		- select,insert,update,delete,index,create,alter,create view,show view
		- FLUSH   PRIVILEGES
	- 创建数据库		create database 数据库名 [DEFAULT CHARACTER SET utf8mb4 COLLATE utf8_general_ci];
	- 备份 mysqldump -uroot -p family_call_data criminal_info > dump_cri.sql
3. es
	- esuser		esuser
	- esuser		ezpwd$123
## 命令行
1. uname -a  查看系统版本信息
2. lsb_release -a 查看分发版本信息
3. mkdir	创建目录  
	-p	递归创建目录
4. rm		删除目录  
	-f	强制删除  
	-r  递归删除子目录  
	-i	交互询问删除
5. chgrp  用户名    文件名  -R
6. chown 用户名   文件名  -R
7. cat		从文件第一行开始读取文件,如果文件过大不建议使用
8. tac		从文件末尾开始读取文件,如果文件过大不建议使用
9. more	分页显示文件内容
10. less	分页显示文件内容,可向上翻页
11. head	只看头几行
12. tail	看文件末尾  
	-f 有新内容加入会实时显示
13. tar		解压tar gz文件  
	tar -zxvf 文件  解压到当前目录
14. scp		远程文件传输  
	scp -v -P port local文件	root@ip:/远程主机目录
15. ssh		远程访问  
	ssh -p port root@ip
16. curl    访问接口  
	-X POST 设置method为post  
	-d ''   添加访问参数  
	-H ''   添加请求头  
	curl -H "sign:223" -H "contentType:application/json" -X post -d '{"a":1}' "https://test.com/demo"
17. vim
	- 命令行模式
		- [addr]s/原字符串/新字符串/[opt]
		- [addr]	默认当前行	1,n从一行开始查找到第n行	1,$(%)全局替换
		- [opt]	可选参数		g全局查找	c需要确认	i忽略大小写
		- :1,$s/127.0.0.1/192.168.3.116/g
		- ndd		删除(剪切)n行(包括当前行)
		- dd		删除(剪切)整行
		- nyy		复制n行
		- yy 		复制当前所在行
		- p 		粘贴剪切板的内容到下一行
		- x		    delete
		- X 		backspace
		- u 		撤回
		- :set nu[mber]   显示行数
		- :e[!]  重新加载当前文件
		- :saveas filename  重命名
		- :[n]r!date    在第n行插入当前时间
18. yum		从指定的服务器自动下载RPM包并且安装，可以自动处理依赖性关系，并且一次安装所有依赖的软体包
	- [options] [command] [package ...]	-y全部选择yes	-q不显示安装的过程
	- check-update	列出所有可更新软件
	- update 			更新所有软件
	- list			列出所有可安装的软件包
	- remove			删除软件包
	- search			所有软件包
19. apt	提供了查找、安装、升级、删除某一个、一组甚至全部软件包的命令  
	apt [options] [command] [package ...]	-y全部选择yes	-q不显示安装的过程
20. nginx
	- apt-get -y install openssl libssl-dev
	- apt-get -y install libpcre3 libpcre3-dev
	- apt-get -y install zlib1g-dev
	- nginx -s stop     		停止
	- nginx -s reload	  		重启
	- nginx -t          		检查
	- start nginx		  		启动
	- nginx -c 配置文件路径 	启动
21. gcc
	- 预编译(Preprocessing 处理头文件)  
		gcc -E a.c -i a.i
	- 编译(Compilation 将源代码编译成汇编)  
		gcc -S a.i -o a.s
	- 汇编(Assembly 汇编文件成目标文件)  
		gcc -c a.s -o a.o
	- 链接(Linking 链接目标文件成可执行文件) 
		gcc a.o -o a
	- 上面4个步骤可以集成一步  
		gcc a.c -o a
	- 调试  
		gcc -g a.c -o a.out  
		生成的a.out支持使用gdb工具调试
22. grep
	- grep -R "test" dir  
		递归查看dir目录下包含test关键字的文件
	- grep -R -n --include="*.sh"  81 ./application  >/root/t.txt  
		在application目录下递归查找所有.sh文件中的关键字 81,显示所属行并将查找到的结果覆盖写入/root/t.txt中
23. crond定时任务
	- 查看定时任务服务是否开启 systemctl status crond.service
	- 重启定时任务服务 systemctl restart crond.service
	- 查看定时任务 crontab -l 
	- 编辑定时任务 crontab -e 
	- 清空定时任务 crontab -r 
24. 杀死进程
	- kill -15
	- kill -9
	- killall 根据进程名杀死全部进程
	- pkill 根据进程名杀死全部进程
## shell
0. shell分类
	- sh
		- Bourne Shell(sh) solaris hpus默认的脚本解释程序
		- Bourne Again Shell(bash) linux kernel默认脚本解释程序
	- csh
		- c shell(csh)
		- tc shell(tcsh)
	- 脚本文件第一行 #! 说明该脚本执行的解释器shell
	- 脚本的执行
		- 文件的绝对路径(文件拥有执行权限) 使用系统默认的shell程序 chmod +x 
		- 文件的相对路径(文件拥有执行权限) 使用系统默认的shell程序
		- sh
		- bash
		- **以上方法都是开启一个新的进程执行脚本**
		- source 在当前终端内执行执行该脚本(可以使用到终端内的变量函数等)
		- export 将变量暴露给子进程查看引用
1. 变量
	- 变量命名
		- 只能包含英文大小写字母,数字,下划线
		- ___不能以数字开头___
		- ___变量名和等号之间不能有空格___
		- 不能使用默认关键字(使用help查看关键字)
	- 变量类型
		- 局部变量  只能在当前脚本内使用
		- 环境变量  所有的shell脚本都可以使用
		- shell变量 由shell程序设定某些特殊的变量
	- ```shell
	 	#!/bin/bash
		name="hello" #定义变量
		echo $name #使用变量
		name=344 #修改变量
		echo ${name}
		readonly name #将变量设置为只读 只读变量不可以修改 不可删除
		name=32
		unset name #删除变量
		```
2. 字符串
	- 可以使用单引号 双引号 也可以不使用引号
	- 单引号字符串
		- 任何使用单引号的字符串内容都将原样输出 所以单引号不能使用变量
		- 单引号内可以再使用单引号 但必须成对出现
	- 双引号字符串
		- 可以使用变量
		- 可以使用\转义符
	- ```shell
		#!/bin/bash
		h1='hello'
		h2='World'
		str1="$h1 $h2" #双引号内使用变量
		echo $str1
		str2='abc'$h1'def'$h2 #单引号字符串拼接
		echo $str2
		echo ${#str1} #字符串长度
		echo ${str1:1:3} #从第2个字符开始截取3个字符
		```
3. 数组
	- 数组内数据空格或者回车列出
	- 数组没有长度不连续
	- 类型不需要一致
	- ```shell
		#!/bin/bash
		arr=(1 '在德国广东富豪' 3 rf 2 6 nnhh '664nnd')
		echo $arr #列出数组第一个元素
		echo ${arr[n]} #列出数组中某个数,索引从0开始
		echo ${arr[@]} #列出数组所有元素
		echo ${arr[*]} #列出数组所有元素
		echo ${#arr[@]} #列出数组长度
		echo ${#arr[*]} #列出数组长度
		```
4. 运算符
	- 借助expr或者awk
	- 需要配合`使用
	- 运算符和运算数之间要有空格
	- ```shell
		#!/bin/bash
		val1=41
		val2=5
		echo `expr $val1 + $val2` 
		echo `expr $val1 - $val2`
		echo `expr $val1 \* $val2` #乘法符号需要转义
		echo `expr $val1 / $val2` #整除法
		echo `expr $val1 % $val2` #取余
		# 逻辑运算
		#	1. 等值判断==(-eq)
		#	2. 不等判断!=(-ne)
		#	3. 大于-gt
		#	4. 大于-lt
		#	5. 大于-ge
		#	6. 大于-le
		#	7. 取反!
		#	8. 逻辑与&&(-a)
		#	9. 逻辑或||(-o)
		#	10. 检查字符串长度为0 -z
		#	11. 检查字符串长度不为0 -n
		#	12. 检查字符串不为空 $
		if [ $val1 == $val2 ] 
		then echo 'val1 == val2'
		else echo 'val1 != val2'
		fi
		# 文件的判断
		#	1. 检测文件是否是普通文件(既不是目录 也不是设备文件) -f
		#	2. 检测文件是否是目录 -d
		#	3. 检测文件是否是字符设备文件 -c
		#	4. 检测文件是否是块设备文件 -b
		#	5. 检测文件是否可读 -r
		#	6. 检测文件是否可写 -w
		#	7. 检测文件是否可执行 -x
		#	8. 检测文件是否为空 -s
		#	9. 检测文件是否存在(包括目录) -e
		#	10. 检测文件是为socket -S
		f='/data/uplaod/index.jpg'
		if [ -e $f ]
		then echo 'f存在'
		else echo 'f不存在'
		fi
		if [ -f $f ]
		then echo 'f是文件'
		else echo 'f不是文件'
		fi
		```
5. 流程控制
	- 判断 
		```shell
		#!/bin/bash
		val1=3
		val2=4
		val3=$[3*4]
		if test $val1 == $val2
		then echo 'val1 == val2'
		elif test $val1 -gt $val2
		then echo 'val1 > val2'
		else echo 'val1 != val2'
		fi

		echo '输入 1 到 4 之间的数字:'
		echo '你输入的数字为:'
		read aNum
		case $aNum in
			1)  echo '你选择了 1'
			;;
			2)  echo '你选择了 2'
			;;
			3)  echo '你选择了 3'
			;;
			4)  echo '你选择了 4'
			;;
			*)  echo '你没有输入 1 到 4 之间的数字'
			;;
		esac
		```
	- 循环
		```shell
		#!/bin/bash
		for loop in 1 2 3 4 5 6 7
		do
			echo $loop
		done

		#只有条件为false才停止循环
		val=1
		while [ $val -le 5 ]
		do
			echo $val
			let "val++"
		done

		#只有条件为true才停止循环
		param=1
		until test $param -eq '110'
		do
			echo $param
			read param
		done
		```
6. 函数
	- 使用function定义函数
	- 函数可以没有返回值 默认还会将函数内最后一条指令结果作为函数返回值
	- ```shell
		#!/bin/bash
		function fnt() #定义一个函数 必须在使用之前先声明 function和()二选一
		{
			echo 'i am ok'
		}
		fnt #使用函数
		echo $? #获得函数返回值

		fnt2()
		{
			echo "传入的参数个数 $#"
			echo "传入的参数 $@"
			return 1 #只能返回数字
		}
		fnt2 4 5 他56 范德萨 43 放到3
		echo $?
		#echo $1 #$n	获取传入脚本的参数,从1开始
		#echo $#	#获取参数个数
		#echo $@ #列出所有参数
		#echo $* #列出所有参数
		#echo $$	#当前脚本的进程号
		#echo $?	#显示最后命令输出状态,0表示没有错误
		```
7. 重定向
	```shell
		>  输出重定向并且覆盖
		>> 输出重定不覆盖使用末尾追加
		<  重定向输入
		0标准输入流
		1标准输出流
		2标准错误流
		1> 正常输出重定向
		2> 错误输出重定向
		echo $? 上一个命令执行后的退出状态 0 表示成功执行
	```
8. 管道符(|)  
	使用管道操作的指令可以将前一个输出作为后一个的输入
9. 注释
	- 单行注释 #
	- 块注释 :<<! 注释内容 !