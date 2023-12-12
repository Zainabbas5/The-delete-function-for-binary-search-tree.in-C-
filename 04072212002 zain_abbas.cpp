#include <iostream>
using namespace std;
template <typename T>
struct tnode {
	tnode *right;
	tnode *left;
	T data;
};
template <typename T>
class bin_tree {
private:
	tnode<T>*root;
	int n;
public:
	bin_tree(){
		root = NULL;
		n = 0;
	}
	void insert(tnode<T> *&ptr, const T&val) {
		if (ptr == NULL) {
			ptr = new tnode<T>;
			ptr->data = val;
			ptr->left = ptr->right = NULL;
			return;
		}
		tnode<T>*parent, *temp;
		parent = NULL;
		temp = ptr;
		while (temp != NULL) {
			parent = temp;
			if (val < temp->data) {
				temp = temp->left;
			}
			else {
				temp = temp->right;
			}
			if (val < parent->data) {
				parent->left = new tnode<T>;
				parent->left->data = val;
				parent->left->right = parent->left->left = NULL;
			}
			else {
				parent->right = new tnode<T>;
				parent->right->data = val;
				parent->right->left = parent->right->right = NULL;
			}
		}
	}
	void Delete(const T&val) {
		tnode<T>*curr;
		curr = root;
		tnode<T>*prev;
		prev = NULL;
		while (val != curr->data) {
			if (val < curr->data) {
				prev = curr;
				curr = curr->left;
				continue;
			}
			if (val > curr->data) {
				prev = curr;
				curr = curr->right;
				continue;
			}
		}
		if ((curr->right&&curr->left) == NULL) {//case 1
			if (prev->left == curr) {
				prev->left = NULL;
			}
			else {
				if (prev->right == curr) {
					prev->right = NULL;
				}
 			}
			delete[]curr;
		}
		else {//case 1
			if ((curr->right || curr->left) != NULL) {
				if (curr->left == NULL) {
					tnode<T>*temp;
					temp = curr;
					if (prev->right == curr) {
						curr = curr->right;
						prev->right = curr;
						delete[]temp;
					}
					if (prev->left == curr) {
						curr = curr->right;
						prev->left = curr;
						delete[]temp;
					}
				}
				else {
					if (curr->right == NULL) {
						tnode<T>*temp;
						temp = curr;
						if (prev->left == curr) {
							curr = curr->left;
							prev->left = curr;
							delete[]temp;
						}
						if (prev->right == curr) {
							curr = curr->left;
							prev->right = curr;
							delete[]temp;
						}
					}
				}
			}
			else {//case 3
				if ((curr->right != NULL) && (curr->left != NULL)) {
					tnode<T>*temp;
					temp = curr->left;
					tnode<T>*temp_prev;
					temp_prev = NULL;
					while (temp->right != NULL) {
						temp_prev = temp;
						temp = temp->right;
					}
					if (temp->left != NULL) {
						curr->data = temp->data;
						tnode<T>*temp12;
						temp12 = temp->left;
						temp_prev->right = temp12;
						delete[]temp;
					}
				}
			}
		}
	}

};
int main() {
	bin_tree <int>t1;
	tnode<int>*root = NULL;
	t1.insert(root, 5);
	t1.insert(root, 10);
	t1.insert(root, 15);
	return 0;
}