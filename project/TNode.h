class TNode
{
private:
	char data;
	TNode* left;
	TNode* right;
public:
	TNode(char val);
	void setdata(char d);
	char getdata();
	void setright(TNode* p);
	TNode*& getright();
	void setleft(TNode* p);
	TNode*& getleft();



};
