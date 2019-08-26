template <class Key, class Value>
class Node
{
private:
	Key key;
	Value value;
	Node left, right;
	int N; /*节点总数*/
	bool color;/*Red--True, Black--false*/

public:
	Node(Key key, Value value, int N, bool color)
	{
		this->color = color;
		this->key = key;
		this.N = N;
		this->value = value;
	}
};