#!/usr/bin/python3
"""
Log Parsing Script

This script reads lines from standard input (stdin), processes log entries,
and computes aggregate metrics. It tracks:
- The total file size processed.
- The count of occurrences for specific HTTP status codes.

Statistics are printed:
- Every 10 lines.
- On receiving a keyboard interrupt (CTRL + C).

Expected log format:
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>

Example:
123.45.67.89 - [2022-03-15 14:32:00] "GET /projects/260 HTTP/1.1" 200 1024

Usage:
    $ ./0-generator.py | ./0-stats.py
"""

import sys

def print_stats(total_size, status_counts):
    """
    Prints the accumulated file size and status code counts in sorted order.

    Args:
        total_size (int): The total file size accumulated.
        status_counts (dict): Dictionary with status codes as keys
                              and their occurrences as values.
    """
    print("File size: {}".format(total_size))
    for code in sorted(status_counts.keys()):
        print("{}: {}".format(code, status_counts[code]))

# Initialize tracking variables
total_size = 0
status_counts = {}
valid_status_codes = {'200', '301', '400', '401', '403', '404', '405', '500'}
line_count = 0

try:
    for line in sys.stdin:
        parts = line.split()
        
        # Ensure the line follows the expected format
        if len(parts) < 7:
            continue
        
        try:
            status_code = parts[-2]
            file_size = int(parts[-1])

            # Update total file size
            total_size += file_size

            # Update status code counts if valid
            if status_code in valid_status_codes:
                status_counts[status_code] = status_counts.get(status_code, 0) + 1

            line_count += 1

            # Print statistics every 10 lines
            if line_count % 10 == 0:
                print_stats(total_size, status_counts)

        except ValueError:
            continue  # Skip the line if file size is not an integer

except KeyboardInterrupt:
    print_stats(total_size, status_counts)
    raise  # Re-raise the exception for proper exit handling
