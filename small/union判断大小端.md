```cpp
typedef union u
{
   int i;
   char c;
}u;
int check_sys()
{
  u.i = 1;
  return u.c;//返回1，表示小端；返回0，表示大端（有效数据在地址大的地方是为大端大概）
}
```


感觉小端就是万一只有十位个位上的数就往地址低的前面放

这样读的快


![cute cat](./imgs/大小端示意1.png)
