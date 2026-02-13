# Data Structures in C / C语言数据结构实现

> **"Data structures are the backbone of efficient algorithms."**
> 这是一个记录我深入学习 **C 语言数据结构** 的代码仓库。从最基础的线性表开始，逐步构建起对底层内存管理和指针操作的深刻理解。
> This repository documents my journey of mastering **Data Structures in C**. Starting from fundamental linear lists, I aim to build a deep understanding of low-level memory management and pointer manipulation.

## 📂 Project Structure (项目结构)

目前已实现以下核心数据结构 (Current Implementations)：

### 1. 线性表 (Linear List)

| 目录 (Directory) | 名称 (Name) | 特性 (Features) | 核心文件 (Core Files) |
| --- | --- | --- | --- |
| **`SeqList`** | [动态顺序表](https://www.google.com/search?q=SeqList.c) <br>

<br> (Dynamic Sequential List) | - 支持动态扩容 (Auto-expansion)<br>

<br>- 连续物理内存<br>

<br>- 随机访问  | `SeqList.c`, `SeqList.h` |
| **`SList`** | [单链表](https://www.google.com/search?q=SListNode.c) <br>

<br> (Singly Linked List) | - 无头结点 (No Sentinel)<br>

<br>- 灵活内存分配<br>

<br>- 适合做其他结构的子结构 | `SListNode.c`, `SListNode.h` |
| **`List`** | [带头双向循环链表](https://www.google.com/search?q=List.c) <br>

<br> (Doubly Circular Linked List) | - **哨兵位 (Sentinel Head)**<br>

<br>- **双向循环 (Bidirectional & Cyclic)**<br>

<br>- 任意位置插入/删除  | `List.c`, `List.h` |

---

## 🚀 Key Highlights (核心亮点)

### 1. 严谨的内存管理 (Memory Management)

所有涉及内存分配的操作（`malloc`, `realloc`）均包含空指针检查，且所有结构均实现了对应的**销毁函数**（`Destroy`），确保无内存泄漏。

> *All memory allocations include `NULL` checks, and every structure comes with a corresponding `Destroy` function to prevent memory leaks.*

### 2. 泛型设计思维 (Generic Design Thinking)

使用 `typedef` 定义数据类型（如 `typedef int SLDataType`），方便未来替换为其他数据类型，增强代码的可维护性。

> *Uses `typedef` to abstract data types, making the code maintainable and adaptable for different data types.*

### 3. 防御式编程 (Defensive Programming)

在关键接口中使用 `assert` 断言，确保指针有效性及索引合法性，快速定位开发过程中的逻辑错误。

> *Extensive use of `assert` to validate pointers and indices, ensuring robustness during development.*

---

## 📝 Code Snippets (代码掠影)

### 双向循环链表的“闭环”初始化

*The elegance of initialization in a circular linked list:*

```c
// List.c
LTNode* LTInit() {
    LTNode* phead = LTBuyNode(-1);
    // 哨兵位指向自己，形成逻辑闭环
    // Sentinel points to itself, forming a logical loop
    phead->next = phead;
    phead->prev = phead;
    return phead;
}

```

### 动态顺序表的自动扩容

*Auto-expansion strategy in Sequential List:*

```c
// SeqList.c
void SLCheckCapacity(SL* ps) {
    if (ps->size == ps->capacity) {
        // 2倍扩容策略 / 2x growth strategy
        int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
        SLDataType* tmp = (SLDataType*)realloc(ps->arr, newCapacity * sizeof(SLDataType));
        // ... (Error handling)
        ps->arr = tmp;
        ps->capacity = newCapacity;
    }
}

```

---

## 🗺️ Roadmap (学习路线)

* [x] **顺序表 (Sequential List)**
* [x] **单链表 (Singly Linked List)**
* [x] **带头双向循环链表 (Doubly Circular Linked List)**
* [ ] 栈与队列 (Stack & Queue)
* [ ] 二叉树 (Binary Tree)
* [ ] 排序算法 (Sorting Algorithms)

---

## 🛠️ How to Build (如何运行)

本项目基于标准的 C11 编写，可以使用 `gcc` 或 Visual Studio 编译。

**Using GCC:**

```bash
# 编译双向链表测试 / Compile List test
gcc List/List.c List/test.c -o list_test
./list_test

```

---

**Author**: A passionate CS student exploring the world of AI & Systems.
**Gitee Mirror**: [https://gitee.com/lu-ma-flies-fast/data-structures-in-c](https://gitee.com/lu-ma-flies-fast/data-structures-in-c)

---