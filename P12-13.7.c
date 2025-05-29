union sigval val;
val.sival_int = 123;
sigqueue(pid, SIGRTMIN, val);
