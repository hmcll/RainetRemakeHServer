# 雷net重做

## 简介
- 雷net重做版的游戏逻辑后端部分。
- 从stdin接受服务端处理过的指令，处理后在stdout输出客户端应得的信息。

### 这个程序里包括的：
- 雷net的游戏逻辑
- 反作弊
- 装饰性指令同步
- 游戏内容同步
- 棋谱保存
- 玩家管理

### 这个程序里不包括的：
- 美术
- session管理
- websocket接收发送
- 账号管理
- 房间管理
- web数据初处理

## 创建

## 指令头

- 2 char

| 指令 | 效果 |
 ---- | ---- 
| BD | 获取棋盘 |
| AP | 添加玩家 |
| IT | 初始化终端 |
| IP | 初始化棋子 |
| TE | 终端卡使用 |
| MV | 移动棋子 |
| AR | 美术指令 |
| ER | 回复专用，指令拒绝 |

## 输入
5 char + alpha + \n

玩家ID + 指令头 + meta + newline

- #### BD
  - 无meta
- #### AP
  - 1 char 角色
    - 先攻
    - 后攻
    - 观赛
    - 上帝
- #### IT
  - 1 char 使用的终端数n
  - n char 选择使用的终端

- #### IP
  - 由该玩家视角从左到右的棋子排列，8char

- #### TE
  - 1 char 使用的终端
  - 4 char x1，y1，x2，y2
- #### MV
  - 4 char x1，y1，x2，y2
- #### AR
  - 所有Meta完整回送

## 输出

玩家ID + 指令头 + Meta

### BD
- 每个棋子4 char，共4 * 8 * 8 char
- 表示方法后述
  
  
