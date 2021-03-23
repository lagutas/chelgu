#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/prctl.h>
#include <string>
#include <mutex>
#include <cstdlib>
#include <vector>

std::mutex mutex;

int main(int argc, char** argv, char** envp){

    std::vector<pid_t> childs;
    pid_t pid;

    unsigned int processCount = atoi(argv[2]);
    unsigned int iterationCount = atoi(argv[3]);

    FILE* logFile = fopen("logs", "a+");

    for(int i = 0; i < processCount; i++){
        pid = fork();
        if(pid == 0){
            for(int j = 0; j < iterationCount; j++){
                prctl(PR_SET_PDEATHSIG, SIGHUP);
                mutex.lock();
                fprintf(logFile, "%s, %d\n", argv[1], i*j);
                mutex.unlock();
                sleep(iterationCount * j);
            }
        }
        else if(pid < 0){
            for (auto child : childs) {
                kill(child, SIGQUIT);
            }
            return 1;
        }
        else{
            childs.push_back(pid);
        }
    }
    if(pid != 0){
        int flag = 0;
        while (wait(&flag) > 0) {
            if (flag) exit(1);
        }
    }

    fclose(logFile);
    return 0;
}