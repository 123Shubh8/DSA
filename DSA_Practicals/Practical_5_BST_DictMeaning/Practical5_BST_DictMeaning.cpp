#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

class TreeNode {
public:
    string keyword;
    string meaning;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string key, string val) {
        keyword = key;
        meaning = val;
        left = right = nullptr;
    }
};

class BST {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, string key, string val) {
        if (node == nullptr)
            return new TreeNode(key, val);

        if (key < node->keyword)
            node->left = insert(node->left, key, val);
        else if (key > node->keyword)
            node->right = insert(node->right, key, val);

        return node;
    }

    TreeNode* remove(TreeNode* node, string key) {
        if (node == nullptr)
            return node;

        if (key < node->keyword)
            node->left = remove(node->left, key);
        else if (key > node->keyword)
            node->right = remove(node->right, key);
        else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode* temp = minValueNode(node->right);

            node->keyword = temp->keyword;
            node->meaning = temp->meaning;

            node->right = remove(node->right, temp->keyword);
        }

        return node;
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;

        while (current->left != nullptr)
            current = current->left;

        return current;
    }

    void inorder(TreeNode* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << setw(15) << node->keyword << ": " << node->meaning << endl;
            inorder(node->right);
        }
    }

    void reverseInorder(TreeNode* node) {
        if (node != nullptr) {
            reverseInorder(node->right);
            cout << setw(15) << node->keyword << ": " << node->meaning << endl;
            reverseInorder(node->left);
        }
    }

    int findMaxComparisons(TreeNode* node, string key, int comparisons) {
        if (node == nullptr)
            return comparisons;

        comparisons++;

        if (key < node->keyword)
            return findMaxComparisons(node->left, key, comparisons);
        else if (key > node->keyword)
            return findMaxComparisons(node->right, key, comparisons);

        return comparisons;
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(string key, string val) {
        root = insert(root, key, val);
    }

    void remove(string key) {
        root = remove(root, key);
    }

    void displayAscending() {
        cout << "\nDisplaying data in ascending order:\n";
        inorder(root);
    }

    void displayDescending() {
        cout << "\nDisplaying data in descending order:\n";
        reverseInorder(root);
    }

    int findMaxComparisons(string key) {
        return findMaxComparisons(root, key, 0);
    }
};

int main() {
    BST bst;

    while (true) {
        cout << "\n---------------------------MENU------------------------------\n";
        cout << "1. Add New Keyword\n";
        cout << "2. Delete Keyword\n";
        cout << "3. Update Keyword Value\n";
        cout << "4. Display Data in Ascending Order\n";
        cout << "5. Display Data in Descending Order\n";
        cout << "6. Find Maximum Comparisons for a Keyword\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string key, val;
                cout << "Enter Keyword: ";
                cin >> key;
                cout << "Enter Meaning: ";
                cin >> val;
                bst.insert(key, val);
                break;
            }
            case 2: {
                string key;
                cout << "Enter Keyword to Delete: ";
                cin >> key;
                bst.remove(key);
                break;
            }
            case 3: {
                string key, val;
                cout << "Enter Keyword to Update: ";
                cin >> key;
                cout << "Enter New Meaning: ";
                cin >> val;
                bst.remove(key);
                bst.insert(key, val);
                break;
            }
            case 4:
                bst.displayAscending();
                break;
            case 5:
                bst.displayDescending();
                break;
            case 6: {
                string key;
                cout << "Enter Keyword to Find Maximum Comparisons: ";
                cin >> key;
                int comparisons = bst.findMaxComparisons(key);
                cout << "Maximum Comparisons for \"" << key << "\": " << comparisons << endl;
                break;
            }
            case 7:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
