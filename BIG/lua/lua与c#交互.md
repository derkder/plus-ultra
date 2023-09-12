[https://blog.csdn.net/qq_37873310/article/details/80455827]
### C#执行Lua
#### 1、代码：Lua 解析器对象.DoString(“Lua 代码”)     
```
Lua lua = new Lua();                    
lua.DoString("name = 'xiaoming' age = 19 sex = 'man'");
lua.DoString("print(name, age, sex)");
```
#### 2、文件：Lua 解析器对象.DoFile(“[路径]Lua 文件.lua”)
```
//加载Lua文件，lua解析器已实例化
lua.DoFile("wzq.lua");
//获取lua文件中的字符类型
string webName = lua.GetString("webname");
//获取lua文件中的方法
LuaFunction ShowGame = lua.GetFunction("ShowGame");
//执行该方法
ShowGame.Call();

LuaFunction add = lua.GetFunction("Add");
//向该方法传参
Object[] obj = add.Call(12, 30);
Console.WriteLine(obj[0]);
```
