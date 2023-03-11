#!/bin/bash

# Author : Johan Jino (@johanjino)
# Year   : 2023

# Initialize counters
non_empty_count=0
total_count=0

# Loop through all .s files
for file in bin/output/*.s; do
    if [ -s "$file" ]; then
        # File is not empty
        ((non_empty_count++))
    fi
    ((total_count++))
done

# Echo results
echo "Number of files parsed: $non_empty_count"
echo "Total number of files: $total_count"
