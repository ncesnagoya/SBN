#ifndef _sbn_ipv4_if_h_
#define _sbn_ipv4_if_h_

#include "sbn_constants.h"
#include "sbn_interfaces.h"
#include "cfe.h"

void    SBN_ShowIPv4PeerData(int i);

void    SBN_SendSockFailedEvent(uint32 Line, int RtnVal);

void    SBN_SendBindFailedEvent(uint32 Line, int RtnVal);

int     SBN_CreateSocket(char *Addr, int Port);

void    SBN_ClearSocket(int SockID);

int     SBN_IPv4RcvMsg(SBN_InterfaceData *Host, SBN_NetPkt_t *MsgBuf);

#ifdef _osapi_confloader_

int     SBN_LoadIPv4Entry(const char **, int, void *);

#else /* ! _osapi_confloader_ */

int     SBN_ParseIPv4FileEntry(char *, uint32, void *);

#endif /* _osapi_confloader_ */

int     SBN_InitIPv4IF(SBN_InterfaceData* data);

int     SBN_SendIPv4NetMsg(SBN_InterfaceData *HostList[], int NumHosts,
            SBN_InterfaceData *IfData, SBN_NetPkt_t *MsgBuf);

int     IPv4_VerifyPeerInterface(SBN_InterfaceData *Peer,
            SBN_InterfaceData *HostList[], int NumHosts);

int     IPv4_VerifyHostInterface(SBN_InterfaceData *Host,
            SBN_PeerData_t *PeerList, int NumPeers);

int     IPv4_ReportModuleStatus(SBN_ModuleStatusPacket_t *Packet,
            SBN_InterfaceData *Peer, SBN_InterfaceData *HostList[],
            int NumHosts);

int     IPv4_ResetPeer(SBN_InterfaceData *Peer, SBN_InterfaceData *HostList[],
            int NumHosts);

SBN_InterfaceOperations IPv4Ops =
{
#ifdef _osapi_confloader_
    SBN_LoadIPv4Entry,
#else /* ! _osapi_confloader_ */
    SBN_ParseIPv4FileEntry,
#endif /* _osapi_confloader_ */
    SBN_InitIPv4IF,
    SBN_SendIPv4NetMsg,
    SBN_IPv4RcvMsg,
    IPv4_VerifyPeerInterface,
    IPv4_VerifyHostInterface,
    IPv4_ReportModuleStatus,
    IPv4_ResetPeer
};

#endif /* _sbn_ipv4_if_h_ */
