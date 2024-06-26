[https://zhuanlan.zhihu.com/p/60622181]   
[https://blog.csdn.net/u012999985/article/details/52902065]
## 元数据与反射：    
是描述程序的二进制信息，存储在公共语言运行时可移植可执行 (PE) 文件或内存中。当您将代码编译为 PE 文件时，元数据将插入文件的一部分，您的代码将转换为 Microsoft 中间语言 (MSIL)   
并插入文件的另一部分。在模块或程序集中定义和引用的每个类型和成员都在元数据中进行了描述。执行代码时，运行时将元数据加载到内存中并引用它以发现有关代码的类、成员、继承等的信息。  
元数据以与语言无关的方式描述代码中定义的每个类型和成员  
程序在运行时，可以查看其它程序集或其本身的元数据。一个运行的程序查看本身的元数据或者其它程序集的元数据的行为称为反射。  
  
  
  
## 特性  
特性（attribute），是一种允许我们向程序的程序集增加元数据的语言结构。它是用于保存程序结构信息的某种特殊类型的类。    
我们将应用了特性的程序结构叫做目标。   
设计用来获取和使用元数据的程序（对象浏览器）叫做特性的消费者。   
.NET预定了很多特性，我们也可以声明自定义特性。   
  
  
  

## 反射：  
可以使用反射动态创建类型的实例，将类型绑定到现有对象，或从现有对象获取类型并调用其方法或访问其字段和属性。如果代码中使用了特性，可以利用反射对它们进行访问。  
通过反射，可以在运行时获得程序或程序集中每一个类型（包括类、结构、委托、接口和枚举等）的成员和成员的信息。     
反射用到的主要类:  
System.Type 类－－通过这个类可以访问任何给定数据类型的信息。  
System.Reflection.Assembly 类－－它可以用于访问给定程序集的信息，或者把这个程序集加载到程序中。  

  
  
  
    

## 实际的应用场景：  
通过名字找gameobject很容易，但是当我们想通过字符串的名字找字符串的值时，就得用这个了  
以下是一个通过MyClass的变量名读取变量值的例子  
```
MyClass myClass = new MyClass();
string varName = "myInt1";
FieldInfo field = typeof(MyClass).GetField(varName);
int value = (int)field.GetValue(myClass);
Console.WriteLine("Original value of {0}: {1}", varName, value);
```



  

##  反射的概念其实在unreal中更更常见：
#### 具体使用
当我们使用C++类创建向导创建类的时候，引擎会把以下3行代码放到头文件中：  s
```
#include "TypeName.generated.h"
UCLASS()
GENERATED_BODY()
```
引擎需要这三行代码，使一个类对反射系统可见。(反射系统允许你将函数以及变量等暴露给蓝图和编辑器)。
  
使变量对反射系统可见：  
```
UPROPERTY()
UStaticMeshComponent* Mesh;
```
     
UFUNCTION（BlueprintCallable）支持蓝图和C++的交互功能
#### 内部实现
一、标记  
1、添加头文件 #include "FileName.generated.h"  
2、使用UENUM()、UCLASS()、USTRUCT()、UFUNCTION()、UPROPERTY()来标记  
二、UnrealBuildTool和UnrealHeaderTool  
1、UBT扫描头文件，**记录**所有包含反射类型的modules  
2、当其中有头文件改变时，就会用UHT**更新**反射数据。UHT解析头文件，扫描标记，生成用于支持反射的C++代码。    
3、UBT本身是干什么的：当你在虚幻引擎中创建一个游戏项目时，你会写很多代码，还会用到很多资源。UBT会帮你把这些东西整理好，检查有没有错误，然后把它们变成一个可以运行的游戏程序。
