# GetNextLine
=> Function prototype 
   int get_net_line(const int fd, char **line);

=> Mandatory part
    1. The first parameter is the file descriptor that will be used to read.
    
    2. The second parameter is the address of a pointer to a character that will be used
       to save the line read from the file descriptor.
       
    3. The return value can be 1, 0 or -1 depending on whether a line has been read,
       when the reading has been completed, or if an error has happened respectively.
    4. Your function get_next_line must return its result without ’\n’.
    
    
    5. Calling your function get_next_line in a loop will then allow you to read the text
       available on a file descriptor one line at a time until the end of the text, no matter
       the size of either the text or one of its lines.
       
    6. Make sure that your function behaves well when it reads from a file, from the
       standard output, from a redirection etc.
       
    7. In you header file get_next_line.h you must have at least the prototype of the
       function get_next_line and a macro that allows to choose the size of the reading
       buffer for the read function. This value will be modified during the defence to
       evaluate the strength of your function. That macro must be named BUFF_SIZE.
       For example: #define BUFF_SIZE 20;
  
=> Used build in function
    - read(int fd, char* str, size_t BUFF_SIZE);
      to read a file.
    - FILE *fopen(const char *filename, const char *mode);
