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
	if (current == NULL) {
		struct node* newRoot = (struct node *) malloc(sizeof(struct node));
		newRoot->value = newValue;
		newRoot->left = newRoot->rigt = NULL;
		return newRoot;
	}

	// otherwise if newValue is less than the value at start then
	// 	  set the left child to be the value returned by add(leftChild, newValue)
	else if (newValue < current->value) {
		current->left = _nodeAddBST(current->left, newValue);
	}

	// otherwise 
	// 	set the right child to be add(rightChild, newValue)
	else {
		current->right = _nodeAddBST(current->right, newValue);
	}


	return current;
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
	while (current->left != NULL) {
		current = current->left;
	}

	return current->value; 
}


struct node * _removeLeftmostChild (struct node *current) {
	// FIXME
	current = _leftMostChild(current);
	_nodeRemoveBST(current, current->value);
}


void _nodeRemoveBST (struct node * current, TYPE d) {
	// FIXME
	// if start.value is the value we seek
	if (current->value == d) {
		// 	decrease the value of dataSize
		current->size--;
		// if right child is null
		if (current->right == null) {
			// 	return left child
			return current->left;
		}
		// otherwise
		else {
			// 	replace value of node with leftmost child of right child
			current = _leftMostChild(current->right);
			// 	set right child to be removeLeftmost(right child)
			
		}
	}
	// otherwise if testValue is smaller than start.value
	else if(d < current->value) {
		// 	set left child to remove (left child, testValue)
		current->left = _nodeRemoveBST(current->left, d);
	}
	// otherwise
	else {
		// set right child to remove (right child, testValue)
		current->right = _nodeRemoveBST(current->right, d);
	}

	return current;
}