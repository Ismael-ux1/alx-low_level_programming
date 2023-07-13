#!/usr/bin/python3

"""
This script reads input from stdin line by line and computes metrics.
"""


def print_stats(size, status_codes):
    """
    Prints the accumulated metrics,
    including the file size and the count of status codes.

    Args:
        size (int): The accumulated file size.
        status_codes (dict): The accumulated count of status codes.
    """
    print("File size: {}".format(size))
    for key in sorted(status_codes):
        print("{}: {}".format(key, status_codes[key]))


if __name__ == "__main__":
    import sys

    size = 0
    status_codes = {}
    valid_codes = ['200', '301', '400', '401', '403', '404', '405', '500']
    count = 0

    try:
        for line in sys.stdin:
            # Check if it's time to print the accumulated metrics
            if count == 10:
                print_stats(size, status_codes)
                count = 1
            else:
                count += 1

            # Split the line into separate elements
            line = line.split()

            # Update the accumulated file size
            try:
                size += int(line[-1])
            except (IndexError, ValueError):
                pass

            # Update the count for valid status codes
            try:
                if line[-2] in valid_codes:
                    if status_codes.get(line[-2], -1) == -1:
                        status_codes[line[-2]] = 1
                    else:
                        status_codes[line[-2]] += 1
            except IndexError:
                pass

        # Print the final accumulated metrics
        print_stats(size, status_codes)

    except KeyboardInterrupt:
        # If a keyboard interruption occurs,
        # print the current accumulated metrics and raise the exception again
        print_stats(size, status_codes)
        raise
