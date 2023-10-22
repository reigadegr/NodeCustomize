# NodeCustomize
检测TopApp，对指定的节点自定义值
可以设置APP打开时的值以及退出时的值
## 编译
```bash
#环境构建(termux)
pkg install clang -y && pkg add ndk-multilib -y
#clone项目
git clone https://github.com/reigadegr/NodeCustomize --depth 1 -b main
cd $(pwd)/NodeCustomize/Build
sh build_release.sh
```
***完成***
