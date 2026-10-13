#pragma once
// MESSAGE DUBINS_PATH PACKING

#define MAVLINK_MSG_ID_DUBINS_PATH 516


typedef struct __mavlink_dubins_path_t {
 uint64_t time_usec; /*< [us] Timestamp (time since system boot).*/
 int32_t lat; /*< [degE7] Latitude of the path start.*/
 int32_t lon; /*< [degE7] Longitude of the path start.*/
 float alt; /*< [m] Altitude (MSL) the path is flown at.*/
 float heading; /*< [rad] Heading at the path start.*/
 float radius; /*< [m] Turn radius of both arcs.*/
 float segment_length[3]; /*< [m] Length of each of the three segments, in path order.*/
 float progress; /*< [m] Arc length of the vehicle's closest point on the path.*/
 uint8_t path_type; /*<  Path word, segment directions in order: 0 none, 1 RSR, 2 LSL, 3 RSL, 4 LSR, 5 RLR, 6 LRL.*/
} mavlink_dubins_path_t;

#define MAVLINK_MSG_ID_DUBINS_PATH_LEN 45
#define MAVLINK_MSG_ID_DUBINS_PATH_MIN_LEN 45
#define MAVLINK_MSG_ID_516_LEN 45
#define MAVLINK_MSG_ID_516_MIN_LEN 45

#define MAVLINK_MSG_ID_DUBINS_PATH_CRC 251
#define MAVLINK_MSG_ID_516_CRC 251

#define MAVLINK_MSG_DUBINS_PATH_FIELD_SEGMENT_LENGTH_LEN 3

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DUBINS_PATH { \
    516, \
    "DUBINS_PATH", \
    9, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_dubins_path_t, time_usec) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_dubins_path_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_dubins_path_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_dubins_path_t, alt) }, \
         { "heading", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_dubins_path_t, heading) }, \
         { "radius", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_dubins_path_t, radius) }, \
         { "segment_length", NULL, MAVLINK_TYPE_FLOAT, 3, 28, offsetof(mavlink_dubins_path_t, segment_length) }, \
         { "progress", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_dubins_path_t, progress) }, \
         { "path_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 44, offsetof(mavlink_dubins_path_t, path_type) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DUBINS_PATH { \
    "DUBINS_PATH", \
    9, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_dubins_path_t, time_usec) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_dubins_path_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_dubins_path_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_dubins_path_t, alt) }, \
         { "heading", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_dubins_path_t, heading) }, \
         { "radius", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_dubins_path_t, radius) }, \
         { "segment_length", NULL, MAVLINK_TYPE_FLOAT, 3, 28, offsetof(mavlink_dubins_path_t, segment_length) }, \
         { "progress", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_dubins_path_t, progress) }, \
         { "path_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 44, offsetof(mavlink_dubins_path_t, path_type) }, \
         } \
}
#endif

