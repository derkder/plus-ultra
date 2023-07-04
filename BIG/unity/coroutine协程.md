## 1、协程的简单原理:
首先需要了解协程不是线程，协程依旧是在主线程中进行  
然后要知道协程是通过迭代器来实现功能的，通过关键字IEnumerator来定义一个迭代方法  
你调用此方法的时候不会真的运行，而是会返回一个迭代器  

## 2、协程的执行  
执行到协程相当于注册了事件，yield return才会把控制权交给外部线程，并不是协程和主要的一起跑！！！（但waitfor什么的又不一样）  
yield return new WaitForSecondsRealtime(5);//使用未缩放时间将协同程序执行暂停指定的秒数。[也就是所有程序都暂停了这些事件，所以可以冻结帧！！]  
截屏：yield return waitforendofFrame,这样可以等到啥都渲染好了再执行后面的协程内容，即会让后续的代码在 lateUpdtae 之后执行  
这样可以每一帧都执行一下协程（比起函数协程还能记录一个长线上的状态，例如淡出开一个协程，就可以每帧但一点点）  
[https://zhuanlan.zhihu.com/p/279383752]
  
看操作系统那一节里的协程  

  
## 3、协程的详细底层原理  
协程分为两部分，协程与协程调度器：协程仅仅是一个能够中间暂停返回的函数，而协程调度是在MonoBehaviour的生命周期中实现的。    
准确的说，Unity只实现了协程调度部分，而协程本身其实就是用了C#原生的”迭代器方法“。  
你调用此方法的时候不会真的运行，而是会返回一个迭代器  
函数调用的本质是压栈，协程的唤醒也一样，调用IEnumerator.MoveNext()时会把协程方法体压入当前的函数调用栈中执行，运行到yield return后再弹栈。  
这点和有些语言中的协程不大一样，有些语言的协程会维护一个自己的函数调用栈，在唤醒的时候会把整个函数调用栈给替换，这类协程被称为有栈协程，而像C#  
中这样直接在当前函数调用栈中压入栈帧的协程我们称之为无栈协程。  
  
## 4、协程的详细底层原理补充：为什么协程每次可以回到原来的状态    
**协程上下文**结构保存了当前的函数栈状态&寄存器值    



## 5、应用：https://blog.csdn.net/hafeiyangha/article/details/125365152
  第一：CaotureFromScreen使用yield return new waitforendofFrame来保证在lateUpdtae 之后再获得渲染好的图像    
  第二：使用协程来进行异步加载https://docs.unity3d.com/ScriptReference/SceneManagement.SceneManager.LoadSceneAsync.html    
```
    //伪代码
    IEnumerator ShowImageFromUrl(string url)
    {
        Image image = null;
        yield return LoadImageAsync(url, image); //异步加载图像，加载完成后唤醒协程
        Show(image);
    }
```
     
  第三：将一个复杂程序分帧执行：如果一个复杂的函数对于一帧的性能需求很大，我们就可以通过yield return null将步骤拆除，从而将性能压力分摊开来，最终获取一个流畅的过程  
  ```
        IEnumerator LoadYourAsyncScene()
        {
            AsyncOperation asyncLoad = SceneManager.LoadSceneAsync("Scene2");
            while (!asyncLoad.isDone)
            {
                yield return null;
            }
        }
```
  第四：定时器  
  
