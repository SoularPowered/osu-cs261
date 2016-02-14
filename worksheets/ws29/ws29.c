// ws29.c

struct node {
	TYPE value;
	struct node * left;
	struct node * right;
};

struct BinarySearchTree {
	struct node *root;
	int size;
};

void initBST(struct BinarySearchTree *tree) { 
	tree->size = 0; tree->root = 0: 
}

void addBST(struct BinarySearchTree *tree, TYPE newValue) {
	tree->root = _nodeAddBST(tree->root, newValue); 
	tree->size++;
}


int sizeBST (struct binarySearchTree *tree) { 
	return tree->size; 
}


struct node * _nodeAddBST (struct node *current, TYPE newValue) {
	// FIXME

	// if start is null then 
	// 		return a new Node with newValue
	struct node* newNode;
	if (current == NULL) {
		newNode = (struct node *) malloc(sizeof(struct node));
		assert(newNode != NULL);
		newNode->value = newValue;
		newNode->left = newNode->right = NULL;
		return newNode;
	}

	// otherwise if newValue is less than the value at start then
	// 	  set the left child to be the value returned by add(leftChild, newValue)
	if (newValue < current->value) {
		current->left = _nodeAddBST(current->left, newValue);
	}

	// otherwise 
	// 	set the right child to be add(rightChild, newValue)
	else if (newValue >= current->value) {
		current->right = _nodeAddBST(current->right, newValue);
	}

	return current;
}

int containsBST (struct binarySearchTree *tree, TYPE d) {
	struct Node * iter = tree->root;

	while (iter != NULL) {
		if (iter->value == 0) {
			return 1; // true
		}
		// else if the search val is < current value, search left subtree
		else if (iter->value < 0) {
			iter = iter->left;
		}
		// else if search val is greater, search right subtree
		else {
			iter = iter->right;
		}
	}
	// If we reach a null pointer, value not found - return false
	return 0;
}


void removeBST (struct binarySearchTree *tree, TYPE d) {
	if (containsBST(tree, d) {
		tree->root = _nodeRemoveBST(tree->root, d);
		tree->size--;
	}
}



// why does this function return a TYPE ??? wouldn't we want, like the left most child?
// Pretty sure this HAS to be a typo, right?
TYPE _leftMostChild (struct node * current) {
	// FIXME
	assert (current != NULL);

	struct node * iter = current;
	while (iter->left != NULL) {
		iter = iter->left;
	}

	return iter->value; 
}


struct node * _removeLeftmostChild (struct node *current) {
	// FIXME
	current = _leftMostChild(current);
	_nodeRemoveBST(current, current->value);
}

/*
 recursive helper function to remove the left most child of a node
 HINT: this function returns cur if its left child is NOT NULL. Otherwise,
 it returns the right child of cur and free cur. */
void _nodeRemoveBST (struct node * current, TYPE d) {
	/*write this*/
	assert(cur != NULL);
	assert(val != NULL);

	// if value == current.value, then handle case where right is null and where right is not null
	if (compare(val, cur->val) == 0) {
		if (cur->right == NULL) {
			return cur->left;
		}
		else {
			cur->val = _leftMost(cur->right);
			cur->right = _removeLeftMost(cur->right);
		}
	}
	// else if value is less, then we will search left subtree
	else if (compare(val, cur->val) < 0) {
		cur->left = _removeNode(cur->left, val);
	}
	// else we will search right subtree
	else {
		cur->right = _removeNode(cur->right, val);
	}

	return cur;
}