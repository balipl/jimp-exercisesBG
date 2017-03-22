//
// Created by bartek on 21.03.17.
//

#include "SmartTree.h"

namespace datastructures {

    unique_ptr <SmartTree> CreateLeaf(int value){
        unique_ptr<SmartTree> p = std::make_unique<SmartTree>();
        p->left = nullptr;
        p->right = nullptr;
        p->value = value;
        return p;
    }
    unique_ptr <SmartTree> InsertLeftChild(unique_ptr<SmartTree> tree, unique_ptr<SmartTree> left_subtree){
        tree->left = std::move(left_subtree);
        return tree;
    }
    unique_ptr <SmartTree> InsertRightChild(unique_ptr<SmartTree> tree, unique_ptr<SmartTree> right_subtree){
        tree ->right = std::move(right_subtree);
        return tree;
    }
    void PrintTreeInOrder(const unique_ptr<SmartTree> &unique_ptr, std::ostream *out){
        if (unique_ptr->left != nullptr)
            PrintTreeInOrder(unique_ptr->left, out);
        (*out) << unique_ptr->value<<", ";
        if (unique_ptr->right != nullptr)
            PrintTreeInOrder(unique_ptr->right, out);

    }
    string DumpTree(const unique_ptr<SmartTree> &tree){


    }
    unique_ptr <SmartTree> RestoreTree(const string &tree);

}