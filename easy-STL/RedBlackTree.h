
#include <sstream>
#include <cstddef>
#include <iostream>

enum class Color { RED, BLACK };

template<typename Key,typename Value>
class RedBlackTree {
    struct Node {
        Key key;
        Value value;
        Color color;
        Node* parent;
        Node* left;
        Node* right;

        Node(const Key& k,const Value& v, const Color& c,Node* p = nullptr) 
            : key(k),value(v),color(c),parent(p),left(nullptr),right(nullptr) {}
        
        Node() : color(Color::BLACK),parent(nullptr),left(nullptr),right(nullptr) {}  
    };

    private:
    Node* root;
    size_t size;
    Node* Nil;

    void inorderTraversal(Node* root){
        if(root == nullptr) return;
        inorderTraversal(root->left);
        std::cout << root->key << " " << root->value << " ";
        inorderTraversal(root->right);
    }

    void leftRotate(Node* node){
        Node* child = node->right;
        Node* grand_child = child->left;

        // 处理gran_child和其未来父亲node之间的关系
        node->right = grand_child;
        if(grand_child){
            grand_child->parent = node;
        }
        // 处理child和其未来父亲（node->parent）之间的关系
        child->parent = node->parent;
        if(node->parent == nullptr){
            root = child;
        } else if (node == node->parent->left){
            node->parent->left = child;
        } else {
            node->parent->right = child;
        }
        // 处理child和node之间的关系
        child->left = node;
        node->parent = child;
    }

    void rightRotate(Node* node){
        Node* child = node->left;
        Node* grand_child = child->right;

        node->left = grand_child;
        if(grand_child){
            grand_child->parent = node;
        }

        child->parent = node->parent;
        if(node->parent == nullptr){
            root = child;
        } else if (node == node->parent->left){
            node->parent->left = child;
        } else {
            node->parent->right = child;
        }

        child->right = node;
        node->parent = child;
    }

    void insertFixup(Node* node){
        while(node->parent && node->parent->color == Color::RED){
            if(node->parent == node->parent->parent->left){
                Node* uncle = node->parent->parent->right;
                if(uncle != nullptr && uncle->color == Color::RED){
                    node->parent->color = Color::BLACK;
                    uncle->color = Color::BLACK;
                    node->parent->parent->color = Color::RED;
                    node = node->parent->parent;
                } else {
                    if(node == node->parent->right){
                        node = node->parent;
                        leftRotate(node);
                    }
                    node->parent->color = Color::BLACK;
                    node->parent->parent->color = Color::RED;
                    rightRotate(node->parent->parent);
                }
            } else {
                Node* uncle = node->parent->parent->left;
                if(uncle != nullptr && uncle->color == Color::RED){
                    node->parent->color = Color::BLACK;
                    uncle->color = Color::BLACK;
                    node->parent->parent->color = Color::RED;
                    node = node->parent->parent;
                } else {
                    if(node == node->parent->left){
                        node = node->parent;
                        rightRotate(node);
                    }
                    node->parent->color = Color::BLACK;
                    node->parent->parent->color = Color::RED;
                    leftRotate(node->parent->parent);
                }
            }
        }
        root->color = Color::BLACK;
    }

    Node* lookUp(const Key& key){
        Node* cur = root;
        while(cur){
            if(key < cur->key){
                cur = cur->left;
            } else if(key > cur->key){
                cur = cur->right;
            } else {
                return cur;
            }
        }
        return cur;
    }

    void insertNode(const Key& key, const Value& value){
        Node* newNode = new Node(key,value,Color::RED);
        Node* cur = root;
        Node* parent = nullptr;
        while(cur){
            parent = cur;
            if(key < cur->key){
                cur = cur->left;
            } else if(key > cur->key){
                cur = cur->right;
            } else {
                delete newNode;
                return;
            }
        }
        newNode->parent = parent;
        if(parent == nullptr){
            root = newNode;
        } else if(key < parent->key){
            parent->left = newNode;
        } else{
            parent->right = newNode;
        }
        
        size++;
        insertFixup(newNode);
    }
    
    // 获取节点颜色，空节点为黑色
    Color getColor(Node* node) {
        if (node == nullptr) {
            return Color::BLACK;
        }
        return node->color;
    }
    
    // 设置节点颜色
    void setColor(Node* node, Color color) {
        if (node == nullptr) {
            return;
        }
        node->color = color;
    }
    
