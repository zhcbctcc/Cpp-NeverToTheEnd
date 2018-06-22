数据结构--线性表详解（一）https://blog.csdn.net/qq_35644234/article/details/53172539

1:线性表是最常用且是最简单的一种数据结构。形如：A1、A2、A3….An这样含有有限的数据序列，我们就称之为线性表。
2、线性表的两种表示形式
顺序表示（其实就是数组）
链表表示

3、线性表一般操作的介绍 
线性表一般包含如下几种操作

线性表的操作包括如下几种
  （1） InitList(& L)
        //构造一个空的线性表 
  （2） DestroyList(& L)
       //线性表存在了，消耗一个线性表
  （3） ClearList（&L ）
       //清空线性表中的内容
  （4） ListEmpty（L）
       //判断线性表是否为空
  （5） ListLength（L）
        //返回线性表的长度
  （6） GetElem（L，i，& e）
        //返回线性表i位置上的元素值，通过e返回     
  （7） PriorElem（L，cur_e,&pre_e）
       //如果cur_e是线性表中的元素，而且不是第一个，那么我们就可以返回该元素前一个元素的值
  （8） NextElem（L，cur_e,&next_e）
       //如果cur_e是线性表中的元素，而且不是最后一个，就返回它下一个元素的值
  （9） Listinsert(&L,i,e)
        //如果线性表存在了，而且i符合条件，则在i位置插入一个元素
  （10）ListDelete（&L,i）
       //删除i位置上的元素
 （11） ListDelete_data(&L,e,order)
      //删除指定的元素e，order决定是删除一个，还是全部。
 （12） Connect_two_List(L_a,L_b,& L_c)
      //连接两个线性表，除去重复的内容    
 （13）print(L)
       //打印线性表 
      
5、线性表顺序表示实现–initList函数 
因为顺序表示就是对数组进行一些操作，我们在第四点已经给出了我们顺序表示线性表的一个结构体，我们要创建一个空表（没有元素的表），我们
就是让表的长度为0，另外，还要对data进行堆内存的分配和初始容量的初始化。

//创建一个空的线性表
void InitList(List & newList) {
    //初始容量为startsize
    newList.size = startsize;
    //首先开辟空间
    newList.data = new Elemtype[newList.size];
    //空表，长度是0
    newList.length = 0;

}

6、线性表顺序表示实现–DestroyList函数
//线性表存在了，现在要销毁线性表
void DestroyList(List & newList) {
    newList.length = 0;
    newList.data = 0;
    //一定要先释放堆内存
    delete[] newList.data;
    //没此释放堆内存后，并将对应的指针赋予NULL是一个良好的习惯
    newList.data = NULL;
}

7、线性表顺序表示实现–ClearList函数

//线性表存在了，但是现在想清空整个线性表
void ClearList(List & newList) {
    newList.length = 0;
    //一定要先释放堆内存
    delete[] newList.data;
    //每次释放堆内存后，并将对应的指针赋予NULL是一个良好的习惯
    newList.data = NULL;
    //重新为存放元素的变量开辟一个新的堆内存
    newList.data = new Elemtype[newList.size];

}

8、线性表顺序表示实现–ListEmpty函数

//判读线性表是否为空
bool ListEmpty(List newList) {
    return newList.length;
}

9、线性表顺序表示实现–ListLength函数

//返回线性表的长度
int ListLength(List newList) {
    return newList.length;
}

10、线性表顺序表示实现–GetElem函数

//返回线性表上某个位置上的元素的值,记住我们的位置是从1开始计算的。
void GetElem(List newList, int i, Elemtype &e) {
    if (ListEmpty(newList)) {
        cout << "当前线性表是空表" << endl;
        return;
    }
    if (i<1 || i>newList.length) {
        cout << "当前位置超出了线性表的范围" << endl;
        return;
    }
    e = newList.data[i - 1];
}

我们需要考虑这个函数的时间复杂度：因为我们是通过下标进行查找对应的元素的，所以它是时间复杂度为：O(1),这个和我们后边说的链式结构
的查找比起来，是占了很大优势的

11、线性表顺序表示实现–PriorElem函数 
我们在执行这个函数的第一步就是判断我们的那个元素在不在线性表中且不是第一个元素，这样我们就可以直接返回该元素的前一个元素的值。


//判读元素的位置的函数
//我们这里直接返回该元素的下标
int LocationElem(List newList, Elemtype e){
    int i;
    for (i = 0; i < newList.length; i++) {
        if (newList.data[i] == e) {
            return i;
        }
    }
    return -1;
}
这个函数的时间复杂为：假定我们有n个元素，那么它的查找时间复杂为O(n),但是因为我们使用的是顺序结构，所以我们可以很方便的使用其他可以减低时间复杂的查找算法，例如二分查找，它的时间复杂度为：O(logn)

//获取前驱的元素
void PriorElem(List newList, Elemtype cur_e, Elemtype & pre_e) {
    int location = 0;
    location = LocationElem(newList, cur_e);
    //如果Location是-1，说明cur_e不在线性表中
    if (location == -1) {
        cout <<cur_e<< "不在线性表中" << endl;
        return;
    }
    //如果Location是0，说明cur_e在线性表第一个位置，没有前一个元素
    if (location == 0)
    {
        cout << cur_e << "是线性表的第一个元素，没有前驱" << endl;
        return;
    }
    pre_e = newList.data[location - 1];
}

