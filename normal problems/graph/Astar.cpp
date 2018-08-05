#include <bits/stdc++.h>
using namespace std;

const int kCost1 = 10;//ֱ��һ������
const int kCost2 = 14;//����һ������

struct Point{
    int x,y;//xΪ�����꣬yΪ������
    int F,G,H;//F=G+H
    Point *parent;
    Point(int _x,int _y):x(_x),y(_y),F(0),G(0),H(0),parent(NULL){}
};

class Astar{
public:
    void InitAstar(vector<vector<int> > &maze);
    list<Point *> GetPath(Point &startPoint,Point &endPoint, bool isIgnoreCorner);

private:
    Point *findPath(Point &startPoint,Point &endPoint,bool isIgnoreCorner);
    bool isCanReach(const Point *point,const Point* target,bool isIgnorCorner);
    vector<Point*> getSurroundPoints(const Point *point,bool isIgnorCorner);
    Point* isInList(list<Point*> &pointList,const Point* point);
    Point* getLeastFPoint();//�ӿ����б��з���Fֵ��С�Ľڵ�
    int calG(Point *temp_start,Point *point);
    int calH(Point *point,Point *end);
    int calF(Point *point);

private:
    vector<vector<int> > maze;
    list<Point*> openList;
    list<Point*> closeList;

};

void Astar::InitAstar(vector<vector<int> > &_maze){
    maze = _maze;
}
int Astar::calG(Point *temp_start,Point *point){
    int extraG = (abs(point->x - temp_start->x) + abs(point->y - temp_start->y) == 1? kCost1:kCost2);
    int parentG = point->parent == NULL? 0:point->parent->G;
    return extraG+parentG;
}
int Astar::calH(Point *point,Point *end){
    return sqrt((double)(end->x-point->x)*(double)(end->x-point->x)+(double)(end->y-point->y)*(double)(end->y-point->y))*kCost1;
}
int Astar::calF(Point *point){
    return point->G+point->H;
}
Point* Astar::getLeastFPoint(){
    if(!openList.empty()){
        Point *resPoint = openList.front();
        list<Point*> ::iterator it;
        for(it = openList.begin(); it != openList.end(); ++it){
            Point *p = *it;
            if(resPoint -> F < p->F){
                resPoint = p;
            }
        }
        return resPoint;
    }
    return NULL;
}

Point *Astar::findPath(Point &startPoint,Point &endPoint,bool isIgnoreCorner)
{
	openList.push_back(new Point(startPoint.x,startPoint.y)); //�������,��������һ���ڵ㣬�������
	while(!openList.empty())
	{
		Point *curPoint=getLeastFPoint(); //�ҵ�Fֵ��С�ĵ�
		openList.remove(curPoint); //�ӿ����б���ɾ��
		closeList.push_back(curPoint); //�ŵ��ر��б�
		//1,�ҵ���ǰ��Χ�˸����п���ͨ���ĸ���
		vector<Point*> surroundPoints=getSurroundPoints(curPoint,isIgnoreCorner);
		for(int i=0; i<surroundPoints.size(); ++i)
		{
		    Point *target = surroundPoints[i];
			//2,��ĳһ�����ӣ���������ڿ����б��У����뵽�����б����õ�ǰ��Ϊ�丸�ڵ㣬����F G H
			if(!isInList(openList,target))
			{
				target->parent=curPoint;

				target->G=calG(curPoint,target);
				target->H=calH(target,&endPoint);
				target->F=calF(target);

				openList.push_back(target);
			}
			//3����ĳһ�����ӣ����ڿ����б��У�����Gֵ, �����ԭ���Ĵ�, ��ʲô������, �����������ĸ��ڵ�Ϊ��ǰ��,������G��F
			else
			{
				int tempG=calG(curPoint,target);
				if(tempG<target->G)
				{
					target->parent=curPoint;

					target->G=tempG;
					target->F=calF(target);
				}
			}
			Point *resPoint=isInList(openList,&endPoint);
			if(resPoint)
				return resPoint; //�����б���Ľڵ�ָ�룬��Ҫ��ԭ�������endpointָ�룬��Ϊ���������
		}
	}

	return NULL;
}

std::list<Point *> Astar::GetPath(Point &startPoint,Point &endPoint,bool isIgnoreCorner)
{
	Point *result=findPath(startPoint,endPoint,isIgnoreCorner);
	std::list<Point *> path;
	//����·�������û�ҵ�·�������ؿ�����
	while(result)
	{
		path.push_front(result);
		result=result->parent;
	}

    // �����ʱ�����б���ֹ�ظ�ִ��GetPath���½���쳣
    openList.clear();
	closeList.clear();

	return path;
}

Point *Astar::isInList(list<Point*> &pointList,const Point *point)
{
	//�ж�ĳ���ڵ��Ƿ����б��У����ﲻ�ܱȽ�ָ�룬��Ϊÿ�μ����б����¿��ٵĽڵ㣬ֻ�ܱȽ�����
	list<Point*> ::iterator it;
	for(it = pointList.begin(); it != pointList.end(); ++it){
        Point *p = *it;
        if(p->x==point->x&&p->y==point->y)
			return p;
	}

	return NULL;
}

bool Astar::isCanReach(const Point *point,const Point *target,bool isIgnoreCorner)
{
	if(target->x<0||target->x>maze.size()-1
		||target->y<0||target->y>maze[0].size()-1
		||maze[target->x][target->y]==1
		||target->x==point->x&&target->y==point->y
		||isInList(closeList,target)) //������뵱ǰ�ڵ��غϡ�������ͼ�����ϰ�������ڹر��б��У�����false
		return false;
	else
	{
		if(abs(point->x-target->x)+abs(point->y-target->y)==1) //��б�ǿ���
			return true;
		else
		{
			//б�Խ�Ҫ�ж��Ƿ��ס
			if(maze[point->x][target->y]==0&&maze[target->x][point->y]==0)
				return true;
			else
				return isIgnoreCorner;
		}
	}
}

std::vector<Point *> Astar::getSurroundPoints(const Point *point,bool isIgnoreCorner)
{
	std::vector<Point *> surroundPoints;

	for(int x=point->x-1;x<=point->x+1;x++)
		for(int y=point->y-1;y<=point->y+1;y++)
			if(isCanReach(point,new Point(x,y),isIgnoreCorner))
				surroundPoints.push_back(new Point(x,y));

	return surroundPoints;
}

int main()
{
	//��ʼ����ͼ���ö�ά��������ͼ��1��ʾ�ϰ��0��ʾ��ͨ
	vector<vector<int> > maze={
		{1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,1,1,0,1,0,0,0,0,1},
		{1,0,0,1,1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,0,0,1,1,1},
		{1,1,1,0,0,0,0,0,1,1,0,1},
		{1,1,0,1,0,0,0,0,0,0,0,1},
		{1,0,1,0,0,0,0,1,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1}
	};
	Astar astar;
	astar.InitAstar(maze);

	//������ʼ�ͽ�����
	Point start(1,1);
	Point end(6,10);
	//A*�㷨��Ѱ·��
	list<Point *> path=astar.GetPath(start,end,false);
	//��ӡ
	for(auto &p:path)
		cout<<'('<<p->x<<','<<p->y<<')'<<endl;

	system("pause");
	return 0;
}
