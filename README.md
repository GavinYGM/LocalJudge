# Local Judge


## What's this?

Local Judge 类似于 Online Judge，但因其运行在本地，故命名为 **Local** Judge。

如果你曾想过提高刷题效率，那么你可能用过 `freopen` 或者 `#ifndef ONLINE_JUDGE`，
那么不妨试试 LocalJudge。

Features：

- 评测无需排队
- 管理多组测试用例
- 自动输入多组数据
- 自动对比输出结果
- 保留评测日志[未完成]

> 刷题时，由于每个项目只能指定一个入口，每道题目都需要新建一个项目很繁琐，
> LocalJudge提供`lj run hello.c` 或 `ljr hello.c`直接编译运行，
>即可在IDE的一个项目里存放多个带有main函数的源文件了。

它的劣势之一是OJ实战不能使用=_=。

## 安装

```bash
pip install --upgrade LocalJudge
```

## 使用截图

<img src="./screenshots/1.svg">


## 使用方法

将 `gcc`、`java` 等编译器所在的目录加入`PATH`，关于自定义编译器参数与自定义语言，请参考下节。

> Windows上使用`Code::Blocks`与`DevC++`的用户，您可以找到安装目录下的mingw等编译器，将`gcc`所在的文件夹加入`PATH`。

> 请善用`lj run`命令独立运行源文件，这样可以在一个IDE的项目中存放多个带有main函数的源文件而不冲突。

1. 创建项目

`lj create poj-1000.c`

项目目录结构如下：

```
.
├── poj-1000 题目文件夹，需要和源码文件名前缀相同
│   ├── 1.in 输入，必须为*.in
│   ├── 1.out 预期输出，必须为*.out
│   ├── 2.in 同上
│   ├── 2.out
│   ├── 3.in
│   ├── 3.out
│   ├── README.md 问题描述文件
└── poj-1000.c 代码文件
```

2. 编写您的代码与测试用例

3. 使用`lj poj-1000.c` 或 `lj poj-1000`(自动搜索后缀) 开始评测。

当然，也可以使用 `lj run poj-1000.c` 或 `ljr poj-1000.c` 手动运行。


> 请注意：由与OJ限制，java源文件名必须为Main.java，因此请将每个项目放在独立的文件夹里。

> 由于IDE会报错，Java源文件无法和其他语言保持一样的文件结构(如文件夹下同时存在poj-1000.java、poj-1001.java)。

## 编译器配置

程序首次运行，会自动新建 `~/.localjudge.json`，请参考配置文件内容，并根据实际情况修改编译参数。

${src} 将会被预定义变量**src**替换，同理，可使用的预定义变量如下：

```
src : 源文件路径
dest: 可执行文件路径
stem: 源文件名前缀
exe_if_win: 如果为Windows系统，值为".exe"，否则为""
......
```

## 其他命令

```
# 开启DEBUG模式
lj -d poj-1000.c

# 以JSON格式输出
lj --json poj-1000.c

# 指定只使用某个测试用例
lj poj-1000.c -c 1

# 创建新项目
lj create poj-1001.c
ls poj-1001*
poj-1001.c

poj-1001:
1.in      1.out     2.in      2.out     README.md

# 直接从源码编译运行
lj run poj-1000.c
ljr poj-1000.c


# 清空某项目临时文件夹
lj clean poj-1000.c

# 显示某项目的内容
lj show 

```

## TODO

[To Do List](https://github.com/NoCLin/LocalJudge/projects/1)
