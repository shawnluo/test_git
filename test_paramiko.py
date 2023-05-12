import paramiko
import signal
import time

# create an SSH client
ssh_client = paramiko.SSHClient()

# automatically add the remote server's host key
ssh_client.set_missing_host_key_policy(paramiko.AutoAddPolicy())

# connect to the remote server
ssh_client.connect(hostname='remote.server.com', username='username', password='password')

# execute a long running command
stdin, stdout, stderr = ssh_client.exec_command('ping 8.8.8.8')

# read the output of the command
output = ''
while not stdout.channel.exit_status_ready():
    # read the output from the channel
    output += stdout.channel.recv(1024).decode('utf-8')

    # wait for the channel to be ready for output
    time.sleep(0.1)

# print the output of the command
print(output)

# get the process ID (PID) of the command
pid = stdout.channel.get_id()

# send a SIGTERM signal to the command to terminate it
ssh_client.exec_command(f'kill -15 {pid}')

# close the SSH client
ssh_client.close()


#=========================================================================================================

import paramiko
import signal
import time

# create an SSH client
ssh_client = paramiko.SSHClient()

# automatically add the remote server's host key
ssh_client.set_missing_host_key_policy(paramiko.AutoAddPolicy())

# connect to the remote server
ssh_client.connect(hostname='remote.server.com', username='username', password='password')

# execute a long running command
stdin, stdout, stderr = ssh_client.exec_command('sleep 30')

# wait for the command to run for some time
time.sleep(5)

# get the process ID (PID) of the command
pid = stdout.channel.get_id()

# send a SIGTERM signal to the command to terminate it
ssh_client.exec_command(f'kill -15 {pid}')

# close the SSH client
ssh_client.close()

#=========================================================================================================

import paramiko

# create an SSH client
ssh_client = paramiko.SSHClient()

# automatically add the remote server's host key
ssh_client.set_missing_host_key_policy(paramiko.AutoAddPolicy())

# connect to the remote server
ssh_client.connect(hostname='remote.server.com', username='username', password='password')

# execute the ps command
stdin, stdout, stderr = ssh_client.exec_command('ps -ef')

# read the output of the command
ps_output = stdout.read().decode('utf-8')

# print the output
print(ps_output)

# close the SSH client
ssh_client.close()


import paramiko

# create an SSH client
ssh_client = paramiko.SSHClient()

# automatically add the remote server's host key
ssh_client.set_missing_host_key_policy(paramiko.AutoAddPolicy())

# connect to the remote server
ssh_client.connect(hostname='remote.server.com', username='username', password='password')

# execute the ping command
stdin, stdout, stderr = ssh_client.exec_command('ping -c 4 8.8.8.8')

# read the output of the command
ping_output = stdout.read().decode('utf-8')

# print the output
print(ping_output)

# close the SSH client
ssh_client.close()



import paramiko

# create SSH client
ssh_client = paramiko.SSHClient()
ssh_client.set_missing_host_key_policy(paramiko.AutoAddPolicy())

# connect to the remote server
ssh_client.connect(hostname='example.com', username='myuser', password='mypassword')

# execute a command with a timeout of 10 seconds
stdin, stdout, stderr = ssh_client.exec_command('ls -l', timeout=10)

# read the output of the command
output = stdout.read().decode('utf-8')

# print the output
print(output)

# close the SSH client
ssh_client.close()

