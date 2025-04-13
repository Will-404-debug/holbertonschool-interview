# Linear Skip Search

## 📚 Description

This project implements an optimized **linear search algorithm** in a **sorted skip list**. A skip list is a singly linked list with an "express lane" that allows faster traversal. This significantly reduces the number of comparisons needed when searching for a value compared to a basic singly linked list.

---

## 🧠 Objective

Create a function that searches for a specific value in a sorted skip list of integers using express lanes.

---

## 🔧 Function Prototype

```c
skiplist_t *linear_skip(skiplist_t *list, int value);
```

### Parameters

- `list`: A pointer to the head of the skip list to search in.
- `value`: The value to search for.

### Return Value

- A pointer to the first node where `value` is located.
- If `value` is not present or if `list` is `NULL`, return `NULL`.

---

## 📌 Requirements

- The list is sorted in ascending order.
- Express nodes are placed at indexes that are multiples of the square root of the list size.
- You **must print** each comparison in the following format:
  ```bash
  Value checked at index [x] = [y]
  ```
- When narrowing the search zone:
  ```bash
  Value found between indexes [a] and [b]
  ```

---

## 🗃️ Data Structures

Defined in `search.h`:

```c
/**
 * struct skiplist_s - Singly linked list with an express lane
 *
 * @n: Integer stored at the node
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 */
typedef struct skiplist_s
{
    int n;
    size_t index;
    struct skiplist_s *next;
    struct skiplist_s *express;
} skiplist_t;
```

---

## 📁 File Structure

```
.
├── 0-linear_skip.c      # Implementation of linear_skip function
├── 0-main.c             # Test case provided
├── search.h             # Header file with structure and prototype
├── skiplist/            # Helper files (create, print, and free skip list)
└── README.md            # This file
```

---

## 🧪 Example Output

Given a skip list with express lanes at indices [0], [4], [8], and [12]:

```
List:
Index[0] = [0]
Index[1] = [1]
Index[2] = [2]
Index[3] = [3]
Index[4] = [4]
Index[5] = [7]
Index[6] = [12]
Index[7] = [15]
Index[8] = [18]
Index[9] = [19]
Index[10] = [23]
Index[11] = [53]
Index[12] = [61]
Index[13] = [62]
Index[14] = [76]
Index[15] = [99]

Express lane:
Index[0] = [0]
Index[4] = [4]
Index[8] = [18]
Index[12] = [61]

Search for 53:
Value checked at index [4] = [4]  
Value checked at index [8] = [18]  
Value checked at index [12] = [61]  
Value found between indexes [8] and [12]  
Value checked at index [8] = [18]  
Value checked at index [9] = [19]  
Value checked at index [10] = [23]  
Value checked at index [11] = [53]  
Found 53 at index: 11

Search for 999:
Value checked at index [4] = [4]  
Value checked at index [8] = [18]  
Value checked at index [12] = [61]  
Value found between indexes [12] and [15]  
Value checked at index [12] = [61]  
Value checked at index [13] = [62]  
Value checked at index [14] = [76]  
Value checked at index [15] = [99]  
Found 999 at index: (nil)
```

---

## 🛠️ Compilation

To compile the project:

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-linear_skip.c skiplist/*.c -lm -o 0-linear_skip
```

To run:

```bash
./0-linear_skip
```

---

## ✅ Sample Output

```
Found 53 at index: 11
Found 2 at index: 2
Found 999 at index: (nil)
```

---

## 🧪 Testing Utilities

The following helper functions are provided (you don't need to submit them):

- `create_skiplist(int *array, size_t size)`
- `print_skiplist(const skiplist_t *list)`
- `free_skiplist(skiplist_t *list)`

Make sure to include `search.h` with your data structure and prototype.

---

## 🧾 Notes

- You do **not** need to implement the helper functions (`create_skiplist`, etc.), as they will be compiled by the checker.
- Ensure your function adheres to the format exactly for output.

---

## 🧑‍💻 Author

**William Guilon Dronnier**  
Project for **Holberton School Interview Preparation**

---

## 📌 Repository

**GitHub Repository:** [holbertonschool-interview](https://github.com/holbertonschool-interview)  
**Directory:** `linear_skip`  
**Files:** `0-linear_skip.c`, `search.h`
