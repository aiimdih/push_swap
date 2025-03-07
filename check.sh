
#!/bin/bash

# Replace 'your_command' with the actual command you want to run.
while true; do
    output=$(arg=$(shuf -i1-500| tr '\n' ' ');./push_swap $arg | wc -ll)
	
    echo "Command output: $output"
    
    # Check if the output is greater than 5500.
    if [ "$output" -gt 5500 ]; then
        echo "Output is greater than 5500. Exiting loop."
        break
    fi

    # Wait for a short period before running the command again.
done
