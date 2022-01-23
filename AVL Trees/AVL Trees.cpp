#include<iostream>
using namespace std;
struct AVL
{
	int data;
	AVL* Right;
	AVL* Left;
};
int height(AVL *T)
{
	int h = 0;
	if (T != NULL)
	{
		int l_height = height(T->Left);
		int r_height = height(T->Right);
		int max_height = max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
}
int difference(AVL* T)
{
	int l_height = height(T->Left);
	int r_height = height(T->Right);
	int b_factor = l_height - r_height;
	return b_factor;
}
AVL* RR_Rotate(AVL* parent)
{
	AVL* T = parent->Right;
	parent->Right = T->Left;
	T->Left = parent;
	return T;
}
AVL* LL_Rotate(AVL* parent)
{
	AVL* T = parent->Left;
	parent->Left = T->Right;
	T->Right = parent;
	return T;
}
AVL* RL_Rotate(AVL* parent)
{
	AVL* T = parent->Right;
	parent->Right = LL_Rotate(T);
	return LL_Rotate(parent);

}
AVL* LR_Rotate(AVL* parent)
{
	AVL* T = parent->Left;
	parent->Left = RR_Rotate(T);
	return RR_Rotate(parent);
}
AVL* Balance(AVL* T)
{
	int bal_factor = difference(T);
	if (bal_factor > 1)
	{
		if (difference(T->Left) > 1)
		{
			T=LL_Rotate(T);
		}
		else
		{
			T = LR_Rotate(T);
		}
	}
	else if (bal_factor < -1)
	{
		if (difference(T->Right) < 1)
		{
			T = RR_Rotate(T);
		}
		else
		{
			T = RL_Rotate(T);
		}
	}
	return T;
}
AVL* insertion(AVL* R, int V)
{
	if (R == NULL)
	{
		R = new AVL;
		R->data = V;
		R->Left = NULL;
		R->Right = NULL;
		return R;
	}
	else if (V < R->data)
	{
		R->Left = insertion(R->Left,V);
		R = Balance(R);
	}
	else if (V > R->data)
	{
		R->Right = insertion(R->Right,V);
		R = Balance(R);
	}
	else
	{
		cout << "Duplication not allowed\n";
	}
	return R;
	
}
void display(AVL* T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		display(T->Left);
		cout << T->data << "\t";
		display(T->Right);
	}
}
int main()
{
	AVL* T = NULL;
	T = insertion(T, 1);
	T = insertion(T, 2);
	T = insertion(T, 3);
	T = insertion(T, 4);
	T = insertion(T, 5);
	T = insertion(T, 6);
	T = insertion(T, 7);
	display(T);
	system("pause");
	return 0;
}