这个函数的时间复杂主要是受LocationElem函数的影响， 
12、线性表顺序表示实现–NextElem函数 
这个函数和前面的函数是一样的，我们只要修改一个位置的参数就可以了，那就是判断第一个元素的变为判断最后一个元素

//获取后驱元素
void NextElem(List newList, Elemtype cur_e, Elemtype & next_e) {
    int location = 0;
    location = LocationElem(newList, cur_e);
    //如果Location是-1，说明cur_e不在线性表中
    if (location == -1) {
        cout << cur_e << "不在线性表中" << endl;
        return;
    }
    //如果Location是0，说明cur_e在线性表最后一个位置，没有后一个元素
    if (location == newList.length-1)
    {
        cout << cur_e << "是线性表的最后一个元素，没有后驱" << endl;
        return;
    }
    next_e = newList.data[location - 1];
}

这个函数的时间复杂为 
13、线性表顺序表示实现–Listinsert函数

//向线性表中插入一个元素，这里我们需要判断插入位置是否合法
//除此之外，我们还需要检测元素的容量是否已经到达了最大值
void Listinsert(List & newList, int i, Elemtype e) {
    //插入的位置不合法
    if (i<1 || i>newList.length+1) {
        cout << "请检查插入位置是否正确" << endl;
        return;
    }
    int j = 0;
    //此时达到了线性表的最大容量，我们需要重新为线性表分配新的内存。
    if (newList.length == newList.size) {
        //先保存之前的内容。
        Elemtype * p =new Elemtype[newList.length];
        for (j = 0; j < newList.length; j++) {
            p[j] = newList.data[j];
        }
        //扩大容量
        newList.size += sizestep;
        delete[] newList.data;
        //重新分配内存
        newList.data = new Elemtype[newList.size];
        //恢复之前内容
        for (j = 0; j < newList.length; j++) {
            newList.data[j] = p[j];
        }
    }
    //插入内容
    for (int k = newList.length; k >i-1; k-- ){
        newList.data[k]=newList.data[k-1];
    }
    newList.data[i - 1] = e;
    ++newList.length;
}

线性表的顺序结构表示的时候，它的最大的缺点就是在插入和删除的时候，需要移动大量的元素，此时，我们插入一个元素的时间复杂为：O(n),时间复杂度虽然是线性的，但是由于它需要移动大量的元素，这也就早造成了它的时间效率的比较低的 
14、线性表顺序表示实现–Listdelete函数

//线性表删除一个元素，我们需要判断删除的位置是否合法
void Listdelete(List & newList, int i) {
    //删除的位置不合法
    if (i<1 || i>newList.length) {
        cout << "请检查插入位置是否正确" << endl;
        return;
    }
    for (int j = i - 1; j < newList.length; j++) {
        newList.data[j] = newList.data[j + 1];
    }
    --newList.length;
}

线性表的删除和插入是差不多的意思，都是要对数组中的元素进行移动。 
15、线性表顺序表示实现–Listdelete_data函数


//按照元素的值，来删除对应元素的内容，
//这个时候我们通过传个参数，来决定我们是删除第一个该元素，
//0,删除一个，1，删除所有
//还是把所有的元素都给删除了
//如果不存在该元素，就直接返回
void Listdelete_data(List & newList, Elemtype e,int order) {
   int flag=0;
    for (int i = 0; i < newList.length; i++) {
        if (newList.data[i] == e) {
            flag=1;
            //删除对应的位置上的元素，而且i也要减少一个
            Listdelete(newList, i + 1);
            --i;
            if (order == 0) {

                return;
            }
        }
    }
    if(flag==1)
    return ;
    cout << e << "不在线性表中" << endl;
}

16、线性表顺序结构表示实现–Connect_two_List函数 
当我们要进行两个线性表的链接的时候，我们最好是希望这两个链表是有序的。

//连接两个线性表
void Connect_two_List(List a, List b, List & c) {
    //对c进行一些数据初始化
    c.length = c.size = a.length + b.length;
    c.data = new Elemtype[c.size];

    //这里采用指针的方式进行数据的移动,我们先把a和b数据第一个和最后一个元素的位置找出来
    int i = 0;
    int j = 0;
    int k = 0;

    while (i <= a.length-1 && j<= b.length-1) {
        if (a.data[i] < b.data[j])
        {
            c.data[k++] = a.data[i++];

        }
        else if(a.data[i] > b.data[j]) c.data[k++] = b.data[j++];
        else {
            c.data[k++] = b.data[j++]; i++; --c.length;
        }
    }
    while (i <= a.length - 1)
    {
        c.data[k++] = a.data[i++];
    }
    while (j <= b.length - 1)
    {
        c.data[k++] = b.data[j++];
    }
}

我们通过分析我们连接函数的代码，我们可以发现，我们将两个元素组合在一起的时候的时间复杂为O(a.lenght+b.lenght).

17、线性表顺序结构表示实现–print函数

void print(List & L) {
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}
