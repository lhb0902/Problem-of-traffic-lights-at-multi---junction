/*
��Ŀ�����·�ڽ�ͨ������
�������׺Ʋ�
ʱ�䣺2020.5.30
*/


#include<iostream>
using namespace std;

//���ڽӾ������ʽ�洢ͼ
int adjacency_matrix[13][13] =
{
	{0,0,0,0,1,1,1,0,0,1,0,0,0},
    {0,0,0,0,0,1,1,1,0,1,1,0,0},
    {0,0,0,0,0,0,0,0,0,1,1,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,1,0,0,1,0,0},
    {1,1,0,0,0,0,1,0,0,0,1,1,0},
    {1,1,0,0,0,1,0,0,0,0,1,1,0},
    {0,1,0,0,1,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,1,1,0,0,0,0,0,0,0,0,0,0},
    {0,1,1,0,1,1,1,0,0,0,0,0,0},
    {0,0,1,0,0,1,1,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0}
};

//�ڵ�Ķ���
struct NODE
{
	int number;
	int sides;
	int color;
	int work;
}item[13];

//�ڵ�ȵ�ͳ�ƺ���
int sides_number()
{
	for (int i = 0; i < 13; i++)
	{
		int work = 0;
		for (int j = 0; j < 13; j++)
		{
			if (adjacency_matrix[i][j] == 1)work++;
		}
		item[i].number = i + 1;
		item[i].sides = work;
	}
	cout << "�ڵ�Ķ�ͳ�Ƴɹ���"<<endl;
	cout << "�ڵ�Ķȵ�ͳ�ƽ�����£�"<<endl;
	for (int i = 0; i < 13; i++)
	{
		cout << i + 1 << "�ڵ�Ķ�:" << item[i].sides << endl;
	}
	return 0;
}

//�����������
int rank_[13];

//Ѱ�Ҷ����Ľڵ�
int indexes(){

		int work = 0;
		int max = 0;
		int j = 0;
		for (; j < 13; j++)
		{
			if (item[j].sides >= max&&item[j].work==0)
			{
				work = j;
				max = item[j].sides;
			}
		}
		item[work].work = 1;
		return work+1;
}

// ������������
int indexes_()
{
	for (int i = 0; i < 13; i++)
		rank_[i] = indexes();
	return 0;
}

//����Ҫʹ�õ���ɫ��
int color[13] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };

//Ϳɫ�㷨
int graph_coloring() {
	//Ϊ�����Ľڵ��ʼ��Ϳɫ
	item[rank_[0]-1].color = 1;
	for (int i = 0; i < 13; i++)
	{
		for (int z = 0; z < 13; z++)
		{
			color[z] = z + 1;
		}
		for (int j = 0; j < 13; j++)
		{
			if (adjacency_matrix[item[rank_[i] - 1].number - 1][j] == 1)
			{
				for (int a = 0; a < 13; a++)
				{
					if (item[rank_[a] - 1].number == j + 1)
					{
						if (item[rank_[a] - 1].color > 0 && item[rank_[a] - 1].color < 8)
							color[item[rank_[a] - 1].color - 1] = 0;
					}
				}
			}
		}
		for (int x = 0; x < 13; x++)
		{
			if (color[x] != 0)
			{
				item[rank_[i] - 1].color = color[x];
				break;
			}
		}
	}
	cout << "Ϳɫ�ɹ���"<<endl;
	return 0;
}

int main() {

	//�Խڵ�ĶȽ���ͳ��
	sides_number();

	//����ȵ�ͳ�ƽ��
	for (int i = 0; i < 13; i++)
		item[i].work = 0;
	indexes_();
	cout << '\n' << "***************************************" << endl;

	//���������
	cout << "��������˳�����Ϳɫ��" << endl;
	for (int i = 0; i < 13; i++)
		cout << rank_[i] << " ";
	cout <<'\n'<< "***************************************" << endl;

	//�������������Ϳɫ
	graph_coloring();

	//���Ϳɫ������Ч��
	for (int i = 0; i < 13; i++)
	{
		cout << item[i].number <<"�ڵ����ɫΪ��"<< " " << item[i].color << endl;
	}
	cout << "�ڵ���Ϊ��Ŀ��ģ���ϵ��´����������α��";
	system("pause");
}