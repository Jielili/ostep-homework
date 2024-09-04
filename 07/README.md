1. Compute the response time and turnaround time when running
three jobs of length 200 with the SJF and FIFO schedulers

```shell
./scheduler.py -l 200,200,200 -p FIFO
response time: 0, 200, 400
turnaround time: 200, 400, 600

./scheduler.py -l 200,200,200 -p SJF
response time: 0, 200, 400
turnaround time: 200, 400, 600
```

2. Now do the same but with jobs of different lengths: 100, 200, and
300.

```shell
./scheduler.py -l 100,200,300 -p FIFO
response time: 0, 100, 300
turnaround time: 100, 300, 600

./scheduler.py -l 100,200,300 -p SJF
response time: 0, 100, 300
turnaround time: 100, 300, 600
```

3.  Now do the same, but also with the RR scheduler and a time-slice
of 1
```shell
./scheduler.py -l 100,200,300 -p RR -q 1
response time: 0, 1, 2
turnaround time: 298, 499, 600
```

4. For what types of workloads does SJF deliver the same turnaround
times as FIFO?

Jobs in ascending order of length.

5. For what types of workloads and quantum lengths does SJF deliver the same response times as RR?

jobs length == the quantum length.

6. What happens to response time with SJF as job lengths increase?
Can you use the simulator to demonstrate the trend?

will increase


7. What happens to response time with RR as quantum lengths increase? Can you write an equation that gives the worst-case response time, given N jobs?

response time will increase. 
response time = (N-1) * quantum length / 2
  