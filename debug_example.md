
```c
 /* debug.c */

 #include <stdio.h>
 #include <stdlib.h>                                                             
                                                                                  
 int process(int i1, int i2)                                                     
 {                                                                               
     int val;                                                                    
           
 #ifdef DEBUG                                                                    
     fprintf(stderr, "process (%i, %i)\n", i1, i2);                              
 #endif                                                                          
     val = i1 * i2;                                                                                                                                             
 #ifdef DEBUG                                                                    
     fprintf(stderr, "return %i\n", val);                                        
 #endif                                                                          
     return val;                                                                 
 }                                                                               
                                                                                 
 int main(int argc, char *argv[])                                                
 {                                                                               
     int a1 = 0, a2 = 0;                                                         
                                                                                
     if(argc > 1)                                                                
         a1 = atoi(argv[1]);                                                         
     if(argc == 3)                                                               
         a2 = atoi(argv[2]);                                                     
 #ifdef DEBUG                                                                    
     fprintf(stderr, "processed %i arguments\n", argc - 1);                      
     fprintf(stderr, "arg1 = %i, arg2 = %i\n", a1, a2);                          
 #endif                                                                          
                                                                                  
     printf("%i\n", process(a1, a2));                                            
                                                                                
     return 0;                                                                   
 }
 
gcc -D DEBUG debug.c
```
