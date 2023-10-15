if (p == nullptr || eAndA.empty()) {
        return;
    }

    processOperations(p->left, eAndA);  // Recursively process left subtree
    processOperations(p->right, eAndA); // Recursively process right subtree

    if (p->left == nullptr && p->right == nullptr) {
        // Leaf node
        return;
    }

    char op = eAndA.back();
    eAndA.pop_back();

    int leftResult = p->left ? p->left->result : 0;
    int rightResult = p->right ? p->right->result : 0;

    if (op == 'a') {
        // Perform & operation for internal node
        std::cout << "AND OP" << std::endl;
        p->result = leftResult & rightResult;
    } else if (op == 'e') {
        // Perform | operation for internal node
         std::cout << "OR OP" << std::endl;
        p->result = leftResult | rightResult;
    }