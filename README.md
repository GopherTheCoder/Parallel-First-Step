# Parallel-First-Step
~~~
编写一个程序，寻找1~20000000中相邻质数差值最大的两个数，并打印出来。
	如： 1~20中的质数为2,3,5,7,11,13,17,19。其中相邻质数差值最大的两个数为7和11。
~~~
+ 使用gcc9编译，运行于WSL Ubuntu 19.10
+ 计划使用OpenMP进行并行化

---
## Usage:
### Build:
+ 串行：make **serial**
+ 并行：make **parallel**
### Run:
+ 串行：./bin/serial
+ 并行：./bin/parallel [thread number]