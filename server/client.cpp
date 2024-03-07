#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

int main() {
 int fd = socket(AF_INET, SOCK_STREAM, 0);
 struct sockaddr_in addr = {
  .sin_family = AF_INET,
  .sin_port = 0x1b39,
  .sin_addr = {.s_addr = INADDR_ANY},
 }; 
  socklen_t len = sizeof(addr); 
  
  int client_fd = connect(fd, (struct sockaddr*) &addr, len);
  if(client_fd < 0) {
    std::cout << "couldnt connect lcient" << std::endl;
    return 1;
  }
  char buffer[256];
  recv(fd, &buffer, sizeof(buffer) , 0);
  std::cout << buffer << std::endl;
  
  char hello_back[] = "hello server";
  send(fd, &hello_back, sizeof(hello_back), 0);

  
  return 0;
}
