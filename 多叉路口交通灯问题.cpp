/*
项目：多叉路口交通灯问题
姓名：雷浩波
时间：2020.5.30
*/


#include<iostream>
using namespace std;

//以邻接矩阵的形式存储图
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

//节点的定义
struct NODE
{
	int number;
	int sides;
	int color;
	int work;
}item[13];

//节点度的统计函数
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
	cout << "节点的度统计成功！"<<endl;
	cout << "节点的度的统计结果如下："<<endl;
	for (int i = 0; i < 13; i++)
	{
		cout << i + 1 << "节点的度:" << item[i].sides << endl;
	}
	return 0;
}

//排序的索引表
int rank_[13];

//寻找度最大的节点
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

// 建立索引表函数
int indexes_()
{
	for (int i = 0; i < 13; i++)
		rank_[i] = indexes();
	return 0;
}

//定义要使用的颜色集
int color[13] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };

//涂色算法
int graph_coloring() {
	//为度最大的节点初始化涂色
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
	cout << "涂色成功！"<<endl;
	return 0;
}

int main() {

	//对节点的度进行统计
	sides_number();

	//输出度的统计结果
	for (int i = 0; i < 13; i++)
		item[i].work = 0;
	indexes_();
	cout << '\n' << "***************************************" << endl;

	//输出索引表
	cout << "将以以下顺序进行涂色：" << endl;
	for (int i = 0; i < 13; i++)
		cout << rank_[i] << " ";
	cout <<'\n'<< "***************************************" << endl;

	//依据索引表进行涂色
	graph_coloring();

	//输出涂色的最终效果
	for (int i = 0; i < 13; i++)
	{
		cout << item[i].number <<"节点的颜色为："<< " " << item[i].color << endl;
	}
	cout << "节点编号为题目建模从上到下从左至右依次编号";
	system("pause");
}