#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#define Max 10000
#define NUM 26
typedef struct ArcCell {
	int adj;
	char *info;
}ArcCell;// 定义边的类型
typedef struct VertexType {
	int number;
	char *sight;
}VertexType; // 定义图的类型
typedef struct {
	VertexType vex[NUM];
	ArcCell arcs[NUM][NUM];
	int vexnum, arcnum;
}MGraph;
MGraph G;
int P[NUM][NUM];
long int D[NUM];// 辅助变量存储最短路径长度
int x[26] = { 0 };
void CreateUDN(int v, int a);// 创建图的函数
void pingmu();//屏幕输出函数
void ShortestPath(int num);//最短路径函数
void output(int sight1, int sight2);//输出函数
char Menu();// 主菜单
void NextValue(int);
int main() // 主函数
{
	int v0, v1;
	char ck;
	CreateUDN(NUM, 26);
	do
	{
		ck = Menu();
		switch (ck)
		{
		case '1':
			pingmu();
			printf("\n\n\t\t\t请选择出发地序号(1～25)：");
			scanf("%d", &v0);
			printf("\t\t\t请选择目的地序号(1～25)：");
			scanf("%d", &v1);
			ShortestPath(v0);
			output(v0, v1);
			printf("\n\n\t\t\t\t请按回车键继续...\n");
			getchar();
			getchar();
			break;
		case'2':
			printf("欢迎来到河南工程学院！\n");
			printf("天行健，君子以自强不息,意谓以刚毅坚卓的品质，发奋图强，奋斗不止！\n");
			getchar();
			getchar();
			break;
		};
	} while (ck != 'e');
	return 0;
}
char Menu() // 主菜单
{
	char c;
	int flag;
	do
	{
		flag = 1;
		pingmu();
		printf("\n\t\t****************************************\n");
		printf("\t\t欢迎使用河南工程学院导航图系统\n");
		printf("\t\t 1.查询路径 \n");
		printf("\t\t 2.学校简介\n");
		printf("\t\t e.退出 \n");
		printf("\t\t****************************************\n");
		printf("\t\t\t请输入您的选择：");
		scanf("%c", &c);
		if (c == '1' || c == '2' || c == 'e')
			flag = 0;
	} while (flag);
	return c;
}
void CreateUDN(int v, int a) // 创建图的函数
{
	int i, j;
	G.vexnum = v;
	G.arcnum = a;
	for (i = 1; i<G.vexnum; ++i) G.vex[i].number = i;
	G.vex[0].sight = "各个景点名字";
	G.vex[1].sight = "综合楼";
	G.vex[2].sight = "图书馆";
	G.vex[3].sight = "1号教学楼";
	G.vex[4].sight = "2号教学楼";
	G.vex[5].sight = "3号教学楼";
	G.vex[6].sight = "4号教学楼";
	G.vex[7].sight = "5号教学楼";
	G.vex[8].sight = "6号教学楼";
	G.vex[9].sight = "7号教学楼";	
	G.vex[10].sight = "8号教学楼";
	G.vex[11].sight = "9号教学楼";
	G.vex[12].sight = "西门";
	G.vex[13].sight = "南门";
	G.vex[14].sight = "东门";
	G.vex[15].sight = "西区餐厅";
	G.vex[16].sight = "南区餐厅";
	G.vex[17].sight = "西区男生宿舍";
	G.vex[18].sight = "西区女生宿舍";
	G.vex[19].sight = "南区男生宿舍";
	G.vex[20].sight = "南区女生宿舍";
	G.vex[21].sight = "西区操场";
	G.vex[22].sight = "游泳馆";
	G.vex[23].sight = "学生活动中心";
	G.vex[24].sight = "南区操场";
	G.vex[25].sight = "怀若谷";
	for (i = 1; i<G.vexnum; ++i)
	{
		for (j = 1; j<G.vexnum; ++j)
		{
			G.arcs[i][j].adj = Max;
			G.arcs[i][j].info = NULL;
		}
	}

	G.arcs[1][2].adj = G.arcs[2][1].adj = 430;
	G.arcs[1][3].adj = G.arcs[3][1].adj = 415;
	G.arcs[1][13].adj = G.arcs[13][1].adj = 50;
	G.arcs[1][16].adj = G.arcs[16][1].adj = 530;
	G.arcs[1][24].adj = G.arcs[24][1].adj = 635;
	G.arcs[2][4].adj = G.arcs[4][2].adj = 200;	
	G.arcs[2][7].adj = G.arcs[7][2].adj = 357;
	G.arcs[2][12].adj = G.arcs[12][2].adj = 350;
	G.arcs[2][22].adj = G.arcs[22][2].adj = 400;
    G.arcs[3][4].adj = G.arcs[4][3].adj = 20;
	G.arcs[4][5].adj = G.arcs[5][4].adj = 20;
	G.arcs[5][12].adj = G.arcs[12][5].adj = 78;
	G.arcs[6][12].adj = G.arcs[12][6].adj = 78;
	G.arcs[6][7].adj = G.arcs[7][6].adj = 20;
	G.arcs[7][8].adj = G.arcs[8][7].adj = 20;
	G.arcs[8][21].adj = G.arcs[21][8].adj = 100;
	G.arcs[9][10].adj = G.arcs[10][9].adj = 80;
	G.arcs[9][11].adj = G.arcs[11][9].adj = 300;
	G.arcs[9][14].adj = G.arcs[14][9].adj = 200;
	G.arcs[10][25].adj = G.arcs[25][10].adj = 200;
	G.arcs[11][25].adj = G.arcs[25][11].adj = 40;
	G.arcs[14][16].adj = G.arcs[16][14].adj = 240;
	G.arcs[14][20].adj = G.arcs[20][14].adj = 220;
	G.arcs[15][22].adj = G.arcs[22][15].adj = 185;
	G.arcs[15][23].adj = G.arcs[23][15].adj = 190;
	G.arcs[15][17].adj = G.arcs[17][15].adj = 200;
	G.arcs[15][18].adj = G.arcs[18][15].adj = 100;	
	G.arcs[16][19].adj = G.arcs[19][16].adj = 130;
	G.arcs[16][20].adj = G.arcs[20][16].adj = 80;
	G.arcs[21][22].adj = G.arcs[22][21].adj = 50;
	G.arcs[22][23].adj = G.arcs[23][22].adj = 120;
}
void pingmu() // 输出函数
{
	int i;
	printf(" **************************河南工程学院景点概况*****************\n");
	for (i = 1; i<NUM; i++)
	{
		printf("\t\t\t\t(%2d)%-20s\t\t\t", i, G.vex[i].sight);
	}
}
void ShortestPath(int num) // 迪杰斯特拉算法最短路径
{
	int v, w, i, t;// i、w和v为计数变量
	int final[NUM];
	int min;
	for (v = 1; v<NUM; v++)
	{
		final[v] = 0;// 假设从顶点num到顶点v没有最短路径
		D[v] = G.arcs[num][v].adj;// 将与之相关的权值放入D中存放
		for (w = 1; w<NUM; w++)
			P[v][w] = 0;
		if (D[v]<10000) // 存在路径
		{
			P[v][num] = 1; //存在标志置为1
			P[v][v] = 1; //自己到自己
		}
	}
	D[num] = 0;
	final[num] = 1;// 初始化num顶点属于S集合
				   // 开始主循环，每一次求得num到某个顶点的最短路径，并将其加入到S集合 for
	for (i = 1; i<NUM; ++i)// 其余G.vexnum-1个顶点
	{
		min = Max;// 当前所知离顶点num的最近距离
		for (w = 1; w<NUM; ++w)
			if (!final[w])//w顶点在v - s中
				if (D[w]<min)
				{
					v = w;
					min = D[w];
				}
		final[v] = 1; //离num顶点更近的v加入到s集合
		for (w = 1; w<NUM; ++w) // 更新当前最短路径极其距离
			if (!final[w] && ((min + G.arcs[v][w].adj)<D[w]))
				// 不在s集合，并且比以前所找到的路径都短就更新当前路径 //
			{
				D[w] = min + G.arcs[v][w].adj;
				for (t = 0; t<NUM; t++)
					P[w][t] = P[v][t];
				P[w][w] = 1;
			}
	}
}
void output(int sight1, int sight2) // 输出函数
{
	int a, b, c, d, q = 0;
	a = sight2;
	if (a != sight1)// 如果景点二不和景点一输入重合，则进行...
	{
		printf("\n\t从%s到%s的最短路径是", G.vex[sight1].sight, G.vex[sight2].sight);
		printf("\t(最短距离为 %dm.)\n\n\t", D[a]); // 输出sight1到sight2的最短路径长度，存放在D[]数组中
		printf("\t%s", G.vex[sight1].sight);// 输出景点一的名称
		d = sight1;
		for (c = 0; c<NUM; ++c)
		{
		gate:; // 标号，可以作为goto语句跳转的位置
			P[a][sight1] = 0;
			for (b = 0; b<NUM; b++)
			{
				if (G.arcs[d][b].adj<10000 && P[a][b])
					// 如果景点一和它的一个临界点之间存在路径且最短路径
				{
					printf("-->%s", G.vex[b].sight);// 输出此节点的名称
					q = q + 1;// 计数变量加一，满8控制输出时的换行
					P[a][b] = 0;
					d = b; //将b作为出发点进行下一次循环输出，如此反复
					if (q % 8 == 0) printf("\n");
					goto gate;
				}
			}
		}
	}
}



