# Prime Game 🎲

Maria and Ben are playing a game with prime numbers.  
Given a set of consecutive integers starting from 1 up to and including `n`, they take turns choosing a prime number from the set and **removing that number and its multiples**.  
The player who cannot make a move **loses** the game.

---

## 📖 Problem Statement

They play `x` rounds of the game, where `n` may be different for each round.  

- Maria always goes **first**.
- Both players play **optimally**.
- You need to determine the **winner of each round** and finally return the player who won the **most rounds**.

If both win the same number of rounds, return `None`.

---

## 📝 Function Prototype

```python
def isWinner(x, nums):
    """
    Determines the winner of the Prime Game.

    Args:
        x (int): number of rounds.
        nums (list): list of integers, where each represents 'n' for a round.

    Returns:
        str: "Maria" if Maria wins more rounds,
             "Ben" if Ben wins more rounds,
             None if no overall winner.
    """
```

---

## ⚙️ Constraints
- `1 <= n <= 10000`
- `1 <= x <= 10000`
- No external packages or libraries may be imported.

---

## 📊 Example

```python
x = 3
nums = [4, 5, 1]
```

### Round 1: n = 4
- Maria picks 2 → removes 2, 4 → remaining {1, 3}
- Ben picks 3 → removes 3 → remaining {1}
- **Ben wins**

### Round 2: n = 5
- Maria picks 2 → removes 2, 4 → remaining {1, 3, 5}
- Ben picks 3 → removes 3 → remaining {1, 5}
- Maria picks 5 → removes 5 → remaining {1}
- **Maria wins**

### Round 3: n = 1
- No prime for Maria to pick → **Ben wins**

➡️ Final Result: **Ben** has the most wins.

---

## 🚀 Usage

Example with the provided test file:

```bash
$ cat main_0.py
#!/usr/bin/python3

isWinner = __import__('0-prime_game').isWinner

print("Winner: {}".format(isWinner(5, [2, 5, 1, 4, 3])))
```

Run:
```bash
$ ./main_0.py
Winner: Ben
```

---

## 📂 Repository Structure

```
holbertonschool-interview/
└── primegame/
    ├── 0-prime_game.py   # Implementation of isWinner
    └── main_0.py         # Example test file
```

---

## ✅ Requirements
- Python 3.8+
- Ubuntu 20.04 LTS (Holberton checker environment)

---

## 🧠 Author
**William K. GUILON DRONNIER**
