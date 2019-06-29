#include <iostream>

void indent(int level) {
    // indent more at each level:
    for (int i = 0; i < level; i++) std::cout << "  ";
}

template <typename T>
class Bst {
    friend T max(const Bst<T>* root){
        const Bst<T>* curr = root;
        if (curr->right == nullptr){
            return curr->data;
        }
        return max(curr->right);
    }
    
    friend T min(const Bst<T>* root){
        const Bst<T>* curr = root;
        if(curr->left == nullptr){
            return curr->data;
        }
        return min(curr->left);
    }
    
    friend void print_bst(const Bst<T>& bst, int level=0) {
        indent(level);
        level++;
        
        std::cout << "data: " << bst.data << std::endl;
        indent(level + 1);
        std::cout << "left: ";
        
        if (!bst.left) std::cout << "nullptr\n";
        else {
            std::cout << "\n";
            indent(level);
            print_bst(*bst.left, level);
        }
        indent(level + 1);
        std::cout << "right: ";
        if (!bst.right) std::cout << "nullptr\n";
        else {
            std::cout << "\n";
            indent(level);
            print_bst(*bst.right, level);
        }
        std::cout << std::endl;
    }
    
public:
    Bst(T d, Bst* p=nullptr, Bst* l=nullptr, Bst* r=nullptr)
    : data(d), parent(p), left(l), right(r) {}
    
    Bst<T>* search(const T d){
        Bst* nw_ptr = this;
        if (nw_ptr == nullptr) {return nullptr;}
        if (nw_ptr->data > d){
            nw_ptr = nw_ptr->left;
            return nw_ptr->search(d);
        }
        else if (nw_ptr->data < d){
            nw_ptr = nw_ptr->right;
            return nw_ptr ->search(d);
        }
        return nw_ptr;
    }
    Bst<T>* predecessor(const T d){
        Bst* nw_ptr = this->search(d);
        if(nw_ptr->left){
            return this->search(max(nw_ptr->left));
        }
        
        Bst* cursor = nw_ptr->parent;
        while (cursor) {
            if (cursor->data > d){
                cursor = cursor->parent;
            }
            else{
                return cursor;
            }
        }
        return nw_ptr;
    }
    
    Bst<T>* successor(const T d){
        Bst* nw_ptr = this->search(d);
        if(nw_ptr->right){
            return this->search(min(nw_ptr->right));
        }
        
        Bst* cursor = nw_ptr->parent;
        while (cursor) {
            if (cursor->data < d){
                cursor = cursor->parent;
            }
            else{
                return cursor;
            }
        }
        return nw_ptr;
    }
    
    Bst<T>* insert(const T d) {
        Bst* nw_ptr = this;
        if (nw_ptr->data > d){
            if (nw_ptr->left == nullptr){
                nw_ptr->left = new Bst(d,this);
                return nw_ptr;
            }
            else{
                nw_ptr = nw_ptr->left;
                return nw_ptr->insert(d);
            }
            
        }
        else{
            if (nw_ptr->right == nullptr){
                nw_ptr->right = new Bst(d,this);
                return nw_ptr;
            }
            else{
                nw_ptr = nw_ptr->right;
                return  nw_ptr->insert(d);
            }
        }
        return this;
    }
    
    T get_val() const {
        return data;
    }
    
    
    
private:
    T data;
    Bst* parent;
    Bst* left;
    Bst* right;
};


//template <typename T>
//void print_bst(const Bst<T>& bst) {
//void print_bst(Bst<int> bst) {
//    std::cout << "data: " << bst.data << "; left: ";
//
//    if (!bst.left) std::cout << "nullptr ";
//    else {
//        std::cout << "\t\n";
//        print_bst(*bst.left);
//    }
//    std::cout << "; right: ";
//    if (!bst.right) std::cout << "nullptr ";
//    else {
//        std::cout << "\t\n";
//        print_bst(*bst.right);
//    }
//    std::cout << std::endl;
//}
