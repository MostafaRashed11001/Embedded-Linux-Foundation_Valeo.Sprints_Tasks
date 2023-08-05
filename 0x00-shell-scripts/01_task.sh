#!/bin/bash
<<comment
Task 1: Creating a Simple Shell Script for File Copying :

Requirements:
	The shell script should accepts two arguments
		The path of a file to be copied and
		The destination path to copy into
	Ensure that the script handles the situation where the destination path may not exist.

	Set the appropriate permissions for the script:
		The owner should have read, write, and execute permissions.
		The group should have read permissions only.
		Any other user should not have read, write, or execute permissions.

Deliverables:
	A shell script file that fulfills the requirements mentioned above.
comment
set -x
source_file="$1"
destination_path="$2"
<<test_code
test -f ${source_file} && test -d ${destination_path} && cp ${source_file} ${destination_path} 
chmod 740 ${destination_path}/${source_file##*/} || echo "Your destination path uncorrect"  || echo "Your file path uncorrect"
test_code

if [ $# -eq 2 ]
then
	if [ -f ${source_file} ]
	then
		if [ -d ${destination_path} ]
		then
			cp ${source_file} ${destination_path}
			chmod 740 ${destination_path}/${source_file##*/}
		else
			echo "Your destination path uncorrect"
		fi
	else
		echo "Your file path uncorrect"
	fi
else
	echo "Please 2 args only"
fi

set +x