/**
 * @brief Pack a dubins_path message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (time since system boot).
 * @param lat [degE7] Latitude of the path start.
 * @param lon [degE7] Longitude of the path start.
 * @param alt [m] Altitude (MSL) the path is flown at.
 * @param heading [rad] Heading at the path start.
 * @param radius [m] Turn radius of both arcs.
 * @param segment_length [m] Length of each of the three segments, in path order.
 * @param progress [m] Arc length of the vehicle's closest point on the path.
 * @param path_type  Path word, segment directions in order: 0 none, 1 RSR, 2 LSL, 3 RSL, 4 LSR, 5 RLR, 6 LRL.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dubins_path_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, int32_t lat, int32_t lon, float alt, float heading, float radius, const float *segment_length, float progress, uint8_t path_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DUBINS_PATH_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, lat);
    _mav_put_int32_t(buf, 12, lon);
    _mav_put_float(buf, 16, alt);
    _mav_put_float(buf, 20, heading);
    _mav_put_float(buf, 24, radius);
    _mav_put_float(buf, 40, progress);
    _mav_put_uint8_t(buf, 44, path_type);
    _mav_put_float_array(buf, 28, segment_length, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DUBINS_PATH_LEN);
#else
    mavlink_dubins_path_t packet;
    packet.time_usec = time_usec;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.heading = heading;
    packet.radius = radius;
    packet.progress = progress;
    packet.path_type = path_type;
    mav_array_assign_float(packet.segment_length, segment_length, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DUBINS_PATH_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DUBINS_PATH;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DUBINS_PATH_MIN_LEN, MAVLINK_MSG_ID_DUBINS_PATH_LEN, MAVLINK_MSG_ID_DUBINS_PATH_CRC);
}

/**
 * @brief Pack a dubins_path message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (time since system boot).
 * @param lat [degE7] Latitude of the path start.
 * @param lon [degE7] Longitude of the path start.
 * @param alt [m] Altitude (MSL) the path is flown at.
 * @param heading [rad] Heading at the path start.
 * @param radius [m] Turn radius of both arcs.
 * @param segment_length [m] Length of each of the three segments, in path order.
 * @param progress [m] Arc length of the vehicle's closest point on the path.
 * @param path_type  Path word, segment directions in order: 0 none, 1 RSR, 2 LSL, 3 RSL, 4 LSR, 5 RLR, 6 LRL.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dubins_path_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint64_t time_usec, int32_t lat, int32_t lon, float alt, float heading, float radius, const float *segment_length, float progress, uint8_t path_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DUBINS_PATH_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, lat);
    _mav_put_int32_t(buf, 12, lon);
    _mav_put_float(buf, 16, alt);
    _mav_put_float(buf, 20, heading);
    _mav_put_float(buf, 24, radius);
    _mav_put_float(buf, 40, progress);
    _mav_put_uint8_t(buf, 44, path_type);
    _mav_put_float_array(buf, 28, segment_length, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DUBINS_PATH_LEN);
#else
    mavlink_dubins_path_t packet;
    packet.time_usec = time_usec;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.heading = heading;
    packet.radius = radius;
    packet.progress = progress;
    packet.path_type = path_type;
    mav_array_memcpy(packet.segment_length, segment_length, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DUBINS_PATH_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DUBINS_PATH;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_DUBINS_PATH_MIN_LEN, MAVLINK_MSG_ID_DUBINS_PATH_LEN, MAVLINK_MSG_ID_DUBINS_PATH_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_DUBINS_PATH_MIN_LEN, MAVLINK_MSG_ID_DUBINS_PATH_LEN);
#endif
}

/**
 * @brief Pack a dubins_path message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (time since system boot).
 * @param lat [degE7] Latitude of the path start.
 * @param lon [degE7] Longitude of the path start.
 * @param alt [m] Altitude (MSL) the path is flown at.
 * @param heading [rad] Heading at the path start.
 * @param radius [m] Turn radius of both arcs.
 * @param segment_length [m] Length of each of the three segments, in path order.
 * @param progress [m] Arc length of the vehicle's closest point on the path.
 * @param path_type  Path word, segment directions in order: 0 none, 1 RSR, 2 LSL, 3 RSL, 4 LSR, 5 RLR, 6 LRL.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dubins_path_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,int32_t lat,int32_t lon,float alt,float heading,float radius,const float *segment_length,float progress,uint8_t path_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DUBINS_PATH_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, lat);
    _mav_put_int32_t(buf, 12, lon);
    _mav_put_float(buf, 16, alt);
    _mav_put_float(buf, 20, heading);
    _mav_put_float(buf, 24, radius);
    _mav_put_float(buf, 40, progress);
    _mav_put_uint8_t(buf, 44, path_type);
    _mav_put_float_array(buf, 28, segment_length, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DUBINS_PATH_LEN);
#else
    mavlink_dubins_path_t packet;
    packet.time_usec = time_usec;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.heading = heading;
    packet.radius = radius;
    packet.progress = progress;
    packet.path_type = path_type;
    mav_array_assign_float(packet.segment_length, segment_length, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DUBINS_PATH_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DUBINS_PATH;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DUBINS_PATH_MIN_LEN, MAVLINK_MSG_ID_DUBINS_PATH_LEN, MAVLINK_MSG_ID_DUBINS_PATH_CRC);
}

/**
 * @brief Encode a dubins_path struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param dubins_path C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dubins_path_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_dubins_path_t* dubins_path)
{
    return mavlink_msg_dubins_path_pack(system_id, component_id, msg, dubins_path->time_usec, dubins_path->lat, dubins_path->lon, dubins_path->alt, dubins_path->heading, dubins_path->radius, dubins_path->segment_length, dubins_path->progress, dubins_path->path_type);
}

/**
 * @brief Encode a dubins_path struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param dubins_path C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dubins_path_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_dubins_path_t* dubins_path)
{
    return mavlink_msg_dubins_path_pack_chan(system_id, component_id, chan, msg, dubins_path->time_usec, dubins_path->lat, dubins_path->lon, dubins_path->alt, dubins_path->heading, dubins_path->radius, dubins_path->segment_length, dubins_path->progress, dubins_path->path_type);
}

/**
 * @brief Encode a dubins_path struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param dubins_path C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dubins_path_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_dubins_path_t* dubins_path)
{
    return mavlink_msg_dubins_path_pack_status(system_id, component_id, _status, msg,  dubins_path->time_usec, dubins_path->lat, dubins_path->lon, dubins_path->alt, dubins_path->heading, dubins_path->radius, dubins_path->segment_length, dubins_path->progress, dubins_path->path_type);
}

/**
 * @brief Send a dubins_path message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec [us] Timestamp (time since system boot).
 * @param lat [degE7] Latitude of the path start.
 * @param lon [degE7] Longitude of the path start.
 * @param alt [m] Altitude (MSL) the path is flown at.
 * @param heading [rad] Heading at the path start.
 * @param radius [m] Turn radius of both arcs.
 * @param segment_length [m] Length of each of the three segments, in path order.
 * @param progress [m] Arc length of the vehicle's closest point on the path.
 * @param path_type  Path word, segment directions in order: 0 none, 1 RSR, 2 LSL, 3 RSL, 4 LSR, 5 RLR, 6 LRL.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_dubins_path_send(mavlink_channel_t chan, uint64_t time_usec, int32_t lat, int32_t lon, float alt, float heading, float radius, const float *segment_length, float progress, uint8_t path_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DUBINS_PATH_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, lat);
    _mav_put_int32_t(buf, 12, lon);
    _mav_put_float(buf, 16, alt);
    _mav_put_float(buf, 20, heading);
    _mav_put_float(buf, 24, radius);
    _mav_put_float(buf, 40, progress);
    _mav_put_uint8_t(buf, 44, path_type);
    _mav_put_float_array(buf, 28, segment_length, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DUBINS_PATH, buf, MAVLINK_MSG_ID_DUBINS_PATH_MIN_LEN, MAVLINK_MSG_ID_DUBINS_PATH_LEN, MAVLINK_MSG_ID_DUBINS_PATH_CRC);
#else
    mavlink_dubins_path_t packet;
    packet.time_usec = time_usec;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.heading = heading;
    packet.radius = radius;
    packet.progress = progress;
    packet.path_type = path_type;
    mav_array_assign_float(packet.segment_length, segment_length, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DUBINS_PATH, (const char *)&packet, MAVLINK_MSG_ID_DUBINS_PATH_MIN_LEN, MAVLINK_MSG_ID_DUBINS_PATH_LEN, MAVLINK_MSG_ID_DUBINS_PATH_CRC);
#endif
}

/**
 * @brief Send a dubins_path message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_dubins_path_send_struct(mavlink_channel_t chan, const mavlink_dubins_path_t* dubins_path)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_dubins_path_send(chan, dubins_path->time_usec, dubins_path->lat, dubins_path->lon, dubins_path->alt, dubins_path->heading, dubins_path->radius, dubins_path->segment_length, dubins_path->progress, dubins_path->path_type);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DUBINS_PATH, (const char *)dubins_path, MAVLINK_MSG_ID_DUBINS_PATH_MIN_LEN, MAVLINK_MSG_ID_DUBINS_PATH_LEN, MAVLINK_MSG_ID_DUBINS_PATH_CRC);
#endif
}

#if MAVLINK_MSG_ID_DUBINS_PATH_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_dubins_path_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, int32_t lat, int32_t lon, float alt, float heading, float radius, const float *segment_length, float progress, uint8_t path_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, lat);
    _mav_put_int32_t(buf, 12, lon);
    _mav_put_float(buf, 16, alt);
    _mav_put_float(buf, 20, heading);
    _mav_put_float(buf, 24, radius);
    _mav_put_float(buf, 40, progress);
    _mav_put_uint8_t(buf, 44, path_type);
    _mav_put_float_array(buf, 28, segment_length, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DUBINS_PATH, buf, MAVLINK_MSG_ID_DUBINS_PATH_MIN_LEN, MAVLINK_MSG_ID_DUBINS_PATH_LEN, MAVLINK_MSG_ID_DUBINS_PATH_CRC);
#else
    mavlink_dubins_path_t *packet = (mavlink_dubins_path_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->lat = lat;
    packet->lon = lon;
    packet->alt = alt;
    packet->heading = heading;
    packet->radius = radius;
    packet->progress = progress;
    packet->path_type = path_type;
    mav_array_assign_float(packet->segment_length, segment_length, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DUBINS_PATH, (const char *)packet, MAVLINK_MSG_ID_DUBINS_PATH_MIN_LEN, MAVLINK_MSG_ID_DUBINS_PATH_LEN, MAVLINK_MSG_ID_DUBINS_PATH_CRC);
#endif
}
#endif

#endif

// MESSAGE DUBINS_PATH UNPACKING


/**
 * @brief Get field time_usec from dubins_path message
 *
 * @return [us] Timestamp (time since system boot).
 */
