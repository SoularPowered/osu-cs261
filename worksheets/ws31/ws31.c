// WS31 -- AVL trees
// NOTE TO SELF: These were implemented before watching the AVL videos at OSU site,
// but I did watch the videos on MIT OpenCourseWare algorithms class lecture for AVL Trees


// Provided for us
int _bf (struct AVLnode * current) { 
	return h(current->right) - h(current->left); 
}


// Provided for us
struct AVLnode * _balance (struct AVLnode * current) {
	int cbf = bf(current);

	if (cbf < -1) {
		if (bf(current->left) > 0) // double rotation
			current->left = rotateLeft(current->left);
		return rotateRight(current); // single rotation
	} else if (cbf > 1) {
		if (bf(current->right) < 0)
			current->right = rotateRight(current->right);
		return rotateLeft(current);
	}
	setHeight(current);
	return current;
}


/*  Left rotation - the passed in node goes down and to the left
                ==>
    A 			==>        B
   / \          ==>       / \
  a   B         ==>      A   c
     / \        ==>     / \
    b   c       ==>    a   b
inorder traversal preserved: aAbBc  ==>  aAbBc
*/
struct AVLnode * _rotateLeft (struct AVLnode * current) {
	struct AVLnode * nodeA = current;
	struct AVLnode * nodeB = current->right;
	// struct AVLnode * a = current->left;
	// struct AVLnode * b = nodeB->left;
	// struct AVLnode * c = nodeB->right;
	nodeA->right = nodeB->left;
	nodeB->left = nodeA;
	return nodeB; // pass the new subtree root, B, back up
}


/*  Right rotation - the passed in node goes down and to the left
             ==>
     B 		 ==>        A
    / \      ==>       / \
   A   c     ==>      a   B
  / \        ==>         / \ 
 a   b       ==>        b   c

inorder traversal preserved: aAbBc  ==>  aAbBc
*/
struct AVLnode * _rotateRight (struct AVLnode * current) {
	struct AVLnode * nodeA = current;
	struct AVLnode * nodeB = current->right;
	// struct AVLnode * a = current->left;
	// struct AVLnode * b = nodeB->left;
	// struct AVLnode * c = nodeB->right;
	nodeB->left = nodeA->right;
	nodeA->right = nodeB;
	return nodeA; // pass the new subtree root, B, back up
}


// PRovided for us
void removeAVLTree(struct AVLTree *tree, TYPE val) {
	if (containsAVLTree(tree, val)) {
		tree->root = _removeNode(tree->root, val);
		tree->cnt--;
	}
}

TYPE _leftMost(struct AVLNode *cur) {
	while(cur->left != 0) {
		cur = cur->left;
	}
	return cur->val;
}


// This was provided by the worksheet... 
struct AVLNode *_removeLeftmost(struct AVLNode *cur) {
	struct AVLNode *temp;
	if(cur->left != 0) {
		cur->left = _removeLeftmost(cur->left);
		return _balance(cur);
	}
	temp = cur->rght;
	free(cur);
	return temp;
}


// Write this one...
struct AVLNode *_removeNode(struct AVLNode *cur, TYPE val) {
	/*write this*/
	assert(cur != NULL);
	assert(val != NULL);

	// if value == current.value, then handle case where right is null and where right is not null
	if (compare(val, cur->val) == 0) {
		if (cur->right == NULL) {
			return _balance(cur->left);  // this is one of two line of code I changed...
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

	return _balance(cur);  // and this is the other.
	// reasoning: the recursive calls will always have to end recursion at a return statement, so when we are returning a subtree, that is the point at which we should balance it... 

}