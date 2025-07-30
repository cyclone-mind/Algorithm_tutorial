#include "RedBlackTree.h"
#include <cstddef>

template<typename Key>
class MultiSet {
    private:
    RedBlackTree<Key, size_t> rbTree;
    size_t sz;
    public:
    MultiSet() : sz(0) {}
    ~MultiSet(){}
    void insert(const Key& key) {
        auto count = rbTree.at(key);
        if(count != nullptr){
            (*count)++;
            sz++;
            return;
        } else {
            rbTree.insert(key, 1);
            sz++;
        }
    }
    void erase(const Key& key) {
        auto count = rbTree.at(key);
        if(count == nullptr){
            return;
        }
        (*count)--;
        sz--;
        if(*count == 0){
            rbTree.remove(key);
        }
    }
    size_t size() const { return sz;}
    bool empty() const { return sz == 0;}
    size_t count(const Key& key) const {
        auto num = rbTree.at(key);
        if(num != nullptr){
            return *num;
        }
        return 0;
    } 
    void clear(){
        sz = 0;
        rbTree.clear();
    }
};