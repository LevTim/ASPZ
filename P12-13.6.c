struct timespec req = {1, 0};
while (nanosleep(&req, &req) == -1 && errno == EINTR);
