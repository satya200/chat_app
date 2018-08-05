import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)		                #line 2: create a socket object
host = "192.168.0.7"
port = 2001

s.connect((host, port))
# s.send("Hello server...")
print s.recv(100)
s.send("hello world !")
# message = raw_input("->")
# while message != 'q':
#     s.send(message)
#     data = s.recv(1000)
#     print "received from server :" + data
#
#     message = raw_input("->")

s.close()