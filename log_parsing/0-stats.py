#!/usr/bin/python3
"""
Log parsing script that reads from stdin line by line
and computes metrics.
"""

import sys

def print_stats(total_size, status_counts):
    """Prints accumulated metrics."""
    print("File size: {}".format(total_size))
    for code in sorted(status_counts.keys()):
        print("{}: {}".format(code, status_counts[code]))

# Initialize variables
total_size = 0
status_counts = {}
valid_status_codes = {'200', '301', '400', '401', '403', '404', '405', '500'}
line_count = 0

try:
    for line in sys.stdin:
        parts = line.split()
        
        # Validate format
        if len(parts) < 7:
            continue
        
        try:
            status_code = parts[-2]
            file_size = int(parts[-1])
            
            # Update total file size
            total_size += file_size
            
            # Update status code count
            if status_code in valid_status_codes:
                status_counts[status_code] = status_counts.get(status_code, 0) + 1

            line_count += 1

            # Print statistics after every 10 lines
            if line_count % 10 == 0:
                print_stats(total_size, status_counts)

        except ValueError:
            continue  # Skip line if file size is not an integer

except KeyboardInterrupt:
    print_stats(total_size, status_counts)
    raise