    // 查找以指定节点为根的子树中的最小节点
    Node* findMinimumNode(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    
    // 用新节点替换旧节点
    void replaceNode(Node* oldNode, Node* newNode) {
        if (oldNode->parent == nullptr) {
            root = newNode;
        } else if (oldNode == oldNode->parent->left) {
            oldNode->parent->left = newNode;
        } else {
            oldNode->parent->right = newNode;
        }
        if (newNode != nullptr) {
            newNode->parent = oldNode->parent;
        }
    }
    
    // 删除修复函数，用于在删除节点后恢复红黑树的性质
    //https://images-xxueyu.oss-cn-shanghai.aliyuncs.com/202507291433323.png
    void removeFixup(Node* node) {
        // 当节点不是根节点且颜色为黑色时继续修复
        while (node != root && getColor(node) == Color::BLACK) {
            // 如果节点是其父节点的左子节点
            if (node == node->parent->left) {
                Node* sibling = node->parent->right; // 兄弟节点
                
                // 情况1：兄弟节点是红色
                if (getColor(sibling) == Color::RED) {
                    // 重新着色兄弟节点和父节点，并进行左旋，实际方向可以理解为朝双黑旋转
                    setColor(sibling, Color::BLACK);
                    setColor(node->parent, Color::RED);
                    leftRotate(node->parent);
                    sibling = node->parent->right; // 更新兄弟节点
                }
                
                // 情况2：兄弟节点的两个子节点都是黑色
                if (getColor(sibling->left) == Color::BLACK &&
                    getColor(sibling->right) == Color::BLACK) {
                    // 重新着色兄弟节点并向上移动
                    setColor(sibling, Color::RED);
                    node = node->parent;
                } else {
                    // 情况3：兄弟节点的右子节点是黑色（左子节点是红色）
                    if (getColor(sibling->right) == Color::BLACK) {
                        // 重新着色兄弟节点和兄弟节点的左子节点，并进行右旋
                        setColor(sibling->left, Color::BLACK);
                        setColor(sibling, Color::RED);
                        rightRotate(sibling);
                        sibling = node->parent->right; // 更新兄弟节点
                    }
                    
                    // 情况4：兄弟节点的右子节点是红色
                    setColor(sibling, getColor(node->parent));
                    setColor(node->parent, Color::BLACK);
                    setColor(sibling->right, Color::BLACK);
                    leftRotate(node->parent);
                    node = root; // 修复完成，将节点设为根节点以退出循环
                }
            } else {
                // 对称情况：节点是其父节点的右子节点
                Node* sibling = node->parent->left; // 兄弟节点
                
                // 情况1：兄弟节点是红色
                if (getColor(sibling) == Color::RED) {
                    // 重新着色兄弟节点和父节点，并进行右旋
                    setColor(sibling, Color::BLACK);
                    setColor(node->parent, Color::RED);
                    rightRotate(node->parent);
                    sibling = node->parent->left; // 更新兄弟节点
                }
                
                // 情况2：兄弟节点的两个子节点都是黑色
                if (getColor(sibling->right) == Color::BLACK &&
                    getColor(sibling->left) == Color::BLACK) {
                    // 重新着色兄弟节点并向上移动
                    setColor(sibling, Color::RED);
                    node = node->parent;
                } else {
                    // 情况3：兄弟节点的左子节点是黑色（右子节点是红色）
                    if (getColor(sibling->left) == Color::BLACK) {
                        // 重新着色兄弟节点和兄弟节点的右子节点，并进行左旋
                        setColor(sibling->right, Color::BLACK);
                        setColor(sibling, Color::RED);
                        leftRotate(sibling);
                        sibling = node->parent->left; // 更新兄弟节点
                    }
                    
                    // 情况4：兄弟节点的左子节点是红色
                    setColor(sibling, getColor(node->parent));
                    setColor(node->parent, Color::BLACK);
                    setColor(sibling->left, Color::BLACK);
                    rightRotate(node->parent);
                    node = root; // 修复完成，将节点设为根节点以退出循环
                }
            }
        }
        // 确保最终节点是黑色的，以维持红黑树性质
        setColor(node, Color::BLACK);
    }

    // 删除节点函数
    void deleteNode(Node* del) {
        Node* rep = del;            // rep（替换节点）初始指向要删除的节点
        Node* child = nullptr;      // 要删除节点的孩子节点
        Color origCol = del->color; // 保存要删除节点的原始颜色
        Node* repOriginalParent = nullptr;
        /*删除节点有三种情况：
        1. 无子节点（叶子节点）：直接删。
        2. 有一个子节点：用子节点替代。
        3. 有两个子节点：找到中序后继，用其值替换被删节点，然后删除后继
        */
        // 如果删除节点没有左孩子
        if (del->left == nullptr) {
            child = del->right;      // 孩子节点指向删除节点的右孩子
            replaceNode(del, child); // 用右孩子替换删除节点
        }
        // 如果删除节点没有右孩子
        else if (del->right == nullptr) {
            child = del->left;       // 孩子节点指向删除节点的左孩子
            replaceNode(del, child); // 用左孩子替换删除节点
        }
        // 如果删除节点有两个孩子
        else {
            // 找到删除节点的后继节点（右子树中的最小节点）
            rep = findMinimumNode(del->right);
            origCol = rep->color;    // 保存后继节点的原始颜色
            child = rep->right;      // 孩子节点指向后继节点的右孩子（后继节点没有左孩子）
            repOriginalParent = rep->parent; // 保存后继节点的原父节点
            // 如果后继节点就是删除节点的直接右孩子
            if (rep == del->right) {
                // 直接用后继节点替换删除节点
                replaceNode(del, rep);
                // 将删除节点的左子树连接到后继节点
                rep->left = del->left;
                rep->left->parent = rep;
            } else {
                // 后继节点不是删除节点的直接右孩子
                // 首先将后继节点从原位置移除，用其右孩子替换它
                replaceNode(rep, rep->right);
                
                // 然后用后继节点替换删除节点
                replaceNode(del, rep);
                
                // 将删除节点的左右子树都连接到后继节点
                rep->left = del->left;
                rep->left->parent = rep;
                rep->right = del->right;
                rep->right->parent = rep;
            }
            
            // 保持后继节点的颜色与删除节点一致
            rep->color = del->color;
        }
        
        // 如果原始颜色是黑色，需要进行额外的修复操作
        // 因为黑色节点的删除可能会破坏红黑树的性质
        if (origCol == Color::BLACK) {
            if (child != nullptr) {
                // 如果存在孩子节点，进行修复操作
                removeFixup(child);
            } else {
                // 如果不存在孩子节点，创建一个哨兵节点进行修复
                Node* nil = new Node();
                // 如果rep == del：说明删除的是只有一个孩子或没有孩子的节点，实际上若删除的是只有一个孩子，则不会走到哨兵分支。而删除没有孩子的节点时才会走到这个分支且rep==del。此时把哨兵的父节点设置为删除节点的父节点
                // 如果rep != del：说明删除的是有两个孩子的节点，rep是后继节点，哨兵的父节点是后继节点的原父节点
                nil->parent = (rep != del) ? repOriginalParent : del->parent; // 设置哨兵节点的父节点
                removeFixup(nil);          // 进行修复操作
                // 断开哨兵节点与树的连接
                if (nil->parent != nullptr) {
                    if (nil == nil->parent->left) {
                        nil->parent->left = nullptr;
                    } else {
                        nil->parent->right = nullptr;
                    }
                }
                delete nil; // 释放哨兵节点内存
            }
        }
        
        // 释放删除节点的内存
        delete del;
    }

    public:
    RedBlackTree() : root(nullptr),size(0),Nil(new Node()) {}
    ~RedBlackTree(){
        deleteTree(root);
    }

    size_t getSize(){ return size; }
    
    bool empty(){ return size == 0;}
    
    Value* at(const Key& key){
        auto* ans = lookUp(key);
        if(ans == nullptr) return nullptr;
        return &ans->value;
    }

    void remove(const Key& key){
        Node* nodeToBeRemoved = lookUp(key);
        if(nodeToBeRemoved != nullptr){
            deleteNode(nodeToBeRemoved);
            size--;
        }
    }

    void print(){
        inorderTraversal(root);
        std::cout << "\n";
    }
    
    void clear(){
        deleteTree(root);
    }
    
    void insert(const Key& key,const Value& value){ insertNode(key,value);}
    
    private:
    void deleteTree(Node* node){
        if(node) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

};
#if 0
int main(){
    RedBlackTree<int,int> rbTree;
    int n;
    std::cin >> n;

    std::cin.ignore();

    std::string line;

    for(int i = 0;i < n;i++){
        std::getline(std::cin,line);
        std::istringstream iss(line);
        std::string command;
        iss >> command;
        int key;
        int value;
        if(command == "insert"){
            iss >> key >> value;
            rbTree.insert(key, value);
        } else if( command == "remove"){
            iss >> key;
            rbTree.remove(key);
        } else if(command == "at") {
            iss >> key;
            auto ans = rbTree.at(key);
            if(ans == nullptr){
                std:: cout << "not exist" << std::endl;
            } else {
                std::cout << *ans << std::endl;
            }
        } else if(command == "size"){
            std::cout << rbTree.getSize() << std::endl;
        } else if(command == "print"){
            if(rbTree.empty()) {
                std::cout << "empty" << std::endl;
            } else {
                rbTree.print();
            }
        }
    }
    return 0;

}
#endif