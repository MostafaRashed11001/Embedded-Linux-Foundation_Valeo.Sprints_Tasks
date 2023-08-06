#!/bin/bash
<<comment
Task 2: Backup service :

Create a systemd service for automated backups

Description:

As part of the system administration team, you need to create a systemd service that automates the backup of
a specific directory to another location. The service should run daily at 2 AM and perform a full backup using
the "rsync" command.

Requirements:

	1. The service should be named "backup.service".
	2. The service should start on boot.
	3. The backup process should preserve file permissions, ownership, and timestamps.
	4. The backup should be stored in a timestamped directory within the "/backup" directory (e.g.,/backup/backup_2023-08-04).
	5. The service should delete old backups and keep the last five backups.

Deliverables:

	1. A systemd service file that defines the "backup.service" with the required configuration.
	2. A script or command that performs the backup using the "rsync" command. Any necessary additional configuration files or instructions needed to complete the task.
	3. A brief explanation of the implemented solution and any assumptions made
comment

# Define the source and destination directories for backup
source_dir="/root/Embedded-Linux-Foundation_Valeo.Sprints_Tasks/my_dir_test"
backup_dir="/root/Embedded-Linux-Foundation_Valeo.Sprints_Tasks/0x00-shell-scripts/backup"

# Create a timestamped directory for the backup
backup_timestamp=$(date +"%Y-%m-%d")
backup_destination="${backup_dir}/backup_${backup_timestamp}"

# Create the backup directory
mkdir  "${backup_destination}"

# Run rsync to perform the backup
rsync -av ${source_dir} ${backup_destination}

# Delete old backups, keeping the last five backups
find "${backup_dir}" -maxdepth 1 -type d -name "backup_*" | sort | head -n -5 | xargs rm -rf
