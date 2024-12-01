Members: <br/>
Panganiban, Joaquin Miguel <br/>
Jovellana, Reuben Seth
         
# LBYARCH Project

A kernel in C and x86-64 Assembly to calculate the distance between the coordinate points across two vectors.

## Setup
Open lbyarch_mp.sln in Visual Studio, then run main.c.



## C vs x86-64 performance
After running the kernel 30 times for vector size of n = 2<sup>20</sup>, this is the output:

*Output for C* <br/>
![2^20_C](https://github.com/user-attachments/assets/98cd3a9c-b205-4b6f-8fa9-989158f0beea) <br/>

*Output for x86_64* <br/>
![2^20_asm](https://github.com/user-attachments/assets/a2f1ceb3-ef5c-4695-ad56-af33ca8b75a0)


We can see x86_64 performed much faster than C running a vector size 2<sup>20</sup>. Let's see the difference with vector size 2<sup>24</sup>:

*Output for C* <br/>
![2^24_C](https://github.com/user-attachments/assets/c9fff954-b22a-4ebc-be85-40cdd855023f) <br/>

*Output for x86_64* <br/>
![2^24_asm](https://github.com/user-attachments/assets/aec1e06d-584c-4fad-89a6-3ef0c0c3c692)


The difference between the performance of C and x86_64 seems to grow as the vector size grows larger. 

The processor can't handle vector size 2<sup>30</sup>, so we test it on 2<sup>27</sup> instead. Additionally, the average time is computed manually by running it multiple times because the processor also can't handle iterating it through a loop 30 times.

After running the kernel 30 times for vector size of n = 2<sup>27</sup>, here are the average times:

Average Time of C program: 8621.16666667 ms

Average Time of x86-64 program: 349.416666667 ms

The C program is significantly more slower than the x86-64 program mainly due to the fact that the C program uses math functions like pow() and sqrt(). The pow() function is better used for arbitrary exponents and not just squaring. The sqrt() function may involve additonal overhead.


## C correctness check
![image](https://github.com/user-attachments/assets/a7700fb0-11e6-4292-a5ee-e14cc8135d66)
## x86-64 correctness check
![image](https://github.com/user-attachments/assets/54c00cea-bbc5-4e1d-bd11-97b9e55efb05)

## Video Demo


https://github.com/user-attachments/assets/788ed392-02b7-4b19-8ae8-4da4c5b65fdb



