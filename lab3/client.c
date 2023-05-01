#include <stdio.h>
#include <errno.h>
#include <pthread.h>
#include <inttypes.h>
#include <string.h>
#include <sys/neutrino.h>

int main()
{
    char smsg[30];
    char rmsg[200];
    int coid;
    long serv_pid;

    printf("Client, enter server PID: ");
    scanf("%ld", &serv_pid);
    getchar();
    printf("Entered: %ld\n", serv_pid);
    coid = ConnectAttach(0, serv_pid, 1, 0, 0);

    printf("Connection result: %d\n Enter your message: ", coid);
    scanf("%s", &smsg);
    getchar();
    printf("Your message is: %s\n", smsg);

    if (MsgSend(coid, smsg, strlen(smsg)+1, rmsg, sizeof(rmsg)) == -1) {
        printf("Error MsgSend\n");
    }

    ConnectDetach(coid);

    return 0;
}