#pragma once
// MESSAGE TILT_ANGLE_SETPOINT PACKING

#define MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT 513


typedef struct __mavlink_tilt_angle_setpoint_t {
 uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot).*/
 float tilt_fl; /*< [deg] Front left tilt angle*/
 float tilt_fr; /*< [deg] Front right tilt angle*/
 float tilt_rl; /*< [deg] Rear left tilt angle*/
 float tilt_rr; /*< [deg] Rear right tilt angle*/
} mavlink_tilt_angle_setpoint_t;

#define MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_LEN 20
#define MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_MIN_LEN 20
#define MAVLINK_MSG_ID_513_LEN 20
#define MAVLINK_MSG_ID_513_MIN_LEN 20

#define MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_CRC 234
#define MAVLINK_MSG_ID_513_CRC 234



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TILT_ANGLE_SETPOINT { \
    513, \
    "TILT_ANGLE_SETPOINT", \
    5, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_tilt_angle_setpoint_t, time_boot_ms) }, \
         { "tilt_fl", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_tilt_angle_setpoint_t, tilt_fl) }, \
         { "tilt_fr", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_tilt_angle_setpoint_t, tilt_fr) }, \
         { "tilt_rl", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_tilt_angle_setpoint_t, tilt_rl) }, \
         { "tilt_rr", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_tilt_angle_setpoint_t, tilt_rr) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TILT_ANGLE_SETPOINT { \
    "TILT_ANGLE_SETPOINT", \
    5, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_tilt_angle_setpoint_t, time_boot_ms) }, \
         { "tilt_fl", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_tilt_angle_setpoint_t, tilt_fl) }, \
         { "tilt_fr", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_tilt_angle_setpoint_t, tilt_fr) }, \
         { "tilt_rl", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_tilt_angle_setpoint_t, tilt_rl) }, \
         { "tilt_rr", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_tilt_angle_setpoint_t, tilt_rr) }, \
         } \
}
#endif

/**
 * @brief Pack a tilt_angle_setpoint message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param tilt_fl [deg] Front left tilt angle
 * @param tilt_fr [deg] Front right tilt angle
 * @param tilt_rl [deg] Rear left tilt angle
 * @param tilt_rr [deg] Rear right tilt angle
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tilt_angle_setpoint_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, float tilt_fl, float tilt_fr, float tilt_rl, float tilt_rr)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, tilt_fl);
    _mav_put_float(buf, 8, tilt_fr);
    _mav_put_float(buf, 12, tilt_rl);
    _mav_put_float(buf, 16, tilt_rr);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_LEN);
#else
    mavlink_tilt_angle_setpoint_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.tilt_fl = tilt_fl;
    packet.tilt_fr = tilt_fr;
    packet.tilt_rl = tilt_rl;
    packet.tilt_rr = tilt_rr;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_MIN_LEN, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_LEN, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_CRC);
}

/**
 * @brief Pack a tilt_angle_setpoint message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param tilt_fl [deg] Front left tilt angle
 * @param tilt_fr [deg] Front right tilt angle
 * @param tilt_rl [deg] Rear left tilt angle
 * @param tilt_rr [deg] Rear right tilt angle
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tilt_angle_setpoint_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t time_boot_ms, float tilt_fl, float tilt_fr, float tilt_rl, float tilt_rr)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, tilt_fl);
    _mav_put_float(buf, 8, tilt_fr);
    _mav_put_float(buf, 12, tilt_rl);
    _mav_put_float(buf, 16, tilt_rr);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_LEN);
#else
    mavlink_tilt_angle_setpoint_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.tilt_fl = tilt_fl;
    packet.tilt_fr = tilt_fr;
    packet.tilt_rl = tilt_rl;
    packet.tilt_rr = tilt_rr;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_MIN_LEN, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_LEN, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_MIN_LEN, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_LEN);
#endif
}

/**
 * @brief Pack a tilt_angle_setpoint message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param tilt_fl [deg] Front left tilt angle
 * @param tilt_fr [deg] Front right tilt angle
 * @param tilt_rl [deg] Rear left tilt angle
 * @param tilt_rr [deg] Rear right tilt angle
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tilt_angle_setpoint_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,float tilt_fl,float tilt_fr,float tilt_rl,float tilt_rr)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, tilt_fl);
    _mav_put_float(buf, 8, tilt_fr);
    _mav_put_float(buf, 12, tilt_rl);
    _mav_put_float(buf, 16, tilt_rr);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_LEN);
#else
    mavlink_tilt_angle_setpoint_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.tilt_fl = tilt_fl;
    packet.tilt_fr = tilt_fr;
    packet.tilt_rl = tilt_rl;
    packet.tilt_rr = tilt_rr;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_MIN_LEN, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_LEN, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_CRC);
}

/**
 * @brief Encode a tilt_angle_setpoint struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param tilt_angle_setpoint C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tilt_angle_setpoint_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_tilt_angle_setpoint_t* tilt_angle_setpoint)
{
    return mavlink_msg_tilt_angle_setpoint_pack(system_id, component_id, msg, tilt_angle_setpoint->time_boot_ms, tilt_angle_setpoint->tilt_fl, tilt_angle_setpoint->tilt_fr, tilt_angle_setpoint->tilt_rl, tilt_angle_setpoint->tilt_rr);
}

/**
 * @brief Encode a tilt_angle_setpoint struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tilt_angle_setpoint C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tilt_angle_setpoint_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_tilt_angle_setpoint_t* tilt_angle_setpoint)
{
    return mavlink_msg_tilt_angle_setpoint_pack_chan(system_id, component_id, chan, msg, tilt_angle_setpoint->time_boot_ms, tilt_angle_setpoint->tilt_fl, tilt_angle_setpoint->tilt_fr, tilt_angle_setpoint->tilt_rl, tilt_angle_setpoint->tilt_rr);
}

/**
 * @brief Encode a tilt_angle_setpoint struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param tilt_angle_setpoint C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tilt_angle_setpoint_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_tilt_angle_setpoint_t* tilt_angle_setpoint)
{
    return mavlink_msg_tilt_angle_setpoint_pack_status(system_id, component_id, _status, msg,  tilt_angle_setpoint->time_boot_ms, tilt_angle_setpoint->tilt_fl, tilt_angle_setpoint->tilt_fr, tilt_angle_setpoint->tilt_rl, tilt_angle_setpoint->tilt_rr);
}

/**
 * @brief Send a tilt_angle_setpoint message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param tilt_fl [deg] Front left tilt angle
 * @param tilt_fr [deg] Front right tilt angle
 * @param tilt_rl [deg] Rear left tilt angle
 * @param tilt_rr [deg] Rear right tilt angle
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_tilt_angle_setpoint_send(mavlink_channel_t chan, uint32_t time_boot_ms, float tilt_fl, float tilt_fr, float tilt_rl, float tilt_rr)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, tilt_fl);
    _mav_put_float(buf, 8, tilt_fr);
    _mav_put_float(buf, 12, tilt_rl);
    _mav_put_float(buf, 16, tilt_rr);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT, buf, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_MIN_LEN, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_LEN, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_CRC);
#else
    mavlink_tilt_angle_setpoint_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.tilt_fl = tilt_fl;
    packet.tilt_fr = tilt_fr;
    packet.tilt_rl = tilt_rl;
    packet.tilt_rr = tilt_rr;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT, (const char *)&packet, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_MIN_LEN, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_LEN, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_CRC);
#endif
}

/**
 * @brief Send a tilt_angle_setpoint message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_tilt_angle_setpoint_send_struct(mavlink_channel_t chan, const mavlink_tilt_angle_setpoint_t* tilt_angle_setpoint)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_tilt_angle_setpoint_send(chan, tilt_angle_setpoint->time_boot_ms, tilt_angle_setpoint->tilt_fl, tilt_angle_setpoint->tilt_fr, tilt_angle_setpoint->tilt_rl, tilt_angle_setpoint->tilt_rr);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT, (const char *)tilt_angle_setpoint, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_MIN_LEN, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_LEN, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_CRC);
#endif
}

#if MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_tilt_angle_setpoint_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time_boot_ms, float tilt_fl, float tilt_fr, float tilt_rl, float tilt_rr)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, tilt_fl);
    _mav_put_float(buf, 8, tilt_fr);
    _mav_put_float(buf, 12, tilt_rl);
    _mav_put_float(buf, 16, tilt_rr);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT, buf, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_MIN_LEN, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_LEN, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_CRC);
#else
    mavlink_tilt_angle_setpoint_t *packet = (mavlink_tilt_angle_setpoint_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    packet->tilt_fl = tilt_fl;
    packet->tilt_fr = tilt_fr;
    packet->tilt_rl = tilt_rl;
    packet->tilt_rr = tilt_rr;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT, (const char *)packet, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_MIN_LEN, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_LEN, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_CRC);
#endif
}
#endif

#endif

// MESSAGE TILT_ANGLE_SETPOINT UNPACKING


/**
 * @brief Get field time_boot_ms from tilt_angle_setpoint message
 *
 * @return [ms] Timestamp (time since system boot).
 */
static inline uint32_t mavlink_msg_tilt_angle_setpoint_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field tilt_fl from tilt_angle_setpoint message
 *
 * @return [deg] Front left tilt angle
 */
static inline float mavlink_msg_tilt_angle_setpoint_get_tilt_fl(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field tilt_fr from tilt_angle_setpoint message
 *
 * @return [deg] Front right tilt angle
 */
static inline float mavlink_msg_tilt_angle_setpoint_get_tilt_fr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field tilt_rl from tilt_angle_setpoint message
 *
 * @return [deg] Rear left tilt angle
 */
static inline float mavlink_msg_tilt_angle_setpoint_get_tilt_rl(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field tilt_rr from tilt_angle_setpoint message
 *
 * @return [deg] Rear right tilt angle
 */
static inline float mavlink_msg_tilt_angle_setpoint_get_tilt_rr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Decode a tilt_angle_setpoint message into a struct
 *
 * @param msg The message to decode
 * @param tilt_angle_setpoint C-struct to decode the message contents into
 */
static inline void mavlink_msg_tilt_angle_setpoint_decode(const mavlink_message_t* msg, mavlink_tilt_angle_setpoint_t* tilt_angle_setpoint)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    tilt_angle_setpoint->time_boot_ms = mavlink_msg_tilt_angle_setpoint_get_time_boot_ms(msg);
    tilt_angle_setpoint->tilt_fl = mavlink_msg_tilt_angle_setpoint_get_tilt_fl(msg);
    tilt_angle_setpoint->tilt_fr = mavlink_msg_tilt_angle_setpoint_get_tilt_fr(msg);
    tilt_angle_setpoint->tilt_rl = mavlink_msg_tilt_angle_setpoint_get_tilt_rl(msg);
    tilt_angle_setpoint->tilt_rr = mavlink_msg_tilt_angle_setpoint_get_tilt_rr(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_LEN? msg->len : MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_LEN;
        memset(tilt_angle_setpoint, 0, MAVLINK_MSG_ID_TILT_ANGLE_SETPOINT_LEN);
    memcpy(tilt_angle_setpoint, _MAV_PAYLOAD(msg), len);
#endif
}
