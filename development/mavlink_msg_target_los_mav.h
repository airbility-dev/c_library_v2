#pragma once
// MESSAGE TARGET_LOS_MAV PACKING

#define MAVLINK_MSG_ID_TARGET_LOS_MAV 61000


typedef struct __mavlink_target_los_mav_t {
 float los_unit[3]; /*<  Unit direction towards the target in camera FRD axes, ordered X, Y, Z.*/
 float los_rate[3]; /*<  Time derivative of los_unit in camera FRD axes, ordered X, Y, Z, in 1/s. This is a vector derivative, not the LOS angular-velocity vector.*/
 uint8_t valid; /*<  1 if the input tracker reports a confirmed lock, otherwise 0. Receivers must also check freshness; an old valid sample is not a current lock.*/
} mavlink_target_los_mav_t;

#define MAVLINK_MSG_ID_TARGET_LOS_MAV_LEN 25
#define MAVLINK_MSG_ID_TARGET_LOS_MAV_MIN_LEN 25
#define MAVLINK_MSG_ID_61000_LEN 25
#define MAVLINK_MSG_ID_61000_MIN_LEN 25

#define MAVLINK_MSG_ID_TARGET_LOS_MAV_CRC 129
#define MAVLINK_MSG_ID_61000_CRC 129

