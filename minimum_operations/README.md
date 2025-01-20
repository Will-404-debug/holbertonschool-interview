# Minimum Operations

This project calculates the minimum number of operations required to achieve exactly `n` characters in a file that initially contains one character `H`. Only two operations are allowed:
1. **Copy All**: Copies all the current characters.
2. **Paste**: Pastes the copied characters.

## Implementation
The solution uses a prime factorization approach to determine the minimum operations.

### Example
For `n = 9`:
- Operations: `Copy All -> Paste -> Paste -> Copy All -> Paste -> Paste`.
- Total operations: 6.

## Requirements
- Python 3.4.3 or later.
- PEP 8 compliance.

## How to Test
Run the test script:
```bash
./0-main.py
