#include "RedBlackBST.h"
#define Node Node<int, int>
template <class Key, class Value>
class RedBlackBST
{
private:
	Node root;

public:
	bool isRed(Node h)
	{
		if (x == nullptr) return false;
		else
			return x.color == true;
	}

	int size(Node h)
	{
		return h.N;
	}
	Node rotateLeft(Node h)
	{
		Node x = h.right;
		h.right = x.left;
		x.left = h;
		x.color = h.color;
		h.color = true;
		x.N = h.N;
		h.N = 1 + size(h.left) + size(h.right);
	}

	Node rotateRight(Node h)
	{
		Node x = h.left;
		h.left = x.right;
		x.right = h;
		x.color = h.color;
		h.color = true;
		x.N = h.N;
		h.N = 1 + size(h.left) + size(h.right);
	}

	void flipColors(Node h)
	{
		h.color = true;
		h.left.color = false;
		h.right.color = true;
	}

	void put(Key key, Value value)
	{
		root = put(root, key, value);
		root.color = false;
	}

	Node put(Node h, Key key, Value value)
	{
		if (h == nullptr)
			return new Node(key, value, 1, true);
		if (key < h.key)
			h.left = put(h.left, key, value);
		else if (key > h.key)
			h.right = put(h.right, key, value);
		else
			h.value = value;

		if (isRed(h.right) && !isRed(h.left))
			h = rotateLeft(h);
		if (isRed(h.left) && !isRed(h.left.left))
			h = rotateRight(h);
		if (isRed(h.left) && isRed(h.right))
			flipColors(h);

		h.N = size(h.left) + size(h.right) + 1;
		return h;
	}
};
