//
// Created by bartek on 21.03.17.
//

#ifndef JIMP_EXERCISES_SMARTTREE_H
#define JIMP_EXERCISES_SMARTTREE_H

#include <ostream>
#include <string>
#include <memory>
#include <iostream>

namespace datastructures{
    using std::string;
    using std::unique_ptr;
    struct SmartTree{
        int value;
        unique_ptr<SmartTree> left;
        unique_ptr<SmartTree> right;

    };
    unique_ptr <SmartTree> CreateLeaf(int value);
    unique_ptr <SmartTree> InsertLeftChild(unique_ptr<SmartTree> tree, unique_ptr<SmartTree> left_subtree);
    unique_ptr <SmartTree> InsertRightChild(unique_ptr<SmartTree> tree, unique_ptr<SmartTree> right_subtree);
    void PrintTreeInOrder(const unique_ptr<SmartTree> &unique_ptr, std::ostream *out);
    string DumpTree(const unique_ptr<SmartTree> &tree);
    unique_ptr <SmartTree> RestoreTree(const string &tree);

}


#endif //JIMP_EXERCISES_SMARTTREE_H
