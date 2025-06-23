# Code_Caprice/design-mode/singleton.py (可以接在饿汉式代码后面)

import threading # 懒汉式需要线程模块

class LazyShoppingCartManager:
    """
    购物车管理类，实现单例模式（懒汉式，线程安全）。
    """
    _instance = None # 初始时实例为空
    _lock = threading.Lock() # 用于线程同步的锁

    def __init__(self):
        """
        构造函数，初始化购物车。
        注意：__init__ 每次创建实例时都会调用，单例模式需要确保只初始化一次。
        """
        if hasattr(self, 'initialized'):
            return # 如果已经初始化过，则直接返回

        self.cart = {}
        self.initialized = True # 标记为已初始化
        print("LazyShoppingCartManager 实例被创建并初始化！") # 仅第一次创建时打印

    @classmethod
    def get_instance(cls):
        """
        提供一个全局访问点来获取唯一的购物车实例（懒汉式，线程安全）。
        """
        if cls._instance is None: # 第一次检查：如果实例为空
            with cls._lock: # 获取锁，确保只有一个线程能进入
                if cls._instance is None: # 第二次检查：在锁内部再次检查，防止多线程竞争
                    cls._instance = cls() # 创建实例
        return cls._instance

    def add_to_cart(self, item_name: str, num: int):
        """
        向购物车添加商品。

        Args:
            item_name (str): 商品名称。
            num (int): 购买数量。
        """
        self.cart[item_name] = self.cart.get(item_name, 0) + num

    def view_cart(self):
        """
        查看购物车内容，并按添加顺序打印。
        """
        print("--- 购物车内容 ---")
        for item, quantity in self.cart.items():
            print(f"{item} {quantity}")
        print("------------------")

# 示例用法 (您可以将这段放在其他地方，例如一个测试文件)
if __name__ == "__main__":
    print("\n--- 懒汉式单例示例 ---")
    # 此时实例尚未创建
    print("尝试获取 LazyShoppingCartManager 实例...")
    lazy_cart1 = LazyShoppingCartManager.get_instance() # 第一次获取，实例才会被创建和初始化
    lazy_cart1.add_to_cart("Milk", 1)

    print("再次尝试获取 LazyShoppingCartManager 实例...")
    lazy_cart2 = LazyShoppingCartManager.get_instance() # 第二次获取，不会再次创建实例
    lazy_cart2.add_to_cart("Bread", 2)

    lazy_cart1.view_cart()
    print(f"Is lazy_cart1 the same as lazy_cart2? {lazy_cart1 is lazy_cart2}") # 应该为 True

    # 模拟多线程访问
    def worker():
        cart_thread = LazyShoppingCartManager.get_instance()
        cart_thread.add_to_cart(f"Item_{threading.current_thread().name}", 1)

    threads = []
    for i in range(5):
        t = threading.Thread(target=worker, name=f"Thread-{i}")
        threads.append(t)
        t.start()

    for t in threads:
        t.join()

    LazyShoppingCartManager.get_instance().view_cart()