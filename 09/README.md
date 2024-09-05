1. Compute the solutions for simulations with 3 jobs and random seeds
of 1, 2, and 3.

```shell
% python3 ./lottery.py -j 3 -s 1
Here is the job list, with the run time of each job: 
  Job 0 ( length = 1, tickets = 84 )
  Job 1 ( length = 7, tickets = 25 )
  Job 2 ( length = 4, tickets = 44 )

Here is the set of random numbers you will need (at most):
Random 651593
Random 788724
Random 93859
Random 28347
Random 835765
Random 432767
Random 762280
Random 2106
Random 445387
Random 721540
Random 228762
Random 945271

job 0 range: 0-83
job 1 range: 84-108
job 2 range: 109-152
** Solutions **
Random 651593 -> Winning ticket 119(of 153) -> Run 2
  Jobs:  (  job:0 timeleft:1 tix:84 ) (  job:1 timeleft:7 tix:25 ) (* job:2 timeleft:4 tix:44 )
Random 788724 -> Winning ticket 9(of 153) -> Run 0
  Jobs:  (* job:0 timeleft:1 tix:84 ) (  job:1 timeleft:7 tix:25 ) (  job:2 timeleft:3 tix:44 )
--> JOB 0 DONE at time 2
job 1 range: 0-24
job 2 range: 25-68
Random 93859 -> Winning ticket 19(of 69) -> Run 1
  Jobs:  (  job:0 timeleft:0 tix:-- ) (* job:1 timeleft:7 tix:25 ) (  job:2 timeleft:3 tix:44 )
Random 28347 -> Winning ticket 57(of 69) -> Run 2
  Jobs:  (  job:0 timeleft:0 tix:-- ) (  job:1 timeleft:6 tix:25 ) (* job:2 timeleft:3 tix:44 )
Random 835765 -> Winning ticket 37(of 69) -> Run 2
  Jobs:  (  job:0 timeleft:0 tix:-- ) (  job:1 timeleft:6 tix:25 ) (* job:2 timeleft:2 tix:44 )
Random 432767 -> Winning ticket 68(of 69) -> Run 2
  Jobs:  (  job:0 timeleft:0 tix:-- ) (  job:1 timeleft:6 tix:25 ) (* job:2 timeleft:1 tix:44 )
--> JOB 2 DONE at time 6
job 1 range: 0-24
Random 762280 -> Winning ticket 5(of 25) -> Run 1
  Jobs:  (  job:0 timeleft:0 tix:-- ) (* job:1 timeleft:6 tix:25 ) (  job:2 timeleft:0 tix:-- )
Random 2106 -> Winning ticket 6(of 25) -> Run 1
  Jobs:  (  job:0 timeleft:0 tix:-- ) (* job:1 timeleft:5 tix:25 ) (  job:2 timeleft:0 tix:-- )
Random 445387 -> Winning ticket 12(of 25) -> Run 1
  Jobs:  (  job:0 timeleft:0 tix:-- ) (* job:1 timeleft:4 tix:25 ) (  job:2 timeleft:0 tix:-- )
Random 721540 -> Winning ticket 15(of 25) -> Run 1
  Jobs:  (  job:0 timeleft:0 tix:-- ) (* job:1 timeleft:3 tix:25 ) (  job:2 timeleft:0 tix:-- )
Random 228762 -> Winning ticket 12(of 25) -> Run 1
  Jobs:  (  job:0 timeleft:0 tix:-- ) (* job:1 timeleft:2 tix:25 ) (  job:2 timeleft:0 tix:-- )
Random 945271 -> Winning ticket 21(of 25) -> Run 1
  Jobs:  (  job:0 timeleft:0 tix:-- ) (* job:1 timeleft:1 tix:25 ) (  job:2 timeleft:0 tix:-- )
--> JOB 1 DONE at time 12
```

```shell
% python3 ./lottery.py -j 3 -s 2
```
2.  Now run with two specific jobs: each of length 10, but one (job 0)
with 1 ticket and the other (job 1) with 100 (e.g., -l 10:1,10:100).
What happens when the number of tickets is so imbalanced? Will
job 0 ever run before job 1 completes? How often? In general, what
does such a ticket imbalance do to the behavior of lottery scheduling?

1/100

3. When running with two jobs of length 100 and equal ticket allocations of 100 (-l 100:100,100:100), how unfair is the scheduler?
Run with some different random seeds to determine the (probabilistic) answer; let unfairness be determined by how much earlier one
job finishes than the other.

192/200
196/200
190/200
196/200


4.
% python3 ./lottery.py -s 0  -l 100:100,100:100 -q 5  -c
160/200 
% python3 ./lottery.py -l 100:100,100:100 -q 6 -s 0 -c
150/200
% python3 ./lottery.py -l 100:100,100:100 -q 7 -s 0 -c
147/200
% python3 ./lottery.py -l 100:100,100:100 -q 8 -s 0 -c
144/200
% python3 ./lottery.py -l 100:100,100:100 -q 9 -s 0 -c
153/200
% python3 ./lottery.py -l 100:100,100:100 -q 10 -s 0 -c
150/200
% python3 ./lottery.py -l 100:100,100:100 -q 15 -s 0 -c
135/200
% python3 ./lottery.py -l 100:100,100:100 -q 20 -s 0 -c
140/200
% python3 ./lottery.py -l 100:100,100:100 -q 25 -s 0 -c
150/200
% python3 ./lottery.py -l 100:100,100:100 -q 30 -s 0 -c
180/200
% python3 ./lottery.py -l 100:100,100:100 -q 35 -s 0 -c
140/200
% python3 ./lottery.py -l 100:100,100:100 -q 40 -s 0 -c
160/200
% python3 ./lottery.py -l 100:100,100:100 -q 45 -s 0 -c
180/200
% python3 ./lottery.py -l 100:100,100:100 -q 50 -s 0 -c
150/200
% python3 ./lottery.py -l 100:100,100:100 -q 55 -s 0 -c

% python3 ./lottery.py -l 100:100,100:100 -q 5 -s 1 -c
190/200
% python3 ./lottery.py -l 100:100,100:100 -q 5 -s 2 -c
175/200
% python3 ./lottery.py -l 100:100,100:100 -q 5 -s 2 -c
185/200
