import threading
import time
import os
os.system('chcp 65001')
# 创建两个锁
lock1 = threading.Lock()
lock2 = threading.Lock()

def thread1():
    print("线程1尝试获取lock1")
    lock1.acquire()
    print("线程1获取到lock1")
    time.sleep(1)  # 模拟一些操作
    
    print("线程1尝试获取lock2")
    lock2.acquire()
    print("线程1获取到lock2")
    
    # 释放锁
    lock2.release()
    lock1.release()

def thread2():
    print("线程2尝试获取lock2")
    lock2.acquire()
    print("线程2获取到lock2")
    time.sleep(1)  # 模拟一些操作
    
    print("线程2尝试获取lock1")
    lock1.acquire()
    print("线程2获取到lock1")
    
    # 释放锁
    lock1.release()
    lock2.release()

# 创建并启动线程
t1 = threading.Thread(target=thread1)
t2 = threading.Thread(target=thread2)

t1.start()
t2.start()

t1.join()
t2.join()