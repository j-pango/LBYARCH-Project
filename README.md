
# LBYARCH Project

A kernel in C and x86-64 Assembly to calculate the distance between the coordinate points across two vectors.





## C vs x86-64 performance
After running the kernel 30 times for vector size of n = 2<sup>27</sup>, here are the average times:

Average Time of C program: 8621.16666667 ms

Average Time of x86-64 program: 349.416666667 ms

The C program is significantly more slower than the x86-64 program mainly due to the fact that the C program uses math functions like pow() and sqrt(). The pow() function is better used for arbitrary exponents and not just squaring. The sqrt() function may involve additonal overhead.


## C correctness check
![image](https://github.com/user-attachments/assets/a7700fb0-11e6-4292-a5ee-e14cc8135d66)
## x86-64 correctness check
![image](https://github.com/user-attachments/assets/54c00cea-bbc5-4e1d-bd11-97b9e55efb05)

## Video Demo


