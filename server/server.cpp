#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
int main() {
  
  int server_fd = socket(AF_INET,SOCK_STREAM,0);
  struct sockaddr_in addr = {
   .sin_family = AF_INET,
   .sin_port = 0x1b39,
   .sin_addr = {.s_addr = INADDR_ANY},  
  };
  socklen_t len = sizeof(addr);
  if(server_fd < 0) {
    std::cout << "Couldn't create socket" << std::endl;
    return 1;
  }
  bind(server_fd,(struct sockaddr*) &addr, len);
 
   
  listen(server_fd, 1);
  while(true) {
    int client_fd = accept(server_fd,(struct sockaddr*) &addr, &len);
  
  char hello[] = "hello client";
  send(client_fd, hello, sizeof(hello), 0);
  
  char buffer[256];
  recv(client_fd, &buffer, sizeof(buffer), 0);
  std::cout << buffer << std::endl;
 
  }
  
  return 0;
}
