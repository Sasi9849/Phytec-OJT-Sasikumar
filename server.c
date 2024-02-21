#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define SIZE 1024

void send_file_data(FILE* fp, int sockfd, struct sockaddr_in addr)
{
  int n;
  unsigned char buffer[SIZE]; // Use unsigned char for binary data

  // Sending the data
  while ((n = fread(buffer, 1, SIZE, fp)) > 0)
  {
    printf("[SENDING] Data: (binary data)\n");

    // Send the binary data
    if (sendto(sockfd, buffer, n, 0, (struct sockaddr*)&addr, sizeof(addr)) == -1)
    {
      perror("[ERROR] sending data to the server.");
      exit(1);
    }
  }

  // Sending the 'END'
  strcpy(buffer, "END");
  sendto(sockfd, buffer, SIZE, 0, (struct sockaddr*)&addr, sizeof(addr));

  fclose(fp);
}

int main(void)
{
  // Defining the IP and Port of the receiving PC (Server)
  char *ip = "192.168.11.112"; // Change this to the server's IP address
  const int port = 8080;

  // Defining variables
  int client_sockfd;
  struct sockaddr_in server_addr;
  char *filename = "test_assignment.pdf"; // Path to the file you want to send
  FILE *fp = fopen(filename, "rb"); // Open the file in binary read mode

  // Creating a UDP socket
  client_sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (client_sockfd < 0)
  {
    perror("[ERROR] socket error");
    exit(1);
  }
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port); // Convert port to network byte order
  server_addr.sin_addr.s_addr = inet_addr(ip);

  // Reading the PDF file in binary mode
  if (fp == NULL)
  {
    perror("[ERROR] reading the file");
    exit(1);
  }

  // Sending the file data to the server
  send_file_data(fp, client_sockfd, server_addr);

  printf("[SUCCESS] Data transfer complete.\n");
  printf("[CLOSING] Disconnecting from the server.\n");

  close(client_sockfd);

  return 0;
}

