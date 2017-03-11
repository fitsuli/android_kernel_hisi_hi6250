/** ****************************************************************************

                    Huawei Technologies Sweden AB (C), 2001-2015

 ********************************************************************************
 * @author    Automatically generated by DAISY
 * @version
 * @date      2015-06-24
 * @file
 * @brief
 * @copyright Huawei Technologies Sweden AB
 *******************************************************************************/
#ifndef RLP_PPP_PUB_PIF_H
#define RLP_PPP_PUB_PIF_H

/*******************************************************************************
 1. Other files included
*******************************************************************************/

#include "vos.h"
#include "cttf_hrpd_pa_public_pif.h"
#include "PsTypeDef.h"
#include "TtfDrvInterface.h"
#include "TtfIpComm.h"

#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif /* __cpluscplus */
#endif /* __cpluscplus */
#pragma pack(4)

/*******************************************************************************
 2. Macro definitions
*******************************************************************************/


/*******************************************************************************
 3. Enumerations declarations
*******************************************************************************/

/** ****************************************************************************
 * Name        : PPP_RLP_HRPD_STREAM_MODE_ENUM_UINT8
 *
 * Description :
 *******************************************************************************/
enum PPP_RLP_HRPD_STREAM_MODE_ENUM
{
    PPP_RLP_HRPD_STREAM_MODE_OCTET_BASED                    = 0x00,
    PPP_RLP_HRPD_STREAM_MODE_PACKET_BASED                   = 0x01,
    PPP_RLP_HRPD_STREAM_MODE_ENUM_BUTT                      = 0x02
};
typedef VOS_UINT8 PPP_RLP_HRPD_STREAM_MODE_ENUM_UINT8;

/*******************************************************************************
 4. Message Header declaration
*******************************************************************************/

/*******************************************************************************
 5. Message declaration
*******************************************************************************/

/*******************************************************************************
 6. STRUCT and UNION declaration
*******************************************************************************/

/** ****************************************************************************
 * Name        : RLP_PPP_HRPD_TRANS_DATA_STRU
 *
 * Description : Struct defines the parameters used when delivering data from
 * PA to PPP in HRPD. Stream number and bound applications are known by PPP. It
 * is forwarded from PA to PPP upon Commit. Higher layer protocol is only
 * applicable for MFPA/EMFPA.
 * 
 * Parameters:
 * -  ucHigherLayerProtocol: Associated higher layer protocol as configured.
 *    Only relevant in MFPA and EMPA.
 * -  ucStreamNumber: The stream on which the data was received.
 * -  ucNumReservLabels: Indicates how many reservation labels are associated
 *    with the received data. Only relevant in MFPA/EMPA.
 * -  aucReservLabel: List of associated reservation labels. Only relevant in
 *    MFPA/EMPA.
 * -  enPartialFrame: In case of Stream based configuration. RLP can upon abort
 *    timer expiration send parts of received packet to higher layer. This is
 *    indicated by setting this enumeration to PS_TRUE. See page 2-34 in
 *    C.S0063-A
 * -  ulSduLen: Length of data in number of octets. pstSdu: Pointer to TTF
 *    memory where the data is stored.
 * -  pstSdu: Pointer to octet based / stream based packet.
 *******************************************************************************/
typedef struct
{
    VOS_UINT16                          ucHigherLayerProtocol;                              /**< MFPA/EMPA relevant only */
    VOS_UINT8                           ucStreamNumber;
    VOS_UINT8                           ucNumReservLabels;                                  /**< MFPA/EMPA relevant only */
    VOS_UINT8                           aucReservLabel[CTTF_HRPD_PA_MAX_NUM_RESERV_LABELS];
    PS_BOOL_ENUM_UINT8                  enPartialFrame;                                     /**< Only applicable if stream based protocol */
    VOS_UINT8                           ucReserved[3];
    VOS_UINT32                          ulSduLen;
    TTF_MEM_ST                          *pstSdu;
} RLP_PPP_HRPD_TRANS_DATA_STRU;

/** ****************************************************************************
 * Name        : PPP_RLP_HRPD_TRANS_DATA_STRU
 *
 * Description : Struct defines the parameters used when delivering data from
 * PPP to PA (RLP) in HRPD. Stream number and bound applications is known by
 * PPP. It is forwarded from PA to PPP upon Commit. Reservation label is only
 * applicable for MFPA and EMPA.
 * 
 * MFPA:
 * Reservation label 0xFF is referred to as access stream/best effort stream in
 * spec. Other reservation labels needs QoS configuration. If reservation is in
 * closed state, then PPP may reroute data to the best effort stream. PPP shall
 * in this case set reservation label to 0xFF
 * 
 * EMPA:
 * In addition to 0xFF best effort flow, there exist an additional best effort
 * flow 0xFE used together with packet based transmissions (higher layer
 * protocol 0x08 or IPv4/IPv6).
 * enStreamMode: In case PPP sends data to PA where Reservation is
 * not mapped to any RLP flow then PA should reroute the data to either octet
 * based BE flow or packet based BE flow. Since this reservation is unmapped,
 * PA has no idea about if it is packet or octet based. This parameter will aid
 * PA in making the correct decision.
 *******************************************************************************/
typedef struct
{
    VOS_UINT8                           ucStreamNumber;
    VOS_UINT8                           ucReservationLabel; /**< MFPA/EMPA only */
    PPP_RLP_HRPD_STREAM_MODE_ENUM_UINT8 enStreamMode;       /**< Packet Based or Octet Based */
    IP_DATA_TYPE_ENUM_UINT8             enIpDataType;
    VOS_UINT8                           ucTotalPppFrgmt;
    VOS_UINT8                           ucCurrPppFrgmt;
    VOS_UINT8                           ucReserved[2];
    VOS_UINT32                          ulSduLen;
    TTF_MEM_ST                          *pstSdu;
} PPP_RLP_HRPD_TRANS_DATA_STRU;

/*******************************************************************************
 7. OTHER declarations
*******************************************************************************/

/*******************************************************************************
 8. Global  declaration
*******************************************************************************/

/*******************************************************************************
 9. Function declarations
*******************************************************************************/

#if ((VOS_OS_VER == VOS_WIN32) || (VOS_OS_VER == VOS_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cpluscplus */
#endif /* __cpluscplus */

#endif