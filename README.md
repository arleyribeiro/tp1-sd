# Server/Client Applications #

Server Socket
- create a socket - Get the file descriptor!
- bind to an address -What port am I on?
- listen on a port, and wait for a connection to be established.
- accept the connection from a client.
- send/recv - the same way we read and write for a file.
- shutdown to end read/write.
- close to releases data.

Client Socket
- create a socket.
- bind* - this is probably be unnecessary because you're the client, not the server.
- connect to a server.
- send/recv - repeat until we have or receive data
- shutdown to end read/write.
- close to releases data.


