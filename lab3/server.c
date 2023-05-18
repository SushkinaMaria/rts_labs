#include <stdio.h>
#include <errno.h>
#include <pthread.h>
#include <inttypes.h>
#include <unistd.h>
#include <string.h>
#include <sys/neutrino.h>

int validate_msg(const char *msg, const char *expected_msg)
{
    return strcmp(msg, expected_msg);
}

void server(void)
{
    int rcvid;
    int chid;
    char msg[30];
    char expected_msg[] = "Sushkina Maria Mikhailovna";
    char response[36];

    printf("Server start working\n");
    chid = ChannelCreate(0);
    printf("Channel id: %d\n", chid);
    printf("Pid: %d\n", getpid());

    while(1) {
        rcvid = MsgReceive(chid, msg, sizeof(msg), NULL);
        printf("Msg received from client, rcvid %X\n", rcvid);
        if (validate_msg(msg, expected_msg)) {
            printf("Message is not valid\n");
            break;
        }

        //Response
        strcpy(response, msg);
	strcat(response, " I993");
        MsgReply(rcvid, EOK, response, sizeof(response));
        printf("\"%s\". \n", response);
    }

    ChannelDestroy(chid);
}

int main(void)
{
    printf("Server\n");
    server();
    sleep(5);

    return(1);
}
