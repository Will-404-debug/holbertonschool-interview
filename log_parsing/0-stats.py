#!/usr/bin/python3
"""
Continuously reads input lines and processes them to compute metrics.

The script:
- Tracks total file size.
- Counts occurrences of specific HTTP status codes.
- Prints metrics every 10 lines or on keyboard interruption (CTRL + C).

Expected input format:
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>
"""

import sys

# Initialize variables
total_file_size = 0
line_count = 0
valid_status_codes = {'200', '301', '400', '401', '403', '404', '405', '500'}
status_code_count = {code: 0 for code in valid_status_codes}


def print_metrics():
    """
    Prints the computed metrics to stdout.
    """
    print(f"File size: {total_file_size}")
    sys.stdout.flush()  # Ensure output is displayed immediately
    for status_code in sorted(status_code_count.keys()):
        if status_code_count[status_code] > 0:
            print(f"{status_code}: {status_code_count[status_code]}")
            sys.stdout.flush()  # Flush after each print


if __name__ == "__main__":
    try:
        for line in sys.stdin:
            parts = line.split()

            # Ensure line has enough parts
            if len(parts) < 7:
                continue

            status_code = parts[-2]
            file_size = parts[-1]

            # Validate file size (should be an integer)
            try:
                file_size = int(file_size)
                total_file_size += file_size
            except ValueError:
                continue  # Skip line if file size is not a valid integer

            # Validate and count status codes
            if status_code in status_code_count:
                status_code_count[status_code] += 1

            line_count += 1

            # Print metrics every 10 lines
            if line_count % 10 == 0:
                print_metrics()

        # Ensure output prints even if only 1 line was processed
        if line_count > 0:  # Always print if at least one valid line was processed
            print_metrics()
        else:
            # Print "File size: 0" for empty files
            print("File size: 0") # Added space after colon haha
            sys.stdout.flush()

    except KeyboardInterrupt:
        print_metrics()  # Print final stats before exiting
        sys.exit(0)  # Exit cleanly without traceback
