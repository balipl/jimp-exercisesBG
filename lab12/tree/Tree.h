//
// Created by Grove on 2017-05-25.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <memory>

using std::unique_ptr;

namespace tree {

    template<class T>
    class Tree {
    public:
        Tree();

        Tree(T value);

        unique_ptr<Tree<T>>InsertLeft(unique_ptr<Tree<T>> root, T value);
        unique_ptr<Tree<T>>InsertRight(unique_ptr<Tree<T>> root ,T value);

        ~Tree();

    private:
        unique_ptr<Tree<T>> left_leaf_ = nullptr;
        unique_ptr<Tree<T>> right_leaf_ = nullptr;
        T value_;
    };

    template<class T>
    Tree<T>::Tree() {

    }

    template<class T>
    Tree<T>::~Tree() {

    }

    template<class T>
    Tree<T>::Tree(T value) {
        value_ = value;
    }



    template<class T>
    unique_ptr<Tree> Tree<T>::InsertLeft(unique_ptr<Tree<T>> root, T value) {
         root->value_ = value;
        root->left_leaf_ =


        return unique_ptr<Tree>();
    }

    template<class T>
    unique_ptr<Tree> Tree<T>::InsertRight(unique_ptr<Tree<T>> root, T value) {
        return unique_ptr<Tree>();
    }
}

#endif //JIMP_EXERCISES_TREE_H