#define MAVLINK_MSG_TARGET_LOS_MAV_FIELD_LOS_UNIT_LEN 3
#define MAVLINK_MSG_TARGET_LOS_MAV_FIELD_LOS_RATE_LEN 3

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TARGET_LOS_MAV { \
    61000, \
    "TARGET_LOS_MAV", \
    3, \
    {  { "los_unit", NULL, MAVLINK_TYPE_FLOAT, 3, 0, offsetof(mavlink_target_los_mav_t, los_unit) }, \
         { "los_rate", NULL, MAVLINK_TYPE_FLOAT, 3, 12, offsetof(mavlink_target_los_mav_t, los_rate) }, \
         { "valid", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_target_los_mav_t, valid) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TARGET_LOS_MAV { \
    "TARGET_LOS_MAV", \
    3, \
    {  { "los_unit", NULL, MAVLINK_TYPE_FLOAT, 3, 0, offsetof(mavlink_target_los_mav_t, los_unit) }, \
         { "los_rate", NULL, MAVLINK_TYPE_FLOAT, 3, 12, offsetof(mavlink_target_los_mav_t, los_rate) }, \
         { "valid", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_target_los_mav_t, valid) }, \
         } \
}
#endif

/**
 * @brief Pack a target_los_mav message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param los_unit  Unit direction towards the target in camera FRD axes, ordered X, Y, Z.
 * @param los_rate  Time derivative of los_unit in camera FRD axes, ordered X, Y, Z, in 1/s. This is a vector derivative, not the LOS angular-velocity vector.
 * @param valid  1 if the input tracker reports a confirmed lock, otherwise 0. Receivers must also check freshness; an old valid sample is not a current lock.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_target_los_mav_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const float *los_unit, const float *los_rate, uint8_t valid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TARGET_LOS_MAV_LEN];
    _mav_put_uint8_t(buf, 24, valid);
    _mav_put_float_array(buf, 0, los_unit, 3);
    _mav_put_float_array(buf, 12, los_rate, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TARGET_LOS_MAV_LEN);
#else
    mavlink_target_los_mav_t packet;
    packet.valid = valid;
    mav_array_assign_float(packet.los_unit, los_unit, 3);
    mav_array_assign_float(packet.los_rate, los_rate, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TARGET_LOS_MAV_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TARGET_LOS_MAV;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TARGET_LOS_MAV_MIN_LEN, MAVLINK_MSG_ID_TARGET_LOS_MAV_LEN, MAVLINK_MSG_ID_TARGET_LOS_MAV_CRC);
}

/**
 * @brief Pack a target_los_mav message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param los_unit  Unit direction towards the target in camera FRD axes, ordered X, Y, Z.
 * @param los_rate  Time derivative of los_unit in camera FRD axes, ordered X, Y, Z, in 1/s. This is a vector derivative, not the LOS angular-velocity vector.
 * @param valid  1 if the input tracker reports a confirmed lock, otherwise 0. Receivers must also check freshness; an old valid sample is not a current lock.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_target_los_mav_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               const float *los_unit, const float *los_rate, uint8_t valid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TARGET_LOS_MAV_LEN];
    _mav_put_uint8_t(buf, 24, valid);
    _mav_put_float_array(buf, 0, los_unit, 3);
    _mav_put_float_array(buf, 12, los_rate, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TARGET_LOS_MAV_LEN);
#else
    mavlink_target_los_mav_t packet;
    packet.valid = valid;
    mav_array_memcpy(packet.los_unit, los_unit, sizeof(float)*3);
    mav_array_memcpy(packet.los_rate, los_rate, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TARGET_LOS_MAV_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TARGET_LOS_MAV;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_TARGET_LOS_MAV_MIN_LEN, MAVLINK_MSG_ID_TARGET_LOS_MAV_LEN, MAVLINK_MSG_ID_TARGET_LOS_MAV_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_TARGET_LOS_MAV_MIN_LEN, MAVLINK_MSG_ID_TARGET_LOS_MAV_LEN);
#endif
}

/**
 * @brief Pack a target_los_mav message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param los_unit  Unit direction towards the target in camera FRD axes, ordered X, Y, Z.
 * @param los_rate  Time derivative of los_unit in camera FRD axes, ordered X, Y, Z, in 1/s. This is a vector derivative, not the LOS angular-velocity vector.
 * @param valid  1 if the input tracker reports a confirmed lock, otherwise 0. Receivers must also check freshness; an old valid sample is not a current lock.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_target_los_mav_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const float *los_unit,const float *los_rate,uint8_t valid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TARGET_LOS_MAV_LEN];
    _mav_put_uint8_t(buf, 24, valid);
    _mav_put_float_array(buf, 0, los_unit, 3);
    _mav_put_float_array(buf, 12, los_rate, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TARGET_LOS_MAV_LEN);
#else
    mavlink_target_los_mav_t packet;
    packet.valid = valid;
    mav_array_assign_float(packet.los_unit, los_unit, 3);
    mav_array_assign_float(packet.los_rate, los_rate, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TARGET_LOS_MAV_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TARGET_LOS_MAV;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TARGET_LOS_MAV_MIN_LEN, MAVLINK_MSG_ID_TARGET_LOS_MAV_LEN, MAVLINK_MSG_ID_TARGET_LOS_MAV_CRC);
}

/**
 * @brief Encode a target_los_mav struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param target_los_mav C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_target_los_mav_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_target_los_mav_t* target_los_mav)
{
    return mavlink_msg_target_los_mav_pack(system_id, component_id, msg, target_los_mav->los_unit, target_los_mav->los_rate, target_los_mav->valid);
}

/**
 * @brief Encode a target_los_mav struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_los_mav C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_target_los_mav_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_target_los_mav_t* target_los_mav)
{
    return mavlink_msg_target_los_mav_pack_chan(system_id, component_id, chan, msg, target_los_mav->los_unit, target_los_mav->los_rate, target_los_mav->valid);
}

/**
 * @brief Encode a target_los_mav struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param target_los_mav C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_target_los_mav_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_target_los_mav_t* target_los_mav)
{
    return mavlink_msg_target_los_mav_pack_status(system_id, component_id, _status, msg,  target_los_mav->los_unit, target_los_mav->los_rate, target_los_mav->valid);
}

/**
 * @brief Send a target_los_mav message
 * @param chan MAVLink channel to send the message
 *
 * @param los_unit  Unit direction towards the target in camera FRD axes, ordered X, Y, Z.
 * @param los_rate  Time derivative of los_unit in camera FRD axes, ordered X, Y, Z, in 1/s. This is a vector derivative, not the LOS angular-velocity vector.
 * @param valid  1 if the input tracker reports a confirmed lock, otherwise 0. Receivers must also check freshness; an old valid sample is not a current lock.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_target_los_mav_send(mavlink_channel_t chan, const float *los_unit, const float *los_rate, uint8_t valid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TARGET_LOS_MAV_LEN];
    _mav_put_uint8_t(buf, 24, valid);
    _mav_put_float_array(buf, 0, los_unit, 3);
    _mav_put_float_array(buf, 12, los_rate, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TARGET_LOS_MAV, buf, MAVLINK_MSG_ID_TARGET_LOS_MAV_MIN_LEN, MAVLINK_MSG_ID_TARGET_LOS_MAV_LEN, MAVLINK_MSG_ID_TARGET_LOS_MAV_CRC);
#else
    mavlink_target_los_mav_t packet;
    packet.valid = valid;
    mav_array_assign_float(packet.los_unit, los_unit, 3);
    mav_array_assign_float(packet.los_rate, los_rate, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TARGET_LOS_MAV, (const char *)&packet, MAVLINK_MSG_ID_TARGET_LOS_MAV_MIN_LEN, MAVLINK_MSG_ID_TARGET_LOS_MAV_LEN, MAVLINK_MSG_ID_TARGET_LOS_MAV_CRC);
#endif
}

/**
 * @brief Send a target_los_mav message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_target_los_mav_send_struct(mavlink_channel_t chan, const mavlink_target_los_mav_t* target_los_mav)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_target_los_mav_send(chan, target_los_mav->los_unit, target_los_mav->los_rate, target_los_mav->valid);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TARGET_LOS_MAV, (const char *)target_los_mav, MAVLINK_MSG_ID_TARGET_LOS_MAV_MIN_LEN, MAVLINK_MSG_ID_TARGET_LOS_MAV_LEN, MAVLINK_MSG_ID_TARGET_LOS_MAV_CRC);
#endif
}

#if MAVLINK_MSG_ID_TARGET_LOS_MAV_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_target_los_mav_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const float *los_unit, const float *los_rate, uint8_t valid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 24, valid);
    _mav_put_float_array(buf, 0, los_unit, 3);
    _mav_put_float_array(buf, 12, los_rate, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TARGET_LOS_MAV, buf, MAVLINK_MSG_ID_TARGET_LOS_MAV_MIN_LEN, MAVLINK_MSG_ID_TARGET_LOS_MAV_LEN, MAVLINK_MSG_ID_TARGET_LOS_MAV_CRC);
#else
    mavlink_target_los_mav_t *packet = (mavlink_target_los_mav_t *)msgbuf;
    packet->valid = valid;
    mav_array_assign_float(packet->los_unit, los_unit, 3);
    mav_array_assign_float(packet->los_rate, los_rate, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TARGET_LOS_MAV, (const char *)packet, MAVLINK_MSG_ID_TARGET_LOS_MAV_MIN_LEN, MAVLINK_MSG_ID_TARGET_LOS_MAV_LEN, MAVLINK_MSG_ID_TARGET_LOS_MAV_CRC);
#endif
}
#endif

#endif

// MESSAGE TARGET_LOS_MAV UNPACKING


/**
 * @brief Get field los_unit from target_los_mav message
 *
 * @return  Unit direction towards the target in camera FRD axes, ordered X, Y, Z.
 */
static inline uint16_t mavlink_msg_target_los_mav_get_los_unit(const mavlink_message_t* msg, float *los_unit)
{
    return _MAV_RETURN_float_array(msg, los_unit, 3,  0);
}

/**
 * @brief Get field los_rate from target_los_mav message
 *
 * @return  Time derivative of los_unit in camera FRD axes, ordered X, Y, Z, in 1/s. This is a vector derivative, not the LOS angular-velocity vector.
 */
static inline uint16_t mavlink_msg_target_los_mav_get_los_rate(const mavlink_message_t* msg, float *los_rate)
{
    return _MAV_RETURN_float_array(msg, los_rate, 3,  12);
}

/**
 * @brief Get field valid from target_los_mav message
 *
 * @return  1 if the input tracker reports a confirmed lock, otherwise 0. Receivers must also check freshness; an old valid sample is not a current lock.
 */
static inline uint8_t mavlink_msg_target_los_mav_get_valid(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  24);
}

/**
 * @brief Decode a target_los_mav message into a struct
 *
 * @param msg The message to decode
 * @param target_los_mav C-struct to decode the message contents into
 */
static inline void mavlink_msg_target_los_mav_decode(const mavlink_message_t* msg, mavlink_target_los_mav_t* target_los_mav)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_target_los_mav_get_los_unit(msg, target_los_mav->los_unit);
    mavlink_msg_target_los_mav_get_los_rate(msg, target_los_mav->los_rate);
    target_los_mav->valid = mavlink_msg_target_los_mav_get_valid(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TARGET_LOS_MAV_LEN? msg->len : MAVLINK_MSG_ID_TARGET_LOS_MAV_LEN;
        memset(target_los_mav, 0, MAVLINK_MSG_ID_TARGET_LOS_MAV_LEN);
    memcpy(target_los_mav, _MAV_PAYLOAD(msg), len);
#endif
}
