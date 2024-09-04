
2. How would you run the scheduler to reproduce each of the examples in the chapter?
Figure 8.2: Long-running Job Over Time
% python3 ./mlfq.py -l 0,200,0 -q 10 -n 3 

Figure 8.3: Along Came An Interactive Job: Two Examples
% python3 ./mlfq.py -q 10 -n 3 -l 0,200,0:100,20,0 
% python3 ./mlfq.py -q 10 -n 3 -l 0,300,0:100,30,1 -s -c

Figure 8.4: Without (Left) and With (Right) Priority Boost
% python3 ./mlfq.py -q 10 -n 3 -S -l 0,200,0:100,100,1:100,100,1 -i 1 
% python3 ./mlfq.py -q 10 -n 3 -S -l 0,200,0:100,100,1:100,100,1 -i 1 -B 100 -c

Figure 8.5: Without (Left) and With (Right) Gaming Tolerance
% python3 ./mlfq.py -q 10 -n 3 -l 0,200,0:100,100,9 -i 1 -S -c
% python3 ./mlfq.py -q 10 -n 3 -l 0,200,0:100,100,9 -i 1 -c

Figure 8.6: Lower Priority, Longer Quanta
% python3 ./mlfq.py -Q 10,20,40 -a 2 -l 0,200,0:0,200,0 -c

3. How would you configure the scheduler parameters to behave just
like a round-robin scheduler?
time slice < job length


4. Craft a workload with two jobs and scheduler parameters so that
one job takes advantage of the older Rules 4a and 4b (turned on
with the -S flag) to game the scheduler and obtain 99% of the CPU
over a particular time interval
% python3 ./mlfq.py -q 10 -n 3 -l 0,50,0:0,50,9 -i 1 -S -c

5. Given a system with a quantum length of 10 ms in its highest queue,
how often would you have to boost jobs back to the highest priority
level (with the -B flag) in order to guarantee that a single longrunning (and potentially-starving) job gets at least 5% of the CPU?
----200ms

6. One question that arises in scheduling is which end of a queue to
add a job that just finished I/O; the -I flag changes this behavior
for this scheduling simulator. Play around with some workloads
and see if you can see the effect of this flag.
% python3 ./mlfq.py -q 10 -n 3 -l 0,50,2:0,50,0 -c  
% python3 ./mlfq.py -q 10 -n 3 -l 0,50,2:0,50,0 -I -c