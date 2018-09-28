#!/usr/bin/python
#filename:backup_ver1.py
import os
import time

#1. the files and directories to be backed up are specified in a list
source = ['/home/autobuild/xh/byte','/home/autobuild/xh/bin']

#2. backup 
target_dir = '/home/autobuild/xh/backup/'

#3. back name  zip  time
target = target_dir + time.strftime('%Y%m%d%H%M%S') + '.zip'
 
 #5 zip command
zip_command = "zip -qr '%s' %s" % (target,' '.join(source))
 
 #run
if os.system(zip_command) == 0:
	print 'success backup to',target
else:
	print 'backup failed'
