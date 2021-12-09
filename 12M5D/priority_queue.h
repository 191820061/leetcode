//
// Created by 13047 on 2021/12/8.
//

#ifndef INC_12M5D_PRIORITY_QUEUE_H
#define INC_12M5D_PRIORITY_QUEUE_H

#include <iostream>

#define DEFAULT_CPTY 30000

template<typename T>
class priority_list {
public:
    priority_list() : nofns(0), capacity(DEFAULT_CPTY), compare(&_compare) {
        pt = new T[capacity];
    }

    priority_list(int val) : nofns(0), capacity(DEFAULT_CPTY), compare(&_compare) {
        //构造函数，指定空间大小，但实际的空间大小为2的n次方
        while (capacity < val) capacity *= 2;//计算需要申请空间容量大小
        pt = new T[capacity];//申请空间
    }

    explicit priority_list(bool (*cmp)(T &, T &)) : nofns(0), capacity(DEFAULT_CPTY), compare(cmp) {
        pt = new T[capacity];//申请空间
    }

    priority_list(int val, bool (*cmp)(T &, T &))\
: nofns(0), capacity(DEFAULT_CPTY), compare(cmp) {
        //设置队列容量和优先级规则//
        while (capacity < val) capacity *= 2;
        pt = new T[capacity];//申请空间
    }

    ~priority_list() {// 析构函数
        if (nullptr != pt) {
            delete[] pt;//释放申请的空间
            pt = nullptr;//置空
        }
    }


    bool push(const T &t) {//入队操作
        T *ptt = pt;
        pt[nofns++] = t;//加入队列
        heap_up();//向上重新调整堆。
        return true;
    }

    bool pop() {
        if (nofns == 0)
            return false;
        if (nofns == 1) {
            nofns = 0;
            return true;
        }
        pt[0] = pt[nofns - 1];//将队尾数据复制到队头，
        nofns--;//队元素个数减一
        heap_down(); //重新向下调整堆
        return true;
    }

    T top() {
        return pt[0];//返回队头元素
    }


    bool is_empty_pl() const {
        return 0 == nofns;//返回队是否为空
    }

    int get_size() const {
        return nofns;//返回队元素个数
    }

    int get_capacity() const {
        return capacity;//返回队当前容量应该为2的n次方
    }

private:

    void heap_up();

    void heap_down();

    void obj_cpy(T *dest, const T *sour, int n) {//复制函数
        for (int i = 0; i < n; i++)
            dest[i] = sour[i];
    }

    bool static _compare(T &t1, T &t2) {//默认的比较函数
        return t1 < t2;
    }

private:
    T *pt;//数据
    int nofns;// 元素个数
    int capacity;// 队容量
    bool (*compare)(T &, T &);//比较函数

};

template<typename T>
void priority_list<T>::heap_up() {
    //当插入队尾后，需要向上重新调整堆结构。
    T temp;
    int itr = nofns - 1;//iter指向最后一个元素
    while (itr > 0) {
        if ((compare(pt[itr / 2], pt[itr]))) {
            //同父节点进行比较，如果满足，交换，上浮
            temp = pt[itr];
            pt[itr] = pt[itr / 2];
            pt[itr / 2] = temp;
            itr = itr / 2;//itr指向他的父节点
            continue;
        }
        break;//不满足条件，即已经处在对的位置，直接结束
    }
}

template<typename T>
void priority_list<T>::heap_down() {
    //当对头出栈韩，需要将队尾数据移动到队头，向下重新调整堆
    T temp;
    int pitr = 0, citr;
    while (pitr <= nofns / 2 - 1) {
        //对一颗完全二叉树来说，第一个存在孩子节点的节点为nofns / 2 - 1;
        citr = pitr * 2 + 1;//pitr的左孩子节点
        if (citr + 1 < nofns && compare(pt[citr], pt[citr + 1]))// 如左孩子小于右孩子
            citr++;//如果存在右孩子节点，citr 指向其中满足条件的。
        if ((compare(pt[pitr], pt[citr]))) {
            //如果孩子节点同父节点满足条件，如父节点小于子节点，交换父子节点
            temp = pt[citr];
            pt[citr] = pt[pitr];
            pt[pitr] = temp;
            pitr = citr;//继续将pitr指向孩子节点，进行下一次的比较
            continue;
        }
        break;//如果处在对的位置，直接结束，不需要继续比较下去了
    }
}

#endif //INC_12M5D_PRIORITY_QUEUE_H
