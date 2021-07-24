#include "calculate_balance.h"
#include "../utils/eign_utils.h"

#include <iostream>

using namespace std;

calculateTotalBalance::calculateTotalBalance() {
    cout << "创建了一个calculateJobType对象！" << endl;
}

//calculateTotalBalance::~calculateTotalBalance() {
//    cout << "析构函数" << endl;
//}


/*************************************************
Function:calculateTotalLoad
Description:计算节点的综合负载

Input:判断矩阵、矩阵维数、RI对应表。。。
Return:节点的综合负载评分
*************************************************/
double calculateTotalBalance::calculateTotalLoad() {
    /*1 输入各个节点的资源列表*/

    /* 2 使用AHP计算指标权重值
     *
     * 输入：
     * 判断矩阵A
     * RI
     *
     *
     * */

    /*这些变量要放在形参里面的*/
    // 资源指标个数
    int n = 4;

    // 判断矩阵A
    double p[16] = {1, 1, 3, 5, 1, 1, 3, 5, 0.3333, 0.3333, 1, 2, 0.2, 0.2, 0.5, 1};
    // RI对应表
    double RI[11]={0,0,0.58,0.90,1.12,1.24,1.32,1.41,1.45,1.49,1.51};

    /*计算指标权重*/
//    double *weights = new double[n];

    double *weights;// 只需要定义一个指针数组的首指针即可（或者说只需要定义一个指针即可！！！）
    weights = AHP(n,p,RI);
    for (int i = 0; i < n; i++)
        cout << weights[i] << endl;

    /*3 使用线性加权矩阵求得各节点的负载评价分*/
    /*各项指标权重*/
    double w1 = weights[0],w2 = weights[1],w3 = weights[2],w4 = weights[3];
    /*各项指标值*/
    double R_cpu,R_mem,R_net,R_disk;
    R_cpu = 0.7, R_mem = 0.6, R_net = 0.7, R_disk = 0.8;
    /*计算节点总负载*/
    double load_score = w1 * R_cpu + w2 * R_mem + w3 * R_net + w4 * R_disk;
    cout << "total load_score = " << load_score << endl;

    return load_score;
};