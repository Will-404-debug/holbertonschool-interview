#!/usr/bin/python3
"""
Log parsing script.

This script reads lines from stdin, extracts HTTP status codes and file sizes,
and computes statistics. It prints the total file size and counts of each status code
every 10 lines and upon receiving a keyboard interruption (CTRL + C).
"""

import sys

def print_stats(total_size, status_counts):
    """Print the computed statistics."""
    print("File size: {}".format(total_size))
    for code in sorted(status_counts.keys()):
        print("{}: {}".format(code, status_counts[code]))

# Initialize variables
total_size = 0
status_counts = {}
valid_status_codes = {200, 301, 400, 401, 403, 404, 405, 500}
line_count = 0

try:
    for line in sys.stdin:
        parts = line.split()
        
        # Validate line format
        if len(parts) < 7:
            continue
        
        try:
            status_code = int(parts[-2])
            file_size = int(parts[-1])
        except ValueError:
            continue

        if status_code in valid_status_codes:
            status_counts[status_code] = status_counts.get(status_code, 0) + 1
        total_size += file_size
        line_count += 1

        # Print statistics after every 10 lines
        if line_count % 10 == 0:
            print_stats(total_size, status_counts)

except KeyboardInterrupt:
    # Handle CTRL + C interruption
    print_stats(total_size, status_counts)
    raise
