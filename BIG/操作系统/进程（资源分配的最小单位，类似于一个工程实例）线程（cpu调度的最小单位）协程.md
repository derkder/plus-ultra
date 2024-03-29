## 核 
堆栈是保证线程独立运行所必须的。    

---

## 基本概念：  
进程：进程是对运行时程序的一个封装，是系统进行资源调度和分配的基本单位（在操作系统层面的并发）。  
线程：线程是进程的子任务，是cpu调度和分派的基本单位（在进程层面的并发）。  
简单来说就是，进程存在的意义是为了在cpu进行并发操作时，保护上下文，保护进程数据间不相互影响而设计出来的概念。有了进程我们就可以在单个cpu进行多进程分片，也可以多个cpu并发处理进程。  
而线程，就是在一个进程内其实也有多个逻辑，当一个逻辑需要io的时候，会白占cpu，占着茅坑不拉屎。  
而进程间切换的代价也比较大，为了提高效率，在就设计出可线程的概念，当进程中其中一个线程需要IO的时候，另一个线程来占用cpu以此提高效率。  

---
## 图  
![进程线程协程](/BIG/操作系统/coroutine.png)

---
## 附
C# Job System 提供了以并行的方式在多核CPU上运行游戏代码的方法(可以让我们无痛写出 多线程 并行处理的代码)

## 线程是并行 协程是并发
周伯通教郭靖一手画圆，一手画方，两只手同时操作，左右互搏，这个就是并行。普通人肯定做不到，不信你试试。你不能并行，却可以并发，你先左手画一笔，然后右手画一笔，同一时候只有一只手在操作，来回交替，直到完成两个图案是，这就是并发，协程主要的功能。