static inline uint64_t mavlink_msg_dubins_path_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field lat from dubins_path message
 *
 * @return [degE7] Latitude of the path start.
 */
static inline int32_t mavlink_msg_dubins_path_get_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field lon from dubins_path message
 *
 * @return [degE7] Longitude of the path start.
 */
static inline int32_t mavlink_msg_dubins_path_get_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field alt from dubins_path message
 *
 * @return [m] Altitude (MSL) the path is flown at.
 */
static inline float mavlink_msg_dubins_path_get_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field heading from dubins_path message
 *
 * @return [rad] Heading at the path start.
 */
static inline float mavlink_msg_dubins_path_get_heading(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field radius from dubins_path message
 *
 * @return [m] Turn radius of both arcs.
 */
static inline float mavlink_msg_dubins_path_get_radius(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field segment_length from dubins_path message
 *
 * @return [m] Length of each of the three segments, in path order.
 */
static inline uint16_t mavlink_msg_dubins_path_get_segment_length(const mavlink_message_t* msg, float *segment_length)
{
    return _MAV_RETURN_float_array(msg, segment_length, 3,  28);
}

/**
 * @brief Get field progress from dubins_path message
 *
 * @return [m] Arc length of the vehicle's closest point on the path.
 */
static inline float mavlink_msg_dubins_path_get_progress(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field path_type from dubins_path message
 *
 * @return  Path word, segment directions in order: 0 none, 1 RSR, 2 LSL, 3 RSL, 4 LSR, 5 RLR, 6 LRL.
 */
static inline uint8_t mavlink_msg_dubins_path_get_path_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  44);
}

/**
 * @brief Decode a dubins_path message into a struct
 *
 * @param msg The message to decode
 * @param dubins_path C-struct to decode the message contents into
 */
static inline void mavlink_msg_dubins_path_decode(const mavlink_message_t* msg, mavlink_dubins_path_t* dubins_path)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    dubins_path->time_usec = mavlink_msg_dubins_path_get_time_usec(msg);
    dubins_path->lat = mavlink_msg_dubins_path_get_lat(msg);
    dubins_path->lon = mavlink_msg_dubins_path_get_lon(msg);
    dubins_path->alt = mavlink_msg_dubins_path_get_alt(msg);
    dubins_path->heading = mavlink_msg_dubins_path_get_heading(msg);
    dubins_path->radius = mavlink_msg_dubins_path_get_radius(msg);
    mavlink_msg_dubins_path_get_segment_length(msg, dubins_path->segment_length);
    dubins_path->progress = mavlink_msg_dubins_path_get_progress(msg);
    dubins_path->path_type = mavlink_msg_dubins_path_get_path_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DUBINS_PATH_LEN? msg->len : MAVLINK_MSG_ID_DUBINS_PATH_LEN;
        memset(dubins_path, 0, MAVLINK_MSG_ID_DUBINS_PATH_LEN);
    memcpy(dubins_path, _MAV_PAYLOAD(msg), len);
#endif
}
