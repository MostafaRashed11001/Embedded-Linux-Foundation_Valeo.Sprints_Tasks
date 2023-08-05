#!/bin/bash
<<comment
Task 1: Creating a Simple Shell Script for File Copying :

Requirements:
	The shell script should accepts two arguments
		The path of a file to be copied and
	:	The destination path to copy into
	Ensure that the script handles the situation where the destination path may not exist.

	Set the appropriate permissions for the script:
		The owner should have read, write, and execute permissions.
		The group should have read permissions only.
		Any other user should not have read, write, or execute permissions.

Deliverables:
	A shell script file that fulfills the requirements mentioned above.
comment


# Assign the first argument to the variable 'source_file'
source_file="$1"
# Assign the second argument to the variable 'destination_path'
destination_path="$2"


<<test_code
test -f ${source_file} && test -d ${destination_path} && cp ${source_file} ${destination_path} 
chmod 740 ${destination_path}/${source_file##*/} || echo "Your destination path uncorrect"  || echo "Your file path uncorrect"
test_code


# Check if the script is called with exactly 2 arguments
if [ $# -eq 2 ]
then
	# Check if the source file exists
	if [ -f ${source_file} ]
	then
		# Check if the destination path is a directory
		if [ -d ${destination_path} ]
		then
			# Copy the source file to the destination path
			cp ${source_file} ${destination_path}

			# Change the permissions of the copied file to 740 (owner can read, write, and execute; group can read only; others have no permissions)
			chmod 740 ${destination_path}/${source_file##*/}
		else
			# If the destination path is not a directory, display an error message
			echo "Your destination path uncorrect"
		fi
	else
		# If the source file does not exist, display an error message
		echo "Your file path uncorrect"
	fi
else
	# If the script is not called with exactly 2 arguments, display an error message
	echo "Please 2 args only"
fi